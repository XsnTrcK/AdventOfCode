//
// Created by albertoaayala on 12/6/2020.
//

#ifndef INC_2020_DAYSIX_H
#define INC_2020_DAYSIX_H

#include "fileExtensions.h"
#include <unordered_set>
#include <map>

using namespace std;

namespace AdventOfCode2020 {
    struct GroupAnswers {
        unordered_set<char> groupAnswers;

        explicit GroupAnswers(const string& answerString) {
            setupGroupAnswers(answerString);
        }

        explicit GroupAnswers(const vector<string>& answers) {
            if (answers.size() == 1)
                setupGroupAnswers(answers[0]);

            map<char, int> groupAnswersCheck;
            for (const auto& answer : answers) {
                for (const auto& yesChar : answer) {
                    if (groupAnswersCheck.find(yesChar) == groupAnswersCheck.end())
                        groupAnswersCheck.insert({yesChar, 1});
                    else
                        groupAnswersCheck[yesChar]++;
                }
            }
            for (const auto& groupAnswer : groupAnswersCheck) {
                if (groupAnswer.second == answers.size())
                    groupAnswers.insert(groupAnswer.first);
            }
        }

        [[nodiscard]] int amountAnsweredYes() const {
            return groupAnswers.size();
        }
    private:
        void setupGroupAnswers(const string& answerString) {
            for (auto const& yesChar : answerString) {
                if (groupAnswers.find(yesChar) == groupAnswers.end())
                    groupAnswers.insert(yesChar);
            }
        }
    };

    vector<GroupAnswers> createAtLeastOneYesAnswers(const vector<string>& lines) {
        vector<GroupAnswers> groupAnswers;
        string groupAnswerString;
        for (const auto& line : lines) {
            if (line.empty()){
                groupAnswers.emplace_back(GroupAnswers(groupAnswerString));
                groupAnswerString = "";
            }
            groupAnswerString += line;
        }

        return groupAnswers;
    }

    vector<GroupAnswers> createAllYesAnswers(const vector<string>& lines) {
        vector<GroupAnswers> groupAnswers;
        vector<string> answerGroup;
        for (const auto& line : lines) {
            if (line.empty()){
                groupAnswers.emplace_back(GroupAnswers(answerGroup));
                answerGroup.clear();
                continue;
            }
            answerGroup.emplace_back(line);
        }

        return groupAnswers;
    }

    string daySix(const string& fileName, DayPart part) {
        vector<GroupAnswers> groupAnswers;
        if (part == DayPart::One)
            groupAnswers = createAtLeastOneYesAnswers(readLines(fileName));
        else if (part == DayPart::Two)
            groupAnswers = createAllYesAnswers(readLines(fileName));
        int totalYesAnswers = 0;
        for (const auto& groupAnswer : groupAnswers) {
            totalYesAnswers += groupAnswer.amountAnsweredYes();
        }

        return to_string(totalYesAnswers);
    }
}

#endif //INC_2020_DAYSIX_H
