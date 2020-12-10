//
// Created by albertoaayala on 12/9/2020.
//

#ifndef INC_2020_DAYNINE_H
#define INC_2020_DAYNINE_H

#include "fileExtensions.h"

namespace AdventOfCode2020 {
    struct XmasEncodingValidator {
        vector<long long> values;
        explicit XmasEncodingValidator(const vector<long long>& values) : values(values) {
        }

        long long findFirstInvalid() {
            for (auto index = 25; index < values.size(); index++) {
                if (!validValue(values[index], index))
                    return values[index];
            }
            throw "Could not find invalid value";
        }
        long long encryptionWeakness() {
            const auto& invalidValue = findFirstInvalid();
            vector<long long> addedToInvalid;
            long long addedValue;
            for (auto first = 0; first < values.size(); first++) {
                auto second = first + 1;
                addedToInvalid.push_back(values[first]);
                addedToInvalid.push_back(values[second]);
                addedValue = values[first] + values[second];
                while (addedValue < invalidValue) {
                    second++;
                    addedValue+=values[second];
                    addedToInvalid.push_back(values[second]);
                }
                if (addedValue == invalidValue){
                    sort(addedToInvalid.begin(), addedToInvalid.end());
                    return addedToInvalid[0] + addedToInvalid[addedToInvalid.size()-1];
                }
                addedToInvalid.clear();
            }
            throw "Could not find a contiguous set of numbers that add to invalid value";
        }
    private:
        bool validValue(long long value, int valueIndex) {
            for (auto first = valueIndex-25; first < valueIndex-1; first++) {
                for (auto second = first+1; second < valueIndex; second++) {
                    if (values[first]+values[second] == value)
                        return true;
                }
            }
            return false;
        }
    };

    vector<long long> createLongLongVector(const vector<string>& lines) {
        vector<long long> longLongs;
        for (const auto& line : lines) {
            longLongs.push_back(stoll(line));
        }

        return longLongs;
    }


    string dayNine(const string& fileName, DayPart dayPart) {
        XmasEncodingValidator xmasEncodingValidator(createLongLongVector(readLines(fileName)));
        if (dayPart == DayPart::One)
            return to_string(xmasEncodingValidator.findFirstInvalid());
        else if (dayPart == DayPart::Two)
            return to_string(xmasEncodingValidator.encryptionWeakness());
    }
}

#endif //INC_2020_DAYNINE_H
