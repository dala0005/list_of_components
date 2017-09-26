#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include <QDebug>
#include <QList>
#include <QDir>
#include <QDesktopServices>

DbManager component_db("/home/daniel/Projekt/QT/komponentlista/components.db");
QList<struct struct_categories> categories_list;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{ 
    ui->setupUi(this);
    QStringList component_list;
    component_list << "ID" << "Box" << "Field" << "Description" << "Quantity" << "Datasheet" << "Category";

    this->setWindowTitle("List of components");

    on_actionSearch_components_triggered();


    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(component_list);

    qDebug() << "Main_meny";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_categoryBox_activated(int index)
{

    QList<struct struct_components> qlist_component_item;
    QList<struct struct_components>::iterator i;

    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

    // clear qlist
    qlist_component_item.clear();

    if(index)
    {
        qDebug() << "Index: " << index-1;
        QList<struct struct_categories>::iterator i;
        int counter = 0;


        for(i = categories_list.begin(); counter != index-1; i++, counter++);


        if(component_db.searchByCategory(&qlist_component_item, i->cat_id))
        {
            QList<struct struct_components>::iterator i;
            for(i = qlist_component_item.begin(); i != qlist_component_item.end(); ++i)
            {
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 0, new QTableWidgetItem(QString::number(i->comp_id)));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 1, new QTableWidgetItem(QString::number(i->comp_box)));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 2, new QTableWidgetItem(QString::number(i->comp_field)));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 3, new QTableWidgetItem(i->comp_description));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 4, new QTableWidgetItem(QString::number(i->comp_quantity)));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 5, new QTableWidgetItem(i->comp_spreadsheets));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 6, new QTableWidgetItem(i->comp_category));

            }
        }
    }


}

void MainWindow::on_actionQuit_triggered()
{
    qDebug() << "Closing application!";
    qApp->quit();
}

void MainWindow::on_actionAdd_component_triggered()
{
   // QString document_path = "home/daniel/Projekt/QT/komponentlista/datasheets/";
   // QDesktopServices::openUrl(QUrl("file:///" + document_path + "SSD1306.pdf"));
    ui->stackedWidget->setCurrentIndex(1);
    /* clear categoryBox_2 */
    ui->categoryBox_2->clear();

    /* add items */
    ui->categoryBox_2->addItem("");

    QList<struct struct_categories>::iterator i;

    for(i = categories_list.begin(); i != categories_list.end(); ++i)
    {
        ui->categoryBox_2->addItem(i->cat_category);
    }

}

/* search component */
void MainWindow::on_actionSearch_components_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    /* clear categoryBox 1 */
    ui->categoryBox->clear();

    /* add items */
    ui->categoryBox->addItem("");

    if(component_db.getCategories(&categories_list))
    {
        QList<struct struct_categories>::iterator i;

        for(i = categories_list.begin(); i != categories_list.end(); ++i)
        {
            ui->categoryBox->addItem(i->cat_category);
        }
    }

    /* clear table */
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

}

/* delete component */
void MainWindow::on_actionTa_bort_komponent_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->textBrowser_component_delete->setReadOnly(true);
    ui->lineEdit_id_delete->setText("0");
}

/* add new component ok */
void MainWindow::on_pushButton_clicked()
{
    int temp_id = 0;
    int temp_box = 0;
    int temp_field = 0;
    QString temp_description;
    int temp_quantity = 0;
    QString temp_category;
    bool success = true;

    /* check if content from box input is valid */
    if(temp_box = (ui->lineEdit_boxNr->text().toInt()))
    {
        qDebug() << "Boxnr: " << temp_box;
    }
    else
    {
        qDebug() << "Boxnr hasn't a valid value!";
        success = false;
    }

    /* check if content from field input is valid */
    if(temp_field = (ui->lineEdit_fieldNr->text().toInt()))
    {
        qDebug() << "Fieldnr: " << temp_field;
    }
    else
    {
        qDebug() << "Fieldnr hasn't a valid value!";
        success = false;
    }

    if(ui->textEdit_description->toPlainText().length() < 256)
    {
        temp_description = ui->textEdit_description->toPlainText();
        qDebug() << "Description: " << temp_description;
    }
    else
    {
        qDebug() << "Description is too long. Maximum 255 characters long";
        success = false;
    }

    if(temp_quantity = (ui->lineEdit_quantity->text().toInt()))
    {
        qDebug() << "Quantity: " << temp_quantity;
    }
    else
    {
        qDebug() << "Quantity: hasn't a valid value!";
        success = false;
    }

    if(ui->tab->isVisible())
    {
        if(ui->categoryBox_2->currentIndex())
        {
            QList<struct struct_categories>::iterator i;
            int counter = 0;
            int index = ui->categoryBox_2->currentIndex();

            for(i = categories_list.begin(); counter != index-1; i++, counter++);

            qDebug() << i->cat_category;

            temp_category = i->cat_category;
            qDebug() << "Category: " << temp_category;
        }
        else
        {
            qDebug() << "Category is empty!";
            success = false;
        }
    }

    if(ui->tab_2->isVisible())
    {
        /* see if text input is not empty */

        if(!(ui->lineEdit_4->text().isEmpty())) {
            /* check if category already exist in database */
            if(component_db.isNotExistingInDB(ui->lineEdit_4->text())) {
                /* insert new category to database */
                component_db.addCategory(ui->lineEdit_4->text());
            }
            else {
                qDebug("already exist");
            }
        }
    }

    if(success && ui->tab->isVisible()) {
        component_db.addComponent(temp_box, temp_field, temp_description, temp_quantity, temp_category);
        on_clearButton_newComponent_clicked();
    }

    if(success && ui->tab_2->isVisible()) {
        component_db.addComponent(temp_box, temp_field, temp_description, temp_quantity, (ui->lineEdit_4->text()));
        on_clearButton_newComponent_clicked();
    }

}

void MainWindow::on_clearButton_newComponent_clicked()
{
    ui->lineEdit_boxNr->clear();
    ui->lineEdit_fieldNr->clear();
    ui->textEdit_description->clear();
    ui->lineEdit_quantity->clear();
    ui->categoryBox_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    int temp_id = 0;
    int temp_boxNr = 0;
    int temp_fieldNr = 0;
    bool success = true;

    if(temp_id = ui->lineEdit_id_delete->text().toInt())
    {
        qDebug() << "Id: " << temp_id;
    }
    else
    {
        if(temp_id != 0)
            qDebug() << "Id: hasn't a valid value";
    }


    if(temp_boxNr = ui->lineEdit_boxNr_delete->text().toInt())
    {
        qDebug() << "Boxnr: " << temp_boxNr;
    }
    else
    {
        qDebug() << "Boxnr: hasn't a valid value";
        success = false;
    }

    if(temp_fieldNr = ui->lineEdit_fieldNr_delete->text().toInt())
    {
        qDebug() << "Fieldnr: " << temp_fieldNr;
    }
    else
    {
        qDebug() << "Fieldnr: hasn't a valid value";
    }

    if(success)
    {
        if(component_db.deleteComponent(temp_id, temp_boxNr, temp_fieldNr))
        {
            if(temp_id == 0) {
                ui->textBrowser_component_delete->setText("Successfully deleted ALL IDs in:\nBox: " + QString::number(temp_boxNr) + ", Field: " + QString::number(temp_fieldNr));
            }
            else {
                /* successfully deleting a component */
                ui->textBrowser_component_delete->setText("Successfully deleted\n ID: " + QString::number(temp_id) + " Box: " + QString::number(temp_boxNr) + ", Field: " + QString::number(temp_fieldNr));
            }
            /* clear input fields */
            ui->lineEdit_boxNr_delete->clear();
            ui->lineEdit_fieldNr_delete->clear();

        }
        else
        {
            ui->textBrowser_component_delete->setText("ERROR: Couldn't delete\n ID: " + QString::number(temp_id) + " Box: " + QString::number(temp_boxNr) + ", Field: " + QString::number(temp_fieldNr));
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    /* clear input fields */
    ui->lineEdit_id_delete->clear();
    ui->lineEdit_boxNr_delete->clear();
    ui->lineEdit_fieldNr_delete->clear();
}

void MainWindow::on_pushButton_ok_search_by_field_clicked()
{
    QList<struct struct_components> qlist_component_item;
    QList<struct struct_components>::iterator i;

    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

    // clear qlist
    qlist_component_item.clear();



        if(component_db.searchByBoxField(&qlist_component_item,ui->lineEdit_search_boxnr->text().toInt(), ui->lineEdit_search_fieldnr->text().toInt()))
        {
            for(i = qlist_component_item.begin(); i != qlist_component_item.end(); ++i)
            {
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 0, new QTableWidgetItem(QString::number(i->comp_id)));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 1, new QTableWidgetItem(QString::number(i->comp_box)));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 2, new QTableWidgetItem(QString::number(i->comp_field)));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 3, new QTableWidgetItem(i->comp_description));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 4, new QTableWidgetItem(QString::number(i->comp_quantity)));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 5, new QTableWidgetItem(i->comp_spreadsheets));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 6, new QTableWidgetItem(i->comp_category));

            }
        }

}
