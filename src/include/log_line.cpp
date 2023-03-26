#include "log_line.hpp"


LogFormatter::LogLine LogFormatter::createLog(std::string log_type, std::string log_str, int log_time){
    LogFormatter::LogLine log_line;
    log_line.type = log_type;
    log_line.log = log_str;
    log_line.time = log_time;

    return log_line;
}

