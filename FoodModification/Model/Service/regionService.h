#ifndef REGIONSERVICE_H
#define REGIONSERVICE_H

#include <QVector>
#include "../SDK/opencv/opencvApi.h"
#include "../Param/color.h"
#include "../Param/source.h"

class RegionService {

/*method*/
public:
    RegionService();
    QVector<int>* calculateAverage(Mat srcBGRImg, QList<Point>& region);
    QList<Point> toPointList(Mat refImg, Scalar refColor);
private:
	QVector<int>* countSum(Mat srcBGRImg, QList<Point>& region);
	QVector<int>* countSum(Source imgs, QList<Point>& region);
	QVector<int>* countSum(Mat srcBGRImg, Mat refImg, Scalar refColor);
};
#endif // REGIONSERVICE_H
