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
    string eraseAll(string original, const string& toRemove) {
        size_t position;
        while ((position = original.find(toRemove)) != string::npos) {
            original.erase(position, toRemove.size());
        }
        return original;
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

    vector<string> split(const string& original, const string& delimiter) {
        vector<string> tokens;
        string token;
        size_t last = 0;
        size_t next = 0;
        while ((next = original.find(delimiter, last)) != string::npos) {
            tokens.push_back(original.substr(last, next-last));
            last = next + delimiter.size();
        }
        tokens.push_back(original.substr(last));

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
