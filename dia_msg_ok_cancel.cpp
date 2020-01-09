#include "dia_msg_ok_cancel.h"


DiaMsgOkCancel::DiaMsgOkCancel(QWidget *parent) : QDialog(parent) {
}


DiaMsgOkCancel::~DiaMsgOkCancel() {
}


//bool DiaMsgOkCancel::get_ok_pressed(void) {
//    return(btn_ok_pressed);
//}


//void DiaMsgOkCancel::set_ok_pressed(bool status) {
//    btn_ok_pressed = status;
//}


//QPushButton *DiaMsgOkCancel::get_btn_ok(void) {
//    return(btn_ok);
//}


//void DiaMsgOkCancel::set_label(std::string label) {
//    label = label.c_str();
//}


//std::string DiaMsgOkCancel::get_value(void) {
//    return(value);
//}


void DiaMsgOkCancel::init(std::__cxx11::string msg) {
    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
    QVBoxLayout *lay1 = new QVBoxLayout;

    QHBoxLayout *lay2 = new QHBoxLayout;
    lay2->addStretch(1);
    QLabel *lbl1 = new QLabel(msg.c_str());
    lay2->addWidget(lbl1);
    lay2->addStretch(1);

    QHBoxLayout *lay3 = new QHBoxLayout;
    lay3->addStretch(1);
    QPushButton *btn_ok = new QPushButton("ok");
    lay3->addWidget(btn_ok);
    QPushButton *btn_cancel = new QPushButton("cancel");
    lay3->addWidget(btn_cancel);
    lay3->addStretch(1);

    lay1->addLayout(lay2);
    lay1->addLayout(lay3);
    setLayout(lay1);
    connect(btn_ok, &QPushButton::clicked, this, &DiaMsgOkCancel::btn_ok_clicked);
    connect(btn_cancel, &QPushButton::clicked, this, &DiaMsgOkCancel::btn_cancel_clicked);
//    connect(btn_ok, &QPushButton::clicked, this, &DiaMsgOkCancel::accept);
}


void DiaMsgOkCancel::btn_ok_clicked(void) {
//    btn_ok_pressed = true;
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    value = edt1->text().toStdString();
    accept();
//    std::cerr << value << std::endl;
}


void DiaMsgOkCancel::btn_cancel_clicked(void) {
    reject();
}
