//
// Created by zxkmm.
//

#include "Interface.h"
#include "AlgoGeneral.h"

void Interface::outputAClearResult(std::string explainContent, std::string result, std::string ADFormat) {
    //detect how long the result is, then put the result into an int variable
    unsigned long resultLength = result.length();
//    std::cout << resultLength << std::endl; //DBG
    //detect how long the explainContent is, then put the explainContent into an int variable
    unsigned long explainContentLength = explainContent.length();
    //output spaces which is as long as explainContentLength
    if (resultLength < 80) {
        for (int i = 0; i < explainContentLength; i++) {
            std::cout << " ";
        }
        std::cout << "┏";
        //output spaces which is as long as resultLength
        for (int i = 0; i < resultLength; i++) {
            std::cout << "━";
        }
        std::cout << "┓" << std::endl;
        std::cout << explainContent << "┃" << result << "┃" << std::endl;
        for (int i = 0; i < explainContentLength; i++) {
            std::cout << " ";
        }
        std::cout << "┗";
        for (int i = 0; i < resultLength; i++) {
            std::cout << "━";
        }
        std::cout << "┛" << std::endl;
        //output spaces which is as long as explainContentLength
        for (int i = 0; i < explainContentLength; i++) {
            std::cout << " ";
        }
        std::cout << " " + ADFormat;
        std::cout << "\n";
    } else {
        std::cout << std::endl << result << std::endl;
    }
}

int Interface::mainMenu() {

    std::cout << "\n----\nPress 1 for demodulated 2262/2260 from URH to static 2262/2260 code\n"
              << "----\nPress 2 for demodulated 1527/2242 from URH to static 1527/2242 code\n"
              << "----\nPress 3 for for 4Bits 1527 code to 2Bits\n"
              << "----\nPress 4 for 2Bits 1527 code to 4Bits\n"
              << "----\nPress 5 for general decode e.g. Tesla/K5 Morining/Car keys\n"
              << "----\nPress 99 to exit.\n"
              << "\nChoice:";

    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {//demodulated 2262/2260 from URH to static 2262/2260 code
            Algo226x decodeUrh2262;
            std::string userInputed2262CodeFromUrh;
            std::cout << "Input 2262/2260 demodulated code from URH:\n>";
            std::cin >> userInputed2262CodeFromUrh;
            Interface::outputAClearResult("static 2262 code is:",
                                          decodeUrh2262.decode2262FromUrh(userInputed2262CodeFromUrh), "AAAAAAAADDDD");
            //press any key to continue


            return 1;
        }
        case 2: {//demodulated 1527/2242 from URH to static 1527/2242 code
            Algo1527_2242 decodeUrh1527;
            std::string userInputed1527CodeFromUrh;
            std::cout << "Input 1527/2242 demodulated code from URH:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            Interface::outputAClearResult("static 1527 code is:",
                                          decodeUrh1527.decode1527FromUrh(userInputed1527CodeFromUrh), "AAAAAAAAAADDDD");

            //press any key to continue

            return 1;
        }
        case 3: {//4Bits 1527 code to 2Bits
            Algo1527_2242 calculate1527_2_4;
            std::string userInputed1527CodeFromUrh;
            std::cout << "Input 4Bits 1527 code:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            Interface::outputAClearResult("2Bits 1527 code is:",
                                          calculate1527_2_4.trans4Bit1527To2Bit(userInputed1527CodeFromUrh),
                                          "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADDDD");
            return 1;

        }
        case 4: {//2Bits 1527 code to 4Bits
            Algo1527_2242 calculate1527_4_2;
            std::string userInputed1527CodeFromUrh;
            std::cout << "Input 2Bits 1527 code:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            Interface::outputAClearResult("4Bits 1527 code is:",
                                          calculate1527_4_2.trans2Bit1527To4Bit(userInputed1527CodeFromUrh),
                                          "AAAAAAAAAADDDD");
            return 1;


        }
        case 5: {//general decode e.g. Tesla/K5 Morining/Car keys
            AlgoGeneral decodeGeneral;
            std::string userInputed1527CodeFromUrh;
            std::cout << "Input 2Bits general code from URH:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            Interface::outputAClearResult("NW Mode of the code is:",
                                          decodeGeneral.decodeGeneralFromUrh(userInputed1527CodeFromUrh),
                                          "");
            return 1;


        }

        case 99:
            return 0;
        default:
            std::cout << "Invalid input, please try again.\n";
            return 1;
    }

}
