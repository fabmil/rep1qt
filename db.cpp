#include "db.h"

Db::Db() {
}

Db::~Db() {
}

void Db::init(std::string database, std::string dbname) {
    db = QSqlDatabase::addDatabase(QString::fromStdString(database));
    db.setDatabaseName(QString::fromStdString(dbname));
}

bool Db::open(void) {
    if (db.isOpen()) {
        return(true);
    } else {
        return(db.open());
    }
}

void Db::close(void) {
    db.close();
}
