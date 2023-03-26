#include "log_displayer.hpp"

Element LogDisplayer::RenderLog(std::vector<LogFormatter::LogLine*> log_lines){
    Elements logs;

    int level_size = 10;
    int message_size = 25;
    int time_size = 10;

    auto header = hbox({
        text("Type") | size(WIDTH, EQUAL, level_size),
        separator(),
        text("Message") | size(WIDTH, GREATER_THAN, message_size) | xflex,
        separator(),
        text("Time") | size(WIDTH, EQUAL, time_size)
    });

    for(auto& log : log_lines){
        Decorator type_style;
        Decorator message_style;
        if(log->type == "WARNING"){
            type_style = size(WIDTH, EQUAL, level_size) | color(Color::Orange1);
            message_style = size(WIDTH, GREATER_THAN, message_size) | color(Color::Orange1) | dim | xflex;
        } else if(log->type == "ERROR") {
            type_style = size(WIDTH, EQUAL, level_size) | color(Color::Red1);
            message_style = size(WIDTH, GREATER_THAN, message_size) | color(Color::Red1) | dim | xflex;
        } else if(log->type == "SUCCESS") {
            type_style = size(WIDTH, EQUAL, level_size) | color(Color::Green1);
            message_style = size(WIDTH, GREATER_THAN, message_size) | color(Color::Green1) | dim | xflex;
        } else {
            type_style = size(WIDTH, EQUAL, level_size) | dim;
            message_style = size(WIDTH, GREATER_THAN, message_size) | dim | xflex;
        }
        Element log_box = hbox({
            text(log->type) | type_style,
            separator(),
            text(log->log) | message_style,
            separator(),
            text(std::to_string(log->time)) | size(WIDTH, EQUAL, time_size)
        });
        logs.push_back(log_box);
    }

    return window(text("Log"), vbox({
                                    header,
                                    separator(),
                                    vbox(logs) | yframe
                                }));
}

