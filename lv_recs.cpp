#include <iostream>
#include <memory>
#include <vector>

#include "lv_recs.h"

#include <boost/algorithm/string.hpp>

//#include "conf.h"
#include "db.h"
//#include "db_add_imgs.h"
//#include "db_add_tag_to_imgs.h"
//#include "db_get_common_tags.h"
//#include "db_get_date_tag.h"
//#include "db_get_img_from_id.h"
//#include "db_get_last_img.h"
//#include "db_get_last_tag.h"
//#include "db_get_tags_from_imgid.h"
//#include "db_get_untagged_imgs.h"
//#include "db_insert_img.h"
//#include "db_newtags_for_img.h"
//#include "db_removetag_for_imgs.h"
//#include "db_rotate.h"
//#include "db_set_date.h"
#include "db_store_md5.h"
#include "dia_editline.h"
#include "dia_msg_ok_cancel.h"
//#include "dia_listchoice.h"
#include "dia_textedit.h"
//#include "file_chk_exists.h"
//#include "img.h"
//#include "is_date.h"
//#include "lv_imginfo.h"
#include "mainwindow.h"
#include "md5_3.h"
#include "mydate.h"
#include "mydebug.h"
#include "myex.h"
#include "str_split.h"
#include "tag.h"
#include "tv_tags.h"

//#include <Magick++.h>

//#include "get_filename.h"
//#include "string_split.h"
//#include "get_filenames_from_textdrop.h"
////#include "trewid_tags.h"
//#include "img_file.h"
//#include "db_update_obnote.h"

////#include <boost/filesystem.hpp>

LV_Recs::LV_Recs(QWidget *parent) : QListView(parent) {
    this->parent = static_cast<MainWindow *>(parent);
    //    QStringList ColumnNames;
    //    ColumnNames << "id" << "des";
    //    setHeaderLabels(ColumnNames);
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    setResizeMode(QListView::Adjust);
}

LV_Recs::~LV_Recs() {
}

QString LV_Recs::MyMimeType() {
    return QStringLiteral("application/x-my-lv-rec-mimetype");
}

void LV_Recs::init(void) {
    QStandardItemModel *model = new QStandardItemModel(this);
    setModel(model);
    this->md = md;
//    setViewMode(QListView::IconMode);
    setViewMode(QListView::ListMode);
    setAcceptDrops(true);
}

///*
// * Add last inserted tag to selected files
// */
//void LV_Recs::btn_add_lasttag_clicked(void) {

//    dia1->close();

//    Tag last_tag = db_get_last_tag(db);

//    // prompt for tag add
//    DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//    dia_msg_ok_cancel->init("add tag <" + last_tag.des + ">to selected item?");
//    {
//        int res = dia_msg_ok_cancel->exec();
//        if (res != QDialog::Accepted) {
//            // no confirm ... do nothing
//            db->close();
//            return;
//        }
//    }

//    std::vector<int> imgids;
//    QModelIndexList list = selectionModel()->selectedIndexes();
//    foreach (const QModelIndex &index, list) {
//        QVariant q = index.data(Qt::UserRole);
//        Img img_file = q.value<Img>();
//        imgids.push_back(img_file.id);
//    }
//    db_add_tag_to_imgs(db, last_tag.id, imgids);
//}


///*
// * Add selected tags
// */
//void LV_Recs::btn_add_selected_tags_clicked(void) {
//    dia1->close();
//    std::vector<int> tagids = parent->tv_tags->get_selected_ids();
//    std::vector<int> imgids = get_selected_ids();

//    QModelIndexList indexes = selectionModel()->selectedIndexes();
////    int tagid = 0;

//    // progress bar
//    QProgressBar *pb = parent->pb;
//    pb->setMinimum(0);
//    unsigned long mm;
//    if (imgids.size() > 0) {
//        mm = imgids.size();
////        // set tagid
////        QModelIndex k = indexes.at(0);
////        QVariant q = k.data(Qt::UserRole);
////        Img img = q.value<Img>();
////        tagid = img.tagid;
//    } else {
//        mm = 1;
//    }
//    pb->setMaximum(static_cast<int>(mm));
//    int j = 0;

//    for (int imgid : imgids) {
//        pb->setValue(j);
//        db_newtags_for_img(db, tagids, imgid);
//        j++;
//    }

//    pb->setValue(0);

////    // Get all items
////    std::vector<QStandardItem*> items;
////    QStandardItem *rootitem = model->invisibleRootItem();
////    int n = rootitem->rowCount();
////    for (int j=0; j<n; j++) {
////        QStandardItem *item = rootitem->child(j,0);
////        items.push_back(std::move(item));
////    }

//    //    QStandardItem *rootitem = model->invisibleRootItem();
//    //    int n = rootitem->rowCount();
//    //        QStandardItem *item = rootitem->child(j,0);

//    refresh_imgs();

////    // Get items to refresh
////    std::vector<QStandardItem*> items;
////    for (QModelIndex qmi : indexes) {
////        QStandardItem *item = model->itemFromIndex(qmi);
////        items.push_back(std::move(item));
////    }
////    refresh_items(items);

////    if ((indexes.size() > 0) && (tagid != 0)) {
////        // refresh thumbnails
////        parent->tv_tags->show_imgs_from_tagid(tagid);
////    }
//}


////void LV_Recs::refresh_items(std::vector<QStandardItem*> items) {
////    for (QStandardItem * item : items) {
//////        QStandardItem *item = model->itemFromIndex(qmi);
////        QVariant qv = item->data(Qt::UserRole);
////        Img img = qv.value<Img>();
////        std::string s = std::to_string(img.id);
////        QFileInfo fi(img.des.c_str());
////        QString base = fi.baseName();
////        s += "\n";
////        s += base.toStdString();
////        s += "\n";
////        std::vector<Tag> tags = db_get_tags_from_imgid(db, img.id);
////        for (Tag tag : tags) {
////            s += tag.des;
////            s += "\n";
////        }
////        boost::trim_right(s);
////        item->setText(QString::fromStdString(s));
////    }
////}




////void LV_Recs::refresh_imgs(std::vector<Img> imgs) {
////    for (Img img : imgs) {
//////        QStandardItem *item = model->itemFromIndex(qmi);
////        QVariant qv = item->data(Qt::UserRole);
////        Img img = qv.value<Img>();
////        std::string s = std::to_string(img.id);
////        QFileInfo fi(img.des.c_str());
////        QString base = fi.baseName();
////        s += "\n";
////        s += base.toStdString();
////        s += "\n";
////        std::vector<Tag> tags = db_get_tags_from_imgid(db, img.id);
////        for (Tag tag : tags) {
////            s += tag.des;
////            s += "\n";
////        }
////        boost::trim_right(s);
////        item->setText(QString::fromStdString(s));
////    }
////}



////int LV_Recs::get_tagid_from_qmi(QModelIndex qmi) {
//////    QModelIndex k = indexes.at(0);
////    QVariant q = qmi.data(Qt::UserRole);
////    Img img = q.value<Img>();
////    return(img.tagid);
////}

///*
// * Copy date
// */
//void LV_Recs::btn_copy_date_clicked(void) {
//    dia1->close();

//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    // Only one selected thumbnail needed
//    if (indexes.size() != 1) {
//        return;
//    }
//    QModelIndex selectedIndex = indexes.at(0);
//    QModelIndex qmi = selectedIndex;
////    int j=0;
////    while ((qmi.isValid()) && (j<10)) {
////        qmis.push_back(qmi);
////        qmi = qmi.parent();
////        j++;
////    }
//    //    j=qmis.size();
//    if (qmi.isValid()) {
//        QVariant data = model->data(qmi);
//        std::string s = data.toString().toStdString();
//        // get date string
//        std::vector<std::string> ss = str_split(s, '\n');
//        for (std::string s : ss) {
//            std::size_t found = s.find("date:");
//            if (found != std::string::npos) {
//                std::string s2 = s.substr(5);
//                // test if date format YYYY-MM-DD
//                bool chk = is_date(s2);
//                if (chk) {
//                    // date format YYYY-MM-DD
//                    // ... copy
//                    parent->lv_imginfo->model->clear();
//                    QStandardItem *item = new QStandardItem();
//                    std::string s3 = "date:" + s2;
//                    item->setText(QString::fromStdString(s3));
//                    parent->lv_imginfo->model->appendRow(item);
//                }
////                mydebug2(__LINE__,__FILE__);
//            }
//        }
////        mydebug2(__LINE__,__FILE__);
//    }
////    mydebug2(__LINE__,__FILE__);
//    //    parent->lbl_seltag->setText(QString::fromStdString(s));
////    QVariant data = model()->data(selectedIndex);
////    std::string tag_str = data.toString().toStdString();
//////    Tag tag = Tag::parse_id_space_des(tag_str);
//////    parent->lbl_markedtagid->setText(QString::number(tag.id));
//////    parent->lbl_markedtagdes->setText(QString::fromStdString(tag.des));
////    parent->lbl_seltag->setText(QString::fromStdString(tag_str + "\n" + "pippo"));
////    parent->lbl_markedtagdes->setText(QString::fromStdString(tag.des));
//}



//void LV_Recs::btn_loadimages_clicked(void) {
//    // load images
//    dia1->close();

//    // Select files to load
//    QFileDialog dialog(this);
//    dialog.setViewMode(QFileDialog::Detail);
//    //    dialog.setFileMode(QFileDialog::Directory);
//    dialog.setFileMode(QFileDialog::ExistingFiles);
//    if (dialog.exec() == QFileDialog::Accepted) {
//        QStringList selfiles = dialog.selectedFiles();
//        dialog.close();
//        if (selfiles.size() < 1) {
//            return;
//        }
//        // get selected files
//        QStringList ff = dialog.selectedFiles();
//        dialog.close();
//        if (ff.size() < 1) {
//            return;
//        }

//        // to stdstring
//        std::vector<std::string> ff2;

//        for (QString f : ff) {
//            ff2.push_back(f.toStdString());
//        }

//        // load images
//        db_add_chk_imgs(db,ff2);
//    }
//}

///*
// * Paste date
// * YYYY-MM-DD
// */
//void LV_Recs::btn_paste_date_clicked(void) {

//    // --- TODO ---

//    dia1->close();

//    std::vector<int> imgids;
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    for (QModelIndex qmi : indexes) {
//        QStandardItem *item = model->itemFromIndex(qmi);
//        QVariant qv = item->data(Qt::UserRole);
//        Img img = qv.value<Img>();
//        imgids.push_back(img.id);
//    }

//    // --- TODO ---
////    try {
////        QString d = parent->lbl_imgdate->text();
////        std::string d2 = d.toStdString();
////        db_set_date(db, imgids, d2);
////    } catch (MyEx& ex) {
////        std::cout << ex.what() << ex.get_info() << std::endl;
////        std::cout << "Function: " << ex.get_func() << std::endl;
////        return;
////    }
//    refresh_imgs();
//}


//void LV_Recs::btn_remove_tag_clicked(void) {
//    // remove img(s) from one tag
//    // if more tags is selected ... then do nothing!!!
//    dia1->close();
//    std::vector<int> tagids = parent->tv_tags->get_selected_ids();
//    if (tagids.size() == 1) {
//        std::vector<int> imgids = get_selected_ids();
//        QModelIndexList indexes = selectionModel()->selectedIndexes();
//        // only if some thumbnail is seleted
//        if (indexes.size() > 0) {
////            int tagid = get_tagid_from_qmi(indexes.at(0));
////            // set tagid
////            QModelIndex k = indexes.at(0);
////            QVariant q = k.data(Qt::UserRole);
////            Img img = q.value<Img>();
////            tagid = img.tagid;
//            DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//            dia_msg_ok_cancel->init("delete tag:" + std::to_string(tagids[0]) + " from " + std::to_string(imgids.size()) + " selected imgs");
//            int res = dia_msg_ok_cancel->exec();
//            if (res == QDialog::Accepted) {
//                db_removetag_for_imgs(db, tagids[0], imgids);
//                refresh_imgs();
////                if (tagid != 0) {
////                    // refresh thumbnails
////                    parent->tv_tags->show_imgs_from_tagid(tagid);
////                }
//            }
//        }
//    }
//}


///*
// * Remove tags
// */
//void LV_Recs::btn_remove_tags_clicked(void) {
//    dia1->close();

//    // --- TODO ---

//    // set tagid
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    if (indexes.size() < 1) {
//        return;
//    }
////    int tagid = get_tagid_from_qmi(indexes.at(0));

//    // Get common tags
//    std::vector<Tag> common_tags = db_get_common_tags(db, indexes);

//    // Choice only one tag to remove
//    DiaListChoice *dia_listchoice = new DiaListChoice(this);
//    // ... tags des array
//    std::vector<std::string> tags_id_des;
//    for (Tag tag : common_tags) {
//        std::string tag_id_des = std::to_string(tag.id) + " " + tag.des;
//        tags_id_des.push_back(std::move(tag_id_des));
//    }
//    std::string prompt_str = "choice tag to remove";
//    // ... choice tag to remove
//    dia_listchoice->init(prompt_str, tags_id_des);
//    int res = dia_listchoice->exec();
//    if (res == QDialog::Accepted) {
//        // get tag to remove
//        std::string tag_id_space_des = dia_listchoice->get_value();
//        Tag tag = Tag::parse_id_space_des(tag_id_space_des);
//        // Remove tag from all selected thumbnails
//        for (QModelIndex qmi : indexes) {
//            try {
//                QVariant q = qmi.data(Qt::UserRole);
//                Img img = q.value<Img>();
//                db_removetag_for_img(db, tag.id, img.id);
//            } catch (MyEx& ex) {
//                std::cout << ex.what() << ex.get_info() << std::endl;
//                std::cout << "Function: " << ex.get_func() << std::endl;
//                return;
//            }
//        }


////        // Get items to refresh
////        std::vector<QStandardItem*> items;
////        for (QModelIndex qmi : indexes) {
////            QStandardItem *item = model->itemFromIndex(qmi);
////            items.push_back(std::move(item));
////        }
////        refresh_items(items);


//        refresh_imgs();


////        if ((indexes.size() > 0) && (tagid != 0)) {
////            // refresh thumbnails
////            parent->tv_tags->show_imgs_from_tagid(tagid);
////        }

//        //            mydebug2(__LINE__,__FILE__);
//    }
////    }
//}

///*
// * Rotate image
// * Does not touch original image, thumbnail only
// */
//void LV_Recs::btn_rotate_clicked(void) {
//    dia1->close();

//    // Get selected images to rotate
////    std::vector<int> imgids = get_selected_ids();
////    if (imdids.size() < 1) {
////        return;
////    }
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
////    if (indexes.size() < 1) {
////        return;
////    }
////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////    std::cerr << indexes.size() << std::endl;

////    // Confirm for rotate
////    DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
////    dia_msg_ok_cancel->init(std::to_string(indexes.size()) +  " thumbnail to rotate?  (does not touch original image)");
////    {
////        int res = dia_msg_ok_cancel->exec();
////        if (res != QDialog::Accepted) {
////            // no confirm ... do nothing
////            return;
////        }

////    int tagid = 0;

//    // progress bar
//    QProgressBar *pb = parent->pb;
//    pb->setMinimum(0);
//    unsigned long mm;
//    if (indexes.size() > 0) {
//        mm = indexes.size();
//    } else {
//        mm = 1;
//    }
//    pb->setMaximum(static_cast<int>(mm));

//    for (int j=0; j < indexes.size(); j++) {
//        // Thumbnail rotate
//        // ... get img
//        pb->setValue(j);
//        QModelIndex k = indexes.at(j);
//        QVariant q = k.data(Qt::UserRole);
//        Img img = q.value<Img>();
////        tagid = img.tagid;
//        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//        // new rotate value
//        if (img.rotate.size() < 1) {
//            img.rotate = "0";
//        }
//        int rotate = (std::stoi(img.rotate) + 1) % 4;
//        // store new rotate value
//        db_rotate(db, img.id, rotate);

//        // remove thumbnail from cache
//        auto iter = qpixmap_thumb.find(img.md5);
//        if (iter != qpixmap_thumb.end()) {
//            // thumbnail in cache ... erase
//            qpixmap_thumb.erase(iter);
//        }
//        iter = qpixmap_thumb.find(img.md5);
//        if (iter != qpixmap_thumb.end()) {
//            std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//        }
//    }

//    pb->setValue(0);

//    refresh_imgs();
////    if ((indexes.size() > 0) && (tagid != 0)) {
////        // refresh thumbnails
////        parent->tv_tags->show_imgs_from_tagid(tagid);
////    }
//}

///*
// * Set date tag
// * YYYY-MM-DD
// */
//void LV_Recs::btn_set_date_clicked(void) {

//    dia1->close();

//    std::vector<int> imgids;
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    for (QModelIndex qmi : indexes) {
//        QStandardItem *item = model->itemFromIndex(qmi);
//        QVariant qv = item->data(Qt::UserRole);
//        Img img = qv.value<Img>();
//        imgids.push_back(img.id);
//    }

//    // Edit date
//    DiaEditLine *dia_editline = new DiaEditLine(this);
//    dia_editline->init("date", "");
//    int res = dia_editline->exec();
//    if (res == QDialog::Accepted) {
//        // Set date to images
//        std::string date = dia_editline->get_value();
//        if (MyDate::isValid(date)) {
//            try {
//                db_set_date(db, imgids, date);
//            } catch (MyEx& ex) {
//                std::cout << ex.what() << ex.get_info() << std::endl;
//                std::cout << "Function: " << ex.get_func() << std::endl;
//                return;
//            }
//        }
//    }
//    refresh_imgs();
//}

///*
// * Show untagged images
// */
//void LV_Recs::btn_showuntagged_clicked(void) {

//    dia1->close();

//    // clear
//    model->clear();

//    // get untagged images
//    std::vector<Img> imgs = db_get_untagged_imgs(db);

////    show_imgs(imgs, 0);
//    show_imgs(imgs);
//}

//void LV_Recs::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) {
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////    mydebug2(__LINE__,__FILE__);
////    MYDEB ;
//    QVariant q = topLeft.data(Qt::UserRole);
//    Img img_file = q.value<Img>();

//    //    QVariant q = topLeft.data(Qt::DisplayRole);
//    //    std::string s = q.value<string>();

//    // --- TODO ---
//    //    QListView::dataChanged(topLeft, bottomRight, roles);
//}

//void LV_Recs::dragEnterEvent(QDragEnterEvent *event) {
////    MYDEB ;
////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    //    setText(tr("<drop content>"));
//    //    setBackgroundRole(QPalette::Highlight);
//    event->acceptProposedAction();
//    //    emit changed(event->mimeData());
//}


//void LV_Recs::dragMoveEvent(QDragMoveEvent *event) {
//    event->acceptProposedAction();
//}

//void LV_Recs::dropEvent(QDropEvent *event) {
//    if (event->mimeData()->hasFormat(LV_ImgInfo::MyMimeType())) {
//        QByteArray itemData = event->mimeData()->data(LV_ImgInfo::MyMimeType());
//        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
//        QString s;
//        dataStream >> s;
//        std::string s2 = s.QString::toStdString();
//        // Check if not null
//        if (s2.size() > 0) {
//            std::vector<std::string> ss = str_split(s2,':');
//            if (ss.size() == 2) {
//                if (ss[0] == "date") {
//                    // Set new date to selected imgs
////                    MYDEB ;
////                    std::cerr << ss[1] << std::endl;
//                    set_date_to_selected(ss[1]);
//                }
//            }
//        }
////        std::cerr << s2.size() << std::endl;
////        model->clear();
////        std::vector<std::string> ss = str_split(s2,'\n');
////        for (std::string s : ss) {
////            QStandardItem *item = new QStandardItem();
////            QString qs = QString::fromStdString(s);
////            item->setText(qs);
////            model->appendRow(item);
////        }
//    }
//    QListView::dropEvent(event);

////    if (event->mimeData()->hasImage()) {
////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////        //        setPixmap(qvariant_cast<QPixmap>(event->mimeData()->imageData()));
////    } else if (event->mimeData()->hasHtml()) {
////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////        //        setText(event->mimeData()->html());
////        //        setTextFormat(Qt::RichText);
////    } else if (event->mimeData()->hasUrls()) {
////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////        QList<QUrl> urlList = event->mimeData()->urls();
////        for (int i = 0; i < urlList.size() && i < 32; ++i) {



////            // --- TODO ---
////            //            QString qs = urlList.at(i).path();
////            //            std::string f = qs.toStdString();
////            //            std::cerr << f << std::endl;

////            //            // calc MD5
////            //            std::string md5 = md5_3(f);

////            ////            // store doc file
////            ////            if (conf->map_conf["db_copy"] == "true") {
////            ////                fs_store(f, md5, conf);
////            ////            }

////            //////            std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;

////            //////            // check if md5 exists
////            ////            if (md5_exists = db_query_md5(md5))

////            //            // Check if file exists ...
////            //            // ... if new insert
////            //            db_insert_img(db, f, md5);




////        }


////    } else if (event->mimeData()->hasText()) {
////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////    } else {
////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////        //        setText(tr("Cannot display data"));
////    }
//}

//void LV_Recs::startDrag(Qt::DropActions /*supportedActions*/) {
//    auto mi = currentIndex();
//    QVariant data = model->data(mi);
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
//        MYDEB ;
////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
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

//std::vector<int> LV_Recs::get_selected_ids(void) {
//    std::vector<int> ids;
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    for (int j = 0; j < indexes.count(); j++) {
//        QModelIndex k = indexes.at(j);
//        QVariant q = k.data(Qt::UserRole);
//        Img img_file = q.value<Img>();
//        //        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//        //        std::string s = k.data(Qt::DisplayRole).toString().toStdString();
//        //        int id = k.data(Qt::DisplayRole).toInt();
//        ids.push_back(img_file.id);
//    }
//    return(ids);
//}


///*
// * Set date to selected images
// */
//void LV_Recs::set_date_to_selected(std::string date) {
//    if (!MyDate::isValid(date)) {
//        QMessageBox msgBox;
//        std::string msg = "date invalid format: " + date;
//        msgBox.setText(msg.c_str());
//        msgBox.exec();
//        return;
//    }
//    QModelIndexList indexes = selectionModel()->selectedIndexes();
//    if (indexes.size() < 1) {
//        return;
//    }
//    // Confirm for set new date
//    DiaMsgOkCancel *dia_msg_ok_cancel = new DiaMsgOkCancel(this);
//    dia_msg_ok_cancel->init(std::to_string(indexes.size()) +  " new date to set?");
//    {
//        int res = dia_msg_ok_cancel->exec();
//        if (res != QDialog::Accepted) {
//            // no confirm ... do nothing
//            return;
//        }
//    }

//    // progress bar
//    QProgressBar *pb = parent->pb;
//    pb->setMinimum(0);
//    unsigned long mm;
//    if (indexes.size() > 0) {
//        mm = indexes.size();
//    } else {
//        mm = 1;
//    }
//    pb->setMaximum(static_cast<int>(mm));
//    // Set new date to selected images
//    for (int j=0; j < indexes.size(); j++) {
//        pb->setValue(j);
//        // Get image
//        QModelIndex k = indexes.at(j);
//        QVariant q = k.data(Qt::UserRole);
//        Img img = q.value<Img>();
//        // Set new date to image
//        try {
////            MYDEB ;
////            std::cerr << img.id << "-" << date << std::endl;
//            db_set_date(db, img.id, date);
//        } catch (MyEx& ex) {
//            std::cout << ex.what() << ex.get_info() << std::endl;
//            std::cout << "Function: " << ex.get_func() << std::endl;
//            return;
//        }
//    }
//    pb->setValue(0);
//    refresh_imgs();
//}


////std::vector<QModelIndexList> qmi::get_selected_qmi(void) {
////    std::vector<QModelIndexList> qmi;
////    QModelIndexList indexes = selectionModel()->selectedIndexes();
////    for (int j = 0; j < indexes.count(); j++) {
////        QModelIndex k = indexes.at(j);
////        QVariant q = k.data(Qt::UserRole);
////        Img img_file = q.value<Img>();
////        //        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////        //        std::string s = k.data(Qt::DisplayRole).toString().toStdString();
////        //        int id = k.data(Qt::DisplayRole).toInt();
////        ids.push_back(img_file.id);
////    }
////    return(ids);
////}



//void LV_Recs::mousePressEvent(QMouseEvent *e) {
//    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    if (e->button() == Qt::RightButton) {
//        dia1 = new QDialog();
//        QPoint p = mapToGlobal(QPoint(e->x(),e->y()));
//        dia1->move(p);
//        //        dia1->move(100,100);

//        QVBoxLayout *lay1 = new QVBoxLayout;

//        // dialog header
//        QLabel *lbl_header = new QLabel("IMG menu");
//        lay1->addWidget(lbl_header);

//        // button add to last tag
//        QPushButton *btn_addtolasttag = new QPushButton("add last inserted tag");
//        lay1->addWidget(btn_addtolasttag);
//        connect(btn_addtolasttag, &QPushButton::clicked, this, &LV_Recs::btn_add_lasttag_clicked);

//        // button add to marked tag
//        QPushButton *btn_addtomarkedtag = new QPushButton("add selected tags");
//        lay1->addWidget(btn_addtomarkedtag);
//        connect(btn_addtomarkedtag, &QPushButton::clicked, this, &LV_Recs::btn_add_selected_tags_clicked);

//        // button remove from tag
//        QPushButton *btn_removefromtag = new QPushButton("remove current tag");
//        lay1->addWidget(btn_removefromtag);
//        connect(btn_removefromtag, &QPushButton::clicked, this, &LV_Recs::btn_remove_tag_clicked);

//        // button remove tags
//        QPushButton *btn_removetags = new QPushButton("remove tags");
//        lay1->addWidget(btn_removetags);
//        connect(btn_removetags, &QPushButton::clicked, this, &LV_Recs::btn_remove_tags_clicked);

//        // button rotate
//        QPushButton *btn_rotate = new QPushButton("rotate");
//        lay1->addWidget(btn_rotate);
//        connect(btn_rotate, &QPushButton::clicked, this, &LV_Recs::btn_rotate_clicked);

//        // button set date
//        QPushButton *btn_set_date = new QPushButton("set date");
//        lay1->addWidget(btn_set_date);
//        connect(btn_set_date, &QPushButton::clicked, this, &LV_Recs::btn_set_date_clicked);

//        // button copy date
//        QPushButton *btn_copy_date = new QPushButton("copy date");
//        lay1->addWidget(btn_copy_date);
//        connect(btn_copy_date, &QPushButton::clicked, this, &LV_Recs::btn_copy_date_clicked);

//        // button paste date
//        QPushButton *btn_paste_date = new QPushButton("paste date");
//        lay1->addWidget(btn_paste_date);
//        connect(btn_paste_date, &QPushButton::clicked, this, &LV_Recs::btn_paste_date_clicked);

//        // load images
//        QPushButton *btn_loadimages = new QPushButton("load images");
//        lay1->addWidget(btn_loadimages);
//        connect(btn_loadimages, &QPushButton::clicked, this, &LV_Recs::btn_loadimages_clicked);

//        // show untagged images
//        QPushButton *btn_showuntagged = new QPushButton("show untagged images");
//        lay1->addWidget(btn_showuntagged);
//        connect(btn_showuntagged, &QPushButton::clicked, this, &LV_Recs::btn_showuntagged_clicked);

//        // test
//        QPushButton *btn_test = new QPushButton("test");
//        lay1->addWidget(btn_test);
//        connect(btn_test, &QPushButton::clicked, this, &LV_Recs::mytest);

//        //        // button note edit
//        //        QPushButton *btn_noteedit = new QPushButton("note edit");
//        //        lay1->addWidget(btn_noteedit);
//        //        connect(btn_noteedit, &QPushButton::clicked, this, &LV_Recs::btn_noteedit);

//        dia1->setLayout(lay1);
//        dia1->exec();
//        //        dia_tags->close();
//        //        emit myrightClicked(e);
//    }
//    QListView::mousePressEvent(e);
//}


///*
// * Imagemagick test
// */
//void LV_Recs::mytest(void) {

//    dia1->close();

////    Magick::InitializeMagick("/home/fab/prj/tagqt8");

//    // Construct the image object. Separating image construction from the
//    // the read operation ensures that a failure to read the image file
//    // doesn't render the image object useless.
//    Magick::Image image;
//    try {
//        // Read a file into image object
//        image.read("/home/fab/scan/neg6x6/scatola_1965/rullino1/2019-07-12-0020.tif");
////        image.read( "/home/fab/prj/tagqt8/test/test.jpeg" );

////        image.resize("640x480");
////        image.resize("128x128");
//        image.resize(Magick::Geometry(128, 128));

////        // Crop the image to specified size (width, height, xOffset, yOffset)
////        image.crop( Magick::Geometry(500, 500, 1500, 1500) );

//        // Write the image to a file
////        image.write( "/tmp/x.gif" );
//        image.write( "/tmp/x.png" );
//    }
//    catch( Magick::Exception &error_ )
//    {
//        std::cout << "Caught exception: " << error_.what() << std::endl;
//        return;
//    }
//}


//void LV_Recs::on_lv_img_doubleClicked(const QModelIndex &index) {
////    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    QStandardItem *item = model->itemFromIndex(index);
//    //    item->data(Qt::)
//    //    QString s = item->text();

//    QVariant qv = item->data(Qt::UserRole);
//    Img img = qv.value<Img>();
//    //    QString pathname = qv.toString();
//    //    std::cerr << pathname.toStdString() << std::endl;

//    //    QProcess *process = new QProcess(this);
//    //    QString file = "eog /home/fab/images/500.jpg";
//    //    process->start(file);
//    if (img.rotate.size() < 1) {
//        img.rotate = "0";
//    }
//    int rotate = std::stoi(img.rotate);

//    if (rotate == 0) {
//        QProcess::execute(QString::fromStdString("eog " + img.des));
//    } else if (rotate == 1) {
//        std::string tmp_img = conf->map_conf["app_pathdir"] + "/tempfile.jpeg";
//        std::string s = "convert -rotate \"90\" " + img.des + " " + tmp_img;
////        std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////        std::cerr << s << std::endl;
//        QProcess::execute(QString::fromStdString(s));
//        QProcess::execute(QString::fromStdString("eog " + tmp_img));
//    } else if (rotate == 2) {
//        std::string tmp_img = conf->map_conf["app_pathdir"] + "/tempfile.jpeg";
//        QProcess::execute(QString::fromStdString("convert -rotate \"180\" " + img.des + " " + tmp_img));
//        QProcess::execute(QString::fromStdString("eog " + tmp_img));
//    } else if (rotate == 3) {
//        std::string tmp_img = conf->map_conf["app_pathdir"] + "/tempfile.jpeg";
//        QProcess::execute(QString::fromStdString("convert -rotate \"270\" " + img.des + " " + tmp_img));
//        QProcess::execute(QString::fromStdString("eog " + tmp_img));
//    }
//}


///*
// * Refresh img panel
// */
//void LV_Recs::refresh_imgs(void) {
//    // Refresh IMGS panel

//    // Get thumbnails
//    std::vector<int> imgids;
//    QStandardItem *rootitem = model->invisibleRootItem();
//    int n = rootitem->rowCount();
//    for (int j=0; j<n; j++) {
//        QStandardItem *item = rootitem->child(j,0);
//        QModelIndex qmi = model->indexFromItem(item);
//        QVariant q = qmi.data(Qt::UserRole);
//        Img img = q.value<Img>();
//        imgids.push_back(img.id);
//    }
////        for (QModelIndex qmi : indexes) {
////            QVariant q = qmi.data(Qt::UserRole);
////            Img img = q.value<Img>();
////            imgs.push_back(std::move(img));
////        }
////        refresh_items(items);

//    // Reload DES ROTATE DAT from DB
//    std::vector<Img> imgs;
//    for (int imgid : imgids) {
//        try {
//            Img img = db_get_img_from_id(db, imgid);
//            imgs.push_back(std::move(img));
//        } catch (MyEx& ex) {
//            std::cout << ex.what() << ex.get_info() << std::endl;
//            std::cout << "Function: " << ex.get_func() << std::endl;
//            return;
//        }
//    }

//    model->clear();
//    show_imgs(imgs);
////        refresh_imgs(imgs);
//}


///*
// * Show images
// */
//int LV_Recs::show_imgs(std::vector<Img> &imgs) {

//    int appended_rows = 0;

//    QProgressBar *pb = parent->pb;
//    pb->setMinimum(0);
//    unsigned long mm;
//    if (imgs.size() > 0) {
//        mm = imgs.size();
//    } else {
//        mm = 1;
//    }
//    pb->setMaximum(static_cast<int>(mm));
//    int thumbsize = stoi(conf->map_conf["thumbsize"]);

//    for (Img img : imgs) {

//        pb->setValue(appended_rows);

//        if (img.md5.length() != 32) {
//            // md5 not valid, calculate and store
//            std::string md5 = md5_3(img.des);
//            // store md5
//            int res = db_store_md5(db, img.id, md5);
//            if (res > 0) {
//                // md5 value updated
//                img.md5 = md5;
//            } else {
//                // md5 value not updated, return
//                mydebug2(__LINE__,__FILE__);
//                std::cerr << "md5 value not updated" << std::endl;
//                return(appended_rows);
//            }
//        }
//        QPixmap qp_thumb;
//        // test if thumbfile is in cache
//        auto res = qpixmap_thumb.find(img.md5);
//        if (res == qpixmap_thumb.end()) {
//            // thumb not in cache ... load from filesystem
//            // ... test if exixts in thumb dir
////            std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
////            std::cerr << "thumb not in cache ... load from filesystem" << std::endl;

//            std::string thumb_filename = conf->map_conf["thumbdir"] + "/" + img.md5 + ".png";
//            bool res = file_chk_exists(thumb_filename);
//            if (! res) {
//                // thumb file does not exist ... create

////                //                QImage *img_tmp = new QImage(img.des.c_str());
////                std::unique_ptr<QImage> img_tmp = std::make_unique<QImage>(img.des.c_str());
////                QPixmap qp = QPixmap::fromImage(*img_tmp);
////                qp_thumb = qp.scaled(thumbsize, thumbsize, Qt::KeepAspectRatio);
////                QFile fout(QString::fromStdString(thumb_filename));
////                fout.open(QIODevice::WriteOnly);
////                qp_thumb.save(&fout, "PNG");
////                fout.close();
////                // thumb file created

//                Magick::Image image;
//                try {
//                    // Read a file into image object
//                    image.read(img.des.c_str());
//            //        image.read( "/home/fab/prj/tagqt8/test/test.jpeg" );

//            //        image.resize("640x480");
//                    image.resize(Magick::Geometry(thumbsize, thumbsize));

//            //        // Crop the image to specified size (width, height, xOffset, yOffset)
//            //        image.crop( Magick::Geometry(500, 500, 1500, 1500) );

//                    // Write the image to a file
//            //        image.write( "/tmp/x.gif" );
////                    image.write( "/tmp/x.png" );
//                    image.write(thumb_filename.c_str());
//                    //                // thumb file created
//                }
//                catch( Magick::Exception &error_ )
//                {
//                    std::cout << "Caught exception: " << error_.what() << std::endl;
//                    return 1;
//                }

//            }
////            else {
////                // file exists, load thumb file from filesystem
////                qp_thumb.load(QString::fromStdString(thumb_filename));
////            }
//            qp_thumb.load(QString::fromStdString(thumb_filename));
//            // store in cache
//            qpixmap_thumb[img.md5] = qp_thumb;
//        } else {
//            // thumb in cache ... load from cache
//            qp_thumb = qpixmap_thumb[img.md5];
//        }

//        QStandardItem *item = new QStandardItem();
////        std::unique_ptr<QStandardItem> item = std::make_unique<QStandardItem>();
//        // thumb rotate if need
//        if (img.rotate == "1") {
//            QMatrix rm;
//            rm.rotate(90);
//            QPixmap qp_thumb_3 = qp_thumb.transformed(rm);
//            item->setData(QVariant(qp_thumb_3), Qt::DecorationRole);
//        } else if (img.rotate == "2") {
//            QMatrix rm;
//            rm.rotate(180);
//            QPixmap qp_thumb_3 = qp_thumb.transformed(rm);
//            item->setData(QVariant(qp_thumb_3), Qt::DecorationRole);
//        } else if (img.rotate == "3") {
//            QMatrix rm;
//            rm.rotate(270);
//            QPixmap qp_thumb_3 = qp_thumb.transformed(rm);
//            item->setData(QVariant(qp_thumb_3), Qt::DecorationRole);
//        } else {
//            // default
//            item->setData(QVariant(qp_thumb), Qt::DecorationRole);
//        }

//        // ID
//        std::string s = "id:" + std::to_string(img.id);
//        // FILENAME
//        QFileInfo fi(img.des.c_str());
//        QString base = fi.baseName();
//        s += "\n";
//        s += "fn:";
//        s += base.toStdString();
//        // DATE
//        s += "\n";
//        s += "date:";
//        s += img.dat;
//        // TAGS
//        std::vector<Tag> tags = db_get_tags_from_imgid(db, img.id);
//        s += "\n";
//        for (Tag tag : tags) {
//            s += "tag:";
//            s += tag.des;
//            s += "\n";
//        }
//        boost::trim_right(s);
//        item->setText(QString::fromStdString(s));

//        // store full pathname
//        QVariant qv2;
//        qv2.setValue(img);
//        item->setData(qv2, Qt::UserRole);

////        model->appendRow(item.get());
//        model->appendRow(item);

//        appended_rows++;
//    }
//    pb->setValue(0);

//    return(appended_rows);
//}
