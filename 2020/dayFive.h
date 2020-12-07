//
// Created by albertoaayala on 12/6/2020.
//

#ifndef INC_2020_DAYFIVE_H
#define INC_2020_DAYFIVE_H

#include "fileExtensions.h"
#include <climits>
#include <algorithm>

namespace AdventOfCode2020 {
    struct BoardingPass {
        string rowCode;
        string seatCode;
        int seatId = INT_MIN;

        explicit BoardingPass(string code) {
            if (code.size() != 10)
                throw "Invalid boarding pass code";

            rowCode = code.substr(0, 7);
            seatCode = code.substr(7);
        }

        int getId() {
            if (seatId == INT_MIN)
                seatId = (resolveCode(rowCode, 0, 127)*8)+resolveCode(seatCode, 0, 7);
            return seatId;
        }

    private:
        static int resolveCode(const string& code, int lowValue, int highValue) {
            auto high = highValue;
            auto low = lowValue;
            char character;
            for (char i : code) {
                character = i;
                if (character == 'F' || character == 'L') {
                    high = (high+low)/2;
                } else if (character == 'B' || character == 'R') {
                    low = ((high+low)/2)+1;
                }
            }

            return high;
        }
    };

    vector<BoardingPass> convertLinesToBoardingPasses(const vector<string>& lines) {
        vector<BoardingPass> boardingPasses;
        for (const auto& line : lines) {
            boardingPasses.emplace_back(BoardingPass(line));
        }

        return boardingPasses;
    }

    bool compareBoardingPasses(BoardingPass first, BoardingPass second) {
        return first.seatId < second.seatId;
    }

    string dayFive(const string& fileName, DayPart part) {
        auto boardingPasses = convertLinesToBoardingPasses(readLines(fileName));
        auto highestSeatId = INT_MIN;
        auto lowestSeatId = INT_MAX;
        int currentSeatId;
        for (auto& boardingPass : boardingPasses) {
            currentSeatId = boardingPass.getId();
            if (highestSeatId < currentSeatId)
                highestSeatId = currentSeatId;
            if (currentSeatId < lowestSeatId)
                lowestSeatId = currentSeatId;
        }

        sort(boardingPasses.begin(), boardingPasses.end(), compareBoardingPasses);
        if (part == DayPart::One)
            return to_string(highestSeatId);
        else {
            auto mySeatId = lowestSeatId;
            auto index = 0;
            while (mySeatId == boardingPasses[index].seatId) {
                mySeatId++;
                index++;
            }
            return to_string(mySeatId);
        }
    }
}

#endif //INC_2020_DAYFIVE_H
