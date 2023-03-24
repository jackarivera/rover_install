#include "ftxui/component/component.hpp"
#include <string>
#include  "../include/log_line.hpp"

using namespace ftxui;

class LogDisplayer : public ComponentBase {
    public:
        LogDisplayer() = default;
        Element RenderLog(std::vector<LogLine> log_lines);
};