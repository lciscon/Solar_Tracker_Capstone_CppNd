#ifndef MOTIONCTRL_H
#define MOTIONCTRL_H
#include <string>

class motionCtrl
{
private:    
    std::string Action;
    int fd;
    const char* device = "/dev/ttyACM0"; 
    const int baud = 9600;              // Arduino baud rate

public:

    //constructor 
    motionCtrl();
    // Take actions to Motors
    std::string sendCmd(std::string cmd);
};



#endif 