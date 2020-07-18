#ifndef REFERENCE_H
#define REFERENCE_H
#include <QtWidgets>

class Reference : public QDockWidget
{
    Q_OBJECT
private:
    QString m_strFileName;
    QTextEdit *m_ptxt;
    QLayout *m_playt;
public:
    Reference(QWidget *pwgt = nullptr);
    void writeSettings();
    void readSettings();
};

#endif // REFERENCE_H
