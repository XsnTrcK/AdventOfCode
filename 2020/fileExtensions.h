//
// Created by albertoaayala on 12/2/2020.
//

#ifndef INC_2020_FILEEXTENSIONS_H
#define INC_2020_FILEEXTENSIONS_H


#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

namespace AdventOfCode2020 {
    vector<string> readLines(string const &fileName) {
        ifstream fileToRead(fileName);
        vector<string> result;

        string line;
        while (getline(fileToRead, line)) {
            result.push_back(line);
        }

        return result;
    }


    vector<int> readIntLinesFromFile(string const &fileName) {
        auto lines = readLines(fileName);
        vector<int> result;

        for(auto const &line :  lines) {
            try {
                result.push_back(stoi(line));
            } catch (exception &error) {
                // skip lines that cannot be converted to int
            }
        }

        return result;
    }
}

#endif //INC_2020_FILEEXTENSIONS_H