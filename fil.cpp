#include "fil.h"

Fil::Fil() {
}

Fil::Fil(const Fil &other) {
    id = other.id;
    des = other.des;
    md5 = other.md5;
}

Fil::~Fil() {
}

void Fil::load_from_query_result(QSqlQuery query) {
    id = query.value(Fil::ID).toInt();
    des = query.value(Fil::DES).toString().toStdString();
    md5 = query.value(Fil::MD5).toString().toStdString();
}
