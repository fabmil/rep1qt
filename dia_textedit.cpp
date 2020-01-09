#include "dia_textedit.h"


DiaTextEdit::DiaTextEdit(QWidget *parent) : QDialog(parent) {
}


DiaTextEdit::~DiaTextEdit() {
}


std::string DiaTextEdit::get_value(void) {
    std::string value = edt1->toPlainText().toStdString();
    return(value);
}


void DiaTextEdit::init(std::__cxx11::string label, std::__cxx11::string value) {
    //    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
    QVBoxLayout *lay1 = new QVBoxLayout;
    QHBoxLayout *lay2 = new QHBoxLayout;
    QLabel *lbl1 = new QLabel(label.c_str());
    lay2->addWidget(lbl1);
    edt1 = new QPlainTextEdit(value.c_str());
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
    connect(btn_ok, &QPushButton::clicked, this, &DiaTextEdit::btn_ok_clicked);
    connect(btn_cancel, &QPushButton::clicked, this, &DiaTextEdit::btn_cancel_clicked);
}


void DiaTextEdit::btn_ok_clicked(void) {
//    btn_ok_pressed = true;
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
    value = edt1->toPlainText().toStdString();
    accept();
//    std::cerr << value << std::endl;
}


void DiaTextEdit::btn_cancel_clicked(void) {
    reject();
}
