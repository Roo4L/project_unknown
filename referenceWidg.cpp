#include "referenceWidg.h"

Reference::Reference(QWidget *pwgt) : QDockWidget(pwgt) {
    m_strFileName = "Reference";
    setWindowTitle(m_strFileName);
    QTextEdit *m_ptxt = new QTextEdit(nullptr);
    m_ptxt->setFrameStyle(1);
    setWidget(m_ptxt);
    m_ptxt->setTextColor(Qt::gray);
}
