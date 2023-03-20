#!/usr/bin/env python3

from lib.menu_creator import TerminalMenu
from variables import *
import time

def main():
    robot_options = ["Mini", "Miti", "Pro", "Zero2", "Zero3", "Skip to Additional Packages", "Exit"]
    robot_install_menu = TerminalMenu(robot_options, multi_select=False, multi_select_empty_ok=True, \
                                    clear_screen=True, title=ROBOTS_TITLE, skip_empty_entries=True)
    robot_install_menu.show()
    robot = robot_install_menu.chosen_menu_entry

    packages_options = ["Foxglove", "Slam Toolbox", "BMI088 Driver", "Nav2", "Slamtec Lidar", "Exit"]
    packages_install_menu = TerminalMenu(packages_options, multi_select=True, multi_select_empty_ok=True, \
                                    clear_screen=True, title=PACKAGES_TITLE, skip_empty_entries=True)

    if(robot == "Mini"):
        run_mini_install()
        for x in range(0, 20):
            print(".", end="", flush=True)
            time.sleep(0.1)
        packages_install_menu.show()
        print("Now installing the following packages: ", end="")
        print(packages_install_menu.chosen_menu_entries)
        time.sleep(100)
    else:
        print(robot_install_menu.chosen_menu_entry)

def run_mini_install():
    print("Running mini install...\n")
    print("Additional Packages will be made available after install.\n")

if __name__ == "__main__":
    main()