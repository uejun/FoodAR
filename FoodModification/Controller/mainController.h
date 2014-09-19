#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "opencv2/opencv.hpp"
#include "./extractController.h"
#include "../Utils/opencvUtils.h"
#include "./textureController.h"

class MainController {

private:
    ExtractController* extractController;
    TextureController* textureController;

public:
    MainController(ExtractParamManager *extractParamManager);
    void doConvertion();
    
};

#endif // MAINCONTROLLER_H