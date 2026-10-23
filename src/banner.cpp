#include "clubhub/banner.hpp"
#ifndef CLUBHUB_VERSION
#define CLUBHUB_VERSION "0.1.0"
#endif
namespace clubhub {
std::string banner(std::string_view teamName) {
    const std::string rule(40, '=');
    std::string out;
    out += rule + '\n';
    out += "  ITC Club Hub  v" CLUBHUB_VERSION "\n";
    out += "  Team: ";
    out += teamName;
    out += '\n';
    out += rule + '\n';
    return out;
}
}