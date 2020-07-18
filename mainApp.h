#ifndef MAINAPP_H
#define MAINAPP_H
#include <QApplication>
#include <QSettings>

class App : public QApplication
{
    Q_OBJECT
private:
    QSettings *m_pSettings;
public:
    App(int& argc, char** argv,
        const QString& strOrg,
        const QString& strAppName);
    static App* theApp()
    {
        return (App*)qApp;
    }
    QSettings* getSettings();

};


#endif // MAINAPP_H
