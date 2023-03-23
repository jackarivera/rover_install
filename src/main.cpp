#include <iostream>
#include <vector>   // for vector
#include <string>

#include "ftxui/component/component.hpp"  // for Checkbox, Renderer, Horizontal, Vertical, Input, Menu, Radiobox, ResizableSplitLeft, Tab
#include "ftxui/component/component_base.hpp"  // for ComponentBase, Component
#include "ftxui/component/component_options.hpp"  // for MenuOption, InputOption
#include "ftxui/component/event.hpp"              // for Event, Event::Custom
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, color, operator|, bgcolor, filler, Element, vbox, size, hbox, separator, flex, window, graph, EQUAL, paragraph, WIDTH, hcenter, Elements, bold, vscroll_indicator, HEIGHT, flexbox, hflow, border, frame, flex_grow, gauge, paragraphAlignCenter, paragraphAlignJustify, paragraphAlignLeft, paragraphAlignRight, dim, spinner, LESS_THAN, center, yframe, GREATER_THAN
#include "ftxui/dom/flexbox_config.hpp"  // for FlexboxConfig
#include "ftxui/screen/color.hpp"  // for Color, Color::BlueLight, Color::RedLight, Color::Black, Color::Blue, Color::Cyan, Color::CyanLight, Color::GrayDark, Color::GrayLight, Color::Green, Color::GreenLight, Color::Magenta, Color::MagentaLight, Color::Red, Color::White, Color::Yellow, Color::YellowLight, Color::Default, Color::Palette256, ftxui
#include "ftxui/screen/color_info.hpp"  // for ColorInfo
#include "ftxui/screen/terminal.hpp"    // for Size, Dimensions
#include "ftxui/dom/canvas.hpp"

using namespace ftxui;

int main(void) {
  const std::vector<std::string> robot_list = {
    "Mini",
    "Miti",
    "Zero2",
    "Zero3",
    "Pro"
  };

  std::array<std::string, 7> additional_packages = {
    "Foxglove",
    "Slam Toolbox",
    "Nav2",
    "Slamtec Lidar Driver",
    "BMI088 IMU Driver",
    "BNO055 IMU Driver",
    "Intel Realsense Driver"
  };

  std::array<bool, 7> additional_packages_states = {
    true,
    false,
    false,
    false,
    false,
    false,
    false
  };

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

  auto layout = Container::Horizontal({
    robots_component,
    packages_component
  });

  auto installer_renderer = Renderer(layout, [&] {
    auto robots_win = window(text("Rover Robots"), robots_component->Render() | frame | size(WIDTH, EQUAL, 20));
    auto packages_win = window(text("Additional Packages"), packages_component->Render() | frame);

    return hbox({
              robots_win,
              packages_win
    });
  });
  

  auto screen = ScreenInteractive::TerminalOutput();
  system("clear");
  screen.Loop(installer_renderer);

  return EXIT_SUCCESS;
}