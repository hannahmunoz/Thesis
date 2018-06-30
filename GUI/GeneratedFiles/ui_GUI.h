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
    QLabel *WelcomeLabel;
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
        GUIClass->setStyleSheet(QLatin1String("/***\n"
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
"QCheckBox {\n"
"    spacing: 5px;\n"
"    outline: none;\n"
"    color: #eff0f1;\n"
"    margin-bottom: 2px;\n"
"}\n"
"\n"
"QCheckBox:disabled {\n"
"    color: #76797C;\n"
"}\n"
"\n"
"QCheckBox::indic"
                        "ator,\n"
"QGroupBox::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QGroupBox::indicator {\n"
"    margin-left: 2px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked,\n"
"QGroupBox::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover,\n"
"QCheckBox::indicator:unchecked:focus,\n"
"QCheckBox::indicator:unchecked:pressed,\n"
"QGroupBox::indicator:unchecked:hover,\n"
"QGroupBox::indicator:unchecked:focus,\n"
"QGroupBox::indicator:unchecked:pressed {\n"
"    border: none;\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked,\n"
"QGroupBox::indicator:checked {\n"
"    image: url(:/qss_icons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover,\n"
"QCheckBox::indicator:checked:focus,\n"
"QCheckBox::indicator:checked:pressed,\n"
"QGroupBox::indicator:checked:hover,\n"
"QGroupBox::indicator:checked:focus,\n"
"QGroupBox::indicator:checked:pres"
                        "sed {\n"
"    border: none;\n"
"    image: url(:/qss_icons/rc/checkbox_checked_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate:focus,\n"
"QCheckBox::indicator:indeterminate:hover,\n"
"QCheckBox::indicator:indeterminate:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate_focus.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:disabled,\n"
"QGroupBox::indicator:checked:disabled {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_disabled.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled,\n"
"QGroupBox::indicator:unchecked:disabled {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_disabled.png);\n"
"}\n"
"\n"
"QRadioButton {\n"
"    spacing: 5px;\n"
"    outline: none;\n"
"    color: #eff0f1;\n"
"    margin-bottom: 2px;\n"
"}\n"
"\n"
"QRadioButton:disabled {\n"
"    color: #76797C;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 21px;\n"
"    heig"
                        "ht: 21px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/radio_unchecked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover,\n"
"QRadioButton::indicator:unchecked:focus,\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_unchecked_focus.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover,\n"
"QRadioButton::indicator:checked:focus,\n"
"QRadioButton::indicator:checked:pressed {\n"
"    border: none;\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked_focus.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:disabled {\n"
"    outline: none;\n"
"    image: url(:/qss_icons/rc/radio_checked_disabled.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:disabled {\n"
"    image: url(:/qss_icons/rc/radio_unchecked_di"
                        "sabled.png);\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #31363b;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background: transparent;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #3daee9;\n"
"    color: #eff0f1;\n"
"    margin-bottom: -1px;\n"
"    padding-bottom: 1px;\n"
"}\n"
"\n"
"QMenu {\n"
"    border: 1px solid #76797C;\n"
"    color: #eff0f1;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QMenu::icon {\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 5px 30px 5px 30px;\n"
"    border: 1px solid transparent;\n"
"    /* reserve space for selection border */\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 2px;\n"
"    background: lightblue;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"    width: 18px"
                        ";\n"
"    height: 18px;\n"
"}\n"
"\n"
"\n"
"QMenu::right-arrow {\n"
"    margin: 5px;\n"
"    image: url(:/qss_icons/rc/right_arrow.png)\n"
"}\n"
"\n"
"QWidget:disabled {\n"
"    color: #454545;\n"
"    background-color: #31363b;\n"
"}\n"
"\n"
"QAbstractItemView {\n"
"    alternate-background-color: #31363b;\n"
"    color: #eff0f1;\n"
"    border: 1px solid #3A3939;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QWidget:focus,\n"
"QMenuBar:focus {\n"
"    border: 1px solid #3daee9;\n"
"}\n"
"\n"
"QTabWidget:focus,\n"
"QCheckBox:focus,\n"
"QRadioButton:focus,\n"
"QSlider:focus {\n"
"    border: none;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #232629;\n"
"    padding: 5px;\n"
"    border-style: solid;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QAbstractItemView QLineEdit {\n"
"    padding: 0;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 2px;\n"
"    margin-top: 20px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"   "
                        " subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"\n"
"QAbstractScrollArea {\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    height: 15px;\n"
"    margin: 3px 15px 3px 15px;\n"
"    border: 1px transparent #2A2929;\n"
"    border-radius: 4px;\n"
"    background-color: #2A2929;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background-color: #605F5F;\n"
"    min-width: 5px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    margin: 0px 3px 0px 3px;\n"
"    border-image: url(:/qss_icons/rc/right_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    margin: 0px 3px 0px 3px;\n"
"    border-image: url(:/qss_icons/rc/left_arrow_d"
                        "isabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal:hover,\n"
"QScrollBar::add-line:horizontal:on {\n"
"    border-image: url(:/qss_icons/rc/right_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal:hover,\n"
"QScrollBar::sub-line:horizontal:on {\n"
"    border-image: url(:/qss_icons/rc/left_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:horizontal,\n"
"QScrollBar::down-arrow:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #2A2929;\n"
"    width: 15px;\n"
"    margin: 15px 3px 15px 3px;\n"
"    bo"
                        "rder: 1px transparent #2A2929;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #605F5F;\n"
"    min-height: 5px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    margin: 3px 0px 3px 0px;\n"
"    border-image: url(:/qss_icons/rc/up_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    margin: 3px 0px 3px 0px;\n"
"    border-image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover,\n"
"QScrollBar::sub-line:vertical:on {\n"
"    border-image: url(:/qss_icons/rc/up_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:hover,\n"
""
                        "QScrollBar::add-line:vertical:on {\n"
"    border-image: url(:/qss_icons/rc/down_arrow.png);\n"
"    height: 10px;\n"
"    width: 10px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical,\n"
"QScrollBar::down-arrow:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QPlainTextEdit {\n"
"    background-color: #232629;\n"
"    ;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #76797C;\n"
"    color: #eff0f1;\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QSizeGrip {\n"
"    image: url(:/qss_icons/rc/sizegrip.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QMainWindow::separator {\n"
""
                        "    background-color: #31363b;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    spacing: 2px;\n"
"    border: 1px dashed #76797C;\n"
"}\n"
"\n"
"QMainWindow::separator:hover {\n"
"    background-color: #787876;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #76797C;\n"
"    spacing: 2px;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background-color: #76797C;\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QFrame {\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QFrame[frameShape=\"0\"] {\n"
"    border-radius: 2px;\n"
"    border: 1px transparent #76797C;\n"
"}\n"
"\n"
"QStackedWidget {\n"
"    border: 1px transparent black;\n"
"}\n"
"\n"
"QToolBar {\n"
"    border: 1px transparent #393838;\n"
"    background: 1px solid #31363b;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QToolBar::handle:horizontal {\n"
"    image: url(:/qss_icons/rc/Hmovetoolbar.png);\n"
"}\n"
""
                        "\n"
"QToolBar::handle:vertical {\n"
"    image: url(:/qss_icons/rc/Vmovetoolbar.png);\n"
"}\n"
"\n"
"QToolBar::separator:horizontal {\n"
"    image: url(:/qss_icons/rc/Hsepartoolbar.png);\n"
"}\n"
"\n"
"QToolBar::separator:vertical {\n"
"    image: url(:/qss_icons/rc/Vsepartoolbar.png);\n"
"}\n"
"\n"
"QToolButton#qt_toolbar_ext_button {\n"
"    background: #58595a\n"
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
"    color: w"
                        "hite;\n"
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
"QComboBox:on {\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    selection-background-color: #4a4a4a;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #232629;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #76797C;\n"
"    selection-background-color: #18465d;\n"
""
                        "}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on,\n"
"QComboBox::down-arrow:hover,\n"
"QComboBox::down-arrow:focus {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QAbstractSpinBox {\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QAbstractSpinBox:up-button {\n"
"    background-color: transparent;\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: center right;\n"
"}\n"
"\n"
"QAbstractSpinBox:down-button {\n"
"    background-color: transparent;\n"
" "
                        "   subcontrol-origin: border;\n"
"    subcontrol-position: center left;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow,\n"
"QAbstractSpinBox::up-arrow:disabled,\n"
"QAbstractSpinBox::up-arrow:off {\n"
"    image: url(:/qss_icons/rc/up_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow:hover {\n"
"    image: url(:/qss_icons/rc/up_arrow.png);\n"
"}\n"
"\n"
"QAbstractSpinBox::down-arrow,\n"
"QAbstractSpinBox::down-arrow:disabled,\n"
"QAbstractSpinBox::down-arrow:off {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
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
"QTabWidget {\n"
"    border: 0px transparent black;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #76797C;\n"
"    padding: 5px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    /* left: 5px; move"
                        " to the right by 5px */\n"
"}\n"
"\n"
"QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QTabBar:focus {\n"
"    border: 0px transparent black;\n"
"}\n"
"\n"
"QTabBar::close-button {\n"
"    image: url(:/qss_icons/rc/close.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBar::close-button:hover {\n"
"    image: url(:/qss_icons/rc/close-hover.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTabBar::close-button:pressed {\n"
"    image: url(:/qss_icons/rc/close-pressed.png);\n"
"    background: transparent;\n"
"}\n"
"\n"
"\n"
"/* TOP TABS */\n"
"\n"
"QTabBar::tab:top {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    min-width: 50px;\n"
"    border-top-left-radius: 2px;\n"
"    border-top-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
""
                        "    border-bottom: 2px solid #3daee9;\n"
"    border-top-left-radius: 2px;\n"
"    border-top-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* BOTTOM TABS */\n"
"\n"
"QTabBar::tab:bottom {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-top: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-bottom-left-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"    min-width: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-top: 2px solid #3daee9;\n"
"    border-bottom-left-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* LEFT TABS */\n"
"\n"
"QTabBar::tab:left {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-left: "
                        "1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-top-right-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"    min-height: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:left:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-left: 2px solid #3daee9;\n"
"    border-top-right-radius: 2px;\n"
"    border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"\n"
"/* RIGHT TABS */\n"
"\n"
"QTabBar::tab:right {\n"
"    color: #eff0f1;\n"
"    border: 1px solid #76797C;\n"
"    border-right: 1px transparent black;\n"
"    background-color: #31363b;\n"
"    padding: 5px;\n"
"    border-top-left-radius: 2px;\n"
"    border-bottom-left-radius: 2px;\n"
"    min-height: 50px;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected {\n"
"    color: #eff0f1;\n"
"    background-color: #54575B;\n"
"    border: 1px solid #76797C;\n"
"    border-right: 2px s"
                        "olid #3daee9;\n"
"    border-top-left-radius: 2px;\n"
"    border-bottom-left-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected:hover {\n"
"    background-color: #3daee9;\n"
"}\n"
"\n"
"QTabBar QToolButton::right-arrow:enabled {\n"
"    image: url(:/qss_icons/rc/right_arrow.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::left-arrow:enabled {\n"
"    image: url(:/qss_icons/rc/left_arrow.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::right-arrow:disabled {\n"
"    image: url(:/qss_icons/rc/right_arrow_disabled.png);\n"
"}\n"
"\n"
"QTabBar QToolButton::left-arrow:disabled {\n"
"    image: url(:/qss_icons/rc/left_arrow_disabled.png);\n"
"}\n"
"\n"
"QDockWidget {\n"
"    background: #31363b;\n"
"    border: 1px solid #403F3F;\n"
"    titlebar-close-icon: url(:/qss_icons/rc/close.png);\n"
"    titlebar-normal-icon: url(:/qss_icons/rc/undock.png);\n"
"}\n"
"\n"
"QDockWidget::close-button,\n"
"QDockWidget::float-button {\n"
"    border: 1px solid transparent;\n"
"    border-radius: 2px;\n"
"    background: transparent;\n"
""
                        "}\n"
"\n"
"QDockWidget::close-button:hover,\n"
"QDockWidget::float-button:hover {\n"
"    background: rgba(255, 255, 255, 10);\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed,\n"
"QDockWidget::float-button:pressed {\n"
"    padding: 1px -1px -1px 1px;\n"
"    background: rgba(255, 255, 255, 10);\n"
"}\n"
"\n"
"QTreeView,\n"
"QListView {\n"
"    border: 1px solid #76797C;\n"
"    background-color: #232629;\n"
"}\n"
"\n"
"QTreeView:branch:selected,\n"
"QTreeView:branch:hover {\n"
"    background: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:!adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"    border-image: url(:/qss_icons/rc/transparent.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:h"
                        "as-siblings {\n"
"    image: url(:/qss_icons/rc/branch_closed.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings {\n"
"    image: url(:/qss_icons/rc/branch_open.png);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed:hover,\n"
"QTreeView::branch:closed:has-children:has-siblings:hover {\n"
"    image: url(:/qss_icons/rc/branch_closed-on.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings:hover,\n"
"QTreeView::branch:open:has-children:has-siblings:hover {\n"
"    image: url(:/qss_icons/rc/branch_open-on.png);\n"
"}\n"
"\n"
"QListView::item:!selected:hover,\n"
"QTreeView::item:!selected:hover {\n"
"    background: #18465d;\n"
"    outline: 0;\n"
"    color: #eff0f1\n"
"}\n"
"\n"
"QListView::item:selected:hover,\n"
"QTreeView::item:selected:hover {\n"
"    background: #287399;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QTreeView::indicator:checked,\n"
"QListView::indicator:checked {\n"
"    image: url(:/qss_ic"
                        "ons/rc/checkbox_checked.png);\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked,\n"
"QListView::indicator:unchecked {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QTreeView::indicator:indeterminate,\n"
"QListView::indicator:indeterminate {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate.png);\n"
"}\n"
"\n"
"QTreeView::indicator:checked:hover,\n"
"QTreeView::indicator:checked:focus,\n"
"QTreeView::indicator:checked:pressed,\n"
"QListView::indicator:checked:hover,\n"
"QListView::indicator:checked:focus,\n"
"QListView::indicator:checked:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_checked_focus.png);\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked:hover,\n"
"QTreeView::indicator:unchecked:focus,\n"
"QTreeView::indicator:unchecked:pressed,\n"
"QListView::indicator:unchecked:hover,\n"
"QListView::indicator:unchecked:focus,\n"
"QListView::indicator:unchecked:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_unchecked_focus.png);\n"
"}\n"
"\n"
"QTreeView::indicator:indetermi"
                        "nate:hover,\n"
"QTreeView::indicator:indeterminate:focus,\n"
"QTreeView::indicator:indeterminate:pressed,\n"
"QListView::indicator:indeterminate:hover,\n"
"QListView::indicator:indeterminate:focus,\n"
"QListView::indicator:indeterminate:pressed {\n"
"    image: url(:/qss_icons/rc/checkbox_indeterminate_focus.png);\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #565a5e;\n"
"    height: 4px;\n"
"    background: #565a5e;\n"
"    margin: 0px;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #232629;\n"
"    border: 1px solid #565a5e;\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -8px 0;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    border: 1px solid #565a5e;\n"
"    width: 4px;\n"
"    background: #565a5e;\n"
"    margin: 0px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: #232629;\n"
"    border: 1px solid #565a5e;\n"
"    width: 16px;\n"
"    height: 16px;\n"
""
                        "    margin: 0 -8px;\n"
"    border-radius: 9px;\n"
"}\n"
"\n"
"QToolButton {\n"
"    background-color: transparent;\n"
"    border: 1px transparent #76797C;\n"
"    border-radius: 2px;\n"
"    margin: 3px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"] {\n"
"    /* only for MenuButtonPopup */\n"
"    padding-right: 20px;\n"
"    /* make way for the popup button */\n"
"    border: 1px #76797C;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"2\"] {\n"
"    /* only for InstantPopup */\n"
"    padding-right: 10px;\n"
"    /* make way for the popup button */\n"
"    border: 1px #76797C;\n"
"}\n"
"\n"
"QToolButton:hover,\n"
"QToolButton::menu-button:hover {\n"
"    background-color: transparent;\n"
"    border: 1px solid #3daee9;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QToolButton:checked,\n"
"QToolButton:pressed,\n"
"QToolButton::menu-button:pressed {\n"
"    background-color: #3daee9;\n"
"    border: 1px solid #3daee9;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"\n"
"/* the subcontrol b"
                        "elow is used only in the InstantPopup or DelayedPopup mode */\n"
"\n"
"QToolButton::menu-indicator {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"    top: -7px;\n"
"    left: -2px;\n"
"    /* shift it a bit */\n"
"}\n"
"\n"
"\n"
"/* the subcontrols below are used only in the MenuButtonPopup mode */\n"
"\n"
"QToolButton::menu-button {\n"
"    border: 1px transparent #76797C;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    /* 16px width + 4px for border = 20px allocated above */\n"
"    width: 16px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QToolButton::menu-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QToolButton::menu-arrow:open {\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QPushButton::menu-indicator {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: bottom right;\n"
"    left: 8px;\n"
"}\n"
"\n"
"QTableView {\n"
"    border: 1px solid #76797C;\n"
"    gridline-color: #31363b;\n"
"    background-color: #232629;\n"
""
                        "}\n"
"\n"
"QTableView,\n"
"QHeaderView {\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QTableView::item:pressed,\n"
"QListView::item:pressed,\n"
"QTreeView::item:pressed {\n"
"    background: #18465d;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QTableView::item:selected:active,\n"
"QTreeView::item:selected:active,\n"
"QListView::item:selected:active {\n"
"    background: #287399;\n"
"    color: #eff0f1;\n"
"}\n"
"\n"
"QHeaderView {\n"
"    background-color: #31363b;\n"
"    border: 1px transparent;\n"
"    border-radius: 0px;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #31363b;\n"
"    color: #eff0f1;\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 0px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QHeaderView::section::vertical::first,\n"
"QHeaderView::section::vertical::only-one {\n"
"    border-top: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section::vertical {\n"
"    border-top: transparent;\n"
"}\n"
"\n"
"QHeaderView:"
                        ":section::horizontal::first,\n"
"QHeaderView::section::horizontal::only-one {\n"
"    border-left: 1px solid #76797C;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal {\n"
"    border-left: transparent;\n"
"}\n"
"\n"
"QHeaderView::section:checked {\n"
"    color: white;\n"
"    background-color: #334e5e;\n"
"}\n"
"\n"
"\n"
"/* style the sort indicator */\n"
"\n"
"QHeaderView::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"    image: url(:/qss_icons/rc/up_arrow.png);\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #31363b;\n"
"    border: 1px transparent #76797C;\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QToolBox {\n"
"    padding: 5px;\n"
"    border: 1px transparent black;\n"
"}\n"
"\n"
"QToolBox::tab {\n"
"    color: #eff0f1;\n"
"    background-color: #31363b;\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 1px transparent #31363b;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
""
                        "QToolBox::tab:selected {\n"
"    /* italicize selected tabs */\n"
"    font: italic;\n"
"    background-color: #31363b;\n"
"    border-color: #3daee9;\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"    border: 0px transparent dark;\n"
"}\n"
"\n"
"QFrame[height=\"3\"],\n"
"QFrame[width=\"3\"] {\n"
"    background-color: #76797C;\n"
"}\n"
"\n"
"QSplitter::handle {\n"
"    border: 1px dashed #76797C;\n"
"}\n"
"\n"
"QSplitter::handle:hover {\n"
"    background-color: #787876;\n"
"    border: 1px solid #76797C;\n"
"}\n"
"\n"
"QSplitter::handle:horizontal {\n"
"    width: 1px;\n"
"}\n"
"\n"
"QSplitter::handle:vertical {\n"
"    height: 1px;\n"
"}\n"
"\n"
"QProgressBar {\n"
"    border: 1px solid #76797C;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #05B8CC;\n"
"}\n"
"\n"
"QDateEdit {\n"
"    selection-background-color: #3daee9;\n"
"    border-style: solid;\n"
"    border: 1px solid #3375A3;\n"
"    border-radius: 2px;\n"
"    padding: 1px;\n"
"    min-"
                        "width: 75px;\n"
"}\n"
"\n"
"QDateEdit:on {\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    selection-background-color: #4a4a4a;\n"
"}\n"
"\n"
"QDateEdit QAbstractItemView {\n"
"    background-color: #232629;\n"
"    border-radius: 2px;\n"
"    border: 1px solid #3375A3;\n"
"    selection-background-color: #3daee9;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 0px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow_disabled.png);\n"
"}\n"
"\n"
"QDateEdit::down-arrow:on,\n"
"QDateEdit::down-arrow:hover,\n"
"QDateEdit::down-arrow:focus {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
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

        WelcomeLabel = new QLabel(centralWidget);
        WelcomeLabel->setObjectName(QStringLiteral("WelcomeLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Vrinda"));
        font.setPointSize(25);
        WelcomeLabel->setFont(font);

        gridLayout_3->addWidget(WelcomeLabel, 1, 0, 1, 1);


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

        retranslateUi(GUIClass);
        QObject::connect(action_Exit, SIGNAL(triggered()), GUIClass, SLOT(close()));

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "CSEWIS", Q_NULLPTR));
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
        WelcomeLabel->setText(QApplication::translate("GUIClass", "Clouds and Snow Estimate from Webcam Image Streams", Q_NULLPTR));
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
