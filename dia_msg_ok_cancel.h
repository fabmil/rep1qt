#ifndef DIA_MSG_OK_CANCEL_H
#define DIA_MSG_OK_CANCEL_H

#include <iostream>

#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QDialog>

;

class DiaMsgOkCancel : public QDialog
{
//    Q_OBJECT

public:
    explicit DiaMsgOkCancel(QWidget *parent = 0);
    ~DiaMsgOkCancel();
//    void set_label(std::string label);
    void init(std::__cxx11::string msg);
//    void set_ok_pressed(bool status);
    void btn_ok_clicked(void);
    void btn_cancel_clicked(void);
////    bool get_ok_pressed(void);
//    std::string get_value(void);
////    QPushButton * get_btn_ok(void);
//private:
//    std::string label;
//    QLineEdit *edt1;
////    QPushButton *btn_ok;
//    std::string value;
////    bool btn_ok_pressed = false;
};

#endif // DIA_MSG_OK_CANCEL_H
