#include "mainProcedure.h"

void MainProcedure::start() {
    _isProcessed = true;
    _sourcer.setUp();
    _saver.save();

    
    while (_isProcessed) {

        MatSet matSet;
        _sourcer.loadSrc(matSet);
		
        _extractor.extract(matSet,_extractedRegion);
        //_extractor.extractCoffee(matSet,_extractedRegion);
        
        Mat resultTexture = Mat::zeros(matSet.size(), CV_8UC3);
        
        if(_textureManager.currentMediaType() != MediaType::no) {
            _textureFactory.create(_extractedRegion, resultTexture);
        }
         
        Mat dstBGRImg = matSet.bgr().clone();
        _converter.convert(matSet, _extractedRegion, resultTexture, dstBGRImg);
        
        imshow(_windowManager.windowName(0), matSet.bgr());
        _outputer.show(dstBGRImg);
        moveWindow(_windowManager.windowName(0), 100, 0);

        char ch = waitKey(10);
        if ( ch == 27 ) break;
    }
}

void MainProcedure::stop() {
    _isProcessed = false;
}

MainProcedure::MainProcedure() {
}

MainProcedure& MainProcedure::getInstance() {
    static MainProcedure instance;
    return instance;
}
