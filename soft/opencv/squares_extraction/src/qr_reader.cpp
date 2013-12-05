
#include "qr_reader.h"

using namespace cv;
using namespace std;

class QrReader::PD
{
public:
    cv::Mat orig;
    cv::Mat rotated;

    int smoothSz;
    int tresholdWndSz;

    vector<Point>   markers;
    QrDecoderHandle decoder;

    bool debug;
    RNG rng;
    PD()
        : rng(12345)
    {
        decoder = qr_decoder_open();
    }

    ~PD()
    {
        qr_decoder_close( decoder );
    }
    void rotateImage( const Mat & input, const vector<Point> & pts );
};

void QrReader::PD::rotateImage( const Mat & input, const vector<Point> & pts )
{
    cv::Point2f src_vertices[3];
    src_vertices[0] = pts[0];
    src_vertices[1] = pts[1];
    src_vertices[2] = pts[2];

    rotated = input.clone();
    Point2f center = Point2f( rotated.rows/2.0, rotated.cols/2.0 );
    double sz = ( rotated.rows < rotated.cols ) ? rotated.rows : rotated.cols;
    double margin = sz * 0.35;
    double w = sz * 0.3;

    Point2f dst_vertices[3];
    dst_vertices[0] = Point( margin,  margin );
    dst_vertices[1] = Point( margin + w, margin );
    dst_vertices[2] = Point( margin, margin + w );

    Mat warpAffineMatrix = getAffineTransform( src_vertices, dst_vertices );
    
    Size s( sz, sz );
    warpAffine( input, rotated, warpAffineMatrix, s, INTER_CUBIC, BORDER_CONSTANT );

}

QrReader::QrReader( int smoothSz, int tresholdWndSz, bool setup )
{
    pd = new PD();
    pd->smoothSz      = smoothSz;
    pd->tresholdWndSz = tresholdWndSz;
    pd->debug = setup;
    if ( setup )
    {
        namedWindow( "QrReader::orig", CV_WINDOW_NORMAL );
        cv::createTrackbar( "Blur value:",        "QrReader::orig", &pd->smoothSz,      300, 0 );
        cv::createTrackbar( "Treshold wnd size:", "QrReader::orig", &pd->tresholdWndSz, 300, 0 );
    }

}

QrReader::~QrReader()
{
    delete pd;
}

const std::string & QrReader::decode( const cv::Mat & img, const std::vector<cv::Point> & bounds )
{
    pd->rotateImage( img, bounds );

    IplImage* src = cvCloneImage( &(IplImage)pd->rotated );
    short stat=qr_decoder_decode_image( pd->decoder, src );
    cvReleaseImage( &src );
    printf("STATUS=%04x\n",stat);

    QrCodeHeader header;
    if ( qr_decoder_get_header( pd->decoder, &header ) )
    {
        //
        // get QR code text
        // To null terminate, a buffer size is larger than body size.
        //
        char *buf=new char[header.byte_size+1];
        int sz = qr_decoder_get_body( pd->decoder,(unsigned char *)buf,header.byte_size+1 );
        /*printf( "<content> *************************\n" );
        for ( int i=0; i<sz; i++ )
            printf( "%c", buf[i] );
        printf( "</content> ************************\n" );*/
        if ( pd->debug )
        {
            Scalar color = Scalar( 0, 0, 255 );
            cv::putText( pd->rotated, std::string( buf ), Point( 20, 40 ), 0, 1.0, color, 3 );
            cv::imshow( "QrReader::orig", pd->rotated );
        }
        delete buf;
    }
    return std::string();
}

