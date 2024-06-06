#include "database.h"
#include <QDebug>
database::database()
{ 
    bd = QSqlDatabase::addDatabase(CONNECT_TYPE);
    bd.setHostName(SERVER_NAME);
    bd.setDatabaseName(DATABASE_NAME);
    bd.setUserName(USERNAME);
    bd.setPassword(PASSWORD);

    qDebug() << "Configuration de la connexion :" << bd.lastError().text();
}


bool database::openDataBase()
{
    if (!bd.open()) {
        qDebug() << "Connection échouée";
        return false;
    } else {
        qDebug() << "Connection réussie";
        return true;
    }
}

void database::closeDataBase()
{
    bd.close();
}


