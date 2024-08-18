#include <solarPanel.h>



solarPanel::solarPanel()
{
}


std::string solarPanel::takeAction(cv::Mat& fr)
{
    sd.setFrame(fr);
    sd.findSun();
    float AzimVal = 0.0;
    float ElevVal = 0.0;

    // According to sun position take the right action
    std::string verticle;   // for vertical tracking motors (frame y-axis )
    std::string horizontal; // for Horizontal tracking motors (frame x-axis )
    // horzontal direction
    if (sd.getSunCenter()[0] < sd.getFrameCenter()[0]) {
        horizontal = "Go Left";
        AzimVal = 5;
    } else if (sd.getSunCenter()[0] > sd.getFrameCenter()[0]) {
        horizontal = "Go Right";
        AzimVal = -5;
    } else {
        horizontal = "Don't move Horzontally";
    }

    // vertical diretion
    if (sd.getSunCenter()[1] < sd.getFrameCenter()[1]) {
        verticle = "Go UP";
        ElevVal = 5;
    } else if (sd.getSunCenter()[1] > sd.getFrameCenter()[1]) {
        verticle = "Go DOWN";
        ElevVal = -5;
    } else {
        verticle = "Don't move verticlly";
    }

    std::cout << " Action : " << verticle << "  " << horizontal << std::endl;
    Action = verticle + " and  " + horizontal;
    sd.display(Action);

    Cmd = "G1 " + "A" + AzimVal + " E" + ElevVal;
    ctrl.sendCmd(Cmd);

    return Action;
}