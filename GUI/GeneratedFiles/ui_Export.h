/********************************************************************************
** Form generated from reading UI file 'Export.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORT_H
#define UI_EXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Export
{
public:
    QGridLayout *gridLayout_2;
    QCheckBox *videoExport;
    QLabel *processingLabel;
    QSpinBox *fpsBox;
    QDialogButtonBox *DialogButton;
    QLabel *fpsLabel;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *cpuButton;
    QRadioButton *MutliGPU;
    QSpinBox *GPUBox;

    void setupUi(QDialog *Export)
    {
        if (Export->objectName().isEmpty())
            Export->setObjectName(QStringLiteral("Export"));
        Export->resize(362, 100);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Export->sizePolicy().hasHeightForWidth());
        Export->setSizePolicy(sizePolicy);
        Export->setMaximumSize(QSize(362, 100));
        gridLayout_2 = new QGridLayout(Export);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setContentsMargins(9, -1, -1, -1);
        videoExport = new QCheckBox(Export);
        videoExport->setObjectName(QStringLiteral("videoExport"));

        gridLayout_2->addWidget(videoExport, 6, 1, 1, 1);

        processingLabel = new QLabel(Export);
        processingLabel->setObjectName(QStringLiteral("processingLabel"));
        sizePolicy.setHeightForWidth(processingLabel->sizePolicy().hasHeightForWidth());
        processingLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(processingLabel, 3, 1, 1, 1);

        fpsBox = new QSpinBox(Export);
        fpsBox->setObjectName(QStringLiteral("fpsBox"));
        sizePolicy.setHeightForWidth(fpsBox->sizePolicy().hasHeightForWidth());
        fpsBox->setSizePolicy(sizePolicy);
        fpsBox->setReadOnly(false);
        fpsBox->setMinimum(1);

        gridLayout_2->addWidget(fpsBox, 6, 3, 1, 1);

        DialogButton = new QDialogButtonBox(Export);
        DialogButton->setObjectName(QStringLiteral("DialogButton"));
        DialogButton->setOrientation(Qt::Horizontal);
        DialogButton->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(DialogButton, 7, 6, 1, 1);

        fpsLabel = new QLabel(Export);
        fpsLabel->setObjectName(QStringLiteral("fpsLabel"));

        gridLayout_2->addWidget(fpsLabel, 6, 4, 1, 1);

        groupBox = new QGroupBox(Export);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(200, 30));
        groupBox->setMaximumSize(QSize(300, 60));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 9);
        cpuButton = new QRadioButton(groupBox);
        cpuButton->setObjectName(QStringLiteral("cpuButton"));
        sizePolicy.setHeightForWidth(cpuButton->sizePolicy().hasHeightForWidth());
        cpuButton->setSizePolicy(sizePolicy);
        cpuButton->setMinimumSize(QSize(20, 20));

        horizontalLayout->addWidget(cpuButton);

        MutliGPU = new QRadioButton(groupBox);
        MutliGPU->setObjectName(QStringLiteral("MutliGPU"));
        sizePolicy.setHeightForWidth(MutliGPU->sizePolicy().hasHeightForWidth());
        MutliGPU->setSizePolicy(sizePolicy);
        MutliGPU->setMinimumSize(QSize(20, 20));

        horizontalLayout->addWidget(MutliGPU);

        GPUBox = new QSpinBox(groupBox);
        GPUBox->setObjectName(QStringLiteral("GPUBox"));
        sizePolicy.setHeightForWidth(GPUBox->sizePolicy().hasHeightForWidth());
        GPUBox->setSizePolicy(sizePolicy);
        GPUBox->setMinimumSize(QSize(20, 18));
        GPUBox->setMaximumSize(QSize(40, 20));
        GPUBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        GPUBox->setReadOnly(false);
        GPUBox->setMinimum(1);

        horizontalLayout->addWidget(GPUBox);


        gridLayout_2->addWidget(groupBox, 3, 3, 1, 1);


        retranslateUi(Export);
        QObject::connect(DialogButton, SIGNAL(accepted()), Export, SLOT(accept()));
        QObject::connect(DialogButton, SIGNAL(rejected()), Export, SLOT(close()));

        QMetaObject::connectSlotsByName(Export);
    } // setupUi

    void retranslateUi(QDialog *Export)
    {
        Export->setWindowTitle(QApplication::translate("Export", "Export", Q_NULLPTR));
        videoExport->setText(QApplication::translate("Export", "Export Video", Q_NULLPTR));
        processingLabel->setText(QApplication::translate("Export", "Processing Type:", Q_NULLPTR));
        fpsLabel->setText(QApplication::translate("Export", "FPS", Q_NULLPTR));
        groupBox->setTitle(QString());
        cpuButton->setText(QApplication::translate("Export", "CPU", Q_NULLPTR));
        MutliGPU->setText(QApplication::translate("Export", "GPU", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Export: public Ui_Export {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORT_H
