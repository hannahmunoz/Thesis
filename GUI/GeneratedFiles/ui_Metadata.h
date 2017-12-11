/********************************************************************************
** Form generated from reading UI file 'Metadata.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METADATA_H
#define UI_METADATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Metadata
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLineEdit *emailLineEdit;
    QLabel *phoneLabel;
    QLineEdit *phoneLineEdit;
    QLabel *websiteLabel;
    QLineEdit *websiteLineEdit;
    QLabel *institutionNameLabel;
    QLineEdit *institutionNameLineEdit;
    QLabel *institutionAddress1Label;
    QLineEdit *institutionAddress1LineEdit;
    QLabel *institutionAddress2Label;
    QLineEdit *institutionAddress2LineEdit;
    QLabel *Adress3Label;
    QLineEdit *Address3Edit;
    QLabel *institutionPhoneLabel;
    QLineEdit *institutionPhoneLineEdit;
    QLabel *notesLabel;
    QTextEdit *notesEdit;
    QLabel *emailLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Save;
    QPushButton *Cancel;

    void setupUi(QWidget *Metadata)
    {
        if (Metadata->objectName().isEmpty())
            Metadata->setObjectName(QStringLiteral("Metadata"));
        Metadata->resize(350, 400);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Metadata->sizePolicy().hasHeightForWidth());
        Metadata->setSizePolicy(sizePolicy);
        Metadata->setMinimumSize(QSize(350, 400));
        Metadata->setMaximumSize(QSize(350, 400));
        Metadata->setStyleSheet(QLatin1String("/* Style sheet from \n"
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
"	color: #DDDDDD;;\n"
"}\n"
"\n"
"QWidget::i"
                        "tem:selected {\n"
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
"	margi"
                        "n: 0px 0px 0px 32px;\n"
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
"	subcontrol"
                        "-position: top left;\n"
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
"	gridline-color: #9"
                        "99999;\n"
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
"\n"
""
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
        formLayoutWidget = new QWidget(Metadata);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 12, 331, 334));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        nameLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(formLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        emailLineEdit = new QLineEdit(formLayoutWidget);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, emailLineEdit);

        phoneLabel = new QLabel(formLayoutWidget);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));
        phoneLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, phoneLabel);

        phoneLineEdit = new QLineEdit(formLayoutWidget);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, phoneLineEdit);

        websiteLabel = new QLabel(formLayoutWidget);
        websiteLabel->setObjectName(QStringLiteral("websiteLabel"));
        websiteLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, websiteLabel);

        websiteLineEdit = new QLineEdit(formLayoutWidget);
        websiteLineEdit->setObjectName(QStringLiteral("websiteLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, websiteLineEdit);

        institutionNameLabel = new QLabel(formLayoutWidget);
        institutionNameLabel->setObjectName(QStringLiteral("institutionNameLabel"));
        institutionNameLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, institutionNameLabel);

        institutionNameLineEdit = new QLineEdit(formLayoutWidget);
        institutionNameLineEdit->setObjectName(QStringLiteral("institutionNameLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, institutionNameLineEdit);

        institutionAddress1Label = new QLabel(formLayoutWidget);
        institutionAddress1Label->setObjectName(QStringLiteral("institutionAddress1Label"));
        institutionAddress1Label->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, institutionAddress1Label);

        institutionAddress1LineEdit = new QLineEdit(formLayoutWidget);
        institutionAddress1LineEdit->setObjectName(QStringLiteral("institutionAddress1LineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, institutionAddress1LineEdit);

        institutionAddress2Label = new QLabel(formLayoutWidget);
        institutionAddress2Label->setObjectName(QStringLiteral("institutionAddress2Label"));
        institutionAddress2Label->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, institutionAddress2Label);

        institutionAddress2LineEdit = new QLineEdit(formLayoutWidget);
        institutionAddress2LineEdit->setObjectName(QStringLiteral("institutionAddress2LineEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, institutionAddress2LineEdit);

        Adress3Label = new QLabel(formLayoutWidget);
        Adress3Label->setObjectName(QStringLiteral("Adress3Label"));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        Adress3Label->setFont(font1);
        Adress3Label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(7, QFormLayout::LabelRole, Adress3Label);

        Address3Edit = new QLineEdit(formLayoutWidget);
        Address3Edit->setObjectName(QStringLiteral("Address3Edit"));
        QFont font2;
        font2.setBold(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        Address3Edit->setFont(font2);
        Address3Edit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(7, QFormLayout::FieldRole, Address3Edit);

        institutionPhoneLabel = new QLabel(formLayoutWidget);
        institutionPhoneLabel->setObjectName(QStringLiteral("institutionPhoneLabel"));
        institutionPhoneLabel->setFont(font);

        formLayout->setWidget(11, QFormLayout::LabelRole, institutionPhoneLabel);

        institutionPhoneLineEdit = new QLineEdit(formLayoutWidget);
        institutionPhoneLineEdit->setObjectName(QStringLiteral("institutionPhoneLineEdit"));

        formLayout->setWidget(11, QFormLayout::FieldRole, institutionPhoneLineEdit);

        notesLabel = new QLabel(formLayoutWidget);
        notesLabel->setObjectName(QStringLiteral("notesLabel"));
        notesLabel->setFont(font);

        formLayout->setWidget(13, QFormLayout::LabelRole, notesLabel);

        notesEdit = new QTextEdit(formLayoutWidget);
        notesEdit->setObjectName(QStringLiteral("notesEdit"));

        formLayout->setWidget(13, QFormLayout::FieldRole, notesEdit);

        emailLabel = new QLabel(formLayoutWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setFont(font1);
        emailLabel->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, emailLabel);

        horizontalLayoutWidget = new QWidget(Metadata);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 349, 331, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Save = new QPushButton(horizontalLayoutWidget);
        Save->setObjectName(QStringLiteral("Save"));

        horizontalLayout->addWidget(Save);

        Cancel = new QPushButton(horizontalLayoutWidget);
        Cancel->setObjectName(QStringLiteral("Cancel"));

        horizontalLayout->addWidget(Cancel);


        retranslateUi(Metadata);
        QObject::connect(Cancel, SIGNAL(clicked()), Metadata, SLOT(close()));

        QMetaObject::connectSlotsByName(Metadata);
    } // setupUi

    void retranslateUi(QWidget *Metadata)
    {
        Metadata->setWindowTitle(QApplication::translate("Metadata", "Metadata Editor", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("Metadata", "Name", Q_NULLPTR));
        phoneLabel->setText(QApplication::translate("Metadata", "Phone", Q_NULLPTR));
        websiteLabel->setText(QApplication::translate("Metadata", "Website", Q_NULLPTR));
        institutionNameLabel->setText(QApplication::translate("Metadata", "Institution Name", Q_NULLPTR));
        institutionAddress1Label->setText(QApplication::translate("Metadata", "Address 1", Q_NULLPTR));
        institutionAddress2Label->setText(QApplication::translate("Metadata", "Address 2", Q_NULLPTR));
        Adress3Label->setText(QApplication::translate("Metadata", "Address 3", Q_NULLPTR));
        institutionPhoneLabel->setText(QApplication::translate("Metadata", "Institution Phone", Q_NULLPTR));
        notesLabel->setText(QApplication::translate("Metadata", "Notes", Q_NULLPTR));
        emailLabel->setText(QApplication::translate("Metadata", "Email", Q_NULLPTR));
        Save->setText(QApplication::translate("Metadata", "Save", Q_NULLPTR));
        Cancel->setText(QApplication::translate("Metadata", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Metadata: public Ui_Metadata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METADATA_H
