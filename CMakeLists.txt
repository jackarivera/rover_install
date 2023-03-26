cmake_minimum_required (VERSION 3.11)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v4.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

project(rover_install
  LANGUAGES CXX
  VERSION 1.0.0
)

add_executable(rover_installer src/main.cpp src/UI/ui.hpp src/UI/ui.cpp src/include/robot_info.hpp src/UI/log_displayer.cpp src/UI/log_displayer.hpp src/include/log_line.cpp src/include/log_line.hpp)
target_include_directories(rover_installer PRIVATE src)

target_link_libraries(rover_installer
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)
