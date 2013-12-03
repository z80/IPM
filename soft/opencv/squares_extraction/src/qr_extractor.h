
#ifndef __QR_EXTRACTOR_H_
#define __QR_EXTRACTOR_H_

#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <iostream>


class QrExtractor
{
public:
    QrExtractor( int smoothSz = 2, int tresholdWndSz = 50 );
    ~QrExtractor();
    bool extract( const cv::Mat & img );
    void setDebug( bool en );
private:
    class PD;
    PD * pd;
};


#endif


