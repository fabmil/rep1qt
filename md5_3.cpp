#include "md5_3.h"

#include <openssl/md5.h>
#include <fstream>


// --- USAGE:
//    std::string fn = "/home/fab/uploads/2019/P90217-083330.jpg";
//    std::string md5 = md5_3(fn);
//    std::cerr << "debug - line: " << __LINE__ << " - file: " << __FILE__ << std::endl;
//    std::cerr << "md5:" << md5 << std::endl;
// ---


const std::string md5_3(const std::string& filename)
{
    std::ifstream file(filename, std::ifstream::binary);
    MD5_CTX md5Context;
    MD5_Init(&md5Context);
    char buf[1024 * 16];
    while (file.good()) {
        file.read(buf, sizeof(buf));
        MD5_Update(&md5Context, buf, file.gcount());
    }
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5_Final(result, &md5Context);
//    std::string res = result;
//    return(res);
    std::stringstream md5string;
//    md5string << std::hex << std::uppercase << std::setfill('0');
    md5string << std::hex << std::nouppercase << std::setfill('0');
    for (const auto &byte: result)
        md5string << std::setw(2) << (int)byte;
    return(md5string.str());
}
