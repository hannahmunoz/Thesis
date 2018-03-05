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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QAction *actionSelect;
    QAction *actionRectangle_ROI;
    QAction *actionLasso_ROI;
    QAction *actionShow_RGB;
    QAction *actionView_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *LeftScrollImage;
    QLabel *FarLeftScrollImage;
    QLabel *CenterScollImage;
    QLabel *RightScrollImage;
    QLabel *FarRightScrollImage;
    QSlider *ImageScroller;
    QGridLayout *gridLayout_3;
    ClickableLabel *PictureFrame;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuEdit;
    QMenu *menuExport;
    QToolBar *toolBar;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->setEnabled(true);
        GUIClass->resize(998, 664);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GUIClass->sizePolicy().hasHeightForWidth());
        GUIClass->setSizePolicy(sizePolicy);
        GUIClass->setMinimumSize(QSize(30, 20));
        GUIClass->setMaximumSize(QSize(1500, 1500));
        GUIClass->setSizeIncrement(QSize(10, 10));
        GUIClass->setAcceptDrops(true);
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
"/** {\n"
"	background: #3e3e3e;\n"
"	color: #DDDDDD;\n"
"\n"
"}\n"
"\n"
"QWid"
                        "get::item:selected {\n"
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
""
                        "	margin: 0px 0px 0px 32px;\n"
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
"	subc"
                        "ontrol-position: top left;\n"
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
"	gridline-col"
                        "or: #999999;\n"
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
"}"
                        "\n"
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
        actionSelect = new QAction(GUIClass);
        actionSelect->setObjectName(QStringLiteral("actionSelect"));
        actionRectangle_ROI = new QAction(GUIClass);
        actionRectangle_ROI->setObjectName(QStringLiteral("actionRectangle_ROI"));
        actionLasso_ROI = new QAction(GUIClass);
        actionLasso_ROI->setObjectName(QStringLiteral("actionLasso_ROI"));
        actionShow_RGB = new QAction(GUIClass);
        actionShow_RGB->setObjectName(QStringLiteral("actionShow_RGB"));
        actionView_2 = new QAction(GUIClass);
        actionView_2->setObjectName(QStringLiteral("actionView_2"));
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(600000, 600000));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        LeftScrollImage = new QLabel(centralWidget);
        LeftScrollImage->setObjectName(QStringLiteral("LeftScrollImage"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LeftScrollImage->sizePolicy().hasHeightForWidth());
        LeftScrollImage->setSizePolicy(sizePolicy1);
        LeftScrollImage->setMinimumSize(QSize(150, 100));
        LeftScrollImage->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LeftScrollImage, 0, 1, 1, 1);

        FarLeftScrollImage = new QLabel(centralWidget);
        FarLeftScrollImage->setObjectName(QStringLiteral("FarLeftScrollImage"));
        sizePolicy1.setHeightForWidth(FarLeftScrollImage->sizePolicy().hasHeightForWidth());
        FarLeftScrollImage->setSizePolicy(sizePolicy1);
        FarLeftScrollImage->setMinimumSize(QSize(150, 100));
        FarLeftScrollImage->setMaximumSize(QSize(150, 100));
        FarLeftScrollImage->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(FarLeftScrollImage, 0, 0, 1, 1);

        CenterScollImage = new QLabel(centralWidget);
        CenterScollImage->setObjectName(QStringLiteral("CenterScollImage"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CenterScollImage->sizePolicy().hasHeightForWidth());
        CenterScollImage->setSizePolicy(sizePolicy2);
        CenterScollImage->setMinimumSize(QSize(150, 100));
        CenterScollImage->setMaximumSize(QSize(150, 100));
        CenterScollImage->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(CenterScollImage, 0, 2, 1, 1);

        RightScrollImage = new QLabel(centralWidget);
        RightScrollImage->setObjectName(QStringLiteral("RightScrollImage"));
        sizePolicy1.setHeightForWidth(RightScrollImage->sizePolicy().hasHeightForWidth());
        RightScrollImage->setSizePolicy(sizePolicy1);
        RightScrollImage->setMinimumSize(QSize(150, 100));
        RightScrollImage->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(RightScrollImage, 0, 3, 1, 1);

        FarRightScrollImage = new QLabel(centralWidget);
        FarRightScrollImage->setObjectName(QStringLiteral("FarRightScrollImage"));
        sizePolicy1.setHeightForWidth(FarRightScrollImage->sizePolicy().hasHeightForWidth());
        FarRightScrollImage->setSizePolicy(sizePolicy1);
        FarRightScrollImage->setMinimumSize(QSize(150, 100));
        FarRightScrollImage->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(FarRightScrollImage, 0, 4, 1, 1);

        ImageScroller = new QSlider(centralWidget);
        ImageScroller->setObjectName(QStringLiteral("ImageScroller"));
        ImageScroller->setMaximumSize(QSize(16777215, 15));
        ImageScroller->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(ImageScroller, 1, 0, 1, 5);


        gridLayout_2->addLayout(gridLayout, 3, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        PictureFrame = new ClickableLabel(centralWidget);
        PictureFrame->setObjectName(QStringLiteral("PictureFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(PictureFrame->sizePolicy().hasHeightForWidth());
        PictureFrame->setSizePolicy(sizePolicy3);
        PictureFrame->setMinimumSize(QSize(0, 0));
        PictureFrame->setMaximumSize(QSize(0, 0));
        PictureFrame->setSizeIncrement(QSize(10, 10));
        PictureFrame->setFrameShape(QFrame::Box);
        PictureFrame->setLineWidth(2);
        PictureFrame->setScaledContents(false);
        PictureFrame->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(PictureFrame, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 0, 1, 1);

        GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUIClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 998, 21));
        menuBar->setMinimumSize(QSize(10, 5));
        menuBar->setDefaultUp(true);
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuExport = new QMenu(menuBar);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuExport->setAcceptDrops(false);
        GUIClass->setMenuBar(menuBar);
        toolBar = new QToolBar(GUIClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        GUIClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuExport->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Recent);
        menu_File->addSeparator();
        menu_File->addSeparator();
        menu_File->addAction(action_Exit);
        menuEdit->addAction(actionView);
        menuExport->addAction(actionView_2);
        toolBar->addAction(actionRectangle_ROI);
        toolBar->addAction(actionLasso_ROI);

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
        actionSelect->setText(QApplication::translate("GUIClass", "Select", Q_NULLPTR));
        actionRectangle_ROI->setText(QApplication::translate("GUIClass", "Rectangle ROI", Q_NULLPTR));
        actionLasso_ROI->setText(QApplication::translate("GUIClass", "Lasso ROI", Q_NULLPTR));
        actionShow_RGB->setText(QApplication::translate("GUIClass", "Show RGB", Q_NULLPTR));
        actionView_2->setText(QApplication::translate("GUIClass", "View", Q_NULLPTR));
        LeftScrollImage->setText(QString());
        FarLeftScrollImage->setText(QString());
        CenterScollImage->setText(QString());
        RightScrollImage->setText(QString());
        FarRightScrollImage->setText(QString());
        PictureFrame->setText(QString());
        menu_File->setTitle(QApplication::translate("GUIClass", "&File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("GUIClass", "Metadata", Q_NULLPTR));
        menuExport->setTitle(QApplication::translate("GUIClass", "Export", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("GUIClass", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
