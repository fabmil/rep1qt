#ifndef MYDEBUG_H
#define MYDEBUG_H

#include <string>

void mydebug(void);
void mydebug2(int line, std::string filename);

#define MYDEB mydebug2(__LINE__,__FILE__);

#endif // MYDEBUG_H
