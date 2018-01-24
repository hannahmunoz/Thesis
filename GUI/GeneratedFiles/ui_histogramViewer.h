/********************************************************************************
** Form generated from reading UI file 'histogramViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMVIEWER_H
#define UI_HISTOGRAMVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistogramViewer
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *GBR_label;
    QCheckBox *green;
    QCheckBox *blue;
    QCheckBox *red;
    QLabel *histogram;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *HistogramViewer)
    {
        if (HistogramViewer->objectName().isEmpty())
            HistogramViewer->setObjectName(QStringLiteral("HistogramViewer"));
        HistogramViewer->resize(320, 353);
        gridLayout_2 = new QGridLayout(HistogramViewer);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        GBR_label = new QLabel(HistogramViewer);
        GBR_label->setObjectName(QStringLiteral("GBR_label"));

        horizontalLayout->addWidget(GBR_label);

        green = new QCheckBox(HistogramViewer);
        green->setObjectName(QStringLiteral("green"));

        horizontalLayout->addWidget(green);

        blue = new QCheckBox(HistogramViewer);
        blue->setObjectName(QStringLiteral("blue"));

        horizontalLayout->addWidget(blue);

        red = new QCheckBox(HistogramViewer);
        red->setObjectName(QStringLiteral("red"));

        horizontalLayout->addWidget(red);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        histogram = new QLabel(HistogramViewer);
        histogram->setObjectName(QStringLiteral("histogram"));
        histogram->setMinimumSize(QSize(300, 300));

        gridLayout->addWidget(histogram, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(HistogramViewer);

        QMetaObject::connectSlotsByName(HistogramViewer);
    } // setupUi

    void retranslateUi(QWidget *HistogramViewer)
    {
        HistogramViewer->setWindowTitle(QApplication::translate("HistogramViewer", "Form", Q_NULLPTR));
        GBR_label->setText(QApplication::translate("HistogramViewer", "GBR", Q_NULLPTR));
        green->setText(QApplication::translate("HistogramViewer", "Green", Q_NULLPTR));
        blue->setText(QApplication::translate("HistogramViewer", "Blue", Q_NULLPTR));
        red->setText(QApplication::translate("HistogramViewer", "Red", Q_NULLPTR));
        histogram->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HistogramViewer: public Ui_HistogramViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMVIEWER_H
