#include "mainApp.h"

App::App(int& argc, char** argv,
    const QString& strOrg,
    const QString& strAppName) :
    QApplication(argc, argv), m_pSettings(0)
{
    setOrganizationName(strOrg);
    setApplicationName(strAppName);

    m_pSettings = new QSettings(strOrg, strAppName, this);
}

QSettings* App::getSettings()
{
    return m_pSettings;
}
