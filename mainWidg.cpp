#include "mainWidg.h"

MainWidget::MainWidget(QWidget *pwgt) : QMainWindow(pwgt)
{
    //cruthes
    //File section
    QAction *pactFileCreateFileProject = new QAction("New file or project", 0);
    pactFileCreateFileProject->setText("&Create new file or project...");
    pactFileCreateFileProject->setShortcut(QKeySequence("CTRL+N"));
    pactFileCreateFileProject->setToolTip("New file or project");
    pactFileCreateFileProject->setStatusTip("Create a new file or project");
    pactFileCreateFileProject->setWhatsThis("Create a new file or project");
    pactFileCreateFileProject->setIcon(QPixmap());
    connect(pactFileCreateFileProject, SIGNAL(triggered()), SLOT(slotFileCreateFileProject()));

    QAction *pactFileOpenFileProject = new QAction("Open file or project", 0);
    pactFileOpenFileProject->setText("&Open file or project...");
    pactFileOpenFileProject->setShortcut(QKeySequence("CTRL+O"));
    pactFileOpenFileProject->setToolTip("Open file or project");
    pactFileOpenFileProject->setStatusTip("Open a new file or project");
    pactFileOpenFileProject->setWhatsThis("Open a new file or project");
    pactFileOpenFileProject->setIcon(QPixmap());
    connect(pactFileOpenFileProject, SIGNAL(triggered()), SLOT(slotFileOpenFileProject()));

    QAction *pactFileRecentProjects = new QAction("Recent projects", 0); //with arrow menu like in Qt
    pactFileRecentProjects->setText("Recent &projects");
    pactFileRecentProjects->setToolTip("Open recent projects");
    pactFileRecentProjects->setStatusTip("Open recent projects");
    pactFileRecentProjects->setWhatsThis("Open recent projects");
    pactFileRecentProjects->setIcon(QPixmap());
    connect(pactFileRecentProjects, SIGNAL(triggered()), SLOT(slotFileRecentProjects()));

    QAction *pactFileSaveFileProject = new QAction("Save project", 0);
    pactFileSaveFileProject->setText("&Save project");
    pactFileSaveFileProject->setShortcut(QKeySequence("CTRL+S"));
    pactFileSaveFileProject->setToolTip("Save project");
    pactFileSaveFileProject->setStatusTip("Save project");
    pactFileSaveFileProject->setWhatsThis("Save project");
    pactFileSaveFileProject->setIcon(QPixmap());
    connect(pactFileSaveFileProject, SIGNAL(triggered()), SLOT(slotFileSaveFileProject()));

    QAction *pactFileSaveAll = new QAction("Save all", 0);
    pactFileSaveAll->setText("Save &all");
    pactFileSaveAll->setShortcut(QKeySequence("CTRL+Shift+S"));
    pactFileSaveAll->setToolTip("Save all");
    pactFileSaveAll->setStatusTip("Save all");
    pactFileSaveAll->setWhatsThis("Save all");
    pactFileSaveAll->setIcon(QPixmap());
    connect(pactFileSaveAll, SIGNAL(triggered()), SLOT(slotFileSaveAll()));

    QAction *pactFileCloseAll = new QAction("Close all", 0);
    pactFileCloseAll->setText("Close &all");
    pactFileCloseAll->setShortcut(QKeySequence("CTRL+Shift+W"));
    pactFileCloseAll->setToolTip("Close all");
    pactFileCloseAll->setStatusTip("Close all");
    pactFileCloseAll->setWhatsThis("Close all");
    pactFileCloseAll->setIcon(QPixmap());
    connect(pactFileCloseAll, SIGNAL(triggered()), SLOT(slotFileCloseAll()));

    //QToolBar section

    QAction *pactNew = new QAction("New File", 0);
    pactNew->setText("&New");
    pactNew->setShortcut(QKeySequence("CTRL+N"));
    pactNew->setToolTip("New Document");
    pactNew->setStatusTip("Create a new file");
    pactNew->setWhatsThis("Create a new file");
   pactNew->setIcon(QPixmap());
    connect(pactNew, SIGNAL(triggered()), SLOT(slotNewDoc()));

    QAction *pactOpen = new QAction("Open File", 0);
    pactOpen->setText("&Open...");
    pactOpen->setShortcut(QKeySequence("CTRL+O"));
    pactOpen->setToolTip("Open Document");
    pactOpen->setStatusTip("Open an existing file");
    pactOpen->setWhatsThis("Open an existing file");
    pactOpen->setIcon(QPixmap());
    connect(pactOpen, SIGNAL(triggered()), SLOT(slotLoad()));

    QAction *pactSave = new QAction("Save File", 0);
    pactSave->setText("&Save");
    pactSave->setShortcut(QKeySequence("CTRL+S"));
    pactSave->setToolTip("Save Document");
    pactSave->setStatusTip("Save the file to disk");
    pactSave->setWhatsThis("Save the file to disk");
    pactSave->setIcon(QPixmap());
    connect(pactSave, SIGNAL(triggered()), SLOT(slotSave()));

    //Edit section

    QAction *pactEditUndo = new QAction("Undo", 0);
    pactEditUndo->setText("&Undo");
    pactEditUndo->setShortcut(QKeySequence("CTRL+Z"));//test
    pactEditUndo->setToolTip("Undo");
    pactEditUndo->setStatusTip("Undo last action");
    pactEditUndo->setWhatsThis("Undo last action");
    pactEditUndo->setIcon(QPixmap());
    connect(pactEditUndo, SIGNAL(triggered()), SLOT(slotEditUndo()));

    QAction *pactEditRepeat = new QAction("Repeat", 0);
    pactEditRepeat->setText("&Repeat");
    pactEditRepeat->setShortcut(QKeySequence("CTRL+Y"));//test
    pactEditRepeat->setToolTip("Repeat");
    pactEditRepeat->setStatusTip("Repeat last action");
    pactEditRepeat->setWhatsThis("Repeat last action");
    pactEditRepeat->setIcon(QPixmap());
    connect(pactEditRepeat, SIGNAL(triggered()), SLOT(slotEditRepeat()));

    QAction *pactEditInsert = new QAction("Insert", 0);
    pactEditInsert->setText("&Insert");
    pactEditInsert->setShortcut(QKeySequence("CTRL+V"));//test
    pactEditInsert->setToolTip("Insert");
    pactEditInsert->setStatusTip("Insert from buffer");
    pactEditInsert->setWhatsThis("Insert from buffer");
    pactEditInsert->setIcon(QPixmap());
    connect(pactEditInsert, SIGNAL(triggered()), SLOT(slotEditInsert()));

    QAction *pactEditOpenTextSettings = new QAction("Open text settings", 0);
    pactEditOpenTextSettings->setText("Open &text settings");
    pactEditOpenTextSettings->setShortcut(QKeySequence(""));//test
    pactEditOpenTextSettings->setToolTip("Open text settings");
    pactEditOpenTextSettings->setStatusTip("Open text settings");
    pactEditOpenTextSettings->setWhatsThis("Open text settings");
    pactEditOpenTextSettings->setIcon(QPixmap());
    connect(pactEditOpenTextSettings, SIGNAL(triggered()), SLOT(slotEditOpenTextSettings()));

    QAction *pactEditSetDefaultSettings = new QAction("Set default text settings", 0);
    pactEditSetDefaultSettings->setText("Set &default &text settings");
    pactEditSetDefaultSettings->setShortcut(QKeySequence(""));//test
    pactEditSetDefaultSettings->setToolTip("Set default text settings");
    pactEditSetDefaultSettings->setStatusTip("Set default text settings");
    pactEditSetDefaultSettings->setWhatsThis("Set default text settings");
    pactEditSetDefaultSettings->setIcon(QPixmap());
    connect(pactEditSetDefaultSettings, SIGNAL(triggered()), SLOT(slotEditSetDefaultSettings()));

    //Widgets section

    QAction *pactCreateRef = new QAction("Create reference widget", 0);
    pactCreateRef->setText("Reference");
    pactCreateRef->setToolTip("Reference widget");
    pactCreateRef->setStatusTip("Create reference widget");
    pactCreateRef->setWhatsThis("Create reference widget");
    connect(pactCreateRef, SIGNAL(triggered()), SLOT(slotCreateReference()));

    QAction *pactCreateDir = new QAction("Create dir widget", 0);
    pactCreateDir->setText("Directory");
    pactCreateDir->setToolTip("Directory widget");
    pactCreateDir->setStatusTip("Create directory widget");
    pactCreateDir->setWhatsThis("Create directory widget");
    connect(pactCreateDir, SIGNAL(triggered()), SLOT(slotCreateDirectory()));

    QAction *pactCreateCom = new QAction("Create com widget", 0);
    pactCreateCom->setText("Command");
    pactCreateCom->setToolTip("Command widget");
    pactCreateCom->setStatusTip("Create command widget");
    pactCreateCom->setWhatsThis("Create command widget");
    connect(pactCreateCom, SIGNAL(triggered()), SLOT(slotCreateCommand()));

    QAction *pactCreateReset = new QAction("Reset widgets", 0);
    pactCreateReset->setText("Reset widgets");
    pactCreateReset->setToolTip("Reset");
    pactCreateReset->setStatusTip("Reset widgets");
    pactCreateReset->setWhatsThis("Reset widgets");
    connect(pactCreateReset, SIGNAL(triggered()), SLOT(slotCreateReset()));

    QAction *pactCreateData = new QAction("Create data widget", 0);
    pactCreateData->setText("Data");
    pactCreateData->setToolTip("Data widget");
    pactCreateData->setStatusTip("Create data widget");
    pactCreateData->setWhatsThis("Create data widget");
    connect(pactCreateData, SIGNAL(triggered()), SLOT(slotCreateData()));

    //windows section

    //view section

    QToolBar *ptbFile = new QToolBar("File Operations");
    ptbFile->addAction(pactNew);
    ptbFile->addAction(pactOpen);
    ptbFile->addAction(pactSave);
    addToolBar(Qt::TopToolBarArea, ptbFile);

    QMenu *pmnuFile = new QMenu("&File");
    pmnuFile->addAction(pactFileCreateFileProject);
    pmnuFile->addAction(pactFileOpenFileProject);
    pmnuFile->addAction(pactFileRecentProjects);
    pmnuFile->addSeparator();
    pmnuFile->addAction(pactFileSaveFileProject);
    pmnuFile->addAction(pactFileSaveAll);
    pmnuFile->addAction(pactFileCloseAll);
    pmnuFile->addSeparator();
    pmnuFile->addAction("&Quit", qApp, SLOT(closeAllWindows()), QKeySequence("CTRL+Q"));
    menuBar()->addMenu(pmnuFile);

    QMenu *pmnuEdit = new QMenu("&Edit");
    pmnuEdit->addAction(pactEditUndo);
    pmnuEdit->addAction(pactEditRepeat);
    pmnuEdit->addAction(pactEditInsert);
    pmnuEdit->addSeparator();
    pmnuEdit->addAction(pactEditOpenTextSettings);
    pmnuEdit->addAction(pactEditSetDefaultSettings);
    menuBar()->addMenu(pmnuEdit);

    m_pmnuWidgets = new QMenu("&Widgets");
    m_psubWidCreate = new QMenu("Create", nullptr);
    m_psubWidCreate->addAction(pactCreateRef);
    m_psubWidCreate->addAction(pactCreateDir);
    m_psubWidCreate->addAction(pactCreateCom);
    m_psubWidCreate->addAction(pactCreateData);
    m_pmnuWidgets->addMenu(m_psubWidCreate);
    m_pmnuWidgets->addSeparator();
    m_pmnuWidgets->addAction(pactCreateReset);
    menuBar()->addMenu(m_pmnuWidgets);

    QMenu *pmnuView = new QMenu("&View");
    pmnuView->addAction("&Presets", this, SLOT(slotViewPresets())); //next - menu
    m_pmnuWindows = new QMenu("&Docs style");
    connect(m_pmnuWindows, SIGNAL(aboutToShow()), SLOT(slotWindows()));
    pmnuView->addMenu(m_pmnuWindows);
    pmnuView->addSeparator();
    pmnuView->addAction("&App view settings", this, SLOT(slotViewAppSettings()));
    pmnuView->addAction("&Set default app settings", this, SLOT(slotViewSetDefaultSettings()));
    menuBar()->addMenu(pmnuView);
    menuBar()->addSeparator();

    //help section
    QMenu *pmnuHelp = new QMenu("&Help");
    pmnuHelp->addAction("&About us", this, SLOT(slotHelpAbout()), Qt::Key_F1);
    pmnuHelp->addAction("&Donates", this, SLOT(slotHelpDonates()), Qt::Key_F2);
    pmnuHelp->addAction("&Documentation", this, SLOT(slotHelpDocumentation()), Qt::Key_F3);
    menuBar()->addMenu(pmnuHelp);

    //QTextEdit *tempEdit = new QTextEdit(nullptr);
    m_pdocRef = new Reference(nullptr);
    //m_pdocRef->setWidget(tempEdit);
    //m_pdocNew->resize(200,100);
    addDockWidget(Qt::LeftDockWidgetArea, m_pdocRef);

    m_pdocDir = new DirWidget(nullptr);
    addDockWidget(Qt::LeftDockWidgetArea, m_pdocDir);

    m_pdocCom = new QDockWidget("Commands", 0);
    addDockWidget(Qt::LeftDockWidgetArea, m_pdocCom);

    m_pdocData = new DataWidget(nullptr);
    addDockWidget(Qt::LeftDockWidgetArea, m_pdocData);

    m_pma = new QMdiArea;
    m_pma->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_pma->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    m_pTab = new QTabWidget;
    m_pTab->addTab(m_pma, "First");
    m_pTab->addTab(new QPushButton("Add tab", m_pTab), "Add new tab");

    setCentralWidget(m_pTab);

    m_psigMapper = new QSignalMapper(this);
    connect(m_psigMapper, SIGNAL(mapped(QWidget*)), this, SLOT(slotSetActiveWindow(QWidget*)));

    statusBar()->showMessage("Ready", 3000);
}

void MainWidget::slotCreateReference()
{
    Reference *tempRef = new Reference();
    m_pdocArr.push_back(tempRef);
    addDockWidget(Qt::LeftDockWidgetArea, tempRef);
    //tempRef->show();
}

void MainWidget::slotCreateDirectory()
{
    DirWidget *tempDir = new DirWidget(nullptr);
    m_pdocArr.push_back(tempDir);
    addDockWidget(Qt::LeftDockWidgetArea, tempDir);
}

void MainWidget::slotCreateCommand()
{
    QDockWidget *tempCom = new QDockWidget("Commands", nullptr);
    m_pdocArr.push_back(tempCom);
    addDockWidget(Qt::LeftDockWidgetArea, tempCom);
}

void MainWidget::slotCreateData()
{
    DataWidget *tempData = new DataWidget(nullptr);
    m_pdocArr.push_back(tempData);
    addDockWidget(Qt::LeftDockWidgetArea, tempData);
}

void MainWidget::slotCreateReset()
{
    if (!m_pdocArr.isEmpty()) {
        for (auto i = 0; i < m_pdocArr.size(); ++i) {
            removeDockWidget(m_pdocArr.at(i));
            delete m_pdocArr.at(i);
        }
        m_pdocArr.clear(); //memory leak - done
    } else {
        return;
    }

}

void MainWidget::slotNewDoc()
{
    createNewDoc()->show();
}

DocWindow* MainWidget::createNewDoc()
{
    DocWindow *pdoc = new DocWindow;
    m_pma->addSubWindow(pdoc);
    pdoc->setAttribute(Qt::WA_DeleteOnClose);
    pdoc->setWindowTitle("Unnamed Document");
    connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(QString&)));
    return pdoc;
}

void MainWidget::slotChangeWindowTitle(const QString& str)
{
    qobject_cast<DocWindow*>(sender())->setWindowTitle(str);
}

/*
void MainWidget::slotLoad()
{
    DocWindow *pdoc = createNewDoc();
    pdoc->slotLoad();
    pdoc->show();
}
*/
/*
void MainWidget::slotSave()
{
    DocWindow *pdoc = qobject_cast<DocWindow*>(m_pma->activeSubWindow());
    if (pdoc) {
        pdoc->slotSave();
    }
}
void MainWidget::slotSaveAs()
{
    DocWindow *pdoc = qobject_cast<DocWindow*>(m_pma->activeSubWindow());
    if (pdoc) {
        pdoc->slotSaveAs();
    }
}
*/
void MainWidget::slotHelpAbout()
{
    QMessageBox::about(this, "WorkDog", "GoldFish Production\n"
                                                    "WorkDog version 0.1\n"
                                                    "by Nikita Ivanov"
                                        "&"
                                        "Alexey Zhavoronkov");
}

void MainWidget::slotWindows()
{
    m_pmnuWindows->clear();
    QAction *pact = m_pmnuWindows->addAction("&Cascade", m_pma, SLOT(cascadeSubWindows()));
    pact->setEnabled(!m_pma->subWindowList().isEmpty());
    pact = m_pmnuWindows->addAction("&Tile", m_pma, SLOT(tileSubWindows()));
    pact->setEnabled(!m_pma->subWindowList().isEmpty());
    m_pmnuWindows->addSeparator();

    QList<QMdiSubWindow*> listDoc = m_pma->subWindowList();
    for (int i = 0; i < listDoc.size(); ++i) {
        pact = m_pmnuWindows->addAction(listDoc.at(i)->windowTitle());
        pact->setCheckable(true);
        pact->setChecked(m_pma->activeSubWindow() == listDoc.at(i));
        connect(pact, SIGNAL(triggered()), m_psigMapper, SLOT(map()));
        m_psigMapper->setMapping(pact, listDoc.at(i));
    }
}

void MainWidget::slotSetActiveSubWindow(QWidget *pwgt)
{
    if (pwgt) {
        m_pma->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(pwgt));
    }
}
