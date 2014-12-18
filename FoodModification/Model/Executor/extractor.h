#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "../TypeDef.h"
#include "../Param/edge.h"
#include "../Param/matSet.h"
#include "../Param/region.h"
#include "../edgeFactory.h"
#include "../Service/edgeService.h"
#include "../Service/extractService.h"
#include "../Service/contourService.h"
#include "../Manager/extractionManager.h"
#include "../Manager/edgeManager.h"
#include "../Manager/regionManager.h"
#include "../SDK/opencv/opencvApi.h"
#include "../Param/channelSet.h"
#include "../Extraction/State/contourState.h"
#include "../Extraction/State/contourExisted.h"
#include "../Extraction/State/contourNonEXisted.h"
#include "../Extraction/State/ContourCount/contourCountState.h"
#include "../Extraction/State/ContourCount/multiContour.h"
#include "../Extraction/State/ContourCount/oneContour.h"


class Extractor {

/*method*/
public:
    static Extractor& getInstance();
    void extract(const MatSet& srcSet);
    int calcIndexOfMaxArea(vPs& contours) {
        if(!contours.size()) {
            return -1;
        }
        size_t max=0;
        int indexForMaxArea=-1;
        for(int i=0; i<contours.size(); ++i) {
            size_t count = contours[i].size();
            //if(count < 300 || count > 1000) continue;

            if(count > max) {
                indexForMaxArea = i;
                max = count;
            }
        }

        return indexForMaxArea;
    }

    vector<int> calcIndexiesOfTop3Area(vPs& contours) {
       
        size_t max=0;
        size_t second =0;
        size_t third = 0;
        vector<int> indexForTop3 = {-1, -1, -1};
        
        const int FIRST = 0;
        const int SECOND = 1;
        const int THIRD = 2;

        if(contours.size() > 0) {
            for(int i=0; i<contours.size(); ++i) {
                size_t count = contours[i].size();
                //if(count < 300 || count > 1000) continue;

                if(count > max) {
                    indexForTop3[THIRD] = indexForTop3[SECOND];
                    indexForTop3[SECOND] = indexForTop3[FIRST];
                    indexForTop3[FIRST] = i;
                    third = second;
                    second = max;
                    max = count;
                } else if(count > second) {
                    indexForTop3[THIRD] = indexForTop3[SECOND];
                    indexForTop3[SECOND] = i;
                    third = second;
                    second = count;
                } else if(count > third) {
                    indexForTop3[THIRD] = i;
                    third = count;
                }
            }
        }
        
        return indexForTop3;
    }

private:
    Extractor();
    Extractor(const Extractor&);

    bool isInROI(Point p, Point2f roi[]) {
        double pro[4];
        for(int i=0; i<4; ++i) {
            pro[i] = computeProduct(p, roi[i], roi[(i+1)%4]);
        }
        if(pro[0]*pro[2]<0 && pro[1]*pro[3]<0) {
            return true;
        }
        return false;
    }

    double computeProduct(Point p, Point2f a, Point2f b) {
        double k = (a.y-b.y)/(a.x-b.x);
        double j = a.y -k*a.x;
        return k*p.x -p.y + j;
    }


/*property*/
private:
	ExtractService  _extractService;
    EdgeService _edgeService;
    ContourService _contourService;
	FeatureReference& _featureReference = FeatureReference::getInstance();
    EdgeFactory& _edgeFactory = EdgeFactory::getInstance();
    ExtractionManager& _extractionManager = ExtractionManager::getInstance();
    RegionManager& _regionManager = RegionManager::getInstance();
    EdgeManager& _edgeManager = EdgeManager::getInstance();
    int _indexOfMaxArea=-1;
    ContourState& _contourExisted = ContourExisted::getInstance();
	ContourState& _contourNonExisted = ContourNonExisted::getInstance();
    ContourCountState& _oneContour = OneContour::getInstance();
    ContourCountState& _multiContour = MultiContour::getInstance();
   

};

#endif // EXTRACTOR_H
