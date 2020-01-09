#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <unordered_map>

#include <QMainWindow>
//#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtGui/QContextMenuEvent>
#include <QtCore/QModelIndex>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QHostInfo>
#include <QtWidgets/QProgressBar>
#include <QtGui/QDesktopServices>
#include <QtCore/QMimeDatabase>
#include <QtCore/QMimeType>
#include <QtWidgets/QSplitter>
#include <QtGui/QStandardItemModel>

class Conf;
class Db;
class LV_Imgs;
class LV_ImgInfo;
class Tag;
//class TreVieFils;
class TV_Tags;
class Calend;

class MainWindow : public QMainWindow
{
//    Q_OBJECT
private:
    int thumbsize = 128;
    std::string thumbdir = "thumbs";

public:
    Conf *conf;
//    std::unordered_map <std::string, std::string> conf_map;
//    std::string currentdir;
//    std::string dbfile;
//    std::string thumbdir;
//    std::string doc_dir;
//    bool db_copy = false; // if true then make a file copy to internal object storage directory
//    int thumbsize;
    Db *db;
    std::string hostname;

//    QLabel *lbl_seltags_count;
//    LV_Tag *lv_tag;
    QLabel *lbl_seltag;
    LV_ImgInfo *lv_imginfo;

    explicit MainWindow(QMainWindow *parent = 0);
    ~MainWindow();
//    void addTreeRoot(QString name, QString description);
//    TreWidTags *trewid_tags;
    TV_Tags *tv_tags;
//    LstWidObs *lstwid_obs;
//    void on_TreWiditemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_btn_untagged_Clicked();
    void on_btn_refresh_Clicked();
//    void on_trevie_obs_DoubleClicked(const QModelIndex &index);
//    void on_TreVieDoubleClicked(const QModelIndex &index);
//    void on_trw_tags_itemDoubleClicked();
    Tag get_marked_tag(void);
//    void on_trewid_tags_clicked();
//    void on_trw_tags_rightClicked();
    LV_Imgs *lv_imgs;
//    TreVieFils *trevie_fils;

//    Calend *calend;
    // progress bar
    QProgressBar *pb;
    QLabel *lbl_markedtaglbl;
    QLabel *lbl_markedtagid;
    QLabel *lbl_markedtagdes;
    QLabel *lbl_info_nfils_n;
    QLabel *lbl_msg;
    QLabel *lbl_copied_tags;

//    QTreeView *treeView;
//    QStandardItemModel *model_tags;
//    QList<QStandardItem *> prepareRow(const QString &first, const QString &second, const QString &third );
//    void show_tags(std::vector<Tag> tags);
//    bool eventFilter(QObject *target, QEvent *event);

//public slots:
//    void on_trewid_tags_rightClicked(QMouseEvent *e);
//    void on_lv_img_doubleClicked(const QModelIndex &index);

//private slots:
//    void on_treTags_itemDoubleClicked(QTreeWidgetItem *item, int column);
//    void on_treTags_clicked(const QModelIndex &index);
//    void on_treTags_pressed(const QModelIndex &index);
//    void on_treTags_doubleClicked(const QModelIndex &index);
//    void on_treTags_customContextMenuRequested(const QPoint &pos);

//private:
//    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
