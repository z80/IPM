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

#include "qr_extractor.h"
#include "qr_reader.h"

using namespace cv;
using namespace std;

void thresh_callback(int, void* );

int thresh = 184;
int max_thresh = 255;
RNG rng(12345);

Mat captured;
Mat gray;
Mat blurred;
Mat binned;
Mat toProcess;

int blurValue = 2;
int thresholdValue = 192;
int threshholdWindowSz = 50;


int main(int argc, const char ** argv)
{
    VideoCapture inputCapture;
    inputCapture.open( 0 );
    if ( !inputCapture.isOpened() )
    {
        cout << "Failed to open camera!";
        return 1;
    }

    //namedWindow( "src", CV_WINDOW_AUTOSIZE );
    //createTrackbar( "Blur value:",        "src", &blurValue,          max_thresh, 0 );
    //createTrackbar( "Treshold value:",    "src", &thresholdValue,     max_thresh,    0 );
    //createTrackbar( "Treshold wnd size:", "src", &threshholdWindowSz, 300, 0 );

    QrExtractor qe( 3, 30, true );
    QrReader    qr( 3, 65, true );

    while ( true )
    {
        inputCapture >> captured;

        bool res = qe.extract( captured );
        if ( res )
            qr.decode( captured, qe.points() );
        //gray.create( captured.rows, captured.cols, CV_8UC1 );
        //blurred.create( captured.rows, captured.cols, CV_8UC1 );

        //cvtColor( captured, gray, CV_RGB2GRAY );

        //medianBlur( gray, blurred, (blurValue & 1) ? blurValue: blurValue+1 );
        //if ( blurValue > 0 )
        //{
        //    blur( blurred, blurred, Size( blurValue, blurValue ) );
        //}
        //else
        //    blurred = gray;

        ////threshold( blurred, toProcess, thresholdValue, cutoffTo, THRESH_BINARY );
        //if ( threshholdWindowSz < 1 )
        //    threshholdWindowSz = 1;
        //adaptiveThreshold( blurred, toProcess, thresholdValue,
        //                   ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,
        //                   threshholdWindowSz*2+1, 0.0 );



        //// Find contours
        //vector<vector<Point> > contours;
        //vector<Vec4i>          hierarchy;

        //Mat cont = toProcess.clone();
        //Mat::MSize sz = toProcess.size;
        //findContours( cont, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

        //// Draw contours
        //for( int i = 0; i<contours.size(); i++ )
        //{
        //    // Random color.
        //    Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        //    // Draw contour function.
        //    drawContours( captured, contours, i, color, 1, 8, hierarchy, 0, Point() );
        //}

        //// Look for patterns.
        //// There should be 3 squares. And each is a "pyramid of 3 squares" in turn.
        //const double s1_s2_min = 1.0; //4.0/3.0;
        //const double s1_s2_max = 6.0; //6.0/3.0;
        //const double s2_s3_min = 1.0; //5.0/3.0;
        //const double s2_s3_max = 6.0; //2.0/3.0;
        //vector<Point> markers;
        //for ( unsigned s3Ind=0; s3Ind<hierarchy.size(); s3Ind++ )
        //{
        //    const Vec4i s3 = hierarchy[s3Ind];
        //    // If there is parent;
        //    if (s3[3] < 0)
        //        continue;
        //    const unsigned s2Ind = s3[3];
        //    const Vec4i s2 = hierarchy[ s2Ind ];
        //    // If there is parent;
        //    if (s2[3] < 0)
        //        continue;
        //    const unsigned s1Ind = s2[3];
        //    const Vec4i s1 = hierarchy[ s1Ind ];

        //    // Compare areas.
        //    const double s3Area = contourArea( contours[ s3Ind ] );
        //    const double s2Area = contourArea( contours[ s2Ind ] );
        //    const double ratio2_3 = s2Area/s3Area;
        //    if ( ( ratio2_3 < s2_s3_min ) || ( ratio2_3 > s2_s3_max ) )
        //        continue;

        //    const double s1Area = contourArea( contours[ s1Ind ] );
        //    const double ratio1_2 = s1Area/s2Area;
        //    if ( ( ratio1_2 < s1_s2_min ) || ( ratio1_2 > s1_s2_max ) )
        //        continue;

        //    Moments mu;
        //    double x, y;

        //    mu = moments( contours[ s1Ind ] );
        //    x = mu.m10 / mu.m00;
        //    y = mu.m01 / mu.m00;

        //    mu = moments( contours[ s2Ind ] );
        //    x += mu.m10 / mu.m00;
        //    y += mu.m01 / mu.m00;

        //    mu = moments( contours[ s3Ind ] );
        //    x += mu.m10 / mu.m00;
        //    y += mu.m01 / mu.m00;

        //    x *= 0.333333333;
        //    y *= 0.333333333;

        //    markers.push_back( Point( x, y ) );
        //}
        //if ( markers.size() > 2 )
        //{
        //    line( captured, markers[0], markers[1], Scalar( 255, 0, 0 ), 3 );
        //    line( captured, markers[1], markers[2], Scalar( 0, 255, 0 ), 3 );
        //    line( captured, markers[2], markers[0], Scalar( 0, 0, 255 ), 3 );
        //}


        //imshow( "src", captured );
        //imshow( "For processing",    toProcess );

        if ( waitKey( 200 ) == 'q' )
            break;
    }
    inputCapture.release();

    return 0;
}






