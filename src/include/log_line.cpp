#include "log_line.hpp"


static LogLine createLog(LogLine::Type log_type, std::string log_str, int log_time){
    LogLine log_line;
    log_line.type = log_type;
    log_line.log = log_str;
    log_line.time = log_time;

    return log_line;
}

