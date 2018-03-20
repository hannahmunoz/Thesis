/********************************************************************************
** Form generated from reading UI file 'progress.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESS_H
#define UI_PROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Progress
{
public:
    QPushButton *cancel;
    QProgressBar *progressBar;

    void setupUi(QDialog *Progress)
    {
        if (Progress->objectName().isEmpty())
            Progress->setObjectName(QStringLiteral("Progress"));
        Progress->resize(466, 80);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Progress->sizePolicy().hasHeightForWidth());
        Progress->setSizePolicy(sizePolicy);
        Progress->setMaximumSize(QSize(500, 80));
        cancel = new QPushButton(Progress);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(380, 50, 75, 23));
        progressBar = new QProgressBar(Progress);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 10, 451, 23));
        progressBar->setValue(24);

        retranslateUi(Progress);
        QObject::connect(cancel, SIGNAL(clicked()), Progress, SLOT(close()));

        QMetaObject::connectSlotsByName(Progress);
    } // setupUi

    void retranslateUi(QDialog *Progress)
    {
        Progress->setWindowTitle(QApplication::translate("Progress", "Dialog", Q_NULLPTR));
        cancel->setText(QApplication::translate("Progress", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Progress: public Ui_Progress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_H
