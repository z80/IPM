
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

    PD()
    {
        debug = false;
    }

    ~PD()
    {

    }

};

QrExtractor::QrExtractor( int smoothSz, int tresholdWndSz )
{
    pd = new PD();
    pd->smoothSz      = smoothSz;
    pd->tresholdWndSz = tresholdWndSz;
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
    if ( debug )
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

    if ( !(pd->pd->tresholdWndSz & 1) )
        pd->tresholdWndSz |= 1;
    cv::adaptiveThreshold( pd->blurred, pd->blurred, 255,
                           cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY,
                           pd->tresholdWndSz, 0.0 );

    if ( pd->debug )
        pd->blurredSaved = pd->blurred.clone();
    cv::findContours( pd->blurred, pd->contours, pd->hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    if ( pd->debug )
    {
        for( int i = 0; i<pd->contours.size(); i++ )
        {
            // Random color.
            Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
            // Draw contour function.
            drawContours( pd->orig, pd->contours, i, color, 1, 8, pd->hierarchy, 0, Point() );
        }
    }

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

        markers.push_back( Point( x, y ) );
        if ( markers.size() > 2 )
            break;
    }

    // Sort markers.
    // First one should be middle one.
    // Second - one along X axis.
    // And the last one along (-Y) axis.
    if ( markers.size() > 2 )
    {

    }


    if ( debug && ( markers.size() > 2 ) )
    {
        cv::line( pd->orig, markers[0], markers[1], Scalar( 255, 0, 0 ), 3 );
        cv::line( pd->orig, markers[1], markers[2], Scalar( 0, 255, 0 ), 3 );
        cv::line( pd->orig, markers[2], markers[0], Scalar( 0, 0, 255 ), 3 );
    }
    if ( debug )
    {
        cv::imshow( "QrExtractor::orig",     pd->orig );
        cv::imshow( "QrExtractor::filtered", pd->blurredSaved );
    }

    return (markers.size() > 2);
}



