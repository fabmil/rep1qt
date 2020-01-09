#ifndef MYDATE_H
#define MYDATE_H

#include <string>
#include <iostream>
#include <vector>

#include <QDate>

#include "str_split.h"

class MyDate {
public:
    MyDate();
    MyDate(int d, int m, int y);
    MyDate(const std::string s);
    MyDate(const MyDate &other);
    ~MyDate();
    static bool isValid(const std::string &date);
private:
    std::string str = "";
    int y = -1;
    int m = -1;
    int d = -1;
//    QDate qdate;
};

#endif // MYDATE_H
