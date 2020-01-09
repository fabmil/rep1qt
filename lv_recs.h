#ifndef LV_RECS_H
#define LV_RECS_H

#include <iostream>
#include <unordered_map>

//#include "tag.h"

#include <QDate>
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QProcess>
#include <QProgressBar>
#include <QtCore/QDebug>
#include <QtCore/QMimeData>

//#include <QtCore/QAbstractItemModel>
//#include <QtWidgets/QTreeWidgetItem>
//#include <QtWidgets/QInputDialog>
//#include <QtWidgets/QLineEdit>
//#include <QtWidgets/QPushButton>
//#include <QtWidgets/QHBoxLayout>
//#include <QtGui/QContextMenuEvent>
//#include <QtCore/QModelIndex>

#include <QtGui/QDragEnterEvent>
#include <QtGui/QStandardItemModel>
#include <QtGui/QImage>
#include <QtGui/QPixmap>
#include <QtGui/QMouseEvent>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtWidgets/QLabel>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

class Db;
class Rec;
class MainWindow;
//class Conf;

class LV_Recs : public QListView
{

public:
    MainWindow *parent;
//    Conf *conf;
//    std::string dbfile;
//    QSqlDatabase db;
    Db *db;
//    std::string thumbdir;
    explicit LV_Recs(QWidget *parent = nullptr);
    virtual ~LV_Recs();
    virtual void init(void);

//    int add_imgs(std::vector<Rec> &imgs, int tagid);
    QStandardItemModel *md;

//    QDialog *dia1;
    static QString MyMimeType();

    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void startDrag(Qt::DropActions /*supportedActions*/);
    void mousePressEvent(QMouseEvent *e);
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int> ());

//    void btn_add_lasttag_clicked(void);
//    void btn_add_selected_tags_clicked(void);
//    void btn_copy_date_clicked(void);
//    void btn_remove_tag_clicked(void);
//    void btn_remove_tags_clicked(void);
//    void btn_loadimages_clicked(void);
//    void btn_paste_date_clicked(void);
//    void btn_rotate_clicked(void);
//    void btn_showuntagged_clicked(void);
//    void btn_set_date_clicked(void);

//    void set_date_to_selected(std::string date);
////    void btn_noteedit(void);
//    std::vector<int> get_selected_ids(void);
////    int get_tagid_from_qmi(QModelIndex qmi);
//    void mytest(void);
    void on_doubleClicked(const QModelIndex &index);
//    void refresh_items(std::vector<QStandardItem *> items);
//    void refresh_imgs(std::vector<Rec> imgs);
    void refresh_recs(void);
//    int show_imgs(std::vector<Rec> &imgs, int tagid);
    int show_recs(std::vector<Rec> &imgs);
};

#endif // LV_RECS_H
