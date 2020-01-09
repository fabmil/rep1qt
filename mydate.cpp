#include "mydate.h"

MyDate::MyDate() {
}

MyDate::MyDate(int d, int m, int y) {
}

MyDate::MyDate(const std::string s) {
    str = s;
    std::vector<std::string> ss = str_split(s,'-');
    // Check if is valid;
    if (ss.size() == 3) {
        if ( ((ss[0].size() == 2) || (ss[0].size() == 4)) && (std::stoi(ss[0]) > 0) && (std::stoi(ss[0]) < 2100) ) {
            // Valid year
            y = std::stoi(ss[0]);
        } else {
            y = -1;
            m = -1;
            d = -1;
            str = "";
            return;
        }
        if ( ((ss[1].size() == 1) || (ss[0].size() == 2)) && (std::stoi(ss[0]) > 0) && (std::stoi(ss[0]) < 13) ) {
            // Valid month
            m = std::stoi(ss[1]);
        } else {
            y = -1;
            m = -1;
            d = -1;
            str = "";
            return;
        }
        if ( ((ss[2].size() == 1) || (ss[2].size() == 2)) && (std::stoi(ss[0]) > 0) && (std::stoi(ss[0]) < 32) ) {
            // Valid day
            m = std::stoi(ss[2]);
        } else {
            y = -1;
            m = -1;
            d = -1;
            str = "";
            return;
        }
    }
}

MyDate::MyDate(const MyDate &other)
{
    y = other.y;
    m = other.m;
    d = other.d;
    str = other.str;
}

MyDate::~MyDate() {
}

bool MyDate::isValid(const std::string &date) {
    if (date.size() != 10) {
        return(false);
    }
    std::vector<std::string> ss = str_split(date, '-');
    if (ss.size() != 3) {
        return(false);
    }
    if ( (ss[0].size() != 2) && (ss[0].size() != 4) ) {
        return(false);
    }
    if ( (ss[1].size() != 1) && (ss[1].size() != 2) ) {
        return(false);
    }
    if ( (ss[2].size() != 1) && (ss[2].size() != 2) ) {
        return(false);
    }
    int y = std::stoi(ss[0]);
    int m = std::stoi(ss[1]);
    int d = std::stoi(ss[2]);
    if ( (y<0) or (y>2100) ) {
        return(false);
    }
    if ( (m<1) or (m>12) ) {
        return(false);
    }
    if ( (d<1) or (d>31) ) {
        return(false);
    }
    return(true);
}
