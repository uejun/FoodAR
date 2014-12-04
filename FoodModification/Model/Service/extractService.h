#ifndef EXTRACTSERVICE_H
#define EXTRACTSERVICE_H

#include "../condition.h"
#include "../Param/region.h"
#include "../Param/matSet.h"
#include "../featureReference.h"
#include "../SDK/opencv/opencvApi.h"
#include "contourService.h"

class ExtractService {

/*method*/
public:
    ExtractService();
    void extractRegionByColor(MatSet& matSet, Region& result);
    Region acquireMaxAreaRegion(Region& region);

/*property*/
private:
	Condition& _condition 				= Condition::getInstance();
	FeatureReference& _featureReference = FeatureReference::getInstance();
    ContourService* _contourService;
	

};

#endif // EXTRACTSERVICE_H
