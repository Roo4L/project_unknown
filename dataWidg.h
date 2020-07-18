#ifndef DATAWIDG_H
#define DATAWIDG_H
#include <QtWidgets>
#include <QLayout>

class DataWidget : public QDockWidget
{
    Q_OBJECT
private:
    QString strFileName;
    QSysInfo *psysInfo;
    QVBoxLayout *playout;
public:
    DataWidget(QWidget *pwgt = nullptr);
};

#endif // DATAWIDG_H
