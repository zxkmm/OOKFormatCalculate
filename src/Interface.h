//
// Created by zxkmm.
//

#ifndef OOKFORMATCALCULATE_INTERFACE_H
#define OOKFORMATCALCULATE_INTERFACE_H

#include <string>
#include <iostream>
#include "Algo226x.h"
#include "Algo1527_2242.h"

#endif //OOKFORMATCALCULATE_INTERFACE_H


class Interface {

public:
    int mainMenu();

private:

    void outputAClearResult(std::string explainContent, std::string result, std::string ADFormat);


    std::string ascii_art = R"(

 ██████╗  ██████╗ ██╗  ██╗███████╗ ██████╗ ███╗   ███╗ ██████╗ █████╗ ██╗
██╔═══██╗██╔═══██╗██║ ██╔╝██╔════╝██╔═══██╗████╗ ████║██╔════╝██╔══██╗██║
██║   ██║██║   ██║█████╔╝ █████╗  ██║   ██║██╔████╔██║██║     ███████║██║
██║   ██║██║   ██║██╔═██╗ ██╔══╝  ██║   ██║██║╚██╔╝██║██║     ██╔══██║██║
╚██████╔╝╚██████╔╝██║  ██╗██║     ╚██████╔╝██║ ╚═╝ ██║╚██████╗██║  ██║███████╗
 ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝      ╚═════╝ ╚═╝     ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝

)";

    std::string menu = "\n----\nPress 1 for demodulated 2262/2260 from URH to static 2262/2260 code, 11 for diff two pieces\n"
                       "----\nPress 2 for demodulated 1527/2242 from URH to static 1527/2242 code, 21 for diff two pieces\n"
                       "----\nPress 3 for for 4Bits 1527 code to 2Bits\n"
                       "----\nPress 4 for 2Bits 1527 code to 4Bits\n"
                       "----\nPress 5 for general decode e.g. Tesla/K5 Morining/Car keys, 51 for diff two pieces\n"
                       "----\nPress 6 for auto decoding, 61 for auto diff (beta)\n"
                       "----\nPress 99 to exit.\n"
                       "\nChoice:";


};



