/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QAction *action_Open;
    QAction *action_Exit;
    QAction *action_Recent;
    QAction *action_Close;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionEdit;
    QAction *actionView;
    QAction *actionAutoGenorate;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExport;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *Toolbox;
    QHBoxLayout *horizontalLayout;
    QLabel *RGBView;
    QPushButton *ProcessButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *ExportButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *FarLeftScrollImage;
    QLabel *LeftScrollImage;
    QLabel *CenterScollImage;
    QLabel *RightScrollImage;
    QLabel *FarRightScrollImage;
    QHBoxLayout *horizontalLayout_3;
    ClickableLabel *PictureFrame;
    QProgressBar *PictureProcessingBar;
    QSlider *ImageScroller;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuEdit;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->resize(1000, 664);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GUIClass->sizePolicy().hasHeightForWidth());
        GUIClass->setSizePolicy(sizePolicy);
        GUIClass->setMinimumSize(QSize(1000, 664));
        GUIClass->setMaximumSize(QSize(1000, 664));
        GUIClass->setSizeIncrement(QSize(10, 10));
        GUIClass->setAutoFillBackground(false);
        GUIClass->setStyleSheet(QLatin1String("/* Style sheet from \n"
"	https://github.com/EClaesson/QTDark/blob/master/QTDark.stylesheet\n"
"	Edited to Grey and Blue for UNR*/\n"
"\n"
"/*\n"
"	Copyright 2013 Emanuel Claesson\n"
"\n"
"	Licensed under the Apache License, Version 2.0 (the \"License\");\n"
"	you may not use this file except in compliance with the License.\n"
"	You may obtain a copy of the License at\n"
"\n"
"		http://www.apache.org/licenses/LICENSE-2.0\n"
"\n"
"	Unless required by applicable law or agreed to in writing, software\n"
"	distributed under the License is distributed on an \"AS IS\" BASIS,\n"
"	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
"	See the License for the specific language governing permissions and\n"
"	limitations under the License.\n"
"*/\n"
"\n"
"/*\n"
"	COLOR_DARK     = #3e3e3e\n"
"	COLOR_MEDIUM   = #a3a3a3\n"
"	COLOR_MEDLIGHT = #999999\n"
"	COLOR_LIGHT    = #DDDDDD\n"
"	COLOR_ACCENT   = #003366\n"
"*/\n"
"\n"
"* {\n"
"	background: #3e3e3e;\n"
"	color: #DDDDDD;\n"
"\n"
"}\n"
"\n"
"QWidge"
                        "t::item:selected {\n"
"	background: #003366;\n"
"}\n"
"\n"
"QCheckBox, QRadioButton {\n"
"	border: none;\n"
"}\n"
"\n"
"QRadioButton::indicator, QCheckBox::indicator {\n"
"	width: 13px;\n"
"	height: 13px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked, QCheckBox::indicator::unchecked {\n"
"	border: 1px solid #999999;\n"
"	background: none;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover, QCheckBox::indicator:unchecked:hover {\n"
"	border: 1px solid #DDDDDD;\n"
"}\n"
"\n"
"QRadioButton::indicator::checked, QCheckBox::indicator::checked {\n"
"	border: 1px solid #999999;\n"
"	background: #999999;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover, QCheckBox::indicator:checked:hover {\n"
"	border: 1px solid #DDDDDD;\n"
"	background: #DDDDDD;\n"
"}\n"
"\n"
"QGroupBox {\n"
"	margin-top: 6px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"	top: -7px;\n"
"	left: 7px;\n"
"}\n"
"\n"
"QScrollBar {\n"
"	border: 1px solid #999999;\n"
"	background: #3e3e3e;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"	height: 15px;\n"
"	m"
                        "argin: 0px 0px 0px 32px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	width: 15px;\n"
"	margin: 32px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle {\n"
"	background: #a3a3a3;\n"
"	border: 1px solid #999999;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"	border-width: 0px 1px 0px 1px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"	border-width: 1px 0px 1px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"	min-width: 20px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"	min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line, QScrollBar::sub-line {\n"
"	background:#a3a3a3;\n"
"	border: 1px solid #999999;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line {\n"
"	position: absolute;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"	width: 15px;\n"
"	subcontrol-position: left;\n"
"	left: 15px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"	height: 15px;\n"
"	subcontrol-position: top;\n"
"	top: 15px;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"	width: 15px;\n"
"	subcon"
                        "trol-position: top left;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"	height: 15px;\n"
"	subcontrol-position: top;\n"
"}\n"
"\n"
"QScrollBar:left-arrow, QScrollBar::right-arrow, QScrollBar::up-arrow, QScrollBar::down-arrow {\n"
"	border: 1px solid #999999;\n"
"	width: 3px;\n"
"	height: 3px;\n"
"}\n"
"\n"
"QScrollBar::add-page, QScrollBar::sub-page {\n"
"	background: none;\n"
"}\n"
"\n"
"QAbstractButton:hover {\n"
"	background: #a3a3a3;\n"
"}\n"
"\n"
"QAbstractButton:pressed {\n"
"	background: #999999;\n"
"}\n"
"\n"
"QAbstractItemView {\n"
"	show-decoration-selected: 1;\n"
"	selection-background-color: #003366;\n"
"	selection-color: #DDDDDD;\n"
"	alternate-background-color: #a3a3a3;\n"
"}\n"
"\n"
"QHeaderView {\n"
"	border: 1px solid #999999;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"	background: #3e3e3e;\n"
"	border: 1px solid #999999;\n"
"	padding: 4px;\n"
"}\n"
"\n"
"QHeaderView::section:selected, QHeaderView::section::checked {\n"
"	background: #a3a3a3;\n"
"}\n"
"\n"
"QTableView {\n"
"	gridline-color"
                        ": #999999;\n"
"}\n"
"\n"
"QTabBar {\n"
"	margin-left: 2px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"	border-radius: 0px;\n"
"	padding: 4px;\n"
"	margin: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	background: #a3a3a3;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	border: 1px solid #999999;\n"
"	background: #a3a3a3;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	border: 1px solid #999999;\n"
"	background: #a3a3a3;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	width: 3px;\n"
"	height: 3px;\n"
"	border: 1px solid #999999;\n"
"}\n"
"\n"
"QAbstractSpinBox {\n"
"	padding-right: 15px;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-button, QAbstractSpinBox::down-button {\n"
"	border: 1px solid #999999;\n"
"	background: #a3a3a3;\n"
"	subcontrol-origin: border;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow, QAbstractSpinBox::down-arrow {\n"
"	width: 3px;\n"
"	height: 3px;\n"
"	border: 1px solid #999999;\n"
"}\n"
"\n"
"QSlider {\n"
"	border: none;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"	height: 5px;\n"
"	margin: 4px 0px 4px 0px;\n"
"}\n"
""
                        "\n"
"QSlider::groove:vertical {\n"
"	width: 5px;\n"
"	margin: 0px 4px 0px 4px;\n"
"}\n"
"\n"
"QSlider::handle {\n"
"	border: 1px solid #999999;\n"
"	background: #a3a3a3;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"	width: 15px;\n"
"	margin: -4px 0px -4px 0px;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"	height: 15px;\n"
"	margin: 0px -4px 0px -4px;\n"
"}\n"
"\n"
"QSlider::add-page:vertical, QSlider::sub-page:horizontal {\n"
"	background: #003366;\n"
"}\n"
"\n"
"QSlider::sub-page:vertical, QSlider::add-page:horizontal {\n"
"	background: #a3a3a3;\n"
"}\n"
"\n"
"QLabel {\n"
"	border: none;\n"
"}\n"
"\n"
"QProgressBar {\n"
"	text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"	width: 1px;\n"
"	background-color: #003366;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"	background: #a3a3a3;\n"
"}"));
        GUIClass->setIconSize(QSize(500, 500));
        GUIClass->setTabShape(QTabWidget::Rounded);
        GUIClass->setUnifiedTitleAndToolBarOnMac(false);
        action_Open = new QAction(GUIClass);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        action_Exit = new QAction(GUIClass);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        action_Recent = new QAction(GUIClass);
        action_Recent->setObjectName(QStringLiteral("action_Recent"));
        action_Close = new QAction(GUIClass);
        action_Close->setObjectName(QStringLiteral("action_Close"));
        actionUndo = new QAction(GUIClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(GUIClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionEdit = new QAction(GUIClass);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        actionView = new QAction(GUIClass);
        actionView->setObjectName(QStringLiteral("actionView"));
        actionAutoGenorate = new QAction(GUIClass);
        actionAutoGenorate->setObjectName(QStringLiteral("actionAutoGenorate"));
        actionSave = new QAction(GUIClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(GUIClass);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExport = new QAction(GUIClass);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(1000, 600));
        centralWidget->setMaximumSize(QSize(300, 600));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Toolbox = new QListWidget(centralWidget);
        Toolbox->setObjectName(QStringLiteral("Toolbox"));
        Toolbox->setMaximumSize(QSize(200, 300));

        gridLayout->addWidget(Toolbox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        RGBView = new QLabel(centralWidget);
        RGBView->setObjectName(QStringLiteral("RGBView"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(RGBView->sizePolicy().hasHeightForWidth());
        RGBView->setSizePolicy(sizePolicy2);
        RGBView->setMaximumSize(QSize(200, 200));

        horizontalLayout->addWidget(RGBView);


        gridLayout->addLayout(horizontalLayout, 1, 0, 3, 1);

        ProcessButton = new QPushButton(centralWidget);
        ProcessButton->setObjectName(QStringLiteral("ProcessButton"));

        gridLayout->addWidget(ProcessButton, 6, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        ExportButton = new QPushButton(centralWidget);
        ExportButton->setObjectName(QStringLiteral("ExportButton"));

        gridLayout->addWidget(ExportButton, 7, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        FarLeftScrollImage = new QLabel(centralWidget);
        FarLeftScrollImage->setObjectName(QStringLiteral("FarLeftScrollImage"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(FarLeftScrollImage->sizePolicy().hasHeightForWidth());
        FarLeftScrollImage->setSizePolicy(sizePolicy3);
        FarLeftScrollImage->setMinimumSize(QSize(150, 100));

        horizontalLayout_2->addWidget(FarLeftScrollImage);

        LeftScrollImage = new QLabel(centralWidget);
        LeftScrollImage->setObjectName(QStringLiteral("LeftScrollImage"));
        sizePolicy3.setHeightForWidth(LeftScrollImage->sizePolicy().hasHeightForWidth());
        LeftScrollImage->setSizePolicy(sizePolicy3);
        LeftScrollImage->setMinimumSize(QSize(150, 100));

        horizontalLayout_2->addWidget(LeftScrollImage);

        CenterScollImage = new QLabel(centralWidget);
        CenterScollImage->setObjectName(QStringLiteral("CenterScollImage"));
        sizePolicy2.setHeightForWidth(CenterScollImage->sizePolicy().hasHeightForWidth());
        CenterScollImage->setSizePolicy(sizePolicy2);
        CenterScollImage->setMinimumSize(QSize(150, 100));

        horizontalLayout_2->addWidget(CenterScollImage);

        RightScrollImage = new QLabel(centralWidget);
        RightScrollImage->setObjectName(QStringLiteral("RightScrollImage"));
        sizePolicy3.setHeightForWidth(RightScrollImage->sizePolicy().hasHeightForWidth());
        RightScrollImage->setSizePolicy(sizePolicy3);
        RightScrollImage->setMinimumSize(QSize(150, 100));

        horizontalLayout_2->addWidget(RightScrollImage);

        FarRightScrollImage = new QLabel(centralWidget);
        FarRightScrollImage->setObjectName(QStringLiteral("FarRightScrollImage"));
        sizePolicy3.setHeightForWidth(FarRightScrollImage->sizePolicy().hasHeightForWidth());
        FarRightScrollImage->setSizePolicy(sizePolicy3);
        FarRightScrollImage->setMinimumSize(QSize(150, 100));

        horizontalLayout_2->addWidget(FarRightScrollImage);


        gridLayout->addLayout(horizontalLayout_2, 3, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        PictureFrame = new ClickableLabel(centralWidget);
        PictureFrame->setObjectName(QStringLiteral("PictureFrame"));
        sizePolicy2.setHeightForWidth(PictureFrame->sizePolicy().hasHeightForWidth());
        PictureFrame->setSizePolicy(sizePolicy2);
        PictureFrame->setMinimumSize(QSize(0, 0));
        PictureFrame->setSizeIncrement(QSize(10, 10));
        PictureFrame->setFrameShape(QFrame::Box);
        PictureFrame->setLineWidth(2);

        horizontalLayout_3->addWidget(PictureFrame);


        gridLayout->addLayout(horizontalLayout_3, 0, 2, 3, 1);

        PictureProcessingBar = new QProgressBar(centralWidget);
        PictureProcessingBar->setObjectName(QStringLiteral("PictureProcessingBar"));
        PictureProcessingBar->setValue(24);

        gridLayout->addWidget(PictureProcessingBar, 7, 2, 1, 1);

        ImageScroller = new QSlider(centralWidget);
        ImageScroller->setObjectName(QStringLiteral("ImageScroller"));
        ImageScroller->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(ImageScroller, 6, 2, 1, 1);

        GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUIClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuBar->setMinimumSize(QSize(10, 5));
        menuBar->setDefaultUp(true);
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        GUIClass->setMenuBar(menuBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Recent);
        menu_File->addSeparator();
        menu_File->addSeparator();
        menu_File->addAction(action_Exit);
        menuEdit->addAction(actionView);

        retranslateUi(GUIClass);
        QObject::connect(action_Exit, SIGNAL(triggered()), GUIClass, SLOT(close()));

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "White Area Detection", Q_NULLPTR));
        action_Open->setText(QApplication::translate("GUIClass", "&Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Open->setShortcut(QApplication::translate("GUIClass", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Exit->setText(QApplication::translate("GUIClass", "&Quit", Q_NULLPTR));
        action_Recent->setText(QApplication::translate("GUIClass", "&Recent", Q_NULLPTR));
        action_Close->setText(QApplication::translate("GUIClass", "&Close", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("GUIClass", "Undo", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("GUIClass", "Redo", Q_NULLPTR));
        actionEdit->setText(QApplication::translate("GUIClass", "Edit", Q_NULLPTR));
        actionView->setText(QApplication::translate("GUIClass", "View", Q_NULLPTR));
        actionAutoGenorate->setText(QApplication::translate("GUIClass", "AutoGenerate", Q_NULLPTR));
        actionSave->setText(QApplication::translate("GUIClass", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("GUIClass", "Save As", Q_NULLPTR));
        actionExport->setText(QApplication::translate("GUIClass", "Export", Q_NULLPTR));
        RGBView->setText(QString());
        ProcessButton->setText(QApplication::translate("GUIClass", "Process", Q_NULLPTR));
        ExportButton->setText(QApplication::translate("GUIClass", "Export", Q_NULLPTR));
        FarLeftScrollImage->setText(QString());
        LeftScrollImage->setText(QString());
        CenterScollImage->setText(QString());
        RightScrollImage->setText(QString());
        FarRightScrollImage->setText(QString());
        PictureFrame->setText(QString());
        menu_File->setTitle(QApplication::translate("GUIClass", "&File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("GUIClass", "Metadata", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
