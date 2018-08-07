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
    QLabel *processingLabel;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *videoExport;
    QSpinBox *fpsBox;
    QLabel *fpsLabel;
    QDialogButtonBox *DialogButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *cpuButton;
    QRadioButton *MutliGPU;
    QCheckBox *debug;

    void setupUi(QDialog *Export)
    {
        if (Export->objectName().isEmpty())
            Export->setObjectName(QStringLiteral("Export"));
        Export->resize(356, 130);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Export->sizePolicy().hasHeightForWidth());
        Export->setSizePolicy(sizePolicy);
        Export->setMaximumSize(QSize(356, 130));
        Export->setStyleSheet(QLatin1String("/***\n"
"Style sheet\"QDarkStyleSheet\" by Colin Duquesnoy and Daniel Pizetta\n"
"https://github.com/ColinDuquesnoy/QDarkStyleSheet\n"
"***/\n"
"\n"
"QToolTip {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #5A7566;\n"
"    color: white;\n"
"    padding: 0px;                /*remove padding, for fix combobox tooltip.*/\n"
"    opacity: 200;\n"
"}\n"
"\n"
"QWidget {\n"
"    color: #eff0f1;\n"
"    background-color: #31363b;\n"
"    selection-background-color: #3daee9;\n"
"    selection-color: #eff0f1;\n"
"    background-clip: border;\n"
"    border-image: none;\n"
"    border: 0px transparent black;\n"
"    outline: 0;\n"
"}\n"
"\n"
"QWidget:item:hover {\n"
"    background-color: #18465d;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QWidget:item:selected {\n"
"    background-color: #18465d;\n"
"}\n"
"\n"
"QRadioButton {\n"
"    spacing: 5px;\n"
"    outline: none;\n"
"    color: #eff0f1;\n"
"    margin-bottom: 2px;\n"
"}\n"
"\n"
"QAbstractSpinBox {\n"
"    padding: 5px;\n"
"    border: 1px solid #76797"
                        "C;\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"\n"
"QAbstractSpinBox::up-arrow:hover {\n"
"    image: url(:/qss_icons/rc/up_arrow.png);\n"
"}\n"
"\n"
"QAbstractSpinBox::down-arrow:hover {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QLabel {\n"
"    border: 0px solid black;\n"
"}\n"
"\n"
"QPushButton {\n"
"    color: #eff0f1;\n"
"    background-color: #31363b;\n"
"    border-width: 1px;\n"
"    border-color: #76797C;\n"
"    border-style: solid;\n"
"    padding: 5px;\n"
"    border-radius: 2px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #31363b;\n"
"    border-width: 1px;\n"
"    border-color: #454545;\n"
"    border-style: solid;\n"
"    padding-top: 5px;\n"
"    padding-bottom: 5px;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    border-radius: 2px;\n"
"    color: #454545;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    background-color: #3daee9;\n"
""
                        "    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3daee9;\n"
"    padding-top: -15px;\n"
"    padding-bottom: -17px;\n"
"}\n"
"\n"
"QComboBox {\n"
"    selection-background-color: #3daee9;\n"
"    border-style: solid;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    padding: 5px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #76797C;\n"
"    border-color: #6A6969;\n"
"}\n"
"\n"
"QComboBox:hover,\n"
"QPushButton:hover,\n"
"QAbstractSpinBox:hover,\n"
"QLineEdit:hover,\n"
"QTextEdit:hover,\n"
"QPlainTextEdit:hover,\n"
"QAbstractView:hover,\n"
"QTreeView:hover {\n"
"    border: 1px solid #3daee9;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"\n"
""));
        gridLayout_2 = new QGridLayout(Export);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setContentsMargins(9, -1, -1, -1);
        processingLabel = new QLabel(Export);
        processingLabel->setObjectName(QStringLiteral("processingLabel"));
        sizePolicy.setHeightForWidth(processingLabel->sizePolicy().hasHeightForWidth());
        processingLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(processingLabel, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        videoExport = new QCheckBox(Export);
        videoExport->setObjectName(QStringLiteral("videoExport"));
        videoExport->setMinimumSize(QSize(50, 0));
        videoExport->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(videoExport);

        fpsBox = new QSpinBox(Export);
        fpsBox->setObjectName(QStringLiteral("fpsBox"));
        sizePolicy.setHeightForWidth(fpsBox->sizePolicy().hasHeightForWidth());
        fpsBox->setSizePolicy(sizePolicy);
        fpsBox->setReadOnly(false);
        fpsBox->setMinimum(1);

        horizontalLayout_2->addWidget(fpsBox);

        fpsLabel = new QLabel(Export);
        fpsLabel->setObjectName(QStringLiteral("fpsLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fpsLabel->sizePolicy().hasHeightForWidth());
        fpsLabel->setSizePolicy(sizePolicy1);
        fpsLabel->setMinimumSize(QSize(25, 0));
        fpsLabel->setMaximumSize(QSize(25, 16777215));

        horizontalLayout_2->addWidget(fpsLabel);

        DialogButton = new QDialogButtonBox(Export);
        DialogButton->setObjectName(QStringLiteral("DialogButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DialogButton->sizePolicy().hasHeightForWidth());
        DialogButton->setSizePolicy(sizePolicy2);
        DialogButton->setMinimumSize(QSize(100, 0));
        DialogButton->setMaximumSize(QSize(100, 16777215));
        DialogButton->setOrientation(Qt::Horizontal);
        DialogButton->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(DialogButton);


        gridLayout_2->addLayout(horizontalLayout_2, 9, 1, 1, 4);

        groupBox = new QGroupBox(Export);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(250, 35));
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
        MutliGPU->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(MutliGPU);

        debug = new QCheckBox(groupBox);
        debug->setObjectName(QStringLiteral("debug"));
        debug->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(debug);


        gridLayout_2->addWidget(groupBox, 3, 2, 1, 3);


        retranslateUi(Export);
        QObject::connect(DialogButton, SIGNAL(accepted()), Export, SLOT(accept()));
        QObject::connect(DialogButton, SIGNAL(rejected()), Export, SLOT(close()));

        QMetaObject::connectSlotsByName(Export);
    } // setupUi

    void retranslateUi(QDialog *Export)
    {
        Export->setWindowTitle(QApplication::translate("Export", "Export", Q_NULLPTR));
        processingLabel->setText(QApplication::translate("Export", "Processing Type:", Q_NULLPTR));
        videoExport->setText(QApplication::translate("Export", "Export Video", Q_NULLPTR));
        fpsLabel->setText(QApplication::translate("Export", "FPS", Q_NULLPTR));
        groupBox->setTitle(QString());
        cpuButton->setText(QApplication::translate("Export", "CPU", Q_NULLPTR));
        MutliGPU->setText(QApplication::translate("Export", "GPU", Q_NULLPTR));
        debug->setText(QApplication::translate("Export", "Debug", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Export: public Ui_Export {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORT_H
