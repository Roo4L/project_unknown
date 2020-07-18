#include "directoryWidg.h"

DirWidget::DirWidget(QWidget *pwgt) : QDockWidget(pwgt)
{
    strFileName = "Directory";
    setWindowTitle(strFileName);

    pDir = new QDir;
    pDir->setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    pDir->setSorting(QDir::Size | QDir::Reversed);

    //QLabel *plbl = new QLabel;
    pwgt = new QWidget;

    pbtnAdd = new QPushButton("Add new");
    connect(pbtnAdd, SIGNAL(clicked()), this, SLOT(slotAdd()));

    playout = new QVBoxLayout;

    pal = new QPalette;
    pal->setColor(QPalette::Window, QColor(53, 53, 53));
    pal->setColor(QPalette::WindowText, QColor(Qt::black));
    pal->setColor(QPalette::Text, QColor(Qt::black));
    pal->setColor(QPalette::Base, QColor(25, 25, 25));
    pal->setColor(QPalette::AlternateBase, QColor(53, 53, 53));

    QLabel *pcurDir = new QLabel;
    //pcurDir->setFrameStyle(1);
    pcurDir->setPalette(*pal);
    pcurDir->setText(pDir->currentPath());

    /*QFileInfoList pDirList = pDir->entryInfoList();
    for (int i = 0; i < pDirList.size(); ++i) {
        QFileInfo fileInfo = pDirList.at(i);
        plbl->setText(QString("%1 %2").arg(fileInfo.size(), 10)
                .arg(fileInfo.fileName()));
        playout->addWidget(plbl);
    }*/

    playout->addWidget(pcurDir);
    playout->addWidget(pbtnAdd);
    //setLayout(playout);
    pwgt->setLayout(playout);
    //setWidget(pcurDir);
    //setWidget(pbtnAdd);
    pwgt->setPalette(*pal);
    setWidget(pwgt);
}

void DirWidget::slotAdd()
{
    QLabel *ptempDir = new QLabel;
    ptempDir->setPalette(*pal);
    ptempDir->setText(pDir->currentPath());
    playout->addWidget(ptempDir);
}
