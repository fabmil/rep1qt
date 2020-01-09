#ifndef TV_TAGS_H
#define TV_TAGS_H

#include <iostream>
#include <vector>
#include <unordered_map>

#include <QDialog>
#include <QMainWindow>

#include <QtGui/QDrag>
#include <QtGui/QMouseEvent>
#include <QtGui/QStandardItemModel>

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QListWidgetItem>

#include <QtCore/QItemSelectionModel>
#include <QtCore/QPersistentModelIndex>
#include <QtCore/QMimeData>

//#include <QtCore/QAbstractItemModel>
//#include <QtWidgets/QTreeWidgetItem>
//#include <QtWidgets/QInputDialog>
//#include <QtWidgets/QLineEdit>

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>

//#include <QtGui/QContextMenuEvent>
//#include <QtCore/QModelIndex>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

//#include <QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenu>


class Conf;
class Db;
class Qmis_Found;
class Tag;
class MainWindow;

class TV_Tags : public QTreeView
{
//    Q_OBJECT
public:
    explicit TV_Tags(QWidget *parent = nullptr);
    ~TV_Tags();
    void init();

    const int MAX_LEVEL = 7;
    const int MAX_LOADED_FILES = 300;

    MainWindow *parent;
//    QSqlDatabase db;
    Db *db;
    std::string dbfile;
    Conf *conf;
    int COL_TAG_ID = 0;
    int COL_TAG_DES = 1;
//    void load(std::vector<Tag> tags, std::vector<TagSupInf> tsis);
//    void add_rootitem(QString name, QString description);
//    void add_rootitem(Tag tag);
//    void add_rootitems(std::vector<Tag> tags);

    void refresh_tree();
    void db_reload_tree();

//    void add_subtree2(QStandardItem *item_sup, Tag tag, int level);
//    void add_subtree(Tag toptag);
//    void add_alltags(std::vector<Tag> tags);
    void add_subtree(std::vector<Tag> tags, Tag tag, QStandardItem *item, int level);
//    void add_tags(std::vector<Tag> tags);
    void add_tags(std::vector<Tag> tags);

//    void add_subtree2_map(QStandardItem *sup_item, std::unordered_map<int,Tag> map_tags, Tag sup, int level);
//    void add_subtree_map(std::unordered_map<int,Tag> map_tags, Tag map_toptag);
//    void add_alltags_map(std::unordered_map<int,Tag> map_tags);

//    void add_tgs_subtree(std::vector<Tgs> tgss, Tgs tgs, QStandardItem *item, int level);
//    void add_tgss(std::vector<Tgs> tgss);

//    void show_childs(std::vector<Tag> tags, std::vector<TagSupInf> tsis, Tag tagsup, QStandardItem *sup_item, int level);
//    void add_tags(std::vector<Tag> tags);
//    void clear(void);
    QStandardItemModel *md;
    QDialog *dia_tags;

    void btn_add_child_clicked(void);
    void btn_add_sibling_clicked(void);
    void btn_addtag_clicked(void);
    void btn_addtagchd_clicked(void);
//    void btn_add_chds_to_pad_clicked(void);
//    void btn_addnote_clicked(void);
    void btn_deltag_clicked(void);
    void btn_find_clicked(void);
    void btn_info_clicked(void);
    void btn_makechild_clicked(void);
    void btn_makeinf_clicked(void);
    void btn_makeinfofmarkedtag_clicked(void);
    void btn_makepadofmarkedtag_clicked(void);
    void btn_makeroot_clicked(void);
    void btn_mark_clicked(void);
    void btn_par_choice_clicked(void);
    void btn_paste_clicked(void);
    void btn_removefrompar_clicked(void);
    void btn_rentag_clicked(void);
    void btn_search_clicked(void);
    void btn_load_dir_files(void);
    void btn_load_files(void);
    void btn_test_clicked(void);
    void chk_and_make_inf(Tag par, Tag chd);
    void chk_and_make_inf(Tag par, std::vector<Tag> chds);
//    std::vector<QModelIndex> find_all_tags(std::string s);
    void find_all_tags(std::string tag_find);
    void find_all_sub_tags(std::string tag_find, QModelIndex qmi_par);
    void show_found_tag_n(int n);
    void show_imgs_from_tagid(int tagid);
    Tag get_parent_tree_tag(QModelIndex qmi_cur);
    std::vector<int> get_selected_ids(void);
    std::vector<Tag> get_selected_tags(void);
    //    std::vector<Tag> get_sel_tags(void);
    int get_seltags_count(void);
    Tag get_tag_from_QModelIndex(QModelIndex qmi);
    void remove_items_from_par(QModelIndexList chds, QModelIndex par);

    QString MyMimeType();
//    std::string tag_find = "";
//    int show_tag_n = 0;
    Qmis_Found *qfs;


    void copy_tag(void);
    Tag get_marked_tag(void);
//    void cut_tag(Tag marked);
    void add_new_parent(Tag marked, Tag par);


    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void startDrag(Qt::DropActions);

public slots:
    void show_next_found_tag(void);
    void show_prev_found_tag(void);
//    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void myClicked(const QModelIndex &index);
    void myDoubleClicked(const QModelIndex &index);
    void myKeyPressEvent(QKeyEvent *event);
//    void tagfind_test(void);

//    void myDoubleClicked(const QModelIndex &index);
//    void mySelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);


//    void show_tags(std::vector<Tag> tags);
//    bool eventFilter(QObject *target, QEvent *event);

//private slots:
//    void on_treTags_itemDoubleClicked(QTreeWidgetItem *item, int column);

//    void on_treTags_clicked(const QModelIndex &index);

//    void on_treTags_pressed(const QModelIndex &index);

//    void on_treTags_doubleClicked(const QModelIndex &index);

//    void on_treTags_customContextMenuRequested(const QPoint &pos);

//private:
//    Ui::MainWindow *ui;
};

#endif // TV_TAGS_H
