#ifndef LOG_LINE_HPP
#define LOG_LINE_HPP

#include <string>
class LogFormatter {
    public:
        LogFormatter() = default;
        struct LogLine {
            std::string type;
            int time = 0;
            std::string log;
        };
        LogLine createLog(std::string log_type, std::string log_str, int log_time);
};




#endif /* end of include guard: DATA_PARSED_LINE_HPP */