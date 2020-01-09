#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include <iostream>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtCore/QDebug>

class Db {
public:
    Db();
    ~Db();
    QSqlDatabase db;
    void init(std::string database, std::string dbname);
    bool open(void);
    void close(void);
};

#endif // DB_H
