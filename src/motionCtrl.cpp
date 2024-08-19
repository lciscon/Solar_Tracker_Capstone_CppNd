#include <solarPanel.h>
#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <unistd.h>  // for usleep()


motionCtrl::motionCtrl()
{
    //open the serial connection to the controller
    fd = serialOpen(device, baud);
    if (fd == -1) {
        std::cerr << "Unable to open serial device" << std::endl;
        exit(0);
    }

    std::cout << "Serial port opened successfully" << std::endl;

}


std::string motionCtrl::sendCmd(std::string cmd)
{

    std::cout << "Sending cmd..." << std::endl;
    serialPuts(fd, cmd.c_str());
    serialPutchar(fd, '\n');
    serialFlush(fd);

    // Wait for acknowledgement
    while (serialDataAvail(fd) <= 0) {
        // Wait for data to be available
        usleep(10000);  // 10ms delay
    }
//    while (serialDataAvail(fd) > 0) {
//        std::cout << (char)serialGetchar(fd);
//    }
//    std::cout << std::endl;
      
    return(cmd);
}

//    serialClose(fd);

