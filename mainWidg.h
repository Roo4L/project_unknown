#ifndef CENTRALWIDG_H
#define CENTRALWIDG_H
#include <QtWidgets>
#include "referenceWidg.h"
#include "directoryWidg.h"
#include "dataWidg.h"
#include "commandWidg.h"
#include "temp_dockWidg.h"

class QMenu;
class QSignalMapper;
class QMdiArea;

class MainWidget : public QMainWindow
{
    Q_OBJECT
private:
    //maybe use QDataWidgetMapper
    //or another mapper
    QMenu *m_pmnuWindows;
    QMenu *m_pmnuWidgets;
    QMenu *m_psubWidCreate;
    QSignalMapper *m_psigMapper;
    QTabWidget *m_pTab;
    QMdiArea *m_pma;
    Reference *m_pdocRef;
    DirWidget *m_pdocDir;
    QDockWidget *m_pdocCom;
    DataWidget *m_pdocData;
    QVector<QDockWidget*> m_pdocArr;
    DocWindow* createNewDoc();
public:
    MainWidget(QWidget *pwgt = nullptr);
    ~MainWidget(){};
    //relocate to mainApp
    //incapsulate
    void writeSettings();
    void readSettings();
private slots:
    /* file section slots
    void slotFileCreateFileProject();
    void slotFileOpenFileProject();
    void slotFileRecentProjects();
    void slotFileSaveFileProject();
    void slotFileSaveAll();
    void slotFileCloseAll();
    */
    /* edit section slots
    void slotEditUndo(); //may be useless
    void slotEditRepeat(); //may be useless
    void slotEditInsert(); //may be useless
    void slotEditOpenTextSettings();
    void slotEditSetDefaultSettings();
    */
    void slotCreateReference();
    void slotCreateDirectory();
    void slotCreateCommand();
    void slotCreateData();
    void slotCreateReset();
    void slotChangeWindowTitle(const QString&);
    void slotNewDoc();
    //void slotLoad();
    //void slotSave();
    //void slotSaveAs();
    void slotHelpAbout(); //also help section slot
    /* help section slots
    void slotHelpDonates();
    void slotHelpDocumentation();
    */
    /* view section slots
    void slotViewPresets();
    void slotViewAppSettings();
    void slotViewSetDefaultAppSettings();
    */
    void slotWindows();
    void slotSetActiveSubWindow(QWidget*);
};

#endif // CENTRALWIDG_H
