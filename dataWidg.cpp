#include "dataWidg.h"

DataWidget::DataWidget(QWidget *pwgt) : QDockWidget(pwgt)
{
    strFileName = "Data";
    setWindowTitle(strFileName);
    psysInfo = new QSysInfo;

    QLabel *plblBuildCPU = new QLabel;
    plblBuildCPU->setText("BuildCPU" + psysInfo->buildCpuArchitecture());
    QLabel *plblCurCPU = new QLabel;
    plblCurCPU->setText("CurrentCPU: " + psysInfo->currentCpuArchitecture());
    QLabel *plblKerType = new QLabel;
    plblKerType->setText("Kernel Type: " + psysInfo->kernelType());
    QLabel *plblKerVer = new QLabel;
    plblKerVer->setText("Kernel Version: " + psysInfo->kernelVersion());
    QLabel *plblHostName = new QLabel;
    plblHostName->setText("Host Name: " + psysInfo->machineHostName());
    QLabel *plblProdType = new QLabel;
    plblProdType->setText(psysInfo->productType());
    QLabel *plblProdVersion = new QLabel;
    plblProdVersion->setText(psysInfo->productVersion());
    QLabel *plblByteOrder = new QLabel;
    plblByteOrder->setText("Byte Order: " + psysInfo->buildAbi());
    QLabel *plblPrettyProdName = new QLabel;
    plblPrettyProdName->setText("Pretty ProductName: " + psysInfo->prettyProductName());

    /*playout = new QVBoxLayout;
    playout->addWidget(plblBuildCPU, 0, 0);
    playout->addWidget(plblCurCPU, 0, 0);
    playout->addWidget(plblKerType, 0, 0);
    playout->addWidget(plblKerVer, 0, 0);
    playout->addWidget(plblHostName, 0, 0);
    playout->addWidget(plblProdType, 0, 0);
    playout->addWidget(plblProdVersion, 0, 0);
    playout->addWidget(plblByteOrder, 0, 0);
    playout->addWidget(plblPrettyProdName, 0, 0);
    setLayout(playout);*/

    setWidget(plblBuildCPU);
    setWidget(plblCurCPU);
    setWidget(plblKerType);
    setWidget(plblKerVer);
    setWidget(plblHostName);
    setWidget(plblProdType);
    setWidget(plblProdVersion);
    setWidget(plblByteOrder);
    setWidget(plblPrettyProdName);
}
