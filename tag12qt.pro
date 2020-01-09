#-------------------------------------------------
#
# Project created by QtCreator 2019-12-17T16:26:18
#
#-------------------------------------------------

QT       += core gui sql network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tag12qt
TEMPLATE = app
LIBS        += -lcrypto -lboost_filesystem -lboost_system -lssl -lMagick++

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mydebug.cpp \
    conf.cpp \
    db.cpp \
    db_get_tags.cpp \
    tv_tags.cpp \
    chk_tag_sup_inf.cpp \
    db_add_tag.cpp \
    search_sup.cpp \
    db_add_tag_to_imgs.cpp \
    db_chk_sibling_exists.cpp \
    db_tools.cpp \
    dia_msg_ok_cancel.cpp \
    db_get_last_tag.cpp \
    md5_3.cpp \
    db_ren_tag.cpp \
    db_insert_img.cpp \
    dia_editline.cpp \
    dia_listchoice.cpp \
    dia_tagfind.cpp \
    dia_tag_info.cpp \
    qmis_found.cpp \
    img.cpp \
    lv_imgs.cpp \
    db_add_imgs.cpp \
    db_get_common_tags.cpp \
    db_get_tags_from_imgid.cpp \
    db_get_img_from_id.cpp \
    db_get_untagged_imgs.cpp \
    db_newtags_for_img.cpp \
    db_removetag_for_imgs.cpp \
    db_rotate.cpp \
    db_set_date.cpp \
    db_store_md5.cpp \
    dia_textedit.cpp \
    file_chk_exists.cpp \
    db_get_imgs_by_tagid.cpp \
    myex.cpp \
    tag.cpp \
    str_split.cpp \
    is_date.cpp \
    lv_imginfo.cpp \
    mydate.cpp \
    lv_people.cpp \
    pers.cpp \
    db_get_people.cpp \
    db_add_pers_to_imgs.cpp \
    db_get_people_from_imgid.cpp \
    tv_places.cpp \
    place.cpp \
    db_get_places.cpp \
    db_get_tag_chds.cpp \
    db_get_place_chds.cpp \
    db_get_tag_parids.cpp \
    db_get_place_parids.cpp \
    db_get_imgs_by_placeid.cpp \
    db_get_places_from_imgid.cpp \
    db_add_place_to_imgs.cpp

HEADERS += \
    mainwindow.h \
    mydebug.h \
    myex.h \
    conf.h \
    db.h \
    db_get_tags.h \
    tag.h \
    tv_tags.h \
    chk_tag_sup_inf.h \
    db_add_tag.h \
    search_sup.h \
    db_add_tag_to_imgs.h \
    db_chk_sibling_exists.h \
    db_tools.h \
    dia_msg_ok_cancel.h \
    db_get_last_tag.h \
    md5_3.h \
    db_ren_tag.h \
    db_insert_img.h \
    dia_editline.h \
    dia_listchoice.h \
    dia_tagfind.h \
    dia_tag_info.h \
    qmis_found.h \
    img.h \
    lv_imgs.h \
    db_add_imgs.h \
    db_get_common_tags.h \
    db_get_tags_from_imgid.h \
    db_get_img_from_id.h \
    db_get_untagged_imgs.h \
    db_newtags_for_img.h \
    db_removetag_for_imgs.h \
    db_rotate.h \
    db_set_date.h \
    db_store_md5.h \
    dia_textedit.h \
    file_chk_exists.h \
    db_get_imgs_by_tagid.h \
    str_split.h \
    is_date.h \
    lv_imginfo.h \
    mydate.h \
    lv_people.h \
    pers.h \
    db_get_people.h \
    db_add_pers_to_imgs.h \
    db_get_people_from_imgid.h \
    tv_places.h \
    place.h \
    db_get_places.h \
    db_get_tag_chds.h \
    db_get_place_chds.h \
    db_get_tag_parids.h \
    db_get_place_parids.h \
    db_get_imgs_by_placeid.h \
    db_get_places_from_imgid.h \
    db_add_place_to_imgs.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    conf.txt
