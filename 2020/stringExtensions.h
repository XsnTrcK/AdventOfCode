//
// Created by albertoaayala on 12/2/2020.
//

#ifndef INC_2020_STRINGEXTENSIONS_H
#define INC_2020_STRINGEXTENSIONS_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace AdventOfCode2020 {
    string eraseAll(string const &original, char removeChar) {
        string result;
        result.reserve(original.size()); // Avoids buffer realloction in loop

        for (auto const &character : original) {
            if (character != removeChar) {
                result += character;
            }
        }

        return result;
    }

    vector<string> split(string const &original, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(original);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }

        return tokens;
    }

    int occurrencesOf(string const& original, char charToCount) {
        int occurrences = 0;
        for (auto const& character : original) {
            if (character == charToCount) {
                occurrences++;
            }
        }

        return occurrences;
    }
}

#endif //INC_2020_STRINGEXTENSIONS_H
