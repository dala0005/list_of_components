#ifndef CONN_H
#define CONN_H

#include <QSqlDatabase>

class Conn : public QMainWindow
{
    Q_OBJECT

    public:
        QSqlDatabase mydb;
}
#endif // CONN_H
