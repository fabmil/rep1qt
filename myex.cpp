#include "myex.h"


//MyEx::MyEx() {
//}


MyEx::MyEx(int line_, const char *file_) : line ( line_ ), file ( file_ ) {
}


MyEx::~MyEx() {
}


const char* MyEx::what() const throw() {
    return "My exception happened";
}


const char* MyEx::get_file() const {
    return file;
}


int MyEx::get_line() const {
    return line;
}


const char* MyEx::get_info() const {
    return info;
}


const char* MyEx::get_func() const {
    return func;
}
