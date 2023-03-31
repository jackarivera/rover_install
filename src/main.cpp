#include <iostream>
#include <string>

#include "ftxui/component/screen_interactive.hpp"

#include "UI/ui.hpp"

int main(void) {

  system("resize -s 40 100");
  system("clear");

  auto screen = ftxui::ScreenInteractive::Fullscreen();

  std::shared_ptr<UI> ui_handler = Make<UI>();
  //auto ui = ui_handler->RenderInstallerUI();
  ui_handler->create_da_logger_man();
  screen.Loop(ui_handler->RenderInstallerUI());
  system("clear");
  
  return EXIT_SUCCESS;
}