#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>

struct struct_components {
    int comp_id;
    int comp_box;
    int comp_field;
    QString comp_description;
    int comp_quantity;
    QString comp_spreadsheets;
    QString comp_category;

};

struct struct_categories {
    int cat_id;
    QString cat_category;
};

class DbManager
{
public:
    DbManager(const QString& path);
    ~DbManager();
    bool searchByBoxField(QList<struct struct_components> *component, int boxnr, int fieldnr);
    bool searchByCategory(QList<struct struct_components> *component, int id);
    bool getCategories(QList<struct struct_categories> *categories);
    bool addComponent(int boxnr, int fieldnr, const QString& description, int quantity, const QString& category);
    bool deleteComponent(int id, int boxnr, int fieldnr);
    bool isNotExistingInDB(const QString &category);
    bool addCategory(const QString &category);
private:
    QSqlDatabase m_db;

};

#endif // DBMANAGER_H
