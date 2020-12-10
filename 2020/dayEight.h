//
// Created by albertoaayala on 12/9/2020.
//

#ifndef INC_2020_DAYEIGHT_H
#define INC_2020_DAYEIGHT_H

#include "fileExtensions.h"
#include "stringExtensions.h"
#include <unordered_set>

namespace AdventOfCode2020 {
    struct instructionSet {
        string instruction;
        int value;

        explicit instructionSet(const string& line) {
            const vector<string> instructionSetVector = split(line, ' ');
            if (instructionSetVector.size() != 2)
                throw "Invalid instruction set";

            instruction = instructionSetVector[0];
            value = stoi(instructionSetVector[1]);
        }
    };
    struct instructionSetManager {
        vector<instructionSet> instructions;

        explicit instructionSetManager(const vector<instructionSet>& instructions) : instructions(instructions) {
        }

        [[nodiscard]] int accumulatorBeforeLoop() const {
            return findAccumulator(instructions, true);
        }

        int solveWithNoLoop() {
            for (auto& instructionSet : instructions) {
                if (instructionSet.instruction == "jmp") {
                    instructionSet.instruction = "nop";
                    auto foundAccumulator = findAccumulator(instructions, false);
                    if (foundAccumulator != -1)
                        return foundAccumulator;
                    instructionSet.instruction = "jmp";
                } else if (instructionSet.instruction == "nop") {
                    instructionSet.instruction = "jmp";
                    auto foundAccumulator = findAccumulator(instructions, false);
                    if (foundAccumulator != -1)
                        return foundAccumulator;
                    instructionSet.instruction = "nop";
                }
            }
            return 0;
        }

    private:
        static int findAccumulator(vector<instructionSet> instructions, bool resolveWithLoop) {
            auto accumulator = 0;
            unordered_set<int> visited;
            for (auto line = 0; line < instructions.size();) {
                const auto& instructionSet = instructions[line];
                if (visited.find(line) != visited.end()){
                    if (resolveWithLoop)
                        return accumulator;
                    else
                        return -1;
                }
                visited.insert(line);
                if (instructionSet.instruction == "acc")
                    accumulator += instructionSet.value;
                else if (instructionSet.instruction == "jmp") {
                    line += instructionSet.value;
                    continue;
                }
                line++;
            }
            return accumulator;
        }
    };

    vector<instructionSet> createInstructions(const vector<string>& instructionLines) {
        vector<instructionSet> instructions;
        for (const auto& instructionLine : instructionLines) {
            instructions.emplace_back(instructionSet(instructionLine));
        }

        return instructions;
    }

    string dayEight(const string& fileName, DayPart part) {
        instructionSetManager instructionSetManager(createInstructions(readLines(fileName)));
        if (part == DayPart::One)
            return to_string(instructionSetManager.accumulatorBeforeLoop());
        else if (part == DayPart::Two)
            return to_string(instructionSetManager.solveWithNoLoop());
    }
}

#endif //INC_2020_DAYEIGHT_H
