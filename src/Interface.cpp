//
// Created by zxkmm.
//

#include "Interface.h"
#include "AlgoGeneral.h"
#include <unordered_set>

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

    std::cout << ascii_art << '\n';

    std::cout << menu << std::endl;

    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {//demodulated 2262/2260 from URH to static 2262/2260 code
            Algo226x decodeUrh2262;
            std::string userInputed2262CodeFromUrh;
            std::cout << "Input 2262/2260 demodulated code from URH:\n>";
            std::cin >> userInputed2262CodeFromUrh;
            Interface::outputAClearResult(
                    "static 2262 code is:",
                    decodeUrh2262.decode2262FromUrh(userInputed2262CodeFromUrh),
                    "AAAAAAAADDDD");
            return 1;
        }
        case 2: {//demodulated 1527/2242 from URH to static 1527/2242 code
            Algo1527_2242 decodeUrh1527;
            std::string userInputed1527CodeFromUrh;
            std::cout << "Input 1527/2242 demodulated code from URH:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            Interface::outputAClearResult(
                    "static 1527 code is:",
                    decodeUrh1527.decode1527FromUrh(userInputed1527CodeFromUrh),
                    "AAAAAAAAAADDDD");

            //press any key to continue

            return 1;
        }
        case 3: {//4Bits 1527 code to 2Bits
            Algo1527_2242 calculate1527_2_4;
            std::string userInputed1527CodeFromUrh;
            std::cout << "Input 4Bits 1527 code:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            Interface::outputAClearResult(
                    "2Bits 1527 code is:",
                    calculate1527_2_4.trans4Bit1527To2Bit(userInputed1527CodeFromUrh),
                    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADDDD");
            return 1;

        }
        case 4: {//2Bits 1527 code to 4Bits
            Algo1527_2242 calculate1527_4_2;
            std::string userInputed1527CodeFromUrh;
            std::cout << "Input 2Bits 1527 code:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            Interface::outputAClearResult(
                    "4Bits 1527 code is:",
                    calculate1527_4_2.trans2Bit1527To4Bit(userInputed1527CodeFromUrh),
                    "AAAAAAAAAADDDD");
            return 1;


        }
        case 5: {//general decode e.g. Tesla/K5 Morining/Car keys
            AlgoGeneral decodeGeneral;
            std::string userInputed1527CodeFromUrh;
            std::cout << "Input 2Bits general code from URH:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            Interface::outputAClearResult(
                    "NW Mode of the code is:",
                    decodeGeneral.decodeGeneralFromUrh(userInputed1527CodeFromUrh),
                    "");
            return 1;


        }

        case 11: {

            Algo226x decodeAndDiffUrh2262;

            std::string userInputed2262CodeFromUrh;

            std::cout << "Input 1st 226x demodulated code from URH:\n>";
            std::cin >> userInputed2262CodeFromUrh;
            std::string firstDecodeResult = decodeAndDiffUrh2262.decode2262FromUrh(userInputed2262CodeFromUrh);
            Interface::outputAClearResult(
                    "first static 226x code is: ",
                    firstDecodeResult,
                    "AAAAAAAADDDD");

            std::cout << "Input 2nd 226x demodulated code from URH:\n>";
            std::cin >> userInputed2262CodeFromUrh;
            std::string secondDecodeResult = decodeAndDiffUrh2262.decode2262FromUrh(userInputed2262CodeFromUrh);
            Interface::outputAClearResult(
                    "second static 226x code is:",
                    secondDecodeResult,
                    "AAAAAAAADDDD");

            StringUnit stringUnit;
            std::string diff = stringUnit.compareTwoStrings(firstDecodeResult, secondDecodeResult);
            std::cout << "diff:" << std::endl;
            std::cout << firstDecodeResult << std::endl;
            std::cout << diff << std::endl;
            std::cout << secondDecodeResult << std::endl;

            if (diff.find_first_not_of("-") == std::string::npos) {
                std::cout << "(all same)" << std::endl;
            }

            return 1;

        }

        case 21: {

            Algo1527_2242 decodeAndDiffUrh1527;

            std::string userInputed1527CodeFromUrh;

            std::cout << "Input 1st 1527/2242 demodulated code from URH:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            std::string firstDecodeResult = decodeAndDiffUrh1527.decode1527FromUrh(userInputed1527CodeFromUrh);
            Interface::outputAClearResult(
                    "first 1527/2242 code is: ",
                    firstDecodeResult,
                    "AAAAAAAADDDD");

            std::cout << "Input 2nd 1527/2242 demodulated code from URH:\n>";
            std::cin >> userInputed1527CodeFromUrh;
            std::string secondDecodeResult = decodeAndDiffUrh1527.decode1527FromUrh(userInputed1527CodeFromUrh);
            Interface::outputAClearResult(
                    "second 1527/2242 code is:",
                    secondDecodeResult,
                    "AAAAAAAADDDD");

            StringUnit stringUnit;
            std::string diff = stringUnit.compareTwoStrings(firstDecodeResult, secondDecodeResult);
            std::cout << "diff:" << std::endl;
            std::cout << firstDecodeResult << std::endl;
            std::cout << diff << std::endl;
            std::cout << secondDecodeResult << std::endl;

            if (diff.find_first_not_of("-") == std::string::npos) {
                std::cout << "(all same)" << std::endl;
            }

            return 1;

        }

        case 51: {//demodulated general code from URH to static 2262/2260 code two times and do diff

            AlgoGeneral decodeGeneral;

            std::string userInputedGeneralCodeFromUrh;

            std::cout << "Input 1st general demodulated code from URH:\n>";
            std::cin >> userInputedGeneralCodeFromUrh;
            std::string firstDecodeResult = decodeGeneral.decodeGeneralFromUrh(userInputedGeneralCodeFromUrh);
            Interface::outputAClearResult("first static general code is: ",
                                          firstDecodeResult, "");

            std::cout << "Input 2nd general demodulated code from URH:\n>";
            std::cin >> userInputedGeneralCodeFromUrh;
            std::string secondDecodeResult = decodeGeneral.decodeGeneralFromUrh(userInputedGeneralCodeFromUrh);
            Interface::outputAClearResult("second static general code is:",
                                          secondDecodeResult, "");

            if (firstDecodeResult.length() != secondDecodeResult.length()) {
                std::cout
                        << "Warning: length is different, it's definitely not same and maybe there's bad decode processing"
                        << std::endl;
            }

            StringUnit stringUnit;
            std::string diff = stringUnit.compareTwoStrings(firstDecodeResult, secondDecodeResult);
            std::cout << "diff:" << std::endl;
            std::cout << firstDecodeResult << std::endl;
            std::cout << diff << std::endl;
            std::cout << secondDecodeResult << std::endl;

            if (diff.find_first_not_of("-") == std::string::npos) {
                std::cout << "(all same)" << std::endl;
            }

            return 1;
        }

        case 6: {//auto decoding
            Algo1527_2242 decodeUnkownTry1527;
            Algo226x decodeUnknownTry2262;
            AlgoGeneral decodeUnknownTryFinal;

            std::string userInputedUnknownCodeFromUrh;
            std::string test1527Result;
            std::string test2262Result;
            std::string testFinalResult;
            std::string typeResult = "notset";
            std::unordered_set<char> valid2262Chars = {'0', 'F', '1'};
            std::unordered_set<char> valid1527Chars = {'0', 'F', '1', 'H'};
            std::unordered_set<char> validGeneralChars = {'.', '_'};
            std::cout << "Input Unknown demodulated code from URH:\n>";
            std::cin >> userInputedUnknownCodeFromUrh;
            test1527Result = decodeUnkownTry1527.decode1527FromUrh(userInputedUnknownCodeFromUrh);
            test2262Result = decodeUnknownTry2262.decode2262FromUrh(userInputedUnknownCodeFromUrh);
            testFinalResult = decodeUnknownTryFinal.decodeGeneralFromUrh(userInputedUnknownCodeFromUrh);

            std::cout << "\n------\n";
            std::cout << test1527Result;

            std::cout << "\n------\n";
            std::cout << test2262Result;

            std::cout << "\n------\n";
            std::cout << testFinalResult;

            std::cout << "\n------\n";


            for (char _set2262: test2262Result) {
                if (valid2262Chars.find(_set2262) == valid2262Chars.end()) {//isn't in 2262 range
                    //try1527
                    std::cout << "\nisn't in 2262 range try1527\n";
                    for (char _set1527: test1527Result) {
                        if (valid1527Chars.find(_set1527) == valid2262Chars.end()) {//isn't in 1527 range
                            //try general
                            std::cout << "\nisn't in 1527 range trygener\n";
                            for (char _setGenral: testFinalResult) {
                                if (validGeneralChars.find(_setGenral) ==
                                    validGeneralChars.end()) {//isn't in general range'
                                    typeResult = "unknown";
                                    break;
                                } else {//in gerenal range
                                    typeResult = "general";
                                    break;
                                }
                            }

                            //try general end
                        } else if (test1527Result.length() == 14) {//is in 1527 range && is 1527 length
                            typeResult = "1527";
                            break;
                        }
                    }

                    //try1527end
                } else if (test2262Result.length() == 14) {//is in 2262 range && is 2262 length
                    typeResult = "2262";
                    break;
                }
            }


            std::cout << "\n------\n";
            std::cout << typeResult;
            std::cout << "\n------\n";

            if (typeResult == "1527") {
                Interface::outputAClearResult("static 1527 code is:", test1527Result, "AAAAAAAAAADDDD");
            } else if (typeResult == "2262") {
                Interface::outputAClearResult("static 2262 code is:", test2262Result, "AAAAAAAAAADDDD");
            } else {
                Interface::outputAClearResult("NW Mode of the code is:", testFinalResult, "");
            }

            return 1;
        }

        case 99:
            return 0;
        default:
            std::cout << "Invalid input, please try again.\n";
            return 1;
    }

}
