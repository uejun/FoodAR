#include "bgr3dPlotDialog.h"
#include "ui_bgr3dPlotDialog.h"

BGR3DPlotDialog::BGR3DPlotDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::BGR3DPlotDialog)
{
    
	ui->setupUi(this);


    _bgr3DPlotController.prepareBGR3dPlot(ui->bgr3dPlotAreaWidget->_viewer);
    _bgr3DPlotController.prepare_xyHistogram(ui->histogram3dAreaWidget->_viewer);

    
}

BGR3DPlotDialog::~BGR3DPlotDialog()
{
	delete ui;
}
