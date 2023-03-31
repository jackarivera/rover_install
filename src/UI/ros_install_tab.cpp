#include "include/ui.hpp"
#include "include/logger.hpp"

using namespace ftxui;

auto ros_tab_layout = Container::Vertical({});

Logger ros_logger = Logger();

void RosTab::create_da_logger_man(){
    ros_logger.log_success("This is a success log");
    ros_logger.log_error("This is an error log");
    ros_logger.log_info("This is an info log");
    ros_logger.log_warning("This is a warning log");
    ros_logger.log_success("Another success");
    ros_logger.log_success("another another success THIS IS THE ROS TAB");
}

Component RosTab::RenderTab(){
    return Renderer(ros_tab_layout, [&] {
        Element logs_win = ros_logger.RenderLog();

        auto vertical_layout = vbox({
            vbox({color(Color::DeepSkyBlue2, text("Logs and Debug"))}) | borderDouble | size(WIDTH, EQUAL, 15),
            logs_win
        });

        return vertical_layout;
    });
}