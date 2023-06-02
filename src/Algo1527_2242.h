//
// Created by zxkmm.
//

#ifndef OOKFORMATCALCULATE_ALGO1527_2242_H
#define OOKFORMATCALCULATE_ALGO1527_2242_H

#include <string>
#include <iostream> //DBG

#include "processUnit.h"


class Algo1527_2242 {

public:
    std::string decode1527FromUrh(std::string stringOf1527WaveformFromUrh);

    std::string trans4Bit1527To2Bit(std::string i1527B4);

    std::string trans2Bit1527To4Bit(std::string i1527B2);
};


#endif //OOKFORMATCALCULATE_ALGO1527_2242_H
