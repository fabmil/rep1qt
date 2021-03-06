#ifndef DIA_EDITLINE_H
#define DIA_EDITLINE_H

#include <iostream>

#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QDialog>


class DiaEditLine : public QDialog
{
//    Q_OBJECT

public:
    explicit DiaEditLine(QWidget *parent = 0);
    ~DiaEditLine();
//    void set_label(std::string label);
    void init(std::__cxx11::string label, std::__cxx11::string value);
    void set_ok_pressed(bool status);
    void btn_ok_clicked(void);
    void btn_cancel_clicked(void);
//    bool get_ok_pressed(void);
    std::string get_value(void);
//    QPushButton * get_btn_ok(void);
private:
    std::string label;
    QLineEdit *edt1;
//    QPushButton *btn_ok;
    std::string value;
//    bool btn_ok_pressed = false;
};

#endif // DIA_EDITLINE_H
