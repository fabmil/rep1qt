#ifndef TAG_H
#define TAG_H

#include <string>
#include <vector>
#include <iostream>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtCore/QDebug>

class Db;
//class Err;

class Tag {
public:
    Tag();
    Tag(const Tag &t);
    Tag(int id, const std::string des);
    ~Tag();
    int id;
    std::string des;
    static const int TREE_ROOT_ID = -1;
//    Db *db;

//    int sup;
//    static int parse(std::string s);
    static Tag parse_id_space_des(std::string s);
    static std::string to_string(std::vector<Tag> tags);
    std::string to_string(void);
    void add_par(Db *db, int par_id);
    void add_par(Db *db, Tag par);
    bool find_chd_des(Db *db, std::string des);

//    std::vector<Tag> db_get_pars(Db *db, Err &err);
//    std::vector<Tag> db_get_pars(Db *db);
//    std::vector<Tag> db_get_chds(Db *db);
//    std::vector<Tag> db_get_tag_chain(Db *db);

//    int get_tagsupid(std::vector<TagSupInf> tt, int tagid_inf);
//    std::vector<int> get_taginf(std::vector<TagSupInf> tt, Tag tagsup);
};

#endif // TAG_H
