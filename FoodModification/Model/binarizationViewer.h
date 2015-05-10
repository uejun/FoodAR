#ifndef BINARIZATIONVIEWER_H
#define BINARIZATIONVIEWER_H

#include "./SDK/opencv/opencvApi.h"
#include "./Manager/cameraManager.h"

class BinarizationViewer {

/*method*/
public:
	BinarizationViewer();
	void showBinarizedImgs(int* thresholdsFromFile);
	void closeBinarizedImgs(int* thresholds);
	void finish() {
		_isShowing=false;
	}

private:

/*property*/
private:
	bool _isShowing = true;
    CameraManager& _cameraManager = CameraManager::getInstance();
	int _thresholds[5];
};

#endif // BINARIZATIONVIEWER_H
