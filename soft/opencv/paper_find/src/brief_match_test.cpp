/*
 * matching_test.cpp
 *
 *  Created on: Oct 17, 2010
 *      Author: ethan
 */
#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;

void thresh_callback(int, void* );

int thresh = 184;
int max_thresh = 255;
RNG rng(12345);

Mat img, gray;
Mat blurred;
Mat toProcess;
int thresholdValue = 192;
int cutoffTo   = 255;

int blurValue = 10;
int eps       = 5;
int threshholdWindowSz = 3;

int main(int argc, const char ** argv)
{
    VideoCapture inputCapture;
    inputCapture.open( 0 );
    if ( !inputCapture.isOpened() )
    {
        cout << "Failed to open camera!";
        return 1;
    }

    namedWindow( "src", CV_WINDOW_AUTOSIZE );
    createTrackbar( "Blur value:",        "src", &blurValue,          max_thresh, 0 );
    createTrackbar( "Treshold from:",     "src", &thresholdValue,     max_thresh,    0 );
    createTrackbar( "Treshold wnd size:", "src", &threshholdWindowSz, 300, 0 );
    createTrackbar( "Contour epsilon:",   "src", &eps,                100, 0 );

    while ( true )
    {
        inputCapture >> img;
        
        gray.create( img.rows, img.cols, CV_8UC1 );
        blurred.create( img.rows, img.cols, CV_8UC1 );

        cvtColor( img, gray, CV_RGB2GRAY );
        
        if ( blurValue > 0 )
            blur( gray, blurred, Size( blurValue, blurValue ) );
        else
            blurred = gray;
        
        threshold( blurred, toProcess, thresholdValue, cutoffTo, THRESH_BINARY );
        //if ( threshholdWindowSz < 1 )
        //    threshholdWindowSz = 1;
        //adaptiveThreshold( blurred, toProcess, thresholdValue,
        //                   ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY,
        //                   threshholdWindowSz*2+1, 0.0 );

        thresh_callback( 0, 0 );

        imshow( "src", img );
        imshow( "For processing", toProcess );
        int res = 0;
        if ( waitKey( 200 ) == 'q' )
            break;
    }
    inputCapture.release();

    return 0;
}

void thresh_callback(int, void* )
{
    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    /// Detect edges using canny
    //Canny( blurred, canny_output, thresh, thresh*2, 3 );
    // Dilate helps to remove potential holes between edge segments
    //dilate( canny_output, canny_output, Mat(), Point(-1,-1) );
    /// Find contours
    //findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    Mat cont = toProcess.clone();
    Mat::MSize sz = toProcess.size;
    findContours( cont, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    const double minArea = 1000.0;
    double maxArea = minArea;
    int maxIndex = -1;
    std::vector<cv::Point> square;
    for ( unsigned i=0; i<contours.size(); i++ )
    {
        std::vector<cv::Point> approx;
        Mat v = Mat( contours[i] );
        double e = static_cast<double>(eps) * 0.01;
        cv::approxPolyDP( v, approx,
                          arcLength( v, true )*e, true );
        if ( ( approx.size() == 4 ) )
        {
            double area = contourArea( v, false );
            if ( area > maxArea )
            {
                maxArea  = area;
                maxIndex = i;
                square   = approx;
            }
        }
    }

    /// Draw contours
    //Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    //Mat drawing = Mat::zeros( blurred.size(), CV_8UC3 );
    for( int i = 0; i<contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        //drawContours( drawing, contours, i, color, 1, 8, hierarchy, 0, Point() );
        drawContours( img, contours, i, color, 1, 8, hierarchy, 0, Point() );
    }

    if ( square.size() > 3 )
    {
        Point pt;
        // Sort elements in decending Y direction.
        for ( unsigned i=0; i<3; i++ )
        {
            for ( unsigned j=i+1; j<4; j++ )
            {
                if (square[i].y > square[j].y)
                {
                    pt = square[i];
                    square[i] = square[j];
                    square[j] = pt;
                }
            }
        }
        // Sort first two in X accending.
        if ( square[0].x > square[1].x )
        {
            pt = square[0];
            square[0] = square[1];
            square[1] = pt;

        }
        // Sort last two in X decending.
        if ( square[2].x < square[3].x )
        {
            pt = square[2];
            square[2] = square[3];
            square[3] = pt;

        }

        //line( drawing, square[0], square[1], Scalar( 255, 0, 0 ), 3 );
        //line( drawing, square[1], square[2], Scalar( 0, 255, 0 ), 3 );
        //line( drawing, square[2], square[3], Scalar( 0, 0, 255 ), 3 );
        //line( drawing, square[3], square[0], Scalar( 255, 0, 0 ), 3 );
        line( img, square[0], square[1], Scalar( 255, 0, 0 ), 3 );
        line( img, square[1], square[2], Scalar( 0, 255, 0 ), 3 );
        line( img, square[2], square[3], Scalar( 0, 0, 255 ), 3 );
        line( img, square[3], square[0], Scalar( 255, 0, 0 ), 3 );

        RotatedRect box = minAreaRect( cv::Mat(square) );

        cv::Point2f src_vertices[4];
        src_vertices[0] = square[0];
        src_vertices[1] = square[1];
        src_vertices[2] = square[2];
        src_vertices[3] = square[3];

        Point2f dst_vertices[4];
        dst_vertices[0] = Point(0, box.boundingRect().height -1);
        dst_vertices[1] = Point(box.boundingRect().width - 1, box.boundingRect().height -1);
        dst_vertices[2] = Point(box.boundingRect().width - 1, 0 );
        dst_vertices[3] = Point(0, 0);

        //Mat warpAffineMatrix = getAffineTransform(src_vertices, dst_vertices);
        Mat warpPerspectiveMatrix = getPerspectiveTransform( src_vertices, dst_vertices );
        cv::Mat rotated;
        cv::Size size( box.boundingRect().width, box.boundingRect().height );
        //warpAffine( img, rotated, warpAffineMatrix, size, INTER_LINEAR, BORDER_CONSTANT);
        warpPerspective( img, rotated, warpPerspectiveMatrix, size, INTER_LINEAR, BORDER_CONSTANT);

        namedWindow( "Result", CV_WINDOW_NORMAL /*CV_WINDOW_AUTOSIZE*/ );
        imshow( "Result", rotated );
    }
    /// Show in a window
    //namedWindow( "Contours", CV_WINDOW_NORMAL /*CV_WINDOW_AUTOSIZE*/ );
    //imshow( "Contours", drawing );


}


