#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include "ftxui/component/component.hpp"
#include <chrono>
#include <ctime>

using namespace ftxui;

class Logger {
    private:
        struct LogLine {
            std::string type;
            char* time = 0;
            std::string log;
        };
        time_t logger_timer;
        std::vector<LogLine> log_lines;
    public:
        Logger() = default;

        // Logger Functions
        Element RenderLog();
        void log_success(std::string log);
        void log_info(std::string log);
        void log_warning(std::string log);
        void log_error(std::string log);

        // Helper Functions
        std::vector<LogLine> get_log_lines() {
            return log_lines;
        }

        LogLine create_log(std::string log_type, std::string log_str, char* log_time) {
            LogLine log_line;
            log_line.type = log_type;
            log_line.log = log_str;
            log_line.time = log_time;
            log_lines.push_back(log_line);
            return log_line;
        }

        char* get_logger_time(){
            logger_timer = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            return std::ctime(&logger_timer);
        }
};

#endif /* end of include guard: LOGGER_HPP */