#ifndef DIRECTORYWIDG_H
#define DIRECTORYWIDG_H
#include <QtWidgets>

class DirWidget : public QDockWidget
{
    Q_OBJECT
private:
    QString strFileName;
    QWidget *pwgt;
    QDir *pDir;
    QPushButton *pbtnAdd;
    QPalette *pal;
    QVBoxLayout *playout;
public:
    DirWidget(QWidget *pwgt = nullptr);
private slots:
    void slotAdd();
};

#endif // DIRECTORYWIDG_H
