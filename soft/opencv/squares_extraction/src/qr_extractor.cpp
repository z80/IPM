
#include "qr_extractor.h"

using namespace cv;
using namespace std;

class QrExtractor::PD
{
public:
    cv::Mat orig;
    cv::Mat gray;
    cv::Mat blurred;
    cv::Mat blurredSaved;
    int smoothSz;
    int tresholdWndSz;

    vector<vector<Point>> contours;
    vector<Vec4i>         hierarchy;

    vector<Point>         markers;

    bool debug;
    RNG rng;
    PD()
        : rng(12345)
    {
        debug = false;
    }

    ~PD()
    {

    }
    static int weightO( const Mat & img, 
                 const Point & o, const Point & x, const Point & y, 
                 int pts = -1 );
    static int detectO( const Mat & img, const vector<Point> & o );
    static bool detectXy( const Point & o, const Point & x, const Point & y );
};

int  QrExtractor::PD::weightO( const Mat & img, 
                               const Point & o, const Point & x, const Point & y, 
                               int pts )
{
    if ( pts < 0 )
        pts = ( img.rows + img.cols ) / 4;
    Point to = Point( (x.x + y.x - 2*o.x), (x.y + y.y - 2*o.y) );
    int res = 0;
    for ( int i=0; i<pts; i++ )
    {
        Point at = Point( o.x + to.x*i/(pts-1), o.y + to.y*i/(pts-1) );
        if (at.x < 0)
            return pts * 255;
        if ( at.y < 0 )
            return pts * 255;
        if ( at.x >= img.cols )
            return pts * 255;
        if ( at.y >= img.rows )
            return pts * 255;
        res += img.data[ at.y * img.cols + at.x ]; //img.at( at )[0];
    }
    return res;
}

int  QrExtractor::PD::detectO( const Mat & img, const vector<Point> & o )
{
    if ( o.size() < 3 )
        return -1;
    int w0 = weightO( img, o[0], o[1], o[2] );
    int w1 = weightO( img, o[1], o[0], o[2] );
    int w2 = weightO( img, o[2], o[1], o[0] );
    if ( ( w0 <= w1 ) && ( w0 <= w2 ) )
        return 0;
    if ( ( w1 <= w0 ) && ( w1 <= w2 ) )
        return 1;
    return 2;
}

bool QrExtractor::PD::detectXy( const Point & o, const Point & x, const Point & y )
{
    Point ox = Point( x.x - o.x, x.y - o.y );
    Point oy = Point( y.x - o.x, y.y - o.y );
    int res = ox.x*oy.y - ox.y*oy.x;
    // Here <0 because QR code has center in upper right corner.
    return ( res > 0 );
}

QrExtractor::QrExtractor( int smoothSz, int tresholdWndSz, bool setup )
{
    pd = new PD();
    pd->smoothSz      = smoothSz;
    pd->tresholdWndSz = tresholdWndSz;
    pd->debug = setup;
    if ( setup )
    {
        namedWindow( "QrExtractor::orig", CV_WINDOW_NORMAL );
        cv::createTrackbar( "Blur value:",        "QrExtractor::orig", &pd->smoothSz,      300, 0 );
        cv::createTrackbar( "Treshold wnd size:", "QrExtractor::orig", &pd->tresholdWndSz, 300, 0 );
    }
}

QrExtractor::~QrExtractor()
{
    delete pd;
}

static unsigned int intRoot(unsigned int x)
{
    unsigned int a,b;
    b     = x;
    a = x = 0x3f;
    x     = b/x;
    a = x = (x+a)>>1;
    x     = b/x;
    a = x = (x+a)>>1;
    x     = b/x;
    x     = (x+a)>>1;
    return(x);
}

bool QrExtractor::extract( const cv::Mat & img )
{
    if ( pd->debug )
        pd->orig = img.clone();

    cv::cvtColor( img, pd->gray, CV_RGB2GRAY );

    if ( pd->smoothSz > 0 )
    {
        // Median accepts only odd values.
        cv::medianBlur( pd->gray, pd->blurred, (pd->smoothSz & 1) ? pd->smoothSz: pd->smoothSz+1 );
        cv::blur( pd->blurred, pd->blurred, cv::Size( pd->smoothSz, pd->smoothSz ) );
    }
    else
        pd->blurred = pd->gray;

    if ( !(pd->tresholdWndSz & 1) )
        pd->tresholdWndSz |= 1;
    cv::adaptiveThreshold( pd->blurred, pd->blurred, 255,
                           cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY,
                           pd->tresholdWndSz, 0.0 );

    
    pd->blurredSaved = pd->blurred.clone();
    cv::findContours( pd->blurred, pd->contours, pd->hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    //if ( pd->debug )
    //{
    //    for( unsigned i = 0; i<pd->contours.size(); i++ )
    //    {
    //        // Random color.
    //        Scalar color = Scalar( pd->rng.uniform(0, 255), pd->rng.uniform(0,255), pd->rng.uniform(0,255) );
    //        // Draw contour function.
    //        drawContours( pd->orig, pd->contours, i, color, 1, 8, pd->hierarchy, 0, Point() );
    //    }
    //}

    // Look for patterns.
    // There should be 3 squares. And each is a "pyramid of 3 squares" in turn.
    const double s1_s2_min = 1.0; //4.0/3.0;
    const double s1_s2_max = 6.0; //6.0/3.0;
    const double s2_s3_min = 1.0; //5.0/3.0;
    const double s2_s3_max = 6.0; //2.0/3.0;
    vector<Point> & markers = pd->markers;
    markers.clear();
    for ( unsigned s3Ind=0; s3Ind<pd->hierarchy.size(); s3Ind++ )
    {
        const Vec4i s3 = pd->hierarchy[s3Ind];
        // If there is parent;
        if (s3[3] < 0)
            continue;
        const unsigned s2Ind = s3[3];
        const Vec4i s2 = pd->hierarchy[ s2Ind ];
        // If there is parent;
        if (s2[3] < 0)
            continue;
        const unsigned s1Ind = s2[3];
        const Vec4i s1 = pd->hierarchy[ s1Ind ];

        // Compare areas.
        const double s3Area = contourArea( pd->contours[ s3Ind ] );
        if ( s3Area < 1.0 )
            continue;
        const double s2Area = contourArea( pd->contours[ s2Ind ] );
        if ( s2Area < 1.0 )
            continue;
        const double ratio2_3 = s2Area/s3Area;
        if ( ( ratio2_3 < s2_s3_min ) || ( ratio2_3 > s2_s3_max ) )
            continue;

        const double s1Area = contourArea( pd->contours[ s1Ind ] );
        const double ratio1_2 = s1Area/s2Area;
        if ( ( ratio1_2 < s1_s2_min ) || ( ratio1_2 > s1_s2_max ) )
            continue;

        Moments mu;
        double x, y;

        mu = moments( pd->contours[ s1Ind ] );
        x = mu.m10 / mu.m00;
        y = mu.m01 / mu.m00;

        mu = moments( pd->contours[ s2Ind ] );
        x += mu.m10 / mu.m00;
        y += mu.m01 / mu.m00;

        mu = moments( pd->contours[ s3Ind ] );
        x += mu.m10 / mu.m00;
        y += mu.m01 / mu.m00;

        x *= 0.333333333;
        y *= 0.333333333;

        markers.push_back( Point( static_cast<int>(x), static_cast<int>(y) ) );
        if ( markers.size() > 2 )
            break;
    }

    // Sort markers.
    // First one should be middle one.
    // Second - one along X axis.
    // And the last one along (-Y) axis.
    if ( markers.size() > 2 )
    {
        int indO = PD::detectO( pd->blurredSaved, markers );
        const Point & o = markers[ indO ];
        int indX = (indO+1)%3;
        int indY = (indO+2)%3;
        const Point & x = markers[ indX ];
        const Point & y = markers[ indY ];
        bool leftRf = PD::detectXy( o, x, y );
        if ( !leftRf )
        {
            int t = indX;
            indX = indY;
            indY = t;
        }
        markers.push_back( markers[ indO ] );
        markers.push_back( markers[ indX ] );
        markers.push_back( markers[ indY ] );
        markers[0] = markers[3];
        markers[1] = markers[4];
        markers[2] = markers[5];
        markers.resize( 3 );
    }


    if ( pd->debug && ( markers.size() > 2 ) )
    {
        cv::line( pd->orig, markers[0], markers[1], Scalar( 0, 0, 255 ), 3 );
        cv::line( pd->orig, markers[0], markers[2], Scalar( 0, 255, 0 ), 3 );
        //cv::line( pd->orig, markers[2], markers[0], Scalar( 0, 0, 255 ), 3 );
    }
    if ( pd->debug )
    {
        cv::imshow( "QrExtractor::orig",     pd->orig );
        cv::imshow( "QrExtractor::filtered", pd->blurredSaved );
    }

    return (markers.size() > 2);
}

const std::vector<cv::Point> & QrExtractor::points() const
{
    return pd->markers;
}



