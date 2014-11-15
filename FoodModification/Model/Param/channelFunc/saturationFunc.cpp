#include "saturationFunc.h"

SaturationFunc::SaturationFunc() {
}

int SaturationFunc::value(Mat img, int x, int y) {
	return G(img, x, y);
}


int SaturationFunc::value(MatSet* matSet, int x, int y) {
	return value(matSet->hsv(),x,y);
}