#ifndef FIL_H
#define FIL_H

#include <iostream>
#include <string>
#include <vector>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtCore/QDebug>

#include "rec.h"

class Fil : public Rec
{
public:
    Fil();
    Fil(const Fil &other);
    ~Fil();
//    int id;
//    std::string des;
//    std::string md5;
//    std::string note;
//    std::string rotate;
//    std::string dat;
//    int tagid;
//    std::vector<Tag> tags;
//    int type;
    static const int ID = 0;
    static const int DES = 1;
    static const int MD5 = 2;
//    static const int NOTE = 3;
//    static const int ROTATE = 3;
//    static const int DAT = 4;
//    void load_from_query_result(QSqlQuery query);
};

#endif // FIL_H
