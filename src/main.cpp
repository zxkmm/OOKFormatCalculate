//
// Created by zxkmm on 2/6/23.
//

#include "main.h"
#include "Interface.h"

int main() {
    Interface interface;
    interface.mainMenu();
    if (interface.mainMenu() == 1) {
        interface.mainMenu();
    }
    return 0;
}
