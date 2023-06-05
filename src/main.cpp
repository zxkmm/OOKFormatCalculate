//
// Created by zxkmm on 2/6/23.
//

#include "main.h"
#include "Interface.h"


int main() {
    Interface interface;
    if (interface.mainMenu() == 1) {
        std::cout << "\nback to main menu\n";
        interface.mainMenu();
    }
    return 0;
}
