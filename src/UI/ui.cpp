#include "ui.hpp"
#include "include/robot_info.hpp"
#include "include/logger.hpp"

using namespace ftxui;

int selected_robot = 0;
Component robots_component = Radiobox(&robot_list, &selected_robot);

Component packages_component = Container::Vertical({
    Checkbox(&additional_packages[0], &additional_packages_states[0]),
    Checkbox(&additional_packages[1], &additional_packages_states[1]),
    Checkbox(&additional_packages[2], &additional_packages_states[2]),
    Checkbox(&additional_packages[3], &additional_packages_states[3]),
    Checkbox(&additional_packages[4], &additional_packages_states[4]),
    Checkbox(&additional_packages[5], &additional_packages_states[5]),
    Checkbox(&additional_packages[6], &additional_packages_states[6])
});

auto install_text_render = [] {
Elements output;
output.push_back(text(robot_list[selected_robot]) | bold);
int add_sel_count = 0;
for(int i = 0; i < sizeof(additional_packages_states) / sizeof(bool); i++){
    if(additional_packages_states[i])
        add_sel_count++;
}
for(int i = 0; i < sizeof(additional_packages) / sizeof(std::string); i++){
    if(additional_packages_states[i] && (add_sel_count == 1 || output.size() == add_sel_count)){
        output.push_back(text(" └─" + additional_packages[i]));
    } else if(additional_packages_states[i]) {
        output.push_back(text(" ├─" + additional_packages[i]));
    }
}
return output;
};

std::string button_label = "Run Install";
    bool installing = true;
    auto install_button = Button(&button_label, []{button_label = "Installing..."; installing = true;}, ButtonOption::Border()) | center | color(Color::CadetBlue);
    auto install_button_container = Container::Horizontal({
        install_button
});

auto logs_container = Container::Horizontal({

});

auto layout = Container::Vertical({
Container::Horizontal({
    robots_component,
    packages_component,
    install_button_container
}),
Container::Horizontal({
    logs_container
})
});


Component UI::RenderInstallerUI(){
    return Renderer(layout, [&] {
        auto robots_win = window(text("Rover Robots"), robots_component->Render() | size(WIDTH, EQUAL, 20));
        auto packages_win = window(text("Additional Packages"), packages_component->Render());
        auto install_win = window(text("Install"), vbox(install_text_render(), text(""), separator(), install_button->Render() | center) | flex_grow);
        Logger logman = Logger();
        logman.log_success("This is a success log");
        logman.log_error("This is an error log");
        logman.log_info("This is an info log");
        logman.log_warning("This is a warning log");
        Element logs_win = logman.RenderLog();

        auto vertical_layout = vbox({
            vbox({color(Color::DeepSkyBlue2, text("Install Options"))}) | borderDouble | size(WIDTH, EQUAL, 15),
            hbox({
                robots_win,
                packages_win,
                install_win
            }),
            vbox({color(Color::DeepSkyBlue2, text("Logs and Debug"))}) | borderDouble | size(WIDTH, EQUAL, 15),
            logs_win
        });

        return vertical_layout;
    });
}