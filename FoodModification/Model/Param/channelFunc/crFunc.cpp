#include "crFunc.h"

CrFunc::CrFunc() {
}

int CrFunc::value(Mat img, int x, int y) {
	return G(img, x, y);
}

int CrFunc::value(MatSet* matSet, int x, int y) {
	return value(matSet->ycrcb(),x,y);
}