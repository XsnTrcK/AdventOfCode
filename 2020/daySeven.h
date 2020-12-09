//
// Created by albertoaayala on 12/7/2020.
//

#ifndef INC_2020_DAYSEVEN_H
#define INC_2020_DAYSEVEN_H

#include "fileExtensions.h"
#include "stringExtensions.h"
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

namespace AdventOfCode2020 {
    static string noOtherBagsIdentifier = string("no other bags");
    struct BagRule { // Don't need struct can replace with kvp of string and innerBags map
        string currentBag;
        map<string, int> innerBags;

        explicit BagRule(const string& bagRule) {
            const auto& currentBagAndBags = split(bagRule, " contain ");
            if (currentBagAndBags.size() != 2)
                throw "Invalid bag rule";

            currentBag = currentBagAndBags[0];
            const auto& innerBagsString = eraseAll(currentBagAndBags[1], '.');
            const auto& innerBagsStringSplit = split(innerBagsString, ", ");
            for (const auto& innerBagString : innerBagsStringSplit) {
                if (innerBagString == noOtherBagsIdentifier) {
                    innerBags.insert({innerBagString, 0});
                    break;
                }
                const auto& numberOfInnerBags = stoi(innerBagString.substr(0, 1));
                auto innerBagKey = innerBagString.substr(2);
                if (innerBagKey.at(innerBagKey.size()-1) != 's') {
                    innerBagKey += "s";
                }
                innerBags.insert({innerBagKey, numberOfInnerBags});
            }
        }
    };
    struct BagRuleHandler {
        unordered_map<string, BagRule> bagRules;

        explicit BagRuleHandler(const unordered_map<string, BagRule>& bagRules) : bagRules(bagRules) {
        }

        int howManyBagsCanContain(const string& bagToFind) {
            for (const auto& bagRule : bagRules) {
                search(bagRule.second, bagToFind);
            }

            return foundBagsThatContain.size();
        }

        int howManyBagsInside(const string& bagToCheck) {
            const auto& bagRuleItr = bagRules.find(bagToCheck);
            if (bagRuleItr == bagRules.end())
                return 0;

            int amountOfInnerBags = 0;
            for (auto& innerBag : bagRuleItr->second.innerBags) {
                if (innerBag.first == noOtherBagsIdentifier)
                    return amountOfInnerBags;

                amountOfInnerBags += innerBag.second;
                amountOfInnerBags += (innerBag.second*howManyBagsInside(innerBag.first));
            }
            return amountOfInnerBags;
        }

    private:
        unordered_set<string> foundBagsThatContain;
        bool search(const BagRule& bagRule, const string& bagToFind) {
            if (foundBagsThatContain.find(bagRule.currentBag) != foundBagsThatContain.end())
                return true;
            for (const auto& innerBagInfo : bagRule.innerBags) {
                if (foundBagsThatContain.find(innerBagInfo.first) != foundBagsThatContain.end()) {
                    foundBagsThatContain.insert(bagRule.currentBag);
                    return true;
                }
                if (innerBagInfo.first == noOtherBagsIdentifier)
                    return false;
                if (innerBagInfo.first == bagToFind) {
                    foundBagsThatContain.insert(bagRule.currentBag);
                    return true;
                }
                const auto& bagRuleItr = bagRules.find(innerBagInfo.first);
                if (bagRuleItr != bagRules.end()) {
                    if (search(bagRuleItr->second, bagToFind)) {
                        foundBagsThatContain.insert(bagRule.currentBag);
                        return true;
                    }
                }
            }

            return false;
        }
    };

    unordered_map<string, BagRule> createBagRules(const vector<string>& lines) {
        unordered_map<string, BagRule> bagRules;
        for (const auto& line : lines) {
            const BagRule& bagRule = BagRule(line);
            bagRules.insert({bagRule.currentBag, bagRule});
        }

        return bagRules;
    }

    string daySeven(const string& fileName, DayPart part) {
        BagRuleHandler bagRuleHandler = BagRuleHandler((createBagRules(readLines(fileName))));

        if (part == DayPart::One)
            return to_string(bagRuleHandler.howManyBagsCanContain("shiny gold bags"));
        else if (part == DayPart::Two)
            return to_string(bagRuleHandler.howManyBagsInside("shiny gold bags"));

        throw "Day part error";
    }
}

#endif //INC_2020_DAYSEVEN_H
