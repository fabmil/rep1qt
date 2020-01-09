#include "dia_editline.h"


DiaEditLine::DiaEditLine(QWidget *parent) : QDialog(parent) {
}


DiaEditLine::~DiaEditLine() {
}


//bool DiaEditLine::get_ok_pressed(void) {
//    return(btn_ok_pressed);
//}


//void DiaEditLine::set_ok_pressed(bool status) {
//    btn_ok_pressed = status;
//}


//QPushButton *DiaEditLine::get_btn_ok(void) {
//    return(btn_ok);
//}


//void DiaEditLine::set_label(std::string label) {
//    label = label.c_str();
//}


std::string DiaEditLine::get_value(void) {
    return(value);
}


void DiaEditLine::init(std::__cxx11::string label, std::__cxx11::string value) {
    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
    QVBoxLayout *lay1 = new QVBoxLayout;
    QHBoxLayout *lay2 = new QHBoxLayout;
    QLabel *lbl1 = new QLabel(label.c_str());
    lay2->addWidget(lbl1);
    edt1 = new QLineEdit(value.c_str());
    lay2->addWidget(edt1);
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
    connect(btn_ok, &QPushButton::clicked, this, &DiaEditLine::btn_ok_clicked);
    connect(btn_cancel, &QPushButton::clicked, this, &DiaEditLine::btn_cancel_clicked);
//    connect(btn_ok, &QPushButton::clicked, this, &DiaEditLine::accept);
}


void DiaEditLine::btn_ok_clicked(void) {
//    btn_ok_pressed = true;
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
    value = edt1->text().toStdString();
    accept();
//    std::cerr << value << std::endl;
}


void DiaEditLine::btn_cancel_clicked(void) {
    reject();
}
