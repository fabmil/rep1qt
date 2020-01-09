#include "tag.h"
#include "db.h"
#include <exception>
#include "myex.h"

Tag::Tag() {
    id = TREE_ROOT_ID;
    des = "";
}

Tag::Tag(const Tag &t) {
    id = t.id;
    des = t.des;
}

Tag::~Tag() {
}

Tag Tag::parse_id_space_des(std::string s) {
    Tag tag;
    int j = s.find(" ");
    tag.id = std::stoi(s.substr(0,j));
    tag.des = s.substr(j+1);
    return(tag);
}

std::string Tag::to_string(void) {
    std::string s = "";
    s = std::to_string(id);
    s += ":";
    s += des;
    return(s);
}

std::string Tag::to_string(std::vector<Tag> tags) {
    std::string s = "";
    int j = 0;
    for (Tag t : tags) {
        if (j>0) {
            s += "|";
        }
        s += t.to_string();
        j++;
    }
    return(s);
}

void Tag::add_par(Db *db, int par_id) {
}

/*
 * Add parent tag
 */
void Tag::add_par(Db *db, Tag par) {
    if (! db->open()) {
        throw MyEx(__LINE__, __FILE__);
    }
    QSqlQuery query;
    // test if already exists
    query.prepare("SELECT * FROM tagparchd WHERE par=? and chd=?");
    query.addBindValue(par.id);
    query.addBindValue(id);
    if (!query.exec()) {
        throw MyEx(__LINE__, __FILE__);
    }
    if (query.first()) {
        // record already exists, do nothing
        db->close();
        return;
    }
    query.prepare("INSERT INTO tagparchd (par, chd) values (?,?)");
    query.addBindValue(par.id);
    query.addBindValue(id);
    if (!query.exec()) {
        throw MyEx(__LINE__, __FILE__);
    }
    db->close();
}

/*
 * Check if child - tag.des exists
 */
bool Tag::find_chd_des(Db *db, std::string des) {
    if (! db->open()) {
        throw MyEx(__LINE__, __FILE__);
    }
    QSqlQuery query;
    query.prepare("SELECT chd FROM tagparchd WHERE par=? AND chd IN (SELECT id FROM tag WHERE des=?)");
    query.addBindValue(QString::number(id));
    query.addBindValue(QString::fromStdString(des));
    if (!query.exec()) {
        throw MyEx(__LINE__, __FILE__);
    }
    if (query.first()) {
        // record already exists, do nothing
        db->close();
        return(true);
    }
    return(false);
}

//std::vector<Tag> Tag::db_get_pars(Db *db, Err &err) {

//    std::vector<Tag> tags;

//    if (! db->open()) {
//        db->errgest(err, __LINE__, __FILE__);
//        return(tags);
//    }
//    QSqlQuery query;
//    query.prepare("SELECT id,des FROM tag WHERE id in (SELECT par FROM tagparchd WHERE chd=?) ORDER BY des COLLATE NOCASE ASC");
//    query.addBindValue(id);
//    if (!query.exec()) {
//        db->errgest(err, __LINE__, __FILE__);
//        return(tags);
//    }

//    while(query.next()) {
//        Tag tag;
//        tag.id = query.value(0).toInt();
//        tag.des = query.value(1).toString().toStdString();
//        tags.push_back(std::move(tag));
//    }

//    db->close();
//    return(tags);
//}


