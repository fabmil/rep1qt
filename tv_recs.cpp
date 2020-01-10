#include "tv_recs.h"

#include <exception>
#include <memory>

#include <boost/algorithm/string.hpp>

//#include "chk_tag_sup_inf.h"
//#include "conf.h"
#include "db.h"
//#include "db_add_tag.h"
//#include "db_add_tag_to_imgs.h"
//#include "db_chk_sibling_exists.h"
//#include "db_tools.h"
//#include "db_get_chds.h"
//#include "db_get_last_tag.h"
//#include "db_get_imgs_by_tagid.h"
//#include "db_get_tags.h"
//#include "db_ren_tag.h"
//#include "db_insert_img.h"
//#include "dia_textedit.h"
//#include "dia_editline.h"
//#include "dia_listchoice.h"
//#include "dia_msg_ok_cancel.h"
//#include "dia_tagfind.h"
//#include "dia_tag_info.h"
//#include "qmis_found.h"
//#include "img.h"
//#include "fs_store.h"d
//#include "lv_imgs.h"
#include "mainwindow.h"
//#include "md5_3.h"
#include "mydebug.h"
#include "myex.h"
//#include "tag.h"


//static inline QString MyTreeViewMimeType() { return QStringLiteral("application/x-mytreeview"); }


TV_Recs::TV_Recs(QWidget *parent) : QTreeView(parent) {
    //    this->parent = (MainWindow *)parent;
    this->parent = static_cast<MainWindow *>(parent);
    md = new QStandardItemModel;
    setModel(md);
    QStringList ColumnNames;
    ColumnNames << "id" << "des";
    //    setHeaderLabels(ColumnNames);
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &TV_Recs::doubleClicked, this, &TV_Recs::myDoubleClicked);
    //    connect(this, &TreVieTags::clicked, this, &TreVieTags::myClicked);
    //    connect(this, &TreVieTags::keyPressEvent, this, &TreVieTags::myKeyPressEvent);
    viewport()->setAcceptDrops(true);
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDragDropMode(QAbstractItemView::DragDrop);
    qfs = new Qmis_Found();
}


TV_Recs::~TV_Recs() {
}


void TV_Recs::init() {
}


QString TV_Recs::MyMimeType() {
    return QStringLiteral("application/x-tv-tags-mimetype");
}


 * On mouse right click show float tags menu
///*
// */
//void TV_Recs::mousePressEvent(QMouseEvent *e) {
//    if (e->button() == Qt::RightButton) {
//        dia_tags = new QDialog();
//        //        std::unique_ptr<QDialog> dia_tags = std::make_unique<QDialog>();

//        QPoint p = mapToGlobal(QPoint(e->x(),e->y()));
//        dia_tags->move(p);

//        QVBoxLayout *lay1 = new QVBoxLayout;

//        // dialog header
//        QLabel *lbl_header = new QLabel("TAG menu");
//        lay1->addWidget(lbl_header);

//        // button info
//        QPushButton *btn_info = new QPushButton("info");
//        lay1->addWidget(btn_info);
//        connect(btn_info, &QPushButton::clicked, this, &TV_Recs::btn_info_clicked);

//        // button add tag
//        QPushButton *btn_addtag = new QPushButton("add");
//        lay1->addWidget(btn_addtag);
//        connect(btn_addtag, &QPushButton::clicked, this, &TV_Recs::btn_addtag_clicked);

//        // button find
//        QPushButton *btn_find = new QPushButton("find");
//        lay1->addWidget(btn_find);
//        connect(btn_find, &QPushButton::clicked, this, &TV_Recs::btn_find_clicked);

//        // button add sibling
//        QPushButton *btn_add_sibling = new QPushButton("add sibling");
//        lay1->addWidget(btn_add_sibling);
//        connect(btn_add_sibling, &QPushButton::clicked, this, &TV_Recs::btn_add_sibling_clicked);

//        // button add child
//        QPushButton *btn_add_child = new QPushButton("add child");
//        lay1->addWidget(btn_add_child);
//        connect(btn_add_child, &QPushButton::clicked, this, &TV_Recs::btn_add_child_clicked);

//        //        // button add tag as child of selected tag
//        //        QPushButton *btn_addtagchd = new QPushButton("add tag as child of selected tag");
//        //        lay1->addWidget(btn_addtagchd);
//        //        connect(btn_addtagchd, &QPushButton::clicked, this, &TV_Recs::btn_addtagchd_clicked);

//        //        // button add selected tag as child of another tag
//        //        QPushButton *btn_addtagchd2 = new QPushButton("add selected tag(s) as child of another tag");
//        //        lay1->addWidget(btn_addtagchd2);
//        //        connect(btn_addtagchd2, &QPushButton::clicked, this, &TreVieTags::btn_add_chds_to_pad_clicked);

//        //        // button add new note (and fil) as child of selected tag
//        //        QPushButton *btn_addnote = new QPushButton("add new note");
//        //        lay1->addWidget(btn_addnote);
//        //        connect(btn_addnote, &QPushButton::clicked, this, &TreVieTags::btn_addnote_clicked);

//        // button rename tag
//        QPushButton *btn_rentag = new QPushButton("ren tag");
//        lay1->addWidget(btn_rentag);
//        connect(btn_rentag, &QPushButton::clicked, this, &TV_Recs::btn_rentag_clicked);

//        // button del tag
//        QPushButton *btn_deltag = new QPushButton("del tag");
//        lay1->addWidget(btn_deltag);
//        connect(btn_deltag, &QPushButton::clicked, this, &TV_Recs::btn_deltag_clicked);

//        // button paste
//        QPushButton *btn_paste = new QPushButton("btn paste");
//        lay1->addWidget(btn_paste);
//        connect(btn_paste, &QPushButton::clicked, this, &TV_Recs::btn_paste_clicked);

//        // button make inf
//        QPushButton *btn_makeinf = new QPushButton("make inf");
//        lay1->addWidget(btn_makeinf);
//        connect(btn_makeinf, &QPushButton::clicked, this, &TV_Recs::btn_makeinf_clicked);

//        // button make inf of marked tags
//        QPushButton *btn_makeinfofmarkedtag = new QPushButton("make inf of marked tag");
//        lay1->addWidget(btn_makeinfofmarkedtag);
//        connect(btn_makeinfofmarkedtag, &QPushButton::clicked, this, &TV_Recs::btn_makeinfofmarkedtag_clicked);

//        // button make child
//        QPushButton *btn_makechild = new QPushButton("make child");
//        lay1->addWidget(btn_makechild);
//        connect(btn_makechild, &QPushButton::clicked, this, &TV_Recs::btn_makechild_clicked);

//        // button make pad of marked tags
//        QPushButton *btn_makepadofmarkedtag = new QPushButton("make pad of marked tag");
//        lay1->addWidget(btn_makepadofmarkedtag);
//        connect(btn_makepadofmarkedtag, &QPushButton::clicked, this, &TV_Recs::btn_makepadofmarkedtag_clicked);

//        // button make root element
//        QPushButton *btn_makeroot = new QPushButton("make root");
//        lay1->addWidget(btn_makeroot);
//        connect(btn_makeroot, &QPushButton::clicked, this, &TV_Recs::btn_makeroot_clicked);

//        // button make root element
//        QPushButton *btn_mark = new QPushButton("mark");
//        lay1->addWidget(btn_mark);
//        connect(btn_mark, &QPushButton::clicked, this, &TV_Recs::btn_mark_clicked);

//        // button remove from par
//        QPushButton *btn_removefrompar = new QPushButton("remove tags from par");
//        lay1->addWidget(btn_removefrompar);
//        connect(btn_removefrompar, &QPushButton::clicked, this, &TV_Recs::btn_removefrompar_clicked);

//        // button tag search
//        QPushButton *btn_search = new QPushButton("search");
//        lay1->addWidget(btn_search);
//        connect(btn_search, &QPushButton::clicked, this, &TV_Recs::btn_search_clicked);

//        // button parent choice
//        QPushButton *btn_par_choice = new QPushButton("par choice");
//        lay1->addWidget(btn_par_choice);
//        connect(btn_par_choice, &QPushButton::clicked, this, &TV_Recs::btn_par_choice_clicked);

//        // test
//        QPushButton *btn_test = new QPushButton("test");
//        lay1->addWidget(btn_test);
//        connect(btn_test, &QPushButton::clicked, this, &TV_Recs::btn_test_clicked);

//        // button load dir files
//        QPushButton *btn_load_dir_files = new QPushButton("load dir files");
//        lay1->addWidget(btn_load_dir_files);
//        connect(btn_load_dir_files, &QPushButton::clicked, this, &TV_Recs::btn_load_dir_files);

//        // button load files
//        QPushButton *btn_load_files = new QPushButton("load files (selected tag)");
//        lay1->addWidget(btn_load_files);
//        connect(btn_load_files, &QPushButton::clicked, this, &TV_Recs::btn_load_files);

//        dia_tags->setLayout(lay1);
//        dia_tags->exec();
//    }
//    QTreeView::mousePressEvent(e);
//}


///*
// * Reload all tags, show tree, expand all
// */
//void TV_Recs::db_reload_tree() {
//    md->clear();
//    std::vector<Tag> tags = db_get_tags(db);
//    add_tags(tags);
//    collapseAll();
//    //    expandAll();
//}





////Qt::DropActions TreeModel::supportedDropActions() const {
////    return Qt::CopyAction | Qt::MoveAction;
////}



//void TV_Recs::startDrag(Qt::DropActions /*supportedActions*/) {
//    auto mi = currentIndex();
//    QVariant data = model()->data(mi);
//    std::string tag_str = data.toString().toStdString();
//    //    Tag tag = Tag::parse(tag_str);
//    QByteArray itemData;
//    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
//    dataStream << QString::fromStdString(tag_str);
//    QMimeData *mimeData = new QMimeData;
//    //    mimeData->setData("application/x-tag-data", itemData);
//    //    mimeData->setData(MyTreeViewMimeType(), itemData);
//    mimeData->setData(MyMimeType(), itemData);
//    QDrag *drag = new QDrag(this);
//    drag->setMimeData(mimeData);
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    //    std::cerr << tag_str << std::endl;
//    if (drag->exec(Qt::MoveAction) == Qt::MoveAction) {
//        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//        ////        delete takeItem(row(item));
//    }
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;

//    //    QTreeView::startDrag(Qt::DropActions);
//    //    QListWidgetItem *item = currentItem();

//    //    QByteArray itemData;
//    //    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
//    //    QPixmap pixmap = qvariant_cast<QPixmap>(item->data(Qt::UserRole));
//    //    QPoint location = item->data(Qt::UserRole+1).toPoint();

//    //    dataStream << pixmap << location;

//    //    QMimeData *mimeData = new QMimeData;
//    //    mimeData->setData("image/x-puzzle-piece", itemData);

//    //    QDrag *drag = new QDrag(this);
//    //    drag->setMimeData(mimeData);
//    //    drag->setHotSpot(QPoint(pixmap.width()/2, pixmap.height()/2));
//    //    drag->setPixmap(pixmap);

//    //    if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
//    //        delete takeItem(row(item));
//}




//void TV_Recs::dragEnterEvent(QDragEnterEvent *event) {
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    event->setDropAction(Qt::MoveAction);
//    //    setText(tr("<drop content>"));
//    //    setBackgroundRole(QPalette::Highlight);

//    //    if (event->mimeData()->hasFormat(fridgetMagnetsMimeType())) {
//    //            if (children().contains(event->source())) {
//    //                event->setDropAction(Qt::MoveAction);
//    //                event->accept();
//    //            } else {
//    //                event->acceptProposedAction();
//    //            }
//    //    }
//    /*
//     * Setting the accept parameter indicates that the event
//     * receiver wants the event.  Unwanted events might be
//     * propagated to the parent widget.
//     * Then we call the event's accept() method to indicate that we
//     * have handled the event.  In general, unaccepted events
//     * might be propagated to the parent widget. If the event
//     * origins from any other widget, we simply accept the
//     * proposed action.
//     */
//    event->accept();
//    //    event->acceptProposedAction();
//    //    emit changed(event->mimeData());
//}


//void TV_Recs::dragMoveEvent(QDragMoveEvent *event) {
//    event->acceptProposedAction();
//    ////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    //    setDropIndicatorShown(true);
//    //    if (event->mimeData()->hasFormat(MyTreeViewMimeType())) {
//    ////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    //        event->accept();
//    //    } else {
//    //        event->ignore();
//    //    }
//    ////     if (dropResultsInValidIndex(event->pos()))
//    ////         event->accept();
//    ////     else
//    ////         event->ignore(); //Show 'forbidden' cursor.
//    //    QTreeView::dragMoveEvent(event);
//}


///*
// * Drop treeview item
// */
//void TV_Recs::dropEvent(QDropEvent *event) {

//    QModelIndex droppedIndex = indexAt( event->pos() );

//    if ( !droppedIndex.isValid() ) {
//        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//        return;
//    }

//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    QTreeView::dropEvent(event);

//    //    const QMimeData *mimeData = event->mimeData();
//    //    if (mimeData->hasImage()) {
//    //        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    //    } else if (event->mimeData()->hasFormat(MyTreeViewMimeType())) {
//    //        auto src = event->source();
//    //        // Make dragging item child of destination item

//    //        // -- get par item
//    //        QModelIndex mi = indexAt(event->pos());
//    //        QVariant data = md->data(mi);
//    //        std::string tag_str = data.toString().toStdString();
//    //        Tag par = Tag::parse(tag_str);
//    ////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    ////        std::cerr << par.id << " " << par.des << std::endl;
//    ////        auto md = event->mimeData();

//    //        // -- get chd item
//    //        const QMimeData *mime = event->mimeData();
//    //        QByteArray itemData = mime->data(MyTreeViewMimeType());
//    //        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
//    //        QString text;
//    //        dataStream >> text;
//    //        QStringList ss = text.split(QRegularExpression(QStringLiteral("\\s+")), QString::SkipEmptyParts);
//    ////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    ////        std::cerr << ss[0].toStdString() << ":" << ss[1].toStdString() << std::endl;

//    //        // Make "chd" as child of "par"
//    //        int chd_id = ss[0].toInt();
//    //        try {
//    //            db_add_tagparchd(db, par.id, chd_id);
//    //        } catch (MyEx& ex) {
//    //            std::cout << ex.what() << ex.get_info() << std::endl;
//    //            std::cout << "Function: " << ex.get_func() << std::endl;
//    //            return;
//    //        }
//    //        event->setDropAction(Qt::MoveAction);
//    //        event->accept();

//    //        // Make "remove tag" from old parent
//    ////        int chd_id = ss[0].toInt();
//    //////        Err err;
//    ////        try {
//    ////            db_add_tagparchd(db, par.id, chd_id);
//    ////        } catch (MyEx& ex) {
//    ////            std::cout << ex.what() << ex.get_info() << std::endl;
//    ////            std::cout << "Function: " << ex.get_func() << std::endl;
//    ////            return;
//    ////        }
//    ////            try {
//    ////                db_del_tag(db, tag.id);
//    //////                    db_reload_tree();
//    ////            } catch (MyEx& ex) {
//    ////                std::cout << ex.what() << ex.get_info() << std::endl;
//    ////                std::cout << "Function: " << ex.get_func() << std::endl;
//    ////                return;
//    ////            }

//    ////            // Remove tag from TreeView
//    ////            QModelIndex mi_par = selectedIndex.parent();
//    ////            md->removeRow(selectedIndex.row(), mi_par);

//    ////                if (err.des.size() > 0) {
//    ////                    err.gest(__LINE__, __FILE__);
//    ////                    return;
//    ////                }

//    ////        db_reload_tree();
//    ////        db_reload_tree();
//    //    }
//    ////    QTreeView::dropEvent(event);
//}


///*
// * Test
// */
//void TV_Recs::btn_test_clicked(void) {
//    dia_tags->close();


//    // test scroll to ...

//    QStandardItemModel *mdsave = md;
////    QModelIndex pmi = indexAt(this->rect().topLeft());
////    QModelIndex pmi = indexAt(QPoint(100,100));
//    int row = 3;
//    int col = 0;
//    QModelIndex pmi = md->index(row, col, QModelIndex());
////    setModel(NULL);
////    setModel(mdsave);
//    if (pmi.isValid()) {
//        scrollTo(pmi, QAbstractItemView::PositionAtTop);
//    }
//    mydebug2(__LINE__,__FILE__);


////    QFileDialog dialog(this);
////    dialog.setViewMode(QFileDialog::Detail);
////    //    dialog.setFileMode(QFileDialog::AnyFile + QFileDialog::Directory);
////    dialog.setFileMode(QFileDialog::Directory);
////    if (dialog.exec()) {
////        // get selected dir
////        QStringList fileNames = dialog.selectedFiles();
////        //        if (QDir(fileNames[0]).exists()) {
////        //            mydebug2(__LINE__,__FILE__);
////        //        }


////        mydebug2(__LINE__,__FILE__);
////    }
////    mydebug2(__LINE__,__FILE__);

//    //    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    //    for (QModelIndex k : indexes) {
//    //        if (is_type_img(k)) {
//    //            FilData fd = get_fildata(k);
//    //            QStandardItem *item = md->itemFromIndex(k);
//    //            item->removeRows(0, item->rowCount());
//    //            Fil fil(fd);
//    //            add_fil_subitems(item, fil, fd.tagid);
//    ////            mydebug2(__LINE__,__FILE__);
//    //        }
//    //    }
//}



//void TV_Recs::refresh_tree(void) {

//    QStandardItemModel *mdsave = md;
//    QPersistentModelIndex pmi = indexAt(this->rect().topLeft());
//    setModel(NULL);
//    setModel(mdsave);
//    if (pmi.isValid()) {
//        scrollTo(pmi, QAbstractItemView::PositionAtTop);
//    }
//    mydebug2(__LINE__,__FILE__);


//    //    expandAll();
//    //    QModelIndex qm = indexAt(this->rect().topLeft());
//    //    QPersistentModelIndex pmi = indexAt(this->rect().topLeft());
//    //    mydebug2(__LINE__,__FILE__);
//    //    scrollTo(qm, QAbstractItemView::PositionAtTop);



//    //    std::vector<int> tagids;

//    //    QModelIndex k = indexAt(this->rect().topLeft());
//    //    int j = 0;
//    //    while (true) {
//    //        QVariant data = model()->data(k);
//    //        if (! data.isValid()) {
//    //            break;
//    //        }
//    //        std::string tag_str = data.toString().toStdString();
//    //        Tag tag = Tag::parse(tag_str);
//    //        tagids.push_back(tag.id);
//    //        k = k.parent();
//    //        if (j > 10) {
//    //            mydebug2(__LINE__,__FILE__);
//    //            std::cerr << "ERR" << std::endl;
//    //            break;
//    //        }
//    //    }
//    //    mydebug2(__LINE__,__FILE__);



//    //    expandAll();
//    //    QModelIndex qm = indexAt(this->rect().topLeft());
//    //    QPersistentModelIndex pmi = indexAt(this->rect().topLeft());
//    //    mydebug2(__LINE__,__FILE__);
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;

//    //    std::vector<Tag> tags = db_rd_tags(db);
//    //    md->clear();
//    //    Err err;
//    //    add_tags(tags, err);
//    //    if (err.des.size() > 0) {
//    //        // err, do nothing
//    //        std::cerr << "ERR - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    //        return;
//    //    }

//    //    scrollTo(qm, QAbstractItemView::PositionAtTop);
//}




//void TV_Recs::myClicked(const QModelIndex &index) {
//    //
//    // (Click on tag)
//    // ... do nothing ...
//    //
//    mydebug2(__LINE__,__FILE__);
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    // if click on icon (first column) ...
//    // ... then toggle expand children

//    //    int tagid = item->data(0, Qt::DisplayRole).toInt();
//    //    std::vector<Img> obs = get_obs_by_tagid(db, tagid);
//    //    lstvie_obs->model->clear();
//    //    lstvie_obs->add_imgs(obs, tagid);
//}



//void TV_Recs::show_imgs_from_tagid(int tagid) {
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;

//    // load fil(s) in TreeView FILS
//    //    Err err;
//    std::vector<Fil> imgs;
//    try {
//        imgs = db_get_imgs_by_tagid(db, tagid);
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }
//    //    if (err.des.size() > 0) {
//    //        err.gest(__LINE__, __FILE__);
//    //        return;
//    //    }

//    parent->lv_imgs->model->clear();
////    int appended_rows = parent->lv_imgs->show_imgs(imgs, tagid);
//    parent->lv_imgs->show_imgs(imgs);
//    //    for (Img img : imgs) {
//    //        parent->lv_imgs->model->appendRow(new QStandardItem(QIcon("/home/fab/prj/tagqt8/icons/Folder-icon.png"), "Test"));
//    //    }

//    //    parent->trevie_fils->md->clear();
//    //    int appended_rows = parent->trevie_fils->add_fils(fils, tagid);
//    //    // Show number of fils loaded in TreeView FILS
//    //    parent->lbl_info_nfils_n->setText(QString::number(appended_rows));

//}

///*
// * Load img panel
// */
//void TV_Recs::myDoubleClicked(const QModelIndex &index) {
//    QVariant data = model()->data(index);
//    QString text = data.toString();
//    std::string tag_str = text.toStdString();

//    int j = tag_str.find(" ");
//    std::string n_str = tag_str.substr(0,j);
//    int tagid = std::stoi(n_str);

//    show_imgs_from_tagid(tagid);
//}



////void TV_Recs::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
////    //
////    // Show info on selected tags
////    //
////    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////    QString s = "selected tags:" + QString::number(get_seltags_count());
////    //    parent->lbl_seltags_count->setText("selected tags:" + QString::number(get_seltags_count()));
////    parent->lbl_seltags_count->setText(s);
////    QTreeView::selectionChanged(selected, deselected);
////}
//////void TreVieTags::mySelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
//////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////////    QTreeWidget::itemSelectionChanged();
////////    parent->lbl_seltags_count->setText("selected tags:" + QString::number(get_seltags_count()));
//////}




///*
// * Choice tag parent
// */
//void TV_Recs::btn_par_choice_clicked(void) {

//    dia_tags->close();

//    std::vector<Tag> chds = get_selected_tags();
//    if (chds.size() != 1) {
//        // Too many tags selected ... must be only one
//        return;
//    }

//    // Get parent tag(s)
//    std::vector<Tag> pars;
//    Tag chd = chds[0];
//    try {
//        pars = db_get_pars(db, chd.id);
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }

//    // Choice parent tag
//    DiaListChoice *dia_listchoice = new DiaListChoice(this);
//    std::vector<std::string> tags_str_vec;
//    for (Tag t : pars) {
//        std::string tag_str = t.to_string();
//        tags_str_vec.push_back(std::move(tag_str));
//    }
//    //    for (Tag tag : tags) {
//    //        std::string tag_str = std::to_string(tag.id) + " " + tag.des;
//    //        tags_str.push_back(std::move(tag_str));
//    //    }
//    std::string prompt_str = "choice parent tag";
//    dia_listchoice->init(prompt_str, tags_str_vec);
//    int res = dia_listchoice->exec();
//    if (res == QDialog::Accepted) {
//        // get new par tag choice
//        std::string tag_par_str = dia_listchoice->get_value();
//        Tag tag_par = Tag::parse_id_space_des(tag_par_str);

//        try {
//            std::vector<Tag> tag_chain = db_get_tag_chain(db, tag_par.id);
//        } catch (MyEx& ex) {
//            std::cout << ex.what() << ex.get_info() << std::endl;
//            std::cout << "Function: " << ex.get_func() << std::endl;
//            return;
//        }

//        mydebug2(__LINE__,__FILE__);
//    }
//}


//void TV_Recs::btn_mark_clicked(void) {
//    //
//    // Load info on marked tag and show on status line
//    //
//    dia_tags->close();

//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    // Only one selected tag needed
//    if (indexes.size() != 1) {
//        return;
//    }

//    std::vector<QModelIndex> qmis;
//    QModelIndex selectedIndex = indexes.at(0);
//    QModelIndex qmi = selectedIndex;
//    int j=0;
//    while ((qmi.isValid()) && (j<10)) {
//        qmis.push_back(qmi);
//        qmi = qmi.parent();
//        j++;
//    }
//    j=qmis.size();
//    std::string s = "";
//    while (j>0) {
//        j--;
//        QModelIndex qmi = qmis[j];
//        QVariant data = model()->data(qmi);
//        std::string tag_str = data.toString().toStdString();
//        s += tag_str;
//        if (j>0) {
//            s += "\n";
//        }
//    }
//    parent->lbl_seltag->setText(QString::fromStdString(s));
////    QVariant data = model()->data(selectedIndex);
////    std::string tag_str = data.toString().toStdString();
//////    Tag tag = Tag::parse_id_space_des(tag_str);
//////    parent->lbl_markedtagid->setText(QString::number(tag.id));
//////    parent->lbl_markedtagdes->setText(QString::fromStdString(tag.des));
////    parent->lbl_seltag->setText(QString::fromStdString(tag_str + "\n" + "pippo"));
////    parent->lbl_markedtagdes->setText(QString::fromStdString(tag.des));
//}


//void TV_Recs::btn_info_clicked(void) {
//    dia_tags->close();

//    std::vector<Tag> tags = get_selected_tags();
//    // Only one selected tag, else do nothing
//    if (tags.size() != 1) {
//        return;
//    }

//    std::vector<Tag> pars = db_get_pars(db, tags[0].id);
//    std::vector<Tag> chds = db_get_chds(db, tags[0]);
//    DiaTagInfo *dia_info = new DiaTagInfo(this);
//    dia_info->init(tags[0], pars, chds);
//    int res = dia_info->exec();
//    if (res == QDialog::Accepted) {
//        std::string val = dia_info->get_value();
//        mydebug2(__LINE__,__FILE__);
//    }
//    //    // input new value
//    //    int res = dia_editline->exec();
//    ////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    //    if (res == QDialog::Accepted) {
//    //        // store new value
//    //        std::string des = dia_editline->get_value();

//    //        try {
//    //            db_add_tag(db, des);
//    //        } catch (MyEx& ex) {
//    //            std::cout << ex.what() << ex.get_info() << std::endl;
//    //            std::cout << "Function: " << ex.get_func() << std::endl;
//    //            return;
//    //        }

//    //        Tag last_inserted = db_get_last_tag(db);
//    //        // Add new tag in TreeView
//    //        QString tagid_qstr = QString::number(last_inserted.id);
//    //        QString tagdes_qstr = QString::fromStdString(last_inserted.des);
//    //        QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
//    //        QStandardItem *rootitem = md->invisibleRootItem();
//    //        rootitem->appendRow(new_item);
//    //    }
//}



//void TV_Recs::btn_addtag_clicked(void) {
//    dia_tags->close();

//    //    DiaEditLine *dia_editline = new DiaEditLine(this);
//    std::unique_ptr<DiaEditLine> dia_editline = std::make_unique<DiaEditLine>(this);
//    dia_editline->init("new tag value", "");
//    // input new value
//    int res = dia_editline->exec();
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    if (res == QDialog::Accepted) {
//        // store new value
//        std::string des = dia_editline->get_value();

//        try {
//            db_add_tag(db, des);
//        } catch (MyEx& ex) {
//            std::cout << ex.what() << ex.get_info() << std::endl;
//            std::cout << "Function: " << ex.get_func() << std::endl;
//            return;
//        }

//        Tag last_inserted = db_get_last_tag(db);
//        // Add new tag in TreeView
//        QString tagid_qstr = QString::number(last_inserted.id);
//        QString tagdes_qstr = QString::fromStdString(last_inserted.des);
//        QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
//        QStandardItem *rootitem = md->invisibleRootItem();
//        rootitem->appendRow(new_item);
//    }
//}


////void TV_Recs::tagfind_test(void) {
////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////}


///*
// * Show prev found tag
// */
//void TV_Recs::show_prev_found_tag(void) {
//    if (qfs->show_index > 0) {
//        qfs->show_index--;
//    }
//    show_found_tag_n(qfs->show_index);
//}


///*
// * Show next found tag
// */
//void TV_Recs::show_next_found_tag(void) {
//    if (qfs->show_index + 1 < qfs->qmis.size()) {
//        qfs->show_index++;
//        show_found_tag_n(qfs->show_index);
//    }
//}


///*
// * Found all sub tags
// */
//void TV_Recs::find_all_sub_tags(std::string tag_find, QModelIndex qmi_par) {
//    QStandardItem *item_par = md->itemFromIndex(qmi_par);
////    QStandardItem *rootitem = md->invisibleRootItem();
//    // loop through all treeview items
//    int col = 0;
//    if (item_par->hasChildren()) {
//        for (int row = 0; row < item_par->rowCount(); row++) {
//            QStandardItem *chd = item_par->child(row,col);
//            QModelIndex index = md->indexFromItem(chd);
//            QVariant data = model()->data(index);
//            QString text = data.toString();
//            std::string tag_str = text.toStdString();
//            int j = tag_str.find(" ");
//            std::string des = tag_str.substr(j+1);
//            bool result = boost::icontains(des, tag_find);
//            QModelIndex qmi_chd = md->index(row, col, qmi_par);
//            if (result) {
//                qfs->qmis.push_back(std::move(qmi_chd));
////                Qmi_Found qf;
////                qmi = md->index(row, col, QModelIndex());
////                qfs.tag_find = tag_find;
//            }
//            find_all_sub_tags(tag_find, qmi_chd);
//        }
//    }
//}



///*
// * Found all tags
// */
//void TV_Recs::find_all_tags(std::string tag_find) {
//    qfs->qmis.clear();
//    QStandardItem *rootitem = md->invisibleRootItem();
//    // loop through all treeview items
//    int col = 0;
//    if (rootitem->hasChildren()) {
//        for (int row = 0; row < rootitem->rowCount(); row++) {
//            QStandardItem *chd = rootitem->child(row,col);
//            QModelIndex index = md->indexFromItem(chd);
//            QVariant data = model()->data(index);
//            QString text = data.toString();
//            std::string tag_str = text.toStdString();
//            int j = tag_str.find(" ");
//            std::string des = tag_str.substr(j+1);
//            bool result = boost::icontains(des, tag_find);
//            QModelIndex qmi = md->index(row, col, QModelIndex());
//            if (result) {
//                qfs->qmis.push_back(std::move(qmi));
////                Qmi_Found qf;
////                qmi = md->index(row, col, QModelIndex());
////                qfs.tag_find = tag_find;
//            }
//            find_all_sub_tags(tag_find, qmi);
//        }
//    }
//}



///*
// * Show found tag n
// */
//void TV_Recs::show_found_tag_n(int n) {
//    // check if n is valid
//    if (n < 0) {
//        return;
//    }
//    if (n + 1 > qfs->qmis.size()) {
//        return;
//    }
////    QModelIndex pmi = md->index(row, col, QModelIndex());
//    if (qfs->qmis[n].isValid()) {
//        scrollTo(qfs->qmis[n], QAbstractItemView::PositionAtTop);
//    }


////    QStandardItem *rootitem = md->invisibleRootItem();
////    int k = 0;
////    // loop through all treeview items
////    if (rootitem->hasChildren()) {
////        for (int row = 0; row < rootitem->rowCount(); row++) {
////            int col = 0;
////            QStandardItem *chd = rootitem->child(row,col);
////            QModelIndex index = md->indexFromItem(chd);
////            QVariant data = model()->data(index);
////            QString text = data.toString();
////            std::string tag_str = text.toStdString();
////            int j = tag_str.find(" ");
////            std::string des = tag_str.substr(j+1);
////            bool result = boost::icontains(des, tag_find);
////            if (result) {
////                k++;
////                if (k > n) {
//////                    mydebug2(__LINE__,__FILE__);
////                    QModelIndex pmi = md->index(row, col, QModelIndex());
////                    if (pmi.isValid()) {
////                        scrollTo(pmi, QAbstractItemView::PositionAtTop);
////                    }
//////                    mydebug2(__LINE__,__FILE__);
////                    break;
////                }
////            }
//////            mydebug2(__LINE__,__FILE__);
////        }
////    }
//}



///*
// * Find
// */
//void TV_Recs::btn_find_clicked(void) {
//    dia_tags->close();
//    //    DiaEditLine *dia_editline = new DiaEditLine(this);
//    std::unique_ptr<DiaEditLine> dia_editline = std::make_unique<DiaEditLine>(this);
//    dia_editline->init("find", "");
//    int res = dia_editline->exec();
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    if (res == QDialog::Accepted) {
//        // search string
//        std::string str2 = dia_editline->get_value();

////        std::unique_ptr<DiaTagFind> dia_tagfind = std::make_unique<DiaTagFind>(this);
//        DiaTagFind *dia_tagfind = new DiaTagFind();
//        dia_tagfind->init("find");
////        dia_prev_next_cancel->setModal(true);
////        connect(btn_makechild, &QPushButton::clicked, this, &TV_Recs::btn_makechild_clicked);

//        expandAll();

//        find_all_tags(str2);
//        qfs->tag_find = str2;
//        qfs->show_index = 0;
////        int res = dia_prev_next_cancel->exec();
////        show_tag_n = 0;
////        tag_find = str2;
//        show_found_tag_n(0);
//        connect(dia_tagfind, &DiaTagFind::diatagprev, this, &TV_Recs::show_prev_found_tag);
//        connect(dia_tagfind, &DiaTagFind::diatagnext, this, &TV_Recs::show_next_found_tag);
////        dia_tagfind->exec();

//        // --- DOC ---
//        // https://stackoverflow.com/questions/26107423/qt-setmodal-does-not-work
//        // You don't need to call setModal(false) at all, because false is default value already.
//        // As stated in the Qt docs:
//        //     This property holds whether show() should pop up the dialog as modal or modeless.
//        //     By default, this property is false and show() pops up the dialog as modeless. Setting his property to true is equivalent to setting QWidget::windowModality to Qt::ApplicationModal.
//        //     exec() ignores the value of this property and always pops up the dialog as modal.
//        // So, when you instantiate your realtimedlg object your should do this from the heap and just call show() method:
//        // realtimedlg* dlg = new realtimedlg(this);
//        // dlg->show();
//        // You don't need to call exec(). Calling of it makes your dialog modal.

//        dia_tagfind->show();
//    }
//}


///*
// * Get selected tags
// */
//std::vector<Tag> TV_Recs::get_selected_tags(void) {
//    std::vector<Tag> tags;
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    for (QModelIndex qmi_sel : indexes) {
//        QVariant data = model()->data(qmi_sel);
//        std::string tag_str = data.toString().toStdString();
//        Tag t = Tag::parse_id_space_des(tag_str);
//        tags.push_back(std::move(t));
//    }
//    return(tags);
//}


//// --- TODO ---
///*
// * Get parent tree tag
// */
//Tag TV_Recs::get_parent_tree_tag(QModelIndex qmi_cur) {
//    QModelIndex qmi_par = qmi_cur.parent();
//    QVariant datapar = model()->data(qmi_par);
//    Tag tag_par;
//    if (datapar.isValid()) {
//        // Selected tag is not a root tag
//        // get par id
//        tag_par = Tag::parse_id_space_des(datapar.toString().toStdString());

//    } else {
//        // Selected tag is a root tag
//    }
//    return(tag_par);
//}


////std::vector<Tag> TV_Recs::get_selected_tags(void) {
////    std::vector<Tag> tags;
////    QModelIndexList indexes = selectionModel()->selectedRows(0);
////    for (int j = 0; j < indexes.count(); j++) {
////        QModelIndex k = indexes.at(j);
////        QVariant data = model()->data(k);
////        std::string tag_str = data.toString().toStdString();
////        Tag tag = Tag::parse_id_space_des(tag_str);
//////        //        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//////        int id = k.data(Qt::DisplayRole).toInt();
////        tags.push_back(std::move(tag));
////    }
////    return(tags);
////}


///*
// * Add sibling tag
// */
//void TV_Recs::btn_add_sibling_clicked(void) {

//    dia_tags->close();

//    std::vector<Tag> seltags = get_selected_tags();
//    if (seltags.size() != 1) {
//        // Must be one (and only one) selected tag
//        return;
//    }

//    Tag tag_par = get_parent_tree_tag(selectionModel()->selectedIndexes().at(0));

//    //    // Get selected tag
//    //    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    //    if (indexes.size() != 1) {
//    //        // Must be one (and only one) selected tag
//    //        return;
//    //    }
//    //    QModelIndex selectedIndex = indexes.at(0);
//    //    QVariant data = model()->data(selectedIndex);
//    //    std::string tag_str = data.toString().toStdString();
//    //    Tag tag1 = Tag::parse_id_space_des(tag_str);

//    // --- TODO ---
//    DiaEditLine *dia_editline = new DiaEditLine(this);
//    dia_editline->init("new sibling tag", "");
//    // input new value
//    int res = dia_editline->exec();
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    if (res == QDialog::Accepted) {
//        std::string new_tag_des = dia_editline->get_value();
//        Tag new_tag;
//        new_tag.des = new_tag_des;

//        // Check if a sibling des already exists
//        bool res = db_chk_sibling_exists(db, new_tag_des, tag_par);
//        if (res) {
//            // 'sibling des' exists, do nothing
//            db->close();
//            return;
//        } else {
//            // 'sibling des' does not exist, create new tree item
//            // get parent tree item
//            QModelIndex qmi_par = selectionModel()->selectedIndexes().at(0).parent();
//            QVariant datapar = model()->data(qmi_par);
//            if (datapar.isValid()) {
//                // Parent tree item exists, selected tag is not a root tag

//                // create new tag in DB
//                db_add_tag(db, new_tag.des);
//                Tag new_tag = db_get_last_tag(db);

//                // create new item and insert in TREEVIEW
//                // ... get parent TREEVIEW item
//                QStandardItem *par_item = md->itemFromIndex(qmi_par);
//                QVariant datapar = model()->data(qmi_par);
//                std::string par_str = datapar.toString().toStdString();
//                Tag tag_par = Tag::parse_id_space_des(par_str);
//                //                Tag tag_par = get_tag_from_QModelIndex(qmi_par);

//                // ... create new TREEVIEW item
//                QString tagid_qstr = QString::number(new_tag.id);
//                QString tagdes_qstr = QString::fromStdString(new_tag.des);
//                QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
//                // ... insert new item in TREEVIEW
//                par_item->appendRow(new_item);

//                // make child in DB
//                db_add_tagparchd(db, tag_par.id, new_tag.id);
//            } else {
//                // Parent tree item does not exist, selected tag is a root tag

//                // create new tag in DB
//                db_add_tag(db, new_tag.des);
//                Tag new_tag = db_get_last_tag(db);

//                // create new item and insert in TREEVIEW
//                // ... create new TREEVIEW item
//                QString tagid_qstr = QString::number(new_tag.id);
//                QString tagdes_qstr = QString::fromStdString(new_tag.des);
//                QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
//                // ... insert new item in TREEVIEW
//                QStandardItem *rootitem = md->invisibleRootItem();
//                rootitem->appendRow(new_item);
//            }
//        }
//    }
//}


///*
// * Get tag from QModelIndex
// */
//Tag TV_Recs::get_tag_from_QModelIndex(QModelIndex qmi) {
//    //    QStandardItem *item = md->itemFromIndex(qmi);
//    QVariant datapar = model()->data(qmi);
//    std::string tag_str = datapar.toString().toStdString();
//    Tag t = Tag::parse_id_space_des(tag_str);
//    return(t);
//}


////                std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;




////        QModelIndex mi_par = selectedIndex.parent();
////        QVariant datapar = model()->data(mi_par);
////        if (datapar.isValid()) {
////            // Selected tag is not a root tag
////            // get par id
////            std::string par_str = datapar.toString().toStdString();
////            Tag par = Tag::parse_id_space_des(par_str);

////        } else {

////        }






////        bool res = tag1.find_chd_des(db, new_tag_des);
////        if (res) {
////            // Tag already exists, do nothing
////            return;
////        }

////        // Add new tag in DB
////        try {
////            db_add_tag(db, new_tag_des);
////        } catch (MyEx& ex) {
////            std::cout << ex.what() << ex.get_info() << std::endl;
////            std::cout << "Function: " << ex.get_func() << std::endl;
////            return;
////        }

////        // Create new tag tree item
////        Tag last_inserted = db_get_last_tag(db);
////        QString tagid_qstr = QString::number(last_inserted.id);
////        QString tagdes_qstr = QString::fromStdString(last_inserted.des);
////        QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);

////        // Add new tree item
////        // get tree parent item
////        QModelIndex mi_par = selectedIndex.parent();
////        QVariant datapar = model()->data(mi_par);
////        if (datapar.isValid()) {
////            // Selected tag is not a root tag
////            // get par id
////            std::string par_str = datapar.toString().toStdString();
////            Tag par = Tag::parse_id_space_des(par_str);
////            std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////            // get par tree item
////            QStandardItem *par_item = md->itemFromIndex(mi_par);
////            // add new tag in TreeView
////            par_item->appendRow(new_item);
////            // update DB: set new tag as child of par tag
////            try {
////                db_add_tagparchd(db, par.id, last_inserted.id);
////            } catch (MyEx& ex) {
////                std::cout << ex.what() << ex.get_info() << std::endl;
////                std::cout << "Function: " << ex.get_func() << std::endl;
////                return;
////            }
////        } else {
////            // Selected tag is a root tag
////            std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////        }





//////        // Add new tag in TreeView
//////        // Get parent tag
//////        QModelIndex mi_par = selectedIndex.parent();
//////        QVariant datapar = model()->data(mi_par);
//////        std::string par_str = datapar.toString().toStdString();
//////        Tag par = Tag::parse_id_space_des(par_str);
//////        QString tagid_qstr = QString::number(last_inserted.id);
//////        QString tagdes_qstr = QString::fromStdString(last_inserted.des);
//////        QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
//////        if (datapar.isValid()) {
//////            // Selected tag is not a root tag
//////            QStandardItem *par_item = md->itemFromIndex(mi_par);
//////            // Add new tag in TreeView
//////            par_item->appendRow(new_item);

//////            // Set new tag as child of ...
//////            try {
//////                db_add_tagparchd(db, par.id, last_inserted.id);
//////            } catch (MyEx& ex) {
//////                std::cout << ex.what() << ex.get_info() << std::endl;
//////                std::cout << "Function: " << ex.get_func() << std::endl;
//////                return;
//////            }

//////        } else {
//////            // Selected tag is a root tag
//////            // add new tag in TreeView
//////            QStandardItem *rootitem = md->invisibleRootItem();
//////            // Add new tag in TreeView
//////            rootitem->appendRow(new_item);
//////        }



///*
// * Add child tag
// */
//void TV_Recs::btn_add_child_clicked(void) {

//    dia_tags->close();

//    // Get selected tag
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    if (indexes.size() != 1) {
//        // Must be one (and only one) selected tag
//        return;
//    }
//    QModelIndex selectedIndex = indexes.at(0);
//    QVariant data = model()->data(selectedIndex);
//    std::string tag_str = data.toString().toStdString();
//    Tag tag1 = Tag::parse_id_space_des(tag_str);

//    DiaEditLine *dia_editline = new DiaEditLine(this);
//    dia_editline->init("new child tag value", "");
//    // input new value
//    int res = dia_editline->exec();
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    if (res == QDialog::Accepted) {

//        std::string new_tag_des = dia_editline->get_value();

//        // --- TODO ---

//        // If tag.des already exists, do nothing
//        std::vector<Tag> chds = db_get_chds(db, tag1);
//        for (Tag chd : chds) {
//            if (chd.des == new_tag_des) {
//                // tag.des already exists, do nothing
//                return;
//            }
//        }

//        // Add new tag in DB
//        try {
//            db_add_tag(db, new_tag_des);
//        } catch (MyEx& ex) {
//            std::cout << ex.what() << ex.get_info() << std::endl;
//            std::cout << "Function: " << ex.get_func() << std::endl;
//            return;
//        }

//        Tag last_inserted = db_get_last_tag(db);
//        // Add new tag in TreeView
//        // Get parent tag
//        QVariant datapar = model()->data(selectedIndex);
//        std::string par_str = datapar.toString().toStdString();
//        Tag par = Tag::parse_id_space_des(par_str);
//        QString tagid_qstr = QString::number(last_inserted.id);
//        QString tagdes_qstr = QString::fromStdString(last_inserted.des);
//        QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
//        if (datapar.isValid()) {
//            QStandardItem *par_item = md->itemFromIndex(selectedIndex);
//            // Add new tag in TreeView
//            par_item->appendRow(new_item);
//            // Set new tag as child of selected tag
//            try {
//                db_add_tagparchd(db, par.id, last_inserted.id);
//            } catch (MyEx& ex) {
//                std::cout << ex.what() << ex.get_info() << std::endl;
//                std::cout << "Function: " << ex.get_func() << std::endl;
//                return;
//            }
//        }
//    }
//}


/////*
//// * Add new note (and fil) as child of selected tag
//// */
////void TreVieTags::btn_addnote_clicked(void) {
////    dia_tags->close();

////    // Get selected tag
////    // Only one selected tag ... if more tags do nothing
////    QModelIndexList indexes = selectionModel()->selectedIndexes();
////    if (indexes.size() != 1) {
////        return;
////    }
////    QModelIndex selectedIndex = indexes.at(0);
////    QVariant data = model()->data(selectedIndex);
////    std::string tag_str = data.toString().toStdString();
////    Tag par = Tag::parse(tag_str);

////    // Input new note value
////    DiaTextEdit *dia_textedit = new DiaTextEdit(this);
////    dia_textedit->init("new note value", "");
////    int res = dia_textedit->exec();
////    if (res == QDialog::Accepted) {
////        // store new value
////        std::string note = dia_textedit->get_value();
//////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;

////        // Create new fil and note
////        try {
////            db_insert_newnote(db, note);
////        } catch (MyEx& ex) {
////            std::cout << ex.what() << ex.get_info() << std::endl;
////            std::cout << "Function: " << ex.get_func() << std::endl;
////            return;
////        }
//////        if (err.des.size() > 0) {
//////            err.gest(__LINE__, __FILE__);
//////            return;
//////        }

////        // Make new fil as child of selected tag
////        // Get last fil ID
////        Fil fil;
////        try {
////            fil = db_get_last_fil(db);
////        } catch (MyEx& ex) {
////            std::cout << ex.what() << ex.get_info() << std::endl;
////            std::cout << "Function: " << ex.get_func() << std::endl;
////            return;
////        }
//////        if (err.des.size() > 0) {
//////            err.gest(__LINE__, __FILE__);
//////            return;
//////        }

////        // Make fil as child of selected tag
////        std::vector<int> filids;
////        filids.push_back(fil.id);

////        try {
////            db_add_tag_to_fils(db, par.id, filids);
////        } catch (MyEx& ex) {
////            std::cout << ex.what() << ex.get_info() << std::endl;
////            std::cout << "Function: " << ex.get_func() << std::endl;
////            return;
////        }
//////        if (err.des.size() > 0) {
//////            err.gest(__LINE__, __FILE__);
//////            return;
//////        }
////    }
////}



///*
// * Add tag as child of selected tag
// */
//void TV_Recs::btn_addtagchd_clicked(void) {
//    dia_tags->close();

//    // Get selected tag
//    // Only one selected tag ... if more tags do nothing
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    if (indexes.size() != 1) {
//        return;
//    }
//    QModelIndex selectedIndex = indexes.at(0);
//    QVariant data = model()->data(selectedIndex);
//    std::string tag_str = data.toString().toStdString();
//    Tag par = Tag::parse_id_space_des(tag_str);

//    // Input new tag value
//    DiaEditLine *dia_editline = new DiaEditLine(this);
//    dia_editline->init("new tag value", "");
//    int res = dia_editline->exec();
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    if (res == QDialog::Accepted) {
//        // store new value
//        std::string des = dia_editline->get_value();

//        try {
//            db_add_tag(db, des);
//            Tag last_inserted = db_get_last_tag(db);
//            chk_and_make_inf(par, last_inserted);
//        } catch (MyEx& ex) {
//            std::cout << ex.what() << ex.get_info() << std::endl;
//            std::cout << "Function: " << ex.get_func() << std::endl;
//            return;
//        }

//        //        db_add_tag(db, des, err);
//        //        if (err.des.size() > 0) {
//        //            err.gest(__LINE__, __FILE__);
//        //            return;
//        //        }
//        //        Tag last_inserted = db_get_last_tag(db, err);
//        //        if (err.des.size() > 0) {
//        //            err.gest(__LINE__, __FILE__);
//        //            return;
//        //        }

//        //        // Set as child of selected tag
//        //        // check if tag par is inf of one of selected tags (avoid infinite tree loop)
//        //        chk_and_make_inf(par, last_inserted, err);
//        //        if (err.des.size() > 0) {
//        //            err.gest(__LINE__, __FILE__);
//        //            return;
//        //        }
//        //        md->beginInsertRows();
//        db_reload_tree();
//    }
//}

/////*
//// * Add selected tag(s) as child of another tag
//// */
////void TreVieTags::btn_add_chds_to_pad_clicked(void) {
////    dia_tags->close();

////    std::vector<Tag> chds = get_selected_tags();

////    DiaListChoice *dia_listchoice = new DiaListChoice(this);

////    std::vector<Tag> tags = db_rd_tags(db);
////    std::vector<std::string> tags_str;
////    for (Tag tag : tags) {
////        std::string tag_str = std::to_string(tag.id) + " " + tag.des;
////        tags_str.push_back(std::move(tag_str));
////    }
////    std::string prompt_str;
////    if (chds.size() == 1) {
////        prompt_str = "tag:" + chds.at(0).des + " - make inf of tag ...";
////    } else {
////        prompt_str = std::to_string(chds.size()) + " tags make inf of tag ...";
////    }
////    dia_listchoice->init(prompt_str, tags_str);
////    int res = dia_listchoice->exec();
////    if (res == QDialog::Accepted) {
////        // get new par tag choice
////        std::string tag_par_str = dia_listchoice->get_value();
////        Tag tag_par = Tag::parse(tag_par_str);

////        // check if tag par is inf of one of selected tags (avoid infinite tree loop)
////        int err = 0;
////        chk_and_make_inf(tag_par, chds, err);
////        if (err != 0) {
////            // err, do nothing
////            std::cerr << "ERR - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////            return;
////        }
////        db_reload_tree();
////    }


////    std::vector<Tag> chds = get_selected_tags();

////    dia_listchoice->init(prompt_str, tags_str);
////    int res = dia_listchoice->exec();
////    if (res == QDialog::Accepted) {
////        // get new par tag choice
////        std::string tag_par_str = dia_listchoice->get_value();
////        Tag tag_par = Tag::parse(tag_par_str);


//////    // Get selected tags
//////    QModelIndexList indexes = selectionModel()->selectedIndexes();
//////    std::vector<Tag> chds;
//////    for (QModelIndex mi : indexes) {
//////        QVariant data = model()->data(mi);
//////        std::string chd_str = data.toString().toStdString();
//////        Tag chd = Tag::parse(chd_str);
//////        chds.push_back(chd);
//////    }
//////    QModelIndex selectedIndex = indexes.at(0);
//////    QVariant data = model()->data(selectedIndex);
//////    std::string tag_str = data.toString().toStdString();
//////    Tag par = Tag::parse(tag_str);

////    // Input new tag value
////    DiaEditLine *dia_editline = new DiaEditLine(this);
////    dia_editline->init("new tag value", "");
////    int res = dia_editline->exec();
//////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////    if (res == QDialog::Accepted) {
////        // store new value
////        std::string des = dia_editline->get_value();
////        int err = 0;
////        db_add_tag(db, des, err);
////        if (err > 0) {
////            return;
////        }
////        Tag last_inserted = db_get_last_tag(db);

////        // Set as child of selected tag
////        // check if tag par is inf of one of selected tags (avoid infinite tree loop)
////        err = 0;
////        chk_and_make_inf(par, last_inserted, err);
////        if (err != 0) {
////            // err, do nothing
////            std::cerr << "ERR - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////            return;
////        }
////        db_reload_tree();
////    }
////}


///*
// * Rename Ttag
// */
//void TV_Recs::btn_rentag_clicked(void) {
//    dia_tags->close();

//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    // Only one tag
//    if (indexes.size() != 1) {
//        return;
//    }

//    QModelIndex selectedIndex = indexes.at(0);
//    QVariant data = model()->data(selectedIndex);
//    std::string tag_str = data.toString().toStdString();
//    //    QModelIndex index = currentIndex();

//    //    // TAG_ID
//    //    QModelIndex index2 = model()->index(index.row(), COL_TAG_ID, QModelIndex());
//    //    QVariant data = model()->data(index2);
//    //    std::string tag_str = data.toString().toStdString();
//    Tag tag = Tag::parse_id_space_des(tag_str);
//    //    int j = tag_str.find(" ");
//    //    std::string tagid_str = tag_str.substr(0,j);
//    //    int tagid = std::stoi(tagid_str);

//    //    // TAG_DES
//    //    std::string tagdes = tag_str.substr(j);

//    DiaEditLine *dia_editline = new DiaEditLine(this);
//    dia_editline->init(std::to_string(tag.id), tag.des);
//    int res = dia_editline->exec();
//    if (res == QDialog::Accepted) {
//        // store new value
//        std::string new_des = dia_editline->get_value();
//        if (new_des != tag.des) {

//            try {
//                db_ren_tag(db, tag.id, new_des);
//            } catch (MyEx& ex) {
//                std::cout << ex.what() << ex.get_info() << std::endl;
//                std::cout << "Function: " << ex.get_func() << std::endl;
//                return;
//            }

//            QStandardItem *item = md->itemFromIndex(indexes.at(0));
//            item->setText(QString::number(tag.id) + " " + QString::fromStdString(new_des));

//            // reload and show all tags
//            //        std::vector<Tag> tags = db_rd_roottags(db);
//            //        md->clear();
//            //        add_rootitems(tags);
//            //        std::vector<Tag> tags = db_rd_roottags(db);
////            db_reload_tree();
//            //            std::vector<Tag> tags = db_rd_roottags(db);
//            //            md->clear();
//            //            add_alltags(tags);
//        }
//    }
//}


///*
// * Remove tag if not empty
// */
//void TV_Recs::btn_deltag_clicked(void) {

//    dia_tags->close();

//    // Only one tag
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    if (indexes.size() != 1) {
//        // No "one tag" selected ... do nothing
//        return;
//    }

//    QModelIndex selectedIndex = indexes.at(0);
//    QVariant data = model()->data(selectedIndex);
//    std::string tag_str = data.toString().toStdString();
//    Tag tag = Tag::parse_id_space_des(tag_str);

//    DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//    dia_msg_ok_cancel->init("delete tag - " + std::to_string(tag.id) + " " + tag.des);
//    int res = dia_msg_ok_cancel->exec();
//    if (res == QDialog::Accepted) {
//        // remove tag, if has no child tags and has no child images

//        // If has childs images ... then do nothing
//        std::vector<Fil> imgs;
//        try {
//            imgs = db_get_imgs_by_tagid(db, tag.id);
//        } catch (MyEx& ex) {
//            std::cout << ex.what() << ex.get_info() << std::endl;
//            std::cout << "Function: " << ex.get_func() << std::endl;
//            return;
//        }
//        std::vector<Tag> chds;
//        if (imgs.size() == 0) {
//            // is empty, test if has childs
//            try {
//                chds = db_get_chds(db, tag);
//            } catch (MyEx& ex) {
//                std::cout << ex.what() << ex.get_info() << std::endl;
//                std::cout << "Function: " << ex.get_func() << std::endl;
//                return;
//            }
//            if (chds.size() == 0) {
//                // has no child tags, can delete
//                try {
//                    db_del_tag(db, tag.id);
//                    //                    db_reload_tree();
//                    db_del_tag_rel(db, tag.id);
//                } catch (MyEx& ex) {
//                    std::cout << ex.what() << ex.get_info() << std::endl;
//                    std::cout << "Function: " << ex.get_func() << std::endl;
//                    return;
//                }

//                // Remove tag from TreeView
//                QModelIndex mi_par = selectedIndex.parent();
//                md->removeRow(selectedIndex.row(), mi_par);

//                //db_reload_tree();
//            } else {
//                // tag has childs, cannot delete it
//                DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//                dia_msg_ok_cancel->init("tag has childs, no delete");
//                dia_msg_ok_cancel->exec();
//            }
//        } else {
//            // tag has images, do nothing
//            DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//            dia_msg_ok_cancel->init("tag has images, do nothing");
//            dia_msg_ok_cancel->exec();
//        }
//    }
//}



//void TV_Recs::chk_and_make_inf(Tag par, Tag chd) {
//    try {
//        db_add_tagparchd(db, par.id, chd.id);
//        bool res = chk_tag_sup_inf(db, par.id, chd.id);
//        if (!res) {
//            // get confirm
//            DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//            dia_msg_ok_cancel->init("copy <" + chd.des + "> under <" + std::to_string(par.id) + " " + par.des + ">");
//            int res2 = dia_msg_ok_cancel->exec();
//            if (res2 == QDialog::Accepted) {
//                db_add_tagparchd(db, par.id, chd.id);
//                db_reload_tree();
//            }
//        } else {
//            DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//            dia_msg_ok_cancel->init("ERR - tag <" + chd.des + "> is already under tag <" + std::to_string(par.id) + " " + par.des + "> do nothing");
//            dia_msg_ok_cancel->exec();
//        }
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }
//}


/////*
//// * Add pad to chd
//// */
////void TreVieTags::db_add_pad(Tag par, Tag chd, int &err) {
////    if (par == chd) {
////        return;
////    }
////    db_add_tagparchd(db, par.id, chd.id);
////}



//void TV_Recs::chk_and_make_inf(Tag par, std::vector<Tag> chds) {

//    bool found = false;
//    Tag tag_inf_2;
//    try {
//        for (Tag tag_inf : chds) {
//            bool res = chk_tag_sup_inf(db, par.id, tag_inf.id);
//            if (res) {
//                found = true;
//                tag_inf_2.id = tag_inf.id;
//                tag_inf_2.des = tag_inf.des;
//                break;
//            }
//        }
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }

//    if (!found) {
//        // get confirm
//        DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//        dia_msg_ok_cancel->init("move " + std::to_string(chds.size()) + "tag(s) under tag:" + std::to_string(par.id) + " " + par.des);
//        int res2 = dia_msg_ok_cancel->exec();
//        if (res2 == QDialog::Accepted) {
//            //            Tag tag_par = Tag::parse(tag_par_str);
//            QProgressBar *pb = parent->pb;
//            pb->setMinimum(0);
//            int mm;
//            if (chds.size() > 0) {
//                mm = chds.size();
//            } else {
//                mm = 1;
//            }
//            pb->setMaximum(mm);
//            int j = 0;
//            for (Tag chd : chds) {
//                pb->setValue(j);
//                try {
//                    db_add_tagparchd(db, par.id, chd.id);
//                } catch (MyEx& ex) {
//                    std::cout << ex.what() << ex.get_info() << std::endl;
//                    std::cout << "Function: " << ex.get_func() << std::endl;
//                    return;
//                }
//                j++;
//            }
//            pb->setValue(0);
//            db_reload_tree();
//        }
//    } else {
//        DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//        dia_msg_ok_cancel->init("ERR - tag <" + tag_inf_2.des + "> is already under tag <" + std::to_string(par.id) + " " + par.des + "> do nothing");
//        dia_msg_ok_cancel->exec();
//    }
//}


///*
// * Create new tag and load files
// * from selected directory (dialog)
// */
//void TV_Recs::btn_load_dir_files(void) {

//    // --- TODO ---

//    dia_tags->close();

//    //    // Get selected tag
//    //    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    //    if (indexes.size() != 1) {
//    //        // Must be one (and only one) selected tag
//    //        return;
//    //    }
//    //    QModelIndex selectedIndex = indexes.at(0);
//    //    QVariant data = model()->data(selectedIndex);
//    //    std::string tag_str = data.toString().toStdString();
//    //    Tag tag1 = Tag::parse(tag_str);

//    //    // Select files to load
//    //    QFileDialog dialog(this);
//    //    dialog.setViewMode(QFileDialog::Detail);
//    ////    dialog.setFileMode(QFileDialog::Directory);
//    //    dialog.setFileMode(QFileDialog::ExistingFiles);
//    //    if (dialog.exec() == QFileDialog::Accepted) {
//    //        QStringList selfiles = dialog.selectedFiles();
//    //        dialog.close();
//    //        if (selfiles.size() < 1) {
//    //            return;
//    //        }

//    //        // Get new tag name -> parent directory
//    //        // get parent directory
//    //        QFile qf(selfiles[0]);
//    //        QFileInfo qfi(qf);
//    //        QDir par_dir = qfi.dir();
//    //        QString par_absdir = par_dir.absolutePath();

//    ////        std::string new_tag_des = dia_editline->get_value();

//    //        // Add new tag in DB
//    //        try {
//    //            mydebug2(__LINE__,__FILE__);
//    //            db_add_tag(db, par_absdir.toStdString());
//    //        } catch (MyEx& ex) {
//    //            std::cout << ex.what() << ex.get_info() << std::endl;
//    //            std::cout << "Function: " << ex.get_func() << std::endl;
//    //            return;
//    //        }

//    //        Tag new_tag = db_get_last_tag(db);

//    //        // --- Add new tag in TreeView
//    //        // Get parent tag (selected TreeView tag)
//    //        QVariant datapar = model()->data(selectedIndex);
//    //        std::string par_str = datapar.toString().toStdString();
//    //        Tag par = Tag::parse(par_str);
//    //        QString tagid_qstr = QString::number(new_tag.id);
//    //        QString tagdes_qstr = QString::fromStdString(new_tag.des);
//    //        QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
//    //        if (datapar.isValid()) {
//    //            QStandardItem *par_item = md->itemFromIndex(selectedIndex);
//    //            // Add new tag in TreeView
//    //            par_item->appendRow(new_item);
//    //            // Set new tag as child of selected tag
//    //            try {
//    //                db_add_tagparchd(db, par.id, new_tag.id);
//    //            } catch (MyEx& ex) {
//    //                std::cout << ex.what() << ex.get_info() << std::endl;
//    //                std::cout << "Function: " << ex.get_func() << std::endl;
//    //                return;
//    //            }
//    //        }


//    //        // Add new imgs to db
//    //        std::vector<std::string> ff;
//    //        std::vector<int> loaded_imgids;
//    //        int duplicated = 0;
//    ////        bool local_store = false;
//    ////        if (conf->map_conf["db_copy"] == "true") local_store = true; else local_store = false;

//    //        for (QString selected_file : selfiles) {
//    //            ff.push_back(selected_file.toStdString());
//    //        }
//    //        size_t max_files = MAX_LOADED_FILES;
//    //        try {
//    //            loaded_imgids = db_insert_imgs(db, ff, parent->pb, conf, max_files, duplicated);
//    //            db_add_tag_to_imgs(db, new_tag.id, loaded_imgids);
//    //        } catch (MyEx& ex) {
//    //            std::cout << ex.what() << ex.get_info() << std::endl;
//    //            std::cout << "Function: " << ex.get_func() << std::endl;
//    //            return;
//    //        }

//    ////        int added = 0;
//    ////        int duplicated = 0;

//    ////        QProgressBar *pb = parent->pb;
//    ////        pb->setMinimum(0);
//    ////        int mm;
//    ////        if (selfiles.size() > 0) {
//    ////            mm = selfiles.size();
//    ////        } else {
//    ////            mm = 1;
//    ////        }
//    ////        pb->setMaximum(mm);

//    ////        int j = 0;
//    ////        for (QString selected_file : selfiles) {
//    ////            if (j > MAX_LOADED_FILES) {
//    ////                break;
//    ////            }
//    ////            pb->setValue(j);
//    ////            std::string f = selected_file.toStdString();
//    ////            std::cerr << f << std::endl;

//    ////            // calc MD5
//    ////            std::string md5 = md5_3(f);

//    ////            // store doc file
//    ////            if (conf->map_conf["db_copy"] == "true") {
//    ////                fs_store(f, md5, conf);
//    ////            }

//    ////            // Check if file exists ...
//    ////            // ... if new insert
//    ////            try {
//    ////                int n = db_insert_fil(db, f, md5);
//    ////                if (n > 0) {
//    ////                    added++;
//    ////                } else {
//    ////                    duplicated++;
//    ////                }
//    ////            } catch (MyEx& ex) {
//    ////                std::cout << ex.what() << ex.get_info() << std::endl;
//    ////                std::cout << "Function: " << ex.get_func() << std::endl;
//    ////                return;
//    ////            }
//    ////            j++;
//    ////        }
//    ////        pb->setValue(0);
//    ////        if (j > MAX_LOADED_FILES) {
//    ////            DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//    ////            dia_msg_ok_cancel->init("Warning: overflow - MAX_LOADED_FILES reached up");
//    ////            dia_msg_ok_cancel->exec();
//    ////        }
//    //        if (loaded_imgids.size() > max_files) {
//    //            DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//    //            dia_msg_ok_cancel->init("Warning: overflow - MAX_LOADED_FILES reached up");
//    //            dia_msg_ok_cancel->exec();
//    //        }
//    //        // Message
//    //        parent->lbl_msg->setText("new FILES:" + QString::number(loaded_imgids.size()) + "   duplicated FILES:" + QString::number(duplicated));
//    //    }
//}



///*
// * Load files as childs of selected tag
// */
//void TV_Recs::btn_load_files(void) {

//    dia_tags->close();

//    //    // Get selected tag
//    //    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    //    if (indexes.size() != 1) {
//    //        // Must be one (and only one) selected tag
//    //        return;
//    //    }
//    //    QModelIndex selectedIndex = indexes.at(0);
//    //    QVariant data = model()->data(selectedIndex);
//    //    std::string selected_tag_str = data.toString().toStdString();
//    //    Tag selected_tag = Tag::parse(selected_tag_str);

//    //    // Select files to load
//    //    QFileDialog dialog(this);
//    //    dialog.setViewMode(QFileDialog::Detail);
//    ////    dialog.setFileMode(QFileDialog::Directory);
//    //    dialog.setFileMode(QFileDialog::ExistingFiles);
//    //    if (dialog.exec() == QFileDialog::Accepted) {
//    //        QStringList selfiles = dialog.selectedFiles();
//    //        dialog.close();
//    //        if (selfiles.size() < 1) {
//    //            return;
//    //        }

//    //        // Add new imgs to db
//    //        std::vector<std::string> ff;
//    //        std::vector<int> loaded_imgids;
//    //        int duplicated = 0;
//    //        for (QString selected_file : selfiles) {
//    //            ff.push_back(selected_file.toStdString());
//    //        }
//    //        int max_files = MAX_LOADED_FILES;
//    //        try {
//    //            loaded_imgids = db_insert_img(db, ff, parent->pb, conf, max_files, duplicated);
//    //            db_add_tag_to_imgs(db, selected_tag.id, loaded_imgids);
//    //        } catch (MyEx& ex) {
//    //            std::cout << ex.what() << ex.get_info() << std::endl;
//    //            std::cout << "Function: " << ex.get_func() << std::endl;
//    //            return;
//    //        }
//    //        if (loaded_imgids.size() > max_files) {
//    //            DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//    //            dia_msg_ok_cancel->init("Warning: overflow - MAX_LOADED_FILES reached up");
//    //            dia_msg_ok_cancel->exec();
//    //        }
//    //        // Message
//    //        parent->lbl_msg->setText("new FILES:" + QString::number(loaded_imgids.size()) + "   duplicated FILES:" + QString::number(duplicated));
//    //    }
//}



//void TV_Recs::btn_makeinf_clicked(void) {
//    dia_tags->close();

//    std::vector<Tag> chds = get_selected_tags();

//    DiaListChoice *dia_listchoice = new DiaListChoice(this);

//    std::vector<Tag> tags = db_get_tags(db);
//    std::vector<std::string> tags_str;
//    for (Tag tag : tags) {
//        std::string tag_str = std::to_string(tag.id) + " " + tag.des;
//        tags_str.push_back(std::move(tag_str));
//    }
//    std::string prompt_str;
//    if (chds.size() == 1) {
//        prompt_str = "tag:" + chds.at(0).des + " - make inf of tag ...";
//    } else {
//        prompt_str = std::to_string(chds.size()) + " tags make inf of tag ...";
//    }
//    dia_listchoice->init(prompt_str, tags_str);
//    int res = dia_listchoice->exec();
//    try {
//        if (res == QDialog::Accepted) {
//            // get new par tag choice
//            std::string tag_par_str = dia_listchoice->get_value();
//            Tag tag_par = Tag::parse_id_space_des(tag_par_str);
//            chk_and_make_inf(tag_par, chds);
//            db_reload_tree();
//        }
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }
//}




/////*
//// * Copy Tag
//// */
////void TV_Recs::copy(void) {

////}



////Tag TV_Recs::get_marked_tag(void) {
////    int id = parent->lbl_markedtagid->text().toInt();
////    std::string des = parent->lbl_markedtagdes->text().toStdString();
////    Tag t(id,des);
////    return(t);
////}


////void TV_Recs::add_new_parent(Tag marked, Tag par) {

////}


///*
// * Add marked tag as child of selected tag (new parent)
// */
//void TV_Recs::btn_paste_clicked(void) {

//    // --- TODO ---
//    dia_tags->close();

//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    if (indexes.size() != 1) {
//        // Not "one tag" selected ... do nothing
//        return;
//    }
//    QVariant data = model()->data(indexes[0]);
//    std::string par_tag_str = data.toString().toStdString();
//    Tag par_tag = Tag::parse_id_space_des(par_tag_str);
//    QStandardItem *par_item = this->md->itemFromIndex(indexes[0]);
//    std::string s = parent->lbl_seltag->text().toStdString();
//    // get last tag
//    // ... search "\n"
//    int n = s.find_last_of('\n',s.size()-1);
//    std::string sel_tag_str = s.substr(n+1);
//    QStandardItem *marked_item = new QStandardItem(QString::fromStdString(sel_tag_str));
//    par_item->appendRow(marked_item);

//    // ... adjust DB







////    // Cut tag from old parent and paste under new selected parent
////    // ... get marked tag
////    Tag marked = get_marked_tag();
////    // ...paste under new parent
////    add_new_parent(marked, par);



////    DiaListChoice *dia_listchoice = new DiaListChoice(this);

////    std::vector<Tag> tags = db_get_tags(db);
////    std::vector<std::string> tags_str;
////    for (Tag tag : tags) {
////        std::string tag_str = std::to_string(tag.id) + " " + tag.des;
////        tags_str.push_back(std::move(tag_str));
////    }
////    std::string prompt_str;
////    if (chds.size() == 1) {
////        prompt_str = "tag:" + chds.at(0).des + " - make inf of tag ...";
////    } else {
////        prompt_str = std::to_string(chds.size()) + " tags make inf of tag ...";
////    }
////    dia_listchoice->init(prompt_str, tags_str);
////    int res = dia_listchoice->exec();
////    try {
////        if (res == QDialog::Accepted) {
////            // get new par tag choice
////            std::string tag_par_str = dia_listchoice->get_value();
////            Tag tag_par = Tag::parse_id_space_des(tag_par_str);
////            chk_and_make_inf(tag_par, chds);
////            db_reload_tree();
////        }
////    } catch (MyEx& ex) {
////        std::cout << ex.what() << ex.get_info() << std::endl;
////        std::cout << "Function: " << ex.get_func() << std::endl;
////        return;
////    }
//}


///*
// * Make seleted tags as child of marked tag
// * (marked tag is showed on status line)
// */
//void TV_Recs::btn_makeinfofmarkedtag_clicked(void) {
//    dia_tags->close();

//    std::vector<Tag> chds = get_selected_tags();
//    if (chds.size() < 1) {
//        return;
//    }

//    // get par marked tag , if any
//    Tag marked_tag = parent->get_marked_tag();
//    try {
//        if (marked_tag.id >= 0) {
//            // marked tag exist, continue
//            // check if tag par is inf of one of selected tags (avoid infinite tree loop)
//            chk_and_make_inf(marked_tag, chds);
//            db_reload_tree();
//        }
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }
//}


///*
// * Make current tag child of other tag
// */
//void TV_Recs::btn_makechild_clicked(void) {
//    dia_tags->close();
//    std::vector<Tag> chds = get_selected_tags();
//    if (chds.size() != 1) {
//        return;
//    }
//    // --- TODO ---
//    // One tag is selected
//    // Choice parent tag
//    DiaListChoice *dia_listchoice = new DiaListChoice(this);
//    // Get all tags
//    std::vector<Tag> tags = db_get_tags(db);
//    std::vector<std::string> tags_str_vec;
//    for (Tag t : tags) {
//        std::string tag_str = t.to_string();
//        tags_str_vec.push_back(std::move(tag_str));
//    }
//    // show all tags for choice
//    std::string prompt_str = "choice parent tag";
//    dia_listchoice->init(prompt_str, tags_str_vec);
//    int res = dia_listchoice->exec();
//    if (res == QDialog::Accepted) {
//        // get parent tag
//        std::string tag_par_str = dia_listchoice->get_value();
//        Tag tag_par = Tag::parse_id_space_des(tag_par_str);
//        //        std::cout << ex.what() << ex.get_info() << std::endl;
//        try {
//            chds[0].add_par(db, tag_par);
//            //            std::vector<Tag> tag_chain = db_get_tag_chain(db, tag_par.id);
//        } catch (MyEx& ex) {
//            std::cout << ex.what() << ex.get_info() << std::endl;
//            std::cout << "Function: " << ex.get_func() << std::endl;
//            return;
//        }
//        mydebug2(__LINE__,__FILE__);
//    }
//}


///*
// * Make seleted tag as pad of marked tag
// * (marked tag is showed on status line)
// */
//void TV_Recs::btn_makepadofmarkedtag_clicked(void) {

//    dia_tags->close();

//    // Get marked tag (child tag)
//    int chd_id = parent->lbl_markedtagid->text().toInt();
//    std::string chd_des = parent->lbl_markedtagdes->text().toStdString();

//    // Get parent tag
//    // --- Only one tag
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    if (indexes.size() != 1) {
//        // Not "one tag" selected ... do nothing
//        return;
//    }
//    QModelIndex selectedIndex = indexes.at(0);
//    QVariant data = model()->data(selectedIndex);
//    std::string par_tag_str = data.toString().toStdString();
//    Tag par_tag = Tag::parse_id_space_des(par_tag_str);

//    // Make seleted tag as pad of marked tag
//    try {
//        db_add_tagparchd(db, par_tag.id, chd_id);
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }

//    // Add item on TreeView
//    QString tagid_qstr = QString::number(chd_id);
//    QString tagdes_qstr = QString::fromStdString(chd_des);
//    QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
//    QStandardItem *par_item = md->itemFromIndex(selectedIndex);
//    par_item->appendRow(new_item);
//}


//void TV_Recs::btn_makeroot_clicked(void) {
//    //
//    // Move selected tag to root level
//    //
//    dia_tags->close();

//    std::vector<Tag> selected_tags = get_selected_tags();

//    std::string prompt_str;
//    if (selected_tags.size() == 1) {
//        prompt_str = "tag:" + selected_tags.at(0).des + " move to root";
//    } else {
//        prompt_str = "n." + std::to_string(selected_tags.size()) + " tags move to root";
//    }
//    DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//    dia_msg_ok_cancel->init(prompt_str);
//    int res = dia_msg_ok_cancel->exec();

//    try {
//        if (res == QDialog::Accepted) {
//            db_rm_chds(db, selected_tags);
//            db_reload_tree();
//        }
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }
//}


///*
// * Tag search
// */
//void TV_Recs::btn_search_clicked(void) {
//    dia_tags->close();
//    DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//    dia_msg_ok_cancel->init("... TODO ...");
//    dia_msg_ok_cancel->exec();
//    return;

//    // ---TODO---
//    //    // input search text
//    //    std::vector<Tag> tags = db_rd_tags(db);
//    //    DiaEditLine *dia_editline = new DiaEditLine(this);
//    //    dia_editline->init("search text", "");
//    //    int res = dia_editline->exec();
//    ////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    //    if (res == QDialog::Accepted) {
//    //        std::string text_search = dia_editline->get_value();
//    //        Err err;
//    ////        db_add_tag(db, des, err);
//    //        if (err.des.size() > 0) {
//    //            err.gest(__LINE__, __FILE__);
//    //            return;
//    //        }
//    //    }


//}


///*
// * Remove selected tags from par
// */
//void TV_Recs::btn_removefrompar_clicked(void) {
//    dia_tags->close();

//    QModelIndexList indexes = selectionModel()->selectedIndexes();

//    // Get parent tag
//    QModelIndex selectedIndex_par = indexes.at(0).parent();
//    QVariant data_par = model()->data(selectedIndex_par);
//    std::string par_str = data_par.toString().toStdString();
//    Tag par = Tag::parse_id_space_des(par_str);

//    // Remove childs from parent tag
//    try {
//        for (QModelIndex selectedIndex_chd : indexes) {
//            QVariant data = model()->data(selectedIndex_chd);
//            std::string chd_str = data.toString().toStdString();
//            Tag chd = Tag::parse_id_space_des(chd_str);
//            db_remove_from_partag(db, par.id, chd.id);
//        }
//        remove_items_from_par(indexes, selectedIndex_par);
//        //        db_reload_tree();
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }
//}


///*
// * Remove items from parent item
// */
//void TV_Recs::remove_items_from_par(QModelIndexList chds, QModelIndex par) {
//    // Remove items from TreeView
//    for (QModelIndex chd : chds) {
//        md->removeRow(chd.row(), par);
//    }
//}



//void TV_Recs::add_subtree(std::vector<Tag> tags, Tag tag, QStandardItem *item, int level) {
//    if (level > MAX_LEVEL) {
//        return;
//    }
//    // add treeview tag
//    QString tagid_qstr = QString::number(tag.id);
//    QString tagdes_qstr = QString::fromStdString(tag.des);
//    QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
//    if (!item) {
//        // root element
//        QStandardItem *rootitem = md->invisibleRootItem();
//        rootitem->appendRow(new_item);
//    } else {
//        item->appendRow(new_item);
//    }
//    // show childs
//    std::vector<Tag> chds = db_get_chds(db, tag);
//    //    if (err.des.size() > 0) {
//    //        // err, do nothing
//    //        err.des = "debug - line: " + std::to_string(__LINE__) + " - file: " + __FILE__;
//    //        std::cout << err.des << std::endl;
//    //        return;
//    //    }
//    try {
//        for (Tag chd : chds) {
//            add_subtree(tags, chd, new_item, level + 1);
//        }
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }
//}


//void TV_Recs::add_tags(std::vector<Tag> tags) {
//    try {
//        for (Tag tag : tags) {
//            std::vector<int> parids = db_get_parids(db, tag.id);
//            if (parids.size() == 0) {
//                // root element, show it
//                QStandardItem *item = nullptr;
//                add_subtree(tags, tag, item, 0);
//            }
//        }
//    } catch (MyEx& ex) {
//        std::cout << ex.what() << ex.get_info() << std::endl;
//        std::cout << "Function: " << ex.get_func() << std::endl;
//        return;
//    }
//}



////void TreVieTags::add_subtree2_map(QStandardItem *sup_item, std::unordered_map<int,Tag> map_tags, Tag sup, int level) {
////    if (level > 10) {
////        return;
////    }
////    QString tagid_qstr = QString::number(sup.id);
////    QString tagdes_qstr = QString::fromStdString(sup.des);
////    QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
////    sup_item->appendRow(new_item);
////    std::vector<Tag> tags = get_child_tags(map_tags, sup);
////    for (Tag tag : tags) {
////        add_subtree2_map(new_item, map_tags, tag, level + 1);
////    }
////}



////void TreVieTags::add_subtree_map(std::unordered_map<int,Tag> map_tags, Tag map_toptag) {
////    // top node
////    QString tagid_qstr = QString::number(map_toptag.id);
////    QString tagdes_qstr = QString::fromStdString(map_toptag.des);
////    QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
////    QStandardItem *item = md->invisibleRootItem();
////    item->appendRow(new_item);
////    std::vector<Tag> tags = get_child_tags(map_tags, map_toptag);
////    int level = 0;
////    for (Tag tag : tags) {
////        add_subtree2_map(new_item, map_tags, tag, level + 1);
////    }
////}



////void TreVieTags::add_alltags_map(std::unordered_map<int,Tag> map_tags) {
//////    std::vector<Tag> tags = db_rd_roottags(db);
////    for (std::pair<const int, Tag> pit : map_tags) {
////        if (pit.second.sup < 1) {
////            // root element
////            add_subtree_map(map_tags, pit.second);
////        }
////    }
////}






////void TreVieTags::add_tgs_subtree(std::vector<Tgs> tgss, Tgs tgs, QStandardItem *item, int level) {
////    if (level > 10) {
////        return;
////    }

////    // show tag
////    QString tagid_qstr = QString::number(tgs.id);
////    QString tagdes_qstr = QString::fromStdString(tgs.des);
////    QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
////    if (!item) {
////        // root element
////        QStandardItem *rootitem = md->invisibleRootItem();
////        rootitem->appendRow(new_item);
////    } else {
////        item->appendRow(new_item);
////    }

////    // show childs
////    std::vector<Tgs> chds = tgs.get_childs(tgss);
////    for (Tgs chd : chds) {
////        add_tgs_subtree(tgss, chd, new_item, level + 1);
////    }
//////    for (Tgs tgs : tgss) {
//////        if (pit.second.sup < 1) {
//////            // root element
//////            add_subtree_map(map_tags, pit.second);
//////        }
//////    }
////}

////void TreVieTags::add_tgss(std::vector<Tgs> tgss) {
////    for (Tgs tgs : tgss) {
////        if (tgs.sups.size() < 1) {
////            QStandardItem *item = nullptr;
////            add_tgs_subtree(tgss, tgs, item, 0);
////        }
////    }
////}


////        QString tagid_qstr = QString::number(tag.id);
////        QString tagdes_qstr = QString::fromStdString(tag.des);
////        QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
////        QStandardItem *item = md->invisibleRootItem();
////        item->appendRow(new_item);
////        std::vector<Tag> tags = db_get_tags_childs(tag);
////        add_childs(tags, tsis, tag, new_item, level + 1);
////        //        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//////        std::cerr << tag.id << std::endl;
////        if (level == 0) {
////            // show only root elements
////            int res = tag.get_tagsupid(tsis, tag.id);
////            if (res == -1) {
////                // tag is root element, show
////                QString tagid_qstr = QString::number(tag.id);
////                QString tagdes_qstr = QString::fromStdString(tag.des);
////                QStandardItem *new_item = new QStandardItem(tagid_qstr + " " + tagdes_qstr);
////                QStandardItem *item = md->invisibleRootItem();
////                item->appendRow(new_item);
////                show_childs(tags, tsis, tag, new_item, level + 1);
////            }
////        } else {

////        }



////void TreVieTags::load(std::vector<Tag> tags, std::vector<TagSupInf> tsis) {
////    add_alltags(tags, tsis);
//////    add_alltags(tags);

//////    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;

////////    model_tags = new QStandardItemModel;

////////    QStandardItem *item0 = model_tags->item(0,0);
//////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//////    std::cerr << md->rowCount() << std::endl;

//////    QList<QStandardItem *> rowItems;
//////    rowItems << new QStandardItem("first");
//////    rowItems << new QStandardItem("second");
////////    rowItems << new QStandardItem("third");

//////    QStandardItem *item = md->invisibleRootItem();
//////    // adding a row to the invisible root item produces a root element
//////    item->appendRow(rowItems);

////////    item0 = model_tags->item(0,0);
//////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//////    std::cerr << md->rowCount() << std::endl;

//////    QList<QStandardItem *> secondRow;
//////    secondRow << new QStandardItem("111");
//////    secondRow << new QStandardItem("222");
////////    secondRow << new QStandardItem("333");
//////    // adding a row to an item starts a subtree
//////    rowItems.first()->appendRow(secondRow);

//////    QList<QStandardItem *> r3;
//////    r3 << new QStandardItem("r31");
//////    r3 << new QStandardItem("r32");
////////    r3 << new QStandardItem("r33");
//////    item->appendRow(r3);

////////    int n = md->rowCount();

////////    for (auto tag : tags) {
////////        add_rootitem(QString::fromStdString(to_string(tag.id)), QString::fromStdString(tag.des));
////////    }
////}



////void TreVieTags::add_rootitems(std::vector<Tag> tags) {
////    for (Tag tag : tags) {
////        add_rootitem(tag);
////    }
////}


////void TreVieTags::add_rootitem(QString name, QString description) {
////    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
////    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

////    // QTreeWidgetItem::setText(int column, const QString & text)
////    treeItem->setText(0, name);
////    treeItem->setText(1, description);
//////    addTreeChild(treeItem, name + "A", "Child_first");
//////    addTreeChild(treeItem, name + "B", "Child_second");
////}



////void TreVieTags::clear(void) {
////    md->clear();
//////    QAbstractItemModel m = model();
//////    m.removeRows();
//////    beginRemoveRows(QModelIndex(), row, row + count - 1);
//////     while (count--) delete m_pageList.takeAt(row);
//////     endRemoveRows();
////}


//int TV_Recs::get_seltags_count(void) {
//    std::vector<int> ids;
//    QItemSelectionModel *sm = selectionModel();
//    QModelIndexList indexes = sm->selectedRows(0);
//    //    QModelIndexList indexes = selectionModel()->selectedRows(0);
//    return(indexes.count());
//}


//std::vector<int> TV_Recs::get_selected_ids(void) {
//    std::vector<int> ids;

//    //    QModelIndex index = currentIndex();
//    //    // TAG_ID
//    //    QModelIndex index2 = model()->index(index.row(), COL_TAG_ID, QModelIndex());
//    //    QVariant data = model()->data(index2);
//    //    std::string tag_str = data.toString().toStdString();
//    //    Tag tag = Tag::parse(tag_str);

//    QModelIndexList indexes = selectionModel()->selectedRows(0);
//    for (int j = 0; j < indexes.count(); j++) {
//        QModelIndex k = indexes.at(j);
//        QVariant data = model()->data(k);
//        std::string tag_str = data.toString().toStdString();
//        Tag tag = Tag::parse_id_space_des(tag_str);
//        //        //        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//        //        int id = k.data(Qt::DisplayRole).toInt();
//        ids.push_back(tag.id);
//    }
//    return(ids);
//}
