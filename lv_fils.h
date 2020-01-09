#ifndef LV_FILS_H
#define LV_FILS_H

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
class Fil;
class MainWindow;
class Conf;

class LV_Fils : public QListView
{
//    Q_OBJECT

public:
    MainWindow *parent;
    Conf *conf;
//    std::string dbfile;
//    QSqlDatabase db;
    Db *db;
//    std::string thumbdir;
    explicit LV_Fils(QWidget *parent = nullptr);
    ~LV_Fils();
    void init(void);

//    int add_imgs(std::vector<Img> &imgs, int tagid);
    QStandardItemModel *model;

//    int thumbsize = 32;
    std::unordered_map <std::string, QPixmap> qpixmap_thumb;

    QDialog *dia1;
    static QString MyMimeType();

    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int> ());
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void startDrag(Qt::DropActions /*supportedActions*/);

    void btn_add_lasttag_clicked(void);
    void btn_add_selected_tags_clicked(void);
    void btn_copy_date_clicked(void);
    void btn_remove_tag_clicked(void);
    void btn_remove_tags_clicked(void);
    void btn_loadimages_clicked(void);
    void btn_paste_date_clicked(void);
    void btn_rotate_clicked(void);
    void btn_showuntagged_clicked(void);
    void btn_set_date_clicked(void);

    void set_date_to_selected(std::string date);
//    void btn_noteedit(void);
    std::vector<int> get_selected_ids(void);
//    int get_tagid_from_qmi(QModelIndex qmi);
    void mytest(void);
    void on_lv_img_doubleClicked(const QModelIndex &index);
//    void refresh_items(std::vector<QStandardItem *> items);
//    void refresh_imgs(std::vector<Img> imgs);
    void refresh_imgs(void);
//    int show_imgs(std::vector<Img> &imgs, int tagid);
    int show_imgs(std::vector<Fil> &imgs);
};

#endif // LV_FILS_H
