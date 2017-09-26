#include "dbmanager.h"
#include <QDebug>
#include <QSqlQuery>

DbManager::DbManager(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

}

bool DbManager::searchByBoxField(QList<struct struct_components> *component, int boxnr, int fieldnr)
{
    bool success = false;
    struct struct_components temp;

    QSqlQuery query;

    qDebug() << "Calling DbManager::searchByBoxField(struct struct_components* component, int boxnr, int fieldnr)";


    query.prepare("SELECT Components.id, Components.box, Components.field, Components.description, Components.quantity, Components.datasheet, Categories.category FROM Components, Categories WHERE Components.box=(:boxnr) AND Components.field=(:fieldnr) AND Components.category = Categories.id");
    query.bindValue(":boxnr", boxnr);
    query.bindValue(":fieldnr", fieldnr);

    if(query.exec())
    {
        success = true;
        while(query.next())
        {
            qDebug() << "ID: " << query.value(0) << " Box: " << query.value(1) << "Field: " << query.value(2) << " Description: " << query.value(3) << " Quantity: " << query.value(4) << " Datasheets: " << query.value(5) << " Category: " << query.value(6);
            temp.comp_id  = query.value(0).toInt();
            temp.comp_box = query.value(1).toInt();
            temp.comp_field = query.value(2).toInt();
            temp.comp_description = query.value(3).toString();
            temp.comp_quantity = query.value(4).toInt();
            temp.comp_spreadsheets = query.value(5).toString();
            temp.comp_category = query.value(6).toString();
            component->append(temp);
        }



   }
    return success;
}


bool DbManager::searchByCategory(QList<struct struct_components> *component, int id)
{

    bool success = false;
    struct struct_components temp;

    QSqlQuery query;

    qDebug() << "Calling DbManager::searchByCategory(struct struct_components* component)";
    qDebug() << "id: " << id;

    query.prepare("SELECT Components.id, Components.box, Components.field, Components.description, Components.quantity, Components.datasheet, Categories.category FROM Components, Categories WHERE Categories.id=(:id) AND Components.category = Categories.id");
    query.bindValue(":id", id);

    if(query.exec())
    {
        success = true;
        while(query.next())
        {
            qDebug() << "ID: " << query.value(0) << " Box: " << query.value(1) << " Field: " << query.value(2) << " Description: " << query.value(3) << " Quantity: " << query.value(4) << " Datasheets: " << query.value(5) << " Category: " << query.value(6);
            temp.comp_id  = query.value(0).toInt();
            temp.comp_box = query.value(1).toInt();
            temp.comp_field = query.value(2).toInt();
            temp.comp_description = query.value(3).toString();
            temp.comp_quantity = query.value(4).toInt();
            temp.comp_spreadsheets = query.value(5).toString();
            temp.comp_category = query.value(6).toString();
            component->append(temp);
        }



   }
    return success;

}

bool DbManager::getCategories(QList<struct struct_categories> *categories)
{
    bool success = false;
    struct_categories category;

    QSqlQuery query;

    categories->clear();

    qDebug() << "Calling DbManager::getCategories(QList<QString> *categories)";

    query.prepare("SELECT id, category FROM Categories ORDER BY category");

    if(query.exec())
    {
        success = true;
        while(query.next())
        {
            qDebug() << "id: " << query.value(0) << " category: " << query.value(1);
            category.cat_id = query.value(0).toInt();
            category.cat_category = query.value(1).toString();
            categories->append(category);
        }
    }


    return success;
}

bool DbManager::addComponent(int boxnr, int fieldnr, const QString& description, int quantity, const QString& category)
{
    bool success = false;

    QSqlQuery query;
    int id = 0;
    int category_id = 0;

    qDebug() << "Calling DbManager::addComponent(int boxnr, int fieldnr, const QString description, int quantity, const QString& category)";



    query.prepare("SELECT id FROM Components ORDER BY id DESC LIMIT 1");

    if(query.exec())
    {
        success = true;
        query.first();

        qDebug() << query.value(0).toInt();
        id = query.value(0).toInt();

        id++;

        qDebug() << "ID: " << id;

        query.clear();

        query.prepare("SELECT id FROM Categories WHERE category=(:cat) LIMIT 1");
        query.bindValue(":cat", category);


        if(query.exec())
        {
            success = true;
            query.next();
            category_id = query.value(0).toInt();

            qDebug() << "Category ID: " << category_id;

            query.clear();

        }
        else
        {
            success = false;
        }

        if(success) {
            query.prepare("INSERT INTO Components (id, box, field, description, quantity, datasheet, category) VALUES ((:id), (:box), (:field), (:desc), (:quant), (:data), (:cat)) ");
            query.bindValue(":id", id);
            query.bindValue(":box", boxnr);
            query.bindValue(":field", fieldnr);
            query.bindValue(":desc", description);
            query.bindValue(":quant", quantity);
            query.bindValue(":data", 1);
            query.bindValue(":cat", category_id);

            if(query.exec())
            {
                success = true;
                qDebug() << "Record inserted";

                query.prepare("UPDATE Categories SET used_by = used_by +1 WHERE id=(:id)");
                query.bindValue(":id", category_id);

                if(query.exec()) {
                    success = true;
                    qDebug() << "Updated used_by column in Categories";
                }
            }

        }

    }
    return success;
}

bool DbManager::deleteComponent(int id, int boxnr, int fieldnr)
{
    struct struct_category {
        int cat_id;
        int cat_sum;
        int cat_total;
    };
    struct struct_category temp_category;
    QList<struct struct_category>struct_categories;

    bool success = false;

    QSqlQuery query;

    qDebug() << "Calling DbManager::deleteComponent(int id, int boxnr, int fieldnr)";



    if(id == 0) {
        qDebug() << "Get alla category ids";
        /* get all id:s to know if any category needs to be deleted
         * (no components will use it)*/
        query.prepare("SELECT category, COUNT(category) FROM Components WHERE box=(:boxnr) AND field=(:fieldnr) GROUP BY category");
        query.bindValue(":boxnr", boxnr);
        query.bindValue(":fieldnr", fieldnr);
    }

    else {
        qDebug() << "Get one category id";
        query.prepare("SELECT category, COUNT(category) FROM Components WHERE id=(:id)");
        query.bindValue(":id", id);
    }



    if(query.exec()) {
        qDebug() << "query.exec()";
        while(query.next()) {
            temp_category.cat_id = query.value(0).toInt();
            temp_category.cat_sum = query.value(1).toInt();
            struct_categories.append(temp_category);
            qDebug() << "temp_category.cat_id = " << temp_category.cat_id;
            qDebug() << "temp_category.cat_sum = " << temp_category.cat_sum;

        }
        success = true;
    }


    /* get total components using the specific category in the db */
    QList<struct struct_category>::Iterator i;
    for(i = struct_categories.begin(); i != struct_categories.end(); ++i) {
        qDebug() << "i->cat_id: " << i->cat_id;
        qDebug() << "i->cat_sum: " << i->cat_sum;

        query.prepare("SELECT COUNT(category) FROM Components WHERE category=(:category)");

        query.bindValue(":category", i->cat_id);

        if(query.exec()) {
            query.next();
            qDebug() << "query.exec()";
           qDebug() << "query.value(0): " << query.value(0).toInt();
           i->cat_total = query.value(0).toInt();
           qDebug() << "i->cat_total: " << i->cat_total;
        }
    }


    if(id == 0) {
        query.prepare("DELETE FROM Components WHERE box=(:boxnr) AND field=(:fieldnr)");
        query.bindValue(":boxnr", boxnr);
        query.bindValue(":fieldnr", fieldnr);
    }

    else {
        query.prepare("DELETE FROM Components WHERE id=(:id)");
        query.bindValue(":id", id);
    }

    /* delete components */
    if(query.exec()) {
        qDebug() << "query.exec() delete components";
        success = true;
    }
    else {
        success = false;
    }

    if(success) {
        qDebug() << "success";
        /* delete categories if no components use it anymore */
       for(i = struct_categories.begin(); i != struct_categories.end(); ++i) {
           if(i->cat_sum == i->cat_total) {
               query.prepare("DELETE FROM Categories WHERE id=(:id)");

               query.bindValue(":id", i->cat_id);

               if(query.exec()) {
                   qDebug() << "Deleting category";
                   success = true;
               }
               else {
                   success = false;
               }
           }
       }
    }

    struct_categories.clear();

    return success;
}

bool DbManager::isNotExistingInDB(const QString &category) {

    QSqlQuery query;
    query.prepare("SELECT COUNT(id) FROM Categories WHERE category=(:category)");
    query.bindValue(":category", category.toLower());

    if(query.exec()) {
        query.next();

        return ((!!query.value(0).toInt())?false : true);
    }
}

bool DbManager::addCategory(const QString &category) {

    bool success = false;
    QSqlQuery query;
    int id = 0;
    query.prepare("SELECT id FROM Categories ORDER BY id DESC LIMIT 1");

    if(query.exec())
    {
        success = true;
        query.first();

        qDebug() << query.value(0).toInt();
        id = query.value(0).toInt();

        id++;

        qDebug() << "ID: " << id;

        query.clear();

        query.prepare("INSERT INTO Categories (id, category, used_by) VALUES ((:id), (:category), (:used_by))");
        query.bindValue(":id", id);
        query.bindValue(":category", category.toLower());
        query.bindValue(":used_by", 0);


        if(query.exec())
        {
            success = true;

            qDebug() << "Inserted new category: " << category.toLower();



        }
        else
        {
            success = false;
        }
    }
    return success;
}


DbManager::~DbManager()
{
    m_db.close();
}
