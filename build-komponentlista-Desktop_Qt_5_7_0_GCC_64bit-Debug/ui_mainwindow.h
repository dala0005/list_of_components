/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAdd_component;
    QAction *actionTa_bort_komponent;
    QAction *action_ndra_komponent;
    QAction *actionSearch_components;
    QAction *actionTest;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *search_component_page;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_search_component_by_field;
    QLabel *label_2;
    QLineEdit *lineEdit_search_boxnr;
    QLabel *label_14;
    QLineEdit *lineEdit_search_fieldnr;
    QPushButton *pushButton_ok_search_by_field;
    QWidget *tab_search_component_by_category;
    QComboBox *categoryBox;
    QWidget *new_component_page;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_boxNr;
    QLineEdit *lineEdit_fieldNr;
    QTextEdit *textEdit_description;
    QLineEdit *lineEdit_quantity;
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *categoryBox_2;
    QWidget *tab_2;
    QLineEdit *lineEdit_4;
    QLabel *label_9;
    QPushButton *pushButton;
    QPushButton *clearButton_newComponent;
    QTextBrowser *textBrowser;
    QLabel *label_15;
    QWidget *delete_component_page;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_boxNr_delete;
    QLineEdit *lineEdit_fieldNr_delete;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser_component_delete;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_id_delete;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuKomponent;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(804, 452);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionAdd_component = new QAction(MainWindow);
        actionAdd_component->setObjectName(QStringLiteral("actionAdd_component"));
        actionTa_bort_komponent = new QAction(MainWindow);
        actionTa_bort_komponent->setObjectName(QStringLiteral("actionTa_bort_komponent"));
        action_ndra_komponent = new QAction(MainWindow);
        action_ndra_komponent->setObjectName(QStringLiteral("action_ndra_komponent"));
        actionSearch_components = new QAction(MainWindow);
        actionSearch_components->setObjectName(QStringLiteral("actionSearch_components"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -1, 711, 381));
        search_component_page = new QWidget();
        search_component_page->setObjectName(QStringLiteral("search_component_page"));
        tableWidget = new QTableWidget(search_component_page);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 130, 711, 251));
        label_3 = new QLabel(search_component_page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 131, 20));
        QFont font;
        font.setUnderline(true);
        label_3->setFont(font);
        tabWidget_2 = new QTabWidget(search_component_page);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 50, 341, 71));
        tab_search_component_by_field = new QWidget();
        tab_search_component_by_field->setObjectName(QStringLiteral("tab_search_component_by_field"));
        label_2 = new QLabel(tab_search_component_by_field);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 41, 16));
        lineEdit_search_boxnr = new QLineEdit(tab_search_component_by_field);
        lineEdit_search_boxnr->setObjectName(QStringLiteral("lineEdit_search_boxnr"));
        lineEdit_search_boxnr->setGeometry(QRect(50, 10, 61, 22));
        label_14 = new QLabel(tab_search_component_by_field);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(120, 10, 51, 16));
        lineEdit_search_fieldnr = new QLineEdit(tab_search_component_by_field);
        lineEdit_search_fieldnr->setObjectName(QStringLiteral("lineEdit_search_fieldnr"));
        lineEdit_search_fieldnr->setGeometry(QRect(170, 10, 51, 22));
        pushButton_ok_search_by_field = new QPushButton(tab_search_component_by_field);
        pushButton_ok_search_by_field->setObjectName(QStringLiteral("pushButton_ok_search_by_field"));
        pushButton_ok_search_by_field->setGeometry(QRect(240, 10, 80, 22));
        tabWidget_2->addTab(tab_search_component_by_field, QString());
        tab_search_component_by_category = new QWidget();
        tab_search_component_by_category->setObjectName(QStringLiteral("tab_search_component_by_category"));
        categoryBox = new QComboBox(tab_search_component_by_category);
        categoryBox->setObjectName(QStringLiteral("categoryBox"));
        categoryBox->setGeometry(QRect(10, 10, 159, 22));
        tabWidget_2->addTab(tab_search_component_by_category, QString());
        stackedWidget->addWidget(search_component_page);
        new_component_page = new QWidget();
        new_component_page->setObjectName(QStringLiteral("new_component_page"));
        label = new QLabel(new_component_page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 141, 21));
        label->setFont(font);
        label_5 = new QLabel(new_component_page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 40, 51, 21));
        label_6 = new QLabel(new_component_page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 70, 61, 21));
        label_7 = new QLabel(new_component_page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 100, 81, 21));
        label_8 = new QLabel(new_component_page);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 210, 61, 21));
        lineEdit_boxNr = new QLineEdit(new_component_page);
        lineEdit_boxNr->setObjectName(QStringLiteral("lineEdit_boxNr"));
        lineEdit_boxNr->setGeometry(QRect(70, 40, 113, 22));
        lineEdit_fieldNr = new QLineEdit(new_component_page);
        lineEdit_fieldNr->setObjectName(QStringLiteral("lineEdit_fieldNr"));
        lineEdit_fieldNr->setGeometry(QRect(70, 70, 113, 22));
        textEdit_description = new QTextEdit(new_component_page);
        textEdit_description->setObjectName(QStringLiteral("textEdit_description"));
        textEdit_description->setGeometry(QRect(10, 130, 171, 61));
        lineEdit_quantity = new QLineEdit(new_component_page);
        lineEdit_quantity->setObjectName(QStringLiteral("lineEdit_quantity"));
        lineEdit_quantity->setGeometry(QRect(80, 210, 101, 22));
        tabWidget = new QTabWidget(new_component_page);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 270, 351, 80));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        categoryBox_2 = new QComboBox(tab);
        categoryBox_2->setObjectName(QStringLiteral("categoryBox_2"));
        categoryBox_2->setGeometry(QRect(10, 10, 159, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(10, 10, 191, 22));
        tabWidget->addTab(tab_2, QString());
        label_9 = new QLabel(new_component_page);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 240, 71, 21));
        pushButton = new QPushButton(new_component_page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 350, 101, 22));
        clearButton_newComponent = new QPushButton(new_component_page);
        clearButton_newComponent->setObjectName(QStringLiteral("clearButton_newComponent"));
        clearButton_newComponent->setGeometry(QRect(170, 350, 80, 22));
        textBrowser = new QTextBrowser(new_component_page);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(400, 100, 256, 192));
        label_15 = new QLabel(new_component_page);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(400, 80, 59, 14));
        stackedWidget->addWidget(new_component_page);
        delete_component_page = new QWidget();
        delete_component_page->setObjectName(QStringLiteral("delete_component_page"));
        label_4 = new QLabel(delete_component_page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 121, 16));
        label_4->setFont(font);
        label_10 = new QLabel(delete_component_page);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 80, 51, 16));
        label_11 = new QLabel(delete_component_page);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 110, 59, 14));
        lineEdit_boxNr_delete = new QLineEdit(delete_component_page);
        lineEdit_boxNr_delete->setObjectName(QStringLiteral("lineEdit_boxNr_delete"));
        lineEdit_boxNr_delete->setGeometry(QRect(60, 80, 113, 22));
        lineEdit_fieldNr_delete = new QLineEdit(delete_component_page);
        lineEdit_fieldNr_delete->setObjectName(QStringLiteral("lineEdit_fieldNr_delete"));
        lineEdit_fieldNr_delete->setGeometry(QRect(60, 110, 113, 22));
        pushButton_2 = new QPushButton(delete_component_page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 180, 80, 22));
        pushButton_3 = new QPushButton(delete_component_page);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 180, 80, 22));
        textBrowser_component_delete = new QTextBrowser(delete_component_page);
        textBrowser_component_delete->setObjectName(QStringLiteral("textBrowser_component_delete"));
        textBrowser_component_delete->setGeometry(QRect(400, 100, 256, 192));
        label_12 = new QLabel(delete_component_page);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(400, 80, 59, 14));
        label_13 = new QLabel(delete_component_page);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 50, 41, 16));
        lineEdit_id_delete = new QLineEdit(delete_component_page);
        lineEdit_id_delete->setObjectName(QStringLiteral("lineEdit_id_delete"));
        lineEdit_id_delete->setGeometry(QRect(60, 50, 113, 22));
        stackedWidget->addWidget(delete_component_page);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 804, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuKomponent = new QMenu(menuBar);
        menuKomponent->setObjectName(QStringLiteral("menuKomponent"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuKomponent->menuAction());
        menuFile->addAction(actionQuit);
        menuKomponent->addAction(actionSearch_components);
        menuKomponent->addAction(actionAdd_component);
        menuKomponent->addAction(actionTa_bort_komponent);
        menuKomponent->addAction(action_ndra_komponent);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionAdd_component->setText(QApplication::translate("MainWindow", "Add component", 0));
        actionTa_bort_komponent->setText(QApplication::translate("MainWindow", "Delete component", 0));
        action_ndra_komponent->setText(QApplication::translate("MainWindow", "Change component", 0));
        actionSearch_components->setText(QApplication::translate("MainWindow", "Search component", 0));
        actionTest->setText(QApplication::translate("MainWindow", "test", 0));
        label_3->setText(QApplication::translate("MainWindow", "Search component", 0));
        label_2->setText(QApplication::translate("MainWindow", "Boxnr:", 0));
        label_14->setText(QApplication::translate("MainWindow", "Fieldnr:", 0));
        pushButton_ok_search_by_field->setText(QApplication::translate("MainWindow", "Ok", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_search_component_by_field), QApplication::translate("MainWindow", "by field", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_search_component_by_category), QApplication::translate("MainWindow", "by category", 0));
        label->setText(QApplication::translate("MainWindow", "Add new component:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Boxnr:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Fieldnr:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Description:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Quantity:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Existing", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "New", 0));
        label_9->setText(QApplication::translate("MainWindow", "Category:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Ok", 0));
        clearButton_newComponent->setText(QApplication::translate("MainWindow", "Clear", 0));
        label_15->setText(QApplication::translate("MainWindow", "Status:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Delete component", 0));
        label_10->setText(QApplication::translate("MainWindow", "Boxnr:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Fieldnr:", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Clear", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Ok", 0));
        label_12->setText(QApplication::translate("MainWindow", "Status: ", 0));
        label_13->setText(QApplication::translate("MainWindow", "ID:", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuKomponent->setTitle(QApplication::translate("MainWindow", "Component", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
