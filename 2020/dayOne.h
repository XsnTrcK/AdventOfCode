//
// Created by albertoaayala on 12/2/2020.
//

#ifndef INC_2020_DAYONE_H
#define INC_2020_DAYONE_H

#include <string>
#include "fileExtensions.h"

using namespace std;

namespace AdventOfCode2020 {
    string dayOnePartOne(string const &dayOneInput) {
        auto inputVector = readIntLinesFromFile(dayOneInput);

        auto sizeOfInput = inputVector.size();
        for (auto firstIndex = 0; firstIndex < sizeOfInput; firstIndex++) {
            auto firstValue = inputVector[firstIndex];
            for (auto secondIndex = firstIndex+1; secondIndex < sizeOfInput; secondIndex++) {
                auto secondValue = inputVector[secondIndex];
                if (firstValue+secondValue == 2020) {
                    return to_string(firstValue*secondValue);
                }
            }
        }
    }

    string dayOnePartTwo(string const &dayOneInput) {
        auto inputVector = readIntLinesFromFile(dayOneInput);

        auto sizeOfInput = inputVector.size();
        for (auto firstIndex = 0; firstIndex < sizeOfInput; firstIndex++) {
            auto firstValue = inputVector[firstIndex];
            for (auto secondIndex = firstIndex+1; secondIndex < sizeOfInput; secondIndex++) {
                auto secondValue = inputVector[secondIndex];
                for (auto thirdIndex = secondIndex+1; thirdIndex<sizeOfInput; thirdIndex++) {
                    auto thirdValue = inputVector[thirdIndex];
                    if (firstValue+secondValue+thirdValue == 2020) {
                        return to_string(firstValue*secondValue*thirdValue);
                    }
                }
            }
        }
    }
}

#endif //INC_2020_DAYONE_H
