#include <iostream>
#include <string>

#include "ftxui/component/screen_interactive.hpp"

#include "include/ui.hpp"

int main(void) {

  system("resize -s 40 100");
  system("clear");

  auto screen = ftxui::ScreenInteractive::Fullscreen();

  // Setup Tab Indexes and Titles
  int tab_index = 0;
  std::vector<std::string> tab_entries = {
    "Ros Installer", "Rover Installer"
  };
  auto tab_selection = Menu(&tab_entries, &tab_index, MenuOption::HorizontalAnimated());

  // Create Tab UI Classes
  std::shared_ptr<RoverTab> rover_install_tab = Make<RoverTab>();
  std::shared_ptr<RosTab> ros_install_tab = Make<RosTab>();

  // Setup test logs
  rover_install_tab->create_da_logger_man();
  ros_install_tab->create_da_logger_man();

  // Create FTXUI Tab Container and Main Layout
  auto tab_content = Container::Tab({
    ros_install_tab->RenderTab(),
    rover_install_tab->RenderTab()
  }, &tab_index);
  
  auto main_container = Container::Vertical({
    tab_selection,
    tab_content
  });

  auto main_renderer = Renderer(main_container, [&] {
    return vbox({
      text("Rover Robotics Toolbox") | bold | hcenter,
      tab_selection->Render(),
      tab_content->Render()
    });
  });

  // Loop Main Renderer
  screen.Loop(main_renderer);
  system("clear");
  
  return EXIT_SUCCESS;
}