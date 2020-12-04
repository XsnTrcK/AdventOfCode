//
// Created by albertoaayala on 12/3/2020.
//

#ifndef INC_2020_DAYTHREE_H
#define INC_2020_DAYTHREE_H

#include <utility>

#include "fileExtensions.h"

using namespace std;

namespace AdventOfCode2020 {
    struct TreeRow {
        explicit TreeRow(string row) : row(std::move(row)) {
            rowSize = this->row.size();
        }
        string row;

        bool hitTree(int xPosition) {
            return row.at(xPosition % rowSize) == _treeCharacter;
        }
    private:
        static const char _treeCharacter = '#';

        int rowSize;
    };

    struct TobogganRider {
        explicit TobogganRider(const vector<string>& lines) {
            for (const auto& line : lines) {
                rideArea.emplace_back(TreeRow(line));
            }
        }

        vector<TreeRow> rideArea;

        int numberOfTreesHitDuringRide(int xRide, int yRide) {
            auto numberOfTreesHit = 0;
            auto xLocation = xRide;
            for (auto yLocation = yRide; yLocation < rideArea.size(); yLocation+=yRide) {
                if (rideArea[yLocation].hitTree(xLocation)){
                    numberOfTreesHit++;
                }
                xLocation += xRide;
            }

            return numberOfTreesHit;
        }
    };

    string dayThreePartOne(const string& fileName) {
        return to_string(TobogganRider(readLines(fileName)).numberOfTreesHitDuringRide(3, 1));
    }

    string dayThreePartTwo(const string& fileName) {
        TobogganRider tobogganRider(readLines(fileName));
        const auto& firstRide = tobogganRider.numberOfTreesHitDuringRide(1,1);
        const auto& secondRide = tobogganRider.numberOfTreesHitDuringRide(3,1);
        const auto& thirdRide = tobogganRider.numberOfTreesHitDuringRide(5,1);
        const auto& fourthRide = tobogganRider.numberOfTreesHitDuringRide(7,1);
        const auto& fifthRide = tobogganRider.numberOfTreesHitDuringRide(1,2);

        return to_string(firstRide*secondRide*thirdRide*fourthRide*fifthRide);
    }
}

#endif //INC_2020_DAYTHREE_H
