#ifndef TV_RECS_H
#define TV_RECS_H

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
class Rec;
class MainWindow;

class TV_Recs : public QTreeView
{
//    Q_OBJECT
public:
    explicit TV_Recs(QWidget *parent = nullptr);
    ~TV_Recs();
    void init();

    const int MAX_LEVEL = 7;
    const int MAX_LOADED_FILES = 300;

    MainWindow *parent;
//    QSqlDatabase db;
    Db *db;
    std::string dbfile;
    Conf *conf;
    int COL_REC_ID = 0;
    int COL_REC_DES = 1;

    void refresh_tree();
    void db_reload_tree();

    void add_subtree(std::vector<Rec> recs, Rec rec, QStandardItem *item, int level);
    void add_recs(std::vector<Rec> recs);

    QStandardItemModel *md;
    QDialog *dia_recs;

    void btn_add_child_clicked(void);
    void btn_add_sibling_clicked(void);
    void btn_addrec_clicked(void);
    void btn_addrecchd_clicked(void);
//    void btn_add_chds_to_pad_clicked(void);
//    void btn_addnote_clicked(void);
    void btn_delrec_clicked(void);
    void btn_find_clicked(void);
    void btn_info_clicked(void);
    void btn_makechild_clicked(void);
    void btn_makeinf_clicked(void);
    void btn_makeinfofmarkedrec_clicked(void);
    void btn_makepadofmarkedrec_clicked(void);
    void btn_makeroot_clicked(void);
    void btn_mark_clicked(void);
    void btn_par_choice_clicked(void);
    void btn_paste_clicked(void);
    void btn_removefrompar_clicked(void);
    void btn_renrec_clicked(void);
    void btn_search_clicked(void);
    void btn_load_dir_files(void);
    void btn_load_files(void);
    void btn_test_clicked(void);
    void chk_and_make_inf(Rec par, Rec chd);
    void chk_and_make_inf(Rec par, std::vector<Rec> chds);
//    std::vector<QModelIndex> find_all_recs(std::string s);
    void find_all_recs(std::string rec_find);
    void find_all_sub_recs(std::string rec_find, QModelIndex qmi_par);
    void show_found_rec_n(int n);
    void show_imgs_from_recid(int recid);
    Rec get_parent_tree_rec(QModelIndex qmi_cur);
    std::vector<int> get_selected_ids(void);
    std::vector<Rec> get_selected_recs(void);
    //    std::vector<Rec> get_sel_recs(void);
    int get_selrecs_count(void);
    Rec get_rec_from_QModelIndex(QModelIndex qmi);
    void remove_items_from_par(QModelIndexList chds, QModelIndex par);

    QString MyMimeType();
//    std::string rec_find = "";
//    int show_rec_n = 0;
    Qmis_Found *qfs;

    void copy_rec(void);
    Rec get_marked_rec(void);
//    void cut_rec(Rec marked);
    void add_new_parent(Rec marked, Rec par);

    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void startDrag(Qt::DropActions);

public slots:
    void show_next_found_rec(void);
    void show_prev_found_rec(void);
//    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void myClicked(const QModelIndex &index);
    void myDoubleClicked(const QModelIndex &index);
    void myKeyPressEvent(QKeyEvent *event);
};

#endif // TV_RECS_H
