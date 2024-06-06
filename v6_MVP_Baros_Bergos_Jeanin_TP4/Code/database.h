#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#define DATABASE_NAME "diapo"
#define SERVER_NAME "lakartxela.iutbayonne.univ-pau.fr"
#define USERNAME "abaros_bd"
#define PASSWORD "abaros_bd"
#define CONNECT_TYPE "QODBC"


class database
{
public:
    database();
    QSqlDatabase bd;


    // base de données
    bool openDataBase();
    void closeDataBase();
};

#endif // DATABASE_H
