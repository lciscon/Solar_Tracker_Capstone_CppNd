#ifndef SOLARPANEL_H
#define SOLARPANEL_H
#include <string>
#include <motionCtrl.h>
#include <SunDetector.h>

class solarPanel
{
private:
    //std::string imagePath = "../resources/sun.png";
    
    std::string Action;

public:
    sunDetector sd;
    motionCtrl ctrl;

    //constructor 
    solarPanel();
    // Take actions to Motors
    std::string takeAction(cv::Mat& fr);
};



#endif 