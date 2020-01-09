#include "mydebug.h"

#include <iostream>
#include <vector>
#include <string>

/*
 * Debug line ...
 */
void mydebug(void) {
    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
}

void mydebug2(int line, std::string filename) {
    std::cerr << "debug - line: " << line << " - file: " << filename << std::endl;
}
