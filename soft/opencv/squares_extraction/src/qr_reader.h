
#ifndef __QR_READER_H_
#define __QR_READER_H_

#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <iostream>
#include "decodeqr.h"

class QrReader
{
public:
    QrReader( int smoothSz = 3, int tresholdWndSz = 65, bool setup = false );
    ~QrReader();
    const std::string & decode( const cv::Mat & img, const std::vector<cv::Point> & bounds );
private:
    class PD;
    PD * pd;
};



#endif




