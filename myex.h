#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>

class MyEx: public std::exception {
    int line;
    char const * file;
    const char* func = "func";
    const char* info = "info";
public:
//    MyEx();
    MyEx(int line_, char const * file_);
    ~MyEx();
    virtual const char* what() const throw();
    const char* get_file() const;
    int get_line() const;
    const char* get_info() const;
    const char* get_func() const;
};

//class MyException : public std::exception {

//    const char* file;
//    int line;
//    const char* func;
//    const char* info;

//public:
//    MyException(const char* msg,
//                const char* file_,
//                int line_,
//                const char* func_,
//                const char* info_ = "") : std::exception(msg),
//                file (file_),
//                line (line_),
//                func (func_),
//                info (info_)
//    {
//    }

//    const char* get_file() const { return file; }
//    int get_line() const { return line; }
//    const char* get_func() const { return func; }
//    const char* get_info() const { return info; }
//}

#endif // MYEXCEPTION_H

/*
try
{
    some_function()
}
catch (MyException& ex)
{
    std::cout << ex.what() << ex.get_info() << std::endl;
    std::cout << "Function: " << ex.get_func() << std::endl;
    return EXIT_FAILURE;
}
*/
