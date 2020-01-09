#ifndef REC_H
#define REC_H

#include <iostream>
#include <string>
#include <vector>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtCore/QDebug>

class Rec {
public:
    Rec();
    Rec(const Rec &other);
    virtual ~Rec()=0;
    int id;
    std::string des;
    std::string md5;
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
    virtual void load_from_query_result(QSqlQuery query);
};

#endif // REC_H
