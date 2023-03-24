#ifndef LOG_LINE_HPP
#define LOG_LINE_HPP

#include <string>

struct LogLine {
    enum Type {
        SUCCESS,
        LOG,
        ERROR,
        WARNING,
    };

    static LogLine createLog(LogLine::Type log_type, std::string log_str, int log_time);

    Type type;
    int time = 0;
    std::string log;
};

#endif /* end of include guard: DATA_PARSED_LINE_HPP */