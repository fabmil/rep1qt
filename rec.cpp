#include "rec.h"

Rec::Rec() {
}

Rec::Rec(const Rec &other) {
    id = other.id;
    des = other.des;
    md5 = other.md5;
}

Rec::~Rec() {
}

void Rec::load_from_query_result(QSqlQuery query) {
    id = query.value(Rec::ID).toInt();
    des = query.value(Rec::DES).toString().toStdString();
    md5 = query.value(Rec::MD5).toString().toStdString();
}
