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
                                    clear_screen=True, title=PACKAGES_TITLE, skip_empty_entries=True, multi_select_select_on_accept=False)

    if(robot == "Mini"):
        run_mini_install()     
        packages_install_menu.show()
    elif(robot == "Miti"):
        run_miti_install()
    elif(robot == "Pro"):
        run_pro_install()
    elif(robot == "Zero2"):
        run_zero2_install()
    elif(robot == "Zero3"):
        run_zero3_install()
    elif(robot == "Skip to Additional Packages"):
        packages_install_menu.show()
        print(packages_install_menu.chosen_menu_entries)
    else:
        print("Goodbye!")

def run_mini_install():
    print("Running mini install...")
    print("Additional Packages will be made available after install.\n")

def run_miti_install():
    print("Running miti install...")
    print("Additional Packages will be made available after install.\n")

def run_pro_install():
    print("Running pro install...")
    print("Additional Packages will be made available after install.\n")

def run_zero2_install():
    print("Running zero2 install...")
    print("Additional Packages will be made available after install.\n")

def run_zero3_install():
    print("Running zero3 install...")
    print("Additional Packages will be made available after install.\n")

if __name__ == "__main__":
    main()