//
// Created by albertoaayala on 12/4/2020.
//

#ifndef INC_2020_DAYFOUR_H
#define INC_2020_DAYFOUR_H

#include "fileExtensions.h"
#include "stringExtensions.h"
#include <map>
#include <regex>

using namespace std;

namespace AdventOfCode2020 {
    struct Passport{
        map<string,string> passportData;

        explicit Passport(const string& passportString) {
            const auto& passportItems = split(passportString, ' ');
            for (const auto& data : passportItems) {
                const auto& keyValue = split(data, ':');
                if (keyValue.size() != 2) {
                    throw "Too many pieces in string";
                }
                passportData.insert({keyValue[0], keyValue[1]});
            }
        }

        [[nodiscard]] bool isValid() const {
            if (passportData.size() == 8) {
                return true;
            }
            if (passportData.size() < 7) {
                return false;
            }
            return passportData.find("cid") == passportData.end();
        }

        [[nodiscard]] bool isRuleValid() const {
            return birthYearValid() && issueYearValid() && expirationYearValid() && heightValid() && hairColorValid() && eyeColorValid() && passportIdValid();
        }

    private:
        [[nodiscard]] bool birthYearValid() const {
            auto birthYearItr = passportData.find("byr");
            if (birthYearItr == passportData.end()) return false;

            auto birthYear = stoi(birthYearItr->second);
            return birthYear >= 1920 && birthYear <= 2002;
        }
        [[nodiscard]] bool issueYearValid() const {
            auto issueYearItr = passportData.find("iyr");
            if (issueYearItr == passportData.end()) return false;

            auto issueYear = stoi(issueYearItr->second);
            return issueYear >= 2010 && issueYear <= 2020;
        }
        [[nodiscard]] bool expirationYearValid() const {
            auto expirationYearItr = passportData.find("eyr");
            if (expirationYearItr == passportData.end()) return false;

            auto expirationYear = stoi(expirationYearItr->second);
            return expirationYear >= 2020 && expirationYear <= 2030;
        }
        [[nodiscard]] bool heightValid() const {
            auto heightItr = passportData.find("hgt");
            if (heightItr == passportData.end()) return false;

            auto heightString = heightItr->second;
            if (heightString.find("cm") != string::npos) {
                auto heightInCm = stoi(eraseAll(heightString, "cm"));
                return heightInCm >= 150 && heightInCm <= 193;
            }
            if (heightString.find("in") != string::npos) {
                auto heightInIn = stoi(eraseAll(heightString, "in"));
                return heightInIn >= 59 && heightInIn <= 76;
            }
            return false;
        }
        [[nodiscard]] bool hairColorValid() const {
            auto hairColorItr = passportData.find("hcl");
            if (hairColorItr == passportData.end()) return false;

            const auto& hairColorRegex = regex("^#[0-9a-f]{6}$");
            return regex_match(hairColorItr->second, hairColorRegex);
        }
        [[nodiscard]] bool eyeColorValid() const {
            auto eyeColorItr = passportData.find("ecl");
            if (eyeColorItr == passportData.end()) return false;

            const vector<string>& validEyeColors{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
            return find(validEyeColors.begin(), validEyeColors.end(), eyeColorItr->second) != validEyeColors.end();
        }
        [[nodiscard]] bool passportIdValid() const {
            auto passportIdItr = passportData.find("pid");
            if (passportIdItr == passportData.end()) return false;

            const auto& passportIdRegex = regex("^[0-9]{9}$");
            return regex_match(passportIdItr->second, passportIdRegex);
        }
    };

    vector<Passport> createPassports(vector<string> lines) {
        string passportString;
        vector<Passport> passports;
        for (const auto& line : lines) {
            if (line.empty()) {
                passports.emplace_back(Passport(passportString));
                passportString = "";
            }
            if (!passportString.empty()){
                passportString += " ";
            }
            passportString += line;
        }
        if (!passportString.empty()) {
            passports.emplace_back(Passport(passportString));
        }

        return passports;
    }

    string dayFourPartOne(const string& fileName, DayPart dayPart) {
        auto valid = 0;
        const auto& passports = createPassports(readLines(fileName));
        for (const auto& passport : passports) {
            if (DayPart::One == dayPart && passport.isValid()) {
                valid++;
            } else if (DayPart::Two == dayPart && passport.isRuleValid()) {
                valid++;
            }
        }

        return to_string(valid);
    }
}

#endif //INC_2020_DAYFOUR_H
