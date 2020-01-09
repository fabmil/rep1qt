#include "mainwindow.h"

#include <chrono>
#include <thread>
#include <boost/filesystem.hpp>

#include <QtCore/QDir>

#include "Magick++.h"

//#include "conf.h"
#include "db.h"
//#include "db_get_untagged_imgs.h"
//#include "db_get_tags.h"
//#include "db_tools.h"
//#include "img.h"
//#include "lv_imginfo.h"
//#include "lv_imgs.h"
//#include "lv_tag.h"
#include "mydebug.h"
#include "myex.h"
#include "tag.h"
#include "tv_tags.h"

MainWindow::MainWindow(QMainWindow *parent) :
    QMainWindow(parent)
{
////    QString cp = QDir::currentPath();
////    currentdir = cp.toStdString();

//////    // ----------------------
//////    // default values
//////    // ----------------------
//    conf = new Conf();
//    conf->map_conf["conf_filename"] = "conf.txt";
//    conf->map_conf["app_pathdir"] = "/home/fab/prj/tagqt8";


//    boost::filesystem::path boost_conf_file(conf->map_conf["app_pathdir"]);
//    boost_conf_file /= conf->map_conf["conf_filename"];
//    // read conf file
////    if (! rd_conf("/home/fab/prj/tagqt8/conf.txt", conf)) {
////        // error in configuration file, quit
////        return;
////    }
//    if (! conf->rd("./conf.txt")) {
//        // error in configuration file, quit
//        return;
//    }

//    boost::filesystem::path boost_thumbdir(conf->map_conf["app_pathdir"]);
////    conf->map_conf["thumbsize"] = "128";
////    thumbsize = 128;
////    boost_thumbdir /= "thumbs";

////    mydebug2(__LINE__,__FILE__);
////    exit(1);

    // create thumbs dir
    if (! boost::filesystem::is_directory(thumbdir)) {
        // dir not exists ... create
        if (boost::filesystem::create_directory(thumbdir)) {
            std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
            std::cerr << "Directory Created: " << conf->map_conf["thumbdir"] << std::endl;
        } else {
            // cannot create dir ... quit
            std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
            std::cerr << "ERR - dir not created: " << conf->map_conf["thumbdir"] << std::endl;
            return;
        }
    }

//    boost_thumbdir /= conf->map_conf["thumbsize"] + "x" + conf->map_conf["thumbsize"];
////    boost::filesystem::path pathdir2 = pathdir / dir2;
////    std::cout << pathdir2 << std::endl;
//    conf->map_conf["thumbdir"] = boost_thumbdir.string();


//    // FILMD5 pathdir
//    std::string filmd5_pathdir = conf->map_conf["app_pathdir"] + "/" + conf->map_conf["filmd5_dir"];
//    conf->map_conf["filmd5_pathdir"] = filmd5_pathdir;

//    // ICONS
//    boost::filesystem::path boost_icons_dir(conf->map_conf["app_pathdir"]);
//    boost_icons_dir /= conf->map_conf["icons_dir"];
//    conf->map_conf["icons_pathdir"] = boost_icons_dir.string();

//    // DB
//    boost::filesystem::path boost_dbfile(conf->map_conf["app_pathdir"]);
//    boost_dbfile /= "tag12.db";
//    conf->map_conf["dbfile"] = boost_dbfile.string();
//    //    db = QSqlDatabase::addDatabase("QSQLITE");
//    //    db->setDatabaseName(conf->map_conf["dbfile"].c_str());
//    db = new Db();
//    db->init("QSQLITE", conf->map_conf["dbfile"].c_str());


////    // THUMB
////    thumbsize = 92;
////    std::ostringstream thumbdirsize;
////    thumbdirsize << "/home/fab/prj/tagqt8/thumbs/";
////    thumbdirsize << thumbsize << "x" << thumbsize;
////    std::string thumbdirsize = thumbdirsize.str();

//    // THUMB dir create
////    const char* path = thumbdir.c_str();
////    boost::filesystem::path boost_thumbdir(thumbdir);
//    if (! boost::filesystem::is_directory(boost_thumbdir)) {
//        // dir not exists ... create
//        if (boost::filesystem::create_directory(boost_thumbdir)) {
//            std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//            std::cerr << "Directory Created: " << conf->map_conf["thumbdir"] << std::endl;
//        } else {
//            // cannot create dir ... quit
//            std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//            std::cerr << "ERR - dir not created: " << conf->map_conf["thumbdir"] << std::endl;
//            return;
//        }
//    }

//    // HOSTNAME
//    QString hn = QHostInfo::localHostName();
//    hostname = hn.toStdString();
////    std::cerr << hostname << std::endl;




//    // LAYOUT
////    QHBoxLayout *mainlayout = new QHBoxLayout;

//    QVBoxLayout *vlay_main = new QVBoxLayout;
//    QHBoxLayout *hlay_tags_imgs = new QHBoxLayout;

//    QSplitter *vsplit_main = new QSplitter;
//    vsplit_main->setOrientation(Qt::Vertical);

//    QSplitter *hsplit_tags_imgs = new QSplitter;
//    hsplit_tags_imgs->setOrientation(Qt::Horizontal);

////    // ----------------
////    // -- Info line - selected tags count
////    // ----------------
////    lbl_seltags_count = new QLabel();


//    /*
//     * -------------------
//     * Tags Treeview
//     * -------------------
//     */
//    std::vector<Tag> tags;
//    try {
//        tags = db_get_tags(db);
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }
//    tv_tags = new TV_Tags(this);
//    tv_tags->db = db;
//    tv_tags->add_tags(tags);
//    tv_tags->conf = conf;
//    tv_tags->expandAll();


//    QSplitter *vsplit_tags = new QSplitter;
//    vsplit_tags->setOrientation(Qt::Vertical);

//    lbl_seltag = new QLabel();//    lv_tag = new LV_Tag();

//    vsplit_tags->addWidget(tv_tags);
//    vsplit_tags->addWidget(lbl_seltag);
//    vsplit_tags->setStretchFactor(0, 1);
//    vsplit_tags->setStretchFactor(1, 0);

////    split_tags_fils->addWidget(trevie_tags);
//    hsplit_tags_imgs->addWidget(vsplit_tags);
//    hlay_tags_imgs->addWidget(hsplit_tags_imgs);


//    /*
//     * -------------------
//     * Thumbnails Listview
//     * -------------------
//     */
//    lv_imgs = new LV_Imgs(this);
////    lstvie_obs->setViewMode(QListWidget::IconMode);
////    lstvie_obs->setIconSize(QSize(200,200));
////    lstvie_obs->setResizeMode(QListWidget::Adjust);
//    lv_imgs->init();
////    QStandardItemModel *model = new QStandardItemModel(lv_imgs);
////    lv_imgs->setModel(model);
////    lv_imgs->model = model;
////    lv_imgs->setViewMode(QListView::IconMode);
////    lv_imgs->setAcceptDrops(true);

//    lv_imgs->conf = conf;
//    lv_imgs->setSpacing(8);
//    lv_imgs->db = db;

////    connect(lv_imgs, SIGNAL(clicked(QModelIndex)), this, SLOT(on_lv_img_doubleClicked(QModelIndex)));
////    connect(lv_imgs, &LV_Imgs::doubleClicked, this, &MainWindow::on_lv_img_doubleClicked);
////        connect(lv_imgs, &LV_Imgs::doubleClicked, this, &abc);
////        connect(lv_imgs, &LV_Imgs::doubleClicked, this, &MainWindow::on_lv_img_doubleClicked);
//    connect(lv_imgs, &LV_Imgs::doubleClicked, lv_imgs, &LV_Imgs::on_lv_img_doubleClicked);

////    QSplitter *split_imgs = new QSplitter;
////    split_imgs->setOrientation(Qt::Vertical);

////    lbl_date = new QLabel();

////    split_imgs->addWidget(lv_imgs);
////    split_imgs->addWidget(lbl_date);
////    split_imgs->setStretchFactor(0, 1);
////    split_imgs->setStretchFactor(1, 0);


//    QSplitter *hsplit_imgs = new QSplitter;
////    vsplit_imgs->setOrientation(Qt::Vertical);
//    hsplit_imgs->setOrientation(Qt::Horizontal);
////    lbl_imgdate = new QLabel("lbl_imgdate");
////    QString lbl_css = "QLabel { background-color : red; color : blue; }";
////    lbl_imgdate->setStyleSheet("QLabel { background-color : red; color : blue; }");
////    lbl_imgdate->setStyleSheet(lbl_css);
//    hsplit_imgs->addWidget(lv_imgs);

//    lv_imginfo = new LV_ImgInfo();
//    lv_imginfo->init();

////    QWidget *wid_img_info = new QWidget;
////    QHBoxLayout *hlay_img_info = new QHBoxLayout;
////    wid_img_info->setLayout(hlay_img_info);
////    lbl_imgtag1 = new QLabel("lbl_imgtag1");
////    lbl_imgtag1->setStyleSheet(lbl_css);
////    hlay_img_info->addWidget(lbl_imgdate);
////    hlay_img_info->addWidget(lbl_imgtag1);
////    hlay_img_info->addStretch(1);
//    hsplit_imgs->addWidget(lv_imginfo);

//    hsplit_imgs->setStretchFactor(0, 1);
//    hsplit_imgs->setStretchFactor(1, 0);

//    hsplit_tags_imgs->addWidget(hsplit_imgs);
//    hsplit_tags_imgs->setStretchFactor(0, 0);
//    hsplit_tags_imgs->setStretchFactor(1, 1);

///*
// * LAYOUT
// *
// * QWidget *window
// *   QVBoxLayout *vlay_main
// *     QSplitter *vsplit_main
// *       QWidget *wid_tags_imgs
// *         QHBoxLayout *hlay_tags_imgs
// *           QSplitter *hsplit_tags_imgs
// *             QSplitter *vsplit_tags
// *               tv_tags = new TV_Tags(this);
// *               lbl_seltag = new QLabel();
// *             QSplitter *hsplit_imgs
// *               lv_imgs = new LV_Imgs(this);
// *               lv_imginfo = new QListView();
// *       QWidget *wid_info
// *         QVBoxLayout *vlay_btns_info
// *           QHBoxLayout *hlay_btns
// *             lbl_markedtagid = new QLabel();
// *             lbl_markedtagdes = new QLabel();
// *             lbl_msg = new QLabel();
// *             lbl_copied_tags = new QLabel();
// *           pb = new QProgressBar();
// *           QHBoxLayout *hlay_info
// *             QLabel *lbl_info_tagssize = new QLabel();
// *             QLabel *lbl_info_nfils_lbl = new QLabel("num fils:");
// *             lbl_info_nfils_n = new QLabel();
// *
// */




//    // ----------------
//    // Info frame
//    // ----------------
//    QVBoxLayout *vlay_btns_info = new QVBoxLayout;
//    QHBoxLayout *hlay_info = new QHBoxLayout;

//    // ----------------
//    // -- Buttons
//    // ----------------
//    QHBoxLayout *hlay_btns = new QHBoxLayout;

////    /*
////     * Refresh treeview
////     */
////    QPushButton *btn_refresh = new QPushButton("refresh");
////    btn_refresh->setStyleSheet("QPushButton:hover { color : red }");
////    hbox_btns->addWidget(btn_refresh);

////    QPushButton *btn_untagged = new QPushButton("untagged");
////    hbox_btns->addWidget(btn_untagged);

////    lbl_markedtaglbl = new QLabel();
////    lbl_markedtaglbl->setText("marked tag");
//////    lbl_markedtaglbl->setStyleSheet("QLabel { background-color : blue; color : white; }");
////    hbox_btns->addWidget(lbl_markedtaglbl);

//    lbl_markedtagid = new QLabel();
//    lbl_markedtagid->setText("");
////    lbl_markedtagid->setStyleSheet("QLabel { background-color : blue; color : white; }");
//    hlay_btns->addWidget(lbl_markedtagid);

//    lbl_markedtagdes = new QLabel();
//    lbl_markedtagdes->setText("");
////    lbl_markedtagid->setStyleSheet("QLabel { background-color : green; color : white; }");
//    hlay_btns->addWidget(lbl_markedtagdes);

//    lbl_msg = new QLabel();
//    lbl_msg->setText("");
////    lbl_markedtagid->setStyleSheet("QLabel { background-color : black; color : white; }");
//    hlay_btns->addWidget(lbl_msg);

//    lbl_copied_tags = new QLabel();
//    lbl_copied_tags->setText("");
////    lbl_markedtagid->setStyleSheet("QLabel { background-color : black; color : white; }");
//    hlay_btns->addWidget(lbl_copied_tags);

//    hlay_btns->addStretch(1);

//    // ----------------
//    // -- Progress bar
//    // ----------------
//    pb = new QProgressBar();

//    // ----------------
//    // -- Info line - tagsize
//    // ----------------
//    QLabel *lbl_info_tagssize = new QLabel();
//    lbl_info_tagssize->setText("tags:" + QString::number(tags.size()));
//    hlay_info->addWidget(lbl_info_tagssize);


//    // Show number of fils in lstvie
//    QLabel *lbl_info_nfils_lbl = new QLabel("num fils:");
//    hlay_info->addWidget(lbl_info_nfils_lbl);
//    lbl_info_nfils_n = new QLabel();
//    lbl_info_nfils_n->setText("0");
//    hlay_info->addWidget(lbl_info_nfils_n);

//    hlay_info->addStretch(1);

//    vlay_btns_info->addLayout(hlay_btns);
//    vlay_btns_info->addWidget(pb);
//    vlay_btns_info->addLayout(hlay_info);



//    QWidget *wid_tags_imgs = new QWidget;
//    wid_tags_imgs->setLayout(hlay_tags_imgs);

//    QWidget *wid_info = new QWidget;
//    wid_info->setLayout(vlay_btns_info);

//    vsplit_main->addWidget(wid_tags_imgs);
//    vsplit_main->addWidget(wid_info);
//    vsplit_main->setStretchFactor(0, 1);
//    vsplit_main->setStretchFactor(1, 0);
//    vlay_main->addWidget(vsplit_main);

//    QWidget *window = new QWidget();
//    window->setLayout(vlay_main);

//    // Set QWidget as the central layout of the main window
//    setCentralWidget(window);



//    // STYLESHEETS
//////    setStyleSheet("QTreeView:item:hover { border: 1px solid #6a6ea9; background: lightblue;}");
////    QFile File(":/stylesheet.qss");
////    File.open(QFile::ReadOnly);
////    QString StyleSheet = QLatin1Strging(File.readAll());
////    setStyleSheet(StyleSheet);

////    QFile styleFile("/home/fab/prj/tagqt8/stylesheet.qss");
////    styleFile.open(QFile::ReadOnly);
////    QString style(styleFile.readAll());
////    setStyleSheet(style);

////    QFile qf(":/test.qss");
////    qf.open(QFile::ReadWrite);
////    qf.write("test2");
////    qf.close();

////    QDir q1 = QDir::currentPath();
////    std::cerr << q1.absolutePath().toStdString() << std::endl;
////    QDir qf_app_pathdir(QString::frgomStdString(conf->map_conf["app_pathdir"]));
//    QFile qf_styleFile(QString::fromStdString(conf->map_conf["app_pathdir"]) + QDir::separator() + QString::fromStdString("stylesheet.qss"));
////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    qf_styleFile.open(QFile::ReadOnly);
//    QString qs(qf_styleFile.readAll());
//    setStyleSheet(qs);
////    std::cerr << qf_styleFile.fileName().toStdString();


////    QDir dir(".");

////    foreach(QFileInfo item, dir.entryInfoList() )
////    {
////        if(item.isDir())
////             qDebug() << "Dir: " << item.absoluteFilePath();
////        if(item.isFile())
////             qDebug() << "File: " << item.absoluteFilePath();
////    }


//// -------------------------------
//// -------------------------------


////    connect(trw_tags, &TreWidTags::clicked, this, &MainWindow::on_trw_tags_clicked);
////    connect(trw_tags, &TreWidTags::myrightClicked, this, &MainWindow::on_trw_tags_rightClicked);
////    connect(trw_tags, SIGNAL(myrightClicked()), this, SLOT(on_trw_tags_rightClicked()));

//    //    connect(trw_tags, &TreWidTags::rightClicked, this, &MainWindow::on_trw_tags_rightClicked);
////    connect(trw_tags, &TreWidTags::mousePressEvent, this, &MainWindow::on_trw_tags_mousePressEvent);
////    connect(btn_refresh, &QPushButton::clicked, this, &MainWindow::on_btn_refresh_Clicked);
////    connect(btn_untagged, &QPushButton::clicked, this, &MainWindow::on_btn_untagged_Clicked);
////    connect(trevie_fils, &TreVieFils::doubleClicked, this, &MainWindow::on_trevie_fils_DoubleClicked);
////    connect(trewid_tags, &TreWidTags::itemSelectionChanged, &TreWidTags::itemSelectionChanged);
////    connect(trevie_tags, &TreVieTags::doubleClicked, this, &MainWindow::on_TreVieDoubleClicked);


//    Magick::InitializeMagick(".");

}


MainWindow::~MainWindow()
{
//    delete ui;
}



//void MainWindow::on_lv_img_doubleClicked(const QModelIndex &index) {
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////      QStandardItem *item = model->itemFromIndex(index); //itemFromIndex does not exist in this context!
//}


//QList<QStandardItem *> MainWindow::prepareRow(const QString &first,
//                                                const QString &second,
//                                                const QString &third)
//{
//    QList<QStandardItem *> rowItems;
//    rowItems << new QStandardItem(first);
//    rowItems << new QStandardItem(second);
//    rowItems << new QStandardItem(third);
//    return rowItems;
//}

//void MainWindow::on_trewid_tags_rightClicked(QMouseEvent *e) {
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//}


//void MainWindow::on_trewid_tags_clicked() {
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////    std::vector<Img> obs = db_get_untagged_obs(db);
//////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//////    std::cerr << obs.size() << std::endl;
////    lstvie_obs->model->clear();
////    lstvie_obs->add_imgs(obs);
//}


//void MainWindow::on_btn_refresh_Clicked() {
////    QModelIndex qm = trevie_tags->indexAt(trevie_tags->rect().topLeft());
////    trevie_tags->refresh_tree();
//    tv_tags->db_reload_tree();
////    trevie_tags->scrollTo(qm, QAbstractItemView::PositionAtTop);
//}



//void MainWindow::on_btn_untagged_Clicked() {
//    std::vector<Img> imgs;
//    try {
//        imgs = db_get_untagged_imgs(db);
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }


//    // TODO
////    trevie_fils->md->clear();
////    int appended_rows = trevie_fils->add_fils(fils,-1);
////    lbl_info_nfils_n->setText(QString::number(appended_rows));
//}



//Tag MainWindow::get_marked_tag(void) {
//    Tag tag;
//    QString s = lbl_markedtagid->text();
//    if (s.size() > 0) {
//        tag.id = s.toInt();
//        tag.des = lbl_markedtagdes->text().toStdString();
//    }
//    return(tag);
//}



//void MainWindow::on_trevie_obs_DoubleClicked(const QModelIndex &index) {
//////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;

////    QVariant q = index.data(Qt::UserRole);
////    ImgFile img_file = q.value<ImgFile>();
////    std::string imgfile = img_file.des;

////    // test if original file exists
////    bool res = file_chk_exists(imgfile);
////    if (! res) {
////        // original file does not exist ...
////        // ... check if local repository file exists
////        std::string fn = getFileName(img_file.des, true, '/');
////        std::string local_fn = conf->map_conf["app_pathdir"] + "/" + conf->map_conf["docs_dir"] + "/" + img_file.md5 + "_" + fn;
////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;

////        bool res2 = file_chk_exists(local_fn);
////        if (! res2) {
////            qDebug() << "file does not exist";
////            return;
////        }
////        QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(local_fn)));
////    }

////    QMimeDatabase db;
//////    QFileInfo fileinfo(QString(imgfile));
////    QString qs = QString::fromStdString(imgfile);
////    QFile qf(qs);
////    QMimeType mime = db->mimeTypeForFile(qf, QMimeDatabase::MatchContent);
//////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//////    qDebug() << mime.name();            // Name of the MIME type ("audio/mpeg").
//////    qDebug() << mime.suffixes();        // Known suffixes for this MIME type ("mp3", "mpga").
//////    qDebug() << mime.preferredSuffix(); // Preferred suffix for this MIME type ("mp3").
////    if (mime.name() == "application/pdf") {
////        QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(imgfile)));
////    } else if ((mime.name() == "image/png") || (mime.name() == "image/jpeg")) {
////        QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(imgfile)));
////    } else if (mime.name() == "text/plain") {
////        QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(imgfile)));
////    } else if (mime.name() == "application/zip") {
////        QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(imgfile)));
////    }
//}










//    setCentralWidget(treeView);
//    model_tags = new QStandardItemModel;

////    QStandardItem *item0 = model_tags->item(0,0);
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    std::cerr << model_tags->rowCount() << std::endl;

//    QList<QStandardItem *> rowItems;
//    rowItems << new QStandardItem("first");
//    rowItems << new QStandardItem("second");
////    rowItems << new QStandardItem("third");

//    QStandardItem *item = model_tags->invisibleRootItem();
//    // adding a row to the invisible root item produces a root element
//    item->appendRow(rowItems);

////    item0 = model_tags->item(0,0);
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    std::cerr << model_tags->rowCount() << std::endl;

//    QList<QStandardItem *> secondRow;
//    secondRow << new QStandardItem("111");
//    secondRow << new QStandardItem("222");
////    secondRow << new QStandardItem("333");
//    // adding a row to an item starts a subtree
//    rowItems.first()->appendRow(secondRow);

//    QList<QStandardItem *> r3;
//    r3 << new QStandardItem("r31");
//    r3 << new QStandardItem("r32");
////    r3 << new QStandardItem("r33");
//    item->appendRow(r3);

//    trevie_tags->setModel(model_tags);
//    trevie_tags->load(tags);






//---------OK------------------------------------------------------------
//    treeView = new QTreeView(this);
////    setCentralWidget(treeView);
//    standardModel = new QStandardItemModel ;

//    QList<QStandardItem *> rowItems;
//    rowItems << new QStandardItem("first");
//    rowItems << new QStandardItem("second");
//    rowItems << new QStandardItem("third");

//    QStandardItem *item = standardModel->invisibleRootItem();
//    // adding a row to the invisible root item produces a root element
//    item->appendRow(rowItems);

//    QList<QStandardItem *> secondRow;
//    secondRow << new QStandardItem("111");
//    secondRow << new QStandardItem("222");
//    secondRow << new QStandardItem("333");
//    // adding a row to an item starts a subtree
//    rowItems.first()->appendRow(secondRow);

//    treeView->setModel(standardModel);
//    treeView->expandAll();
//-----------------------------------------------------------------------






//------------------OK-------------------------------------------------
//    treeView = new QTreeView(this);
//    setCentralWidget(treeView);
//    standardModel = new QStandardItemModel ;

//    QList<QStandardItem *> rowItems;
//    rowItems << new QStandardItem("first");
//    rowItems << new QStandardItem("second");
//    rowItems << new QStandardItem("third");

//    QStandardItem *item = standardModel->invisibleRootItem();
//    // adding a row to the invisible root item produces a root element
//    item->appendRow(rowItems);

//    QList<QStandardItem *> secondRow;
//    secondRow << new QStandardItem("111");
//    secondRow << new QStandardItem("222");
//    secondRow << new QStandardItem("333");
//    // adding a row to an item starts a subtree
//    rowItems.first()->appendRow(secondRow);

//    treeView->setModel(standardModel);
//    treeView->expandAll();
//---------------------------------------------------------------------







// -------------- OK ------------------------------------------------------
//    treeView = new QTreeView(this);
//    setCentralWidget(treeView);
//    standardModel = new QStandardItemModel ;

//    QList<QStandardItem *> preparedRow =prepareRow("first", "second", "third");
//    QStandardItem *item = standardModel->invisibleRootItem();
//    // adding a row to the invisible root item produces a root element
//    item->appendRow(preparedRow);

//    QList<QStandardItem *> secondRow =prepareRow("111", "222", "333");
//    // adding a row to an item starts a subtree
//    preparedRow.first()->appendRow(secondRow);

//    treeView->setModel(standardModel);
//    treeView->expandAll();
// ------------------------------------------------------------------------






//    QStandardItemModel model_test( 5, 2 );
//    for( int r=0; r<5; r++ ) {
//        for( int c=0; c<2; c++) {
//            QStandardItem *item = new QStandardItem( QString("Row:%0, Column:%1").arg(r).arg(c) );

//            if ( c == 0 ) {
//                for( int i=0; i<3; i++ ) {
//                    QStandardItem *child = new QStandardItem( QString("Item %0").arg(i) );
//                    child->setEditable( false );
//                    item->appendRow( child );
//                }
//            }

//            model_test.setItem(r, c, item);
//        }
//    }

//    model_test.setHorizontalHeaderItem( 0, new QStandardItem( "Foo" ) );
//    model_test.setHorizontalHeaderItem( 1, new QStandardItem( "Bar-Baz" ) );



//    QTreeView *view = new QTreeView(this);
//    view->setModel(&model_test);
//    view->show();




















//void MainWindow::on_TreVieDoubleClicked(const QModelIndex &index) {
//    QVariant data = trevie_tags->model()->data(index);
//    QString text = data.toString();


////    QStandardItem* item = new QStandardItem("myItem")
////    item->setIcon(QIcon("icon.jpg"));
////    rootNode->appendRow(item);


//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;



////    int tagid = item->data(0, Qt::DisplayRole).toInt();
////    std::vector<Img> obs = get_obs_by_tagid(db, tagid);
////    lstvie_obs->model->clear();
////    lstvie_obs->add_imgs(obs, tagid);
//}




//void MainWindow::on_treTags_itemDoubleClicked(QTreeWidgetItem *item, int column)
//{
//    bool ok;
//    //    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
//    //                                             tr("tag value"), QLineEdit::Normal,
//    //                                             QDir::home().dirName(), &ok);
//    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
//                                         tr("tag value"),
//                                         QLineEdit::Normal,
//                                         item->text(1), &ok);
//    if (ok && !text.isEmpty()) {
//     //           textLabel->setText(text);
//        item->setText(1,text);

//        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;



////        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306",  "root", "r++mysql"));
////        con->setAutoCommit(0);
////        con->setSchema("imgviewcppqt5");
////        std::unique_ptr<sql::Statement> stmt(con->createStatement());
////        std::string idstr = item->text(0).toStdString();
////        std::string val = item->text(1).toStdString();
////        std::string query = "UPDATE tag SET val='" + val + "' WHERE id=" + idstr;
////        stmt->execute(query);
////        con->commit();



//    }
//    //    QString str = item->text(1);
//    //    ui->txtEditTag->setText(str);
//    //    str = item->text(0);
//    //    ui->lblEditTagJ->setText(str);
//    ////    std::cerr << "line: " << __LINE__ << "- file: " << __FILE__ << std::endl;

//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    //    std::cerr << "ok" << std::endl;
//}


//void MainWindow::on_treTags_clicked(const QModelIndex &index)
//{
//    // filter on right click ...
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//}


//void MainWindow::on_treTags_pressed(const QModelIndex &index)
//{
////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;

//}


/////////////////////////////////////////////////////////////////////////////////////////
////if (event->button()==Qt::RightButton){
////        qDebug() << "right button is pressed
////    }
/////////////////////////////////////////////////////////////////////////////////////////
////void MyTreeView::mouseReleaseEvent(QMouseEvent *e) {
////    if (e->button() == Qt::RightButton) {
////        QTreeWidgetItem *item = itemAt(e->pos());
////        if (item) {
////            QMenu m;
////            m.addAction("hello");
////            m.addAction("world");
////            QAction *selected = m.exec(mapToGlobal(e->pos()));
////            if (selected) {
////                qDebug() << "selected" << selected->text();
////            }
////        }
////    } else {
////        QTreeView::mouseReleaseEvent(e);
////    }
////}
/////////////////////////////////////////////////////////////////////////////////////////






//void MainWindow::on_treTags_doubleClicked(const QModelIndex &index)
//{

//}



//void MainWindow::on_btnFilterFirst_clicked()
//{
//    if (filter_img_ids.size() > 0) {
//        filter_imgidj = 0;
//        unsigned id = filter_img_ids[filter_imgidj];
//        string pathname;
//        pathname = mapImg_id[id].pat + "/" + mapImg_id[id].nam;
//        QPixmap image(QString::fromStdString(pathname));
//        int w = ui->lblImage->width();
//        int h = ui->lblImage->height();
//        ui->lblImage->setPixmap(image.scaled(w,h,Qt::KeepAspectRatio));
//        ui->lblFilename->setText(QString::fromStdString(pathname));
////        ui->lblImgj->setText(QString::fromStdString(to_string(imgidj) + ":" + to_string(imgids.size())));
////        unsigned int n = show_tags(imgidj);
////        ui->sliderImg->setValue(imgidj);
////        ui->lblNTagsImg->setText(QString::fromStdString(to_string(n)));
//    }
//}

//QSqlQuery query;
//query.prepare("INSERT INTO employee (id, name, salary) "
//                "VALUES (:id, :name, :salary)");
//  query.bindValue(":id", 1001);
//  query.bindValue(":name", "Thad Beaumont");
//  query.bindValue(":salary", 65000);
//  query.exec();


//QSqlQuery query;
//query.prepare("INSERT INTO employee (id, name, salary) "
//              "VALUES (?, ?, ?)");
//query.addBindValue(1001);
//query.addBindValue("Thad Beaumont");
//query.addBindValue(65000);
//query.exec();



//////////////////////////////////////////////////
// TREEWDIGET traverse
//// myWidget is a QTreeWidgetItem*
//void traverseNode(QTreeWidgetItem *item) {
//    // Do something with item
//    for (int i = 0; i < item->childCount(); ++i)
//        traverseNode(item->child(i));
//}

//for (int i = 0; i < myWidget->topLevelItemCount(); ++i) {
//    QTreeWidgetItem *item = myWidget->topLevelItem(i);
//    traverseNode(item);
//}
//////////////////////////////////////////////////





//////////////////////////////////////////////////
//QList<QTreeWidgetItem *> itemList;
//itemList = this->MyTree->selectedItems();
//foreach(QTreeWidgetItem *item, itemList)
//{
//   QString str = item->text();
//   //str is what you want
//}
//////////////////////////////////////////////////




//////////////////////////////////////////////////
//std::set<int> example = {1, 2, 3, 4};
//auto search = example.find(2);
//if(search != example.end()) {
//    std::cout << "Found " << (*search) << '\n';
//}
//else {
//    std::cout << "Not found\n";
//}
//////////////////////////////////////////////////



//////////////////////////////////////////////////
//#include <json_parser.h>
//////////////////////////////////////////////////



//////////////////////////////////////////////////
//conn->setAutoCommit(0);
//////////////////////////////////////////////////




//////////////////////////////////////////////////
// std::string ---> QSTRING
//    ui->lblImgj->setText(QString::fromStdString(to_string(imgidj) + ":" + to_string(imgids.size())));
// QSTRING     ---> std:string
//    std::string idstr = item->text(0).toStdString();
// int         ---> std::string
//    to_string(imgidj)
//////////////////////////////////////////////////


//////////////////////////////////////////////////
// std::cerr << "ERR - line: " << __LINE__ << "- file: " << __FILE__ << std::endl;
//////////////////////////////////////////////////
