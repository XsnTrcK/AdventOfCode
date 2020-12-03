//
// Created by albertoaayala on 12/2/2020.
//

#ifndef INC_2020_DAYTWO_H
#define INC_2020_DAYTWO_H

#include <utility>

#include "fileExtensions.h"
#include "stringExtensions.h"

namespace AdventOfCode2020 {
    struct Range {
        Range(int const &min, int const &max) : max(max), min(min) {
        }
        int min;
        int max;

        [[nodiscard]] bool inRange(int const& numberToCheck) const {
            return numberToCheck >= min && numberToCheck <= max;
        }
    };
    struct PasswordHandler {
        PasswordHandler(int const& min, int const& max, char const &letter, string password) : letterOccurrences(Range(min, max)), letter(letter), password(std::move(password)) {
        }
        Range letterOccurrences;
        char letter;
        string password;

        [[nodiscard]] bool isBetweenRangeValid() const {
            return letterOccurrences.inRange(occurrencesOf(password, letter));
        }

        [[nodiscard]] bool isInPositionValid() const {
            auto sizeOfPassword = password.size();
            bool valid = false;
            if (sizeOfPassword >= letterOccurrences.min && password.at(letterOccurrences.min-1) == letter) {
                valid = !valid;
            }
            if (sizeOfPassword >= letterOccurrences.max && password.at(letterOccurrences.max-1) == letter) {
                valid = !valid;
            }

            return valid;
        }
    };

    vector<PasswordHandler> convertToPasswordHandlers(const vector<string>& lines) {
        vector<PasswordHandler> passwordHandlers;
        passwordHandlers.reserve(lines.size());
        for (auto const &line : lines) {
            auto editedLine = eraseAll(line, ':');
            auto spaceSplit = split(editedLine, ' ');
            if (spaceSplit.size() != 3) {
                continue;
            }
            auto rangeSplit = split(spaceSplit[0], '-');
            if (rangeSplit.size() != 2) {
                continue;
            }
            passwordHandlers.emplace_back(PasswordHandler(stoi(rangeSplit[0]), stoi(rangeSplit[1]), spaceSplit[1].at(0), spaceSplit[2]));
        }

        return passwordHandlers;
    }

    enum DayPart {
        One,
        Two
    };

    string dayTwo(const string& fileName, const DayPart& dayPart) {
        auto passwordHandlers = convertToPasswordHandlers(readLines(fileName));
        int amountValid = 0;
        for (auto const& passwordHandler : passwordHandlers) {
            switch (dayPart) {
                case DayPart::One:
                    if (passwordHandler.isBetweenRangeValid()) {
                        amountValid++;
                    }
                    break;
                case DayPart::Two:
                    if (passwordHandler.isInPositionValid()) {
                        amountValid++;
                    }
                    break;
            }
        }

        return to_string(amountValid);
    }
}

#endif //INC_2020_DAYTWO_H
