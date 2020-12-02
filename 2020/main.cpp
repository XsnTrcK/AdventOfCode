#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> readIntLinesFromFile(string const &fileName) {
    ifstream fileToRead(fileName);
    vector<int> result;

    string line;
    while (getline(fileToRead, line)) {
        try {
            result.push_back(stoi(line));
        } catch (exception &error) {
            // Skip lines that cannot be converted to an int
        }
    }

    return result;
}

string dayOnePartOne() {
    auto inputVector = readIntLinesFromFile(R"(C:\Projects\AdventOfCode\2020\dayOnePartOneInput.txt)");

    auto sizeOfInput = inputVector.size();
    for (auto firstIndex = 0; firstIndex < sizeOfInput; firstIndex++) {
        auto firstValue = inputVector[firstIndex];
        for (auto secondIndex = firstIndex+1; secondIndex < sizeOfInput; secondIndex++) {
            auto secondValue = inputVector[secondIndex];
            if (firstValue+secondValue == 2020) {
                return to_string(firstValue*secondValue);
            }
        }
    }
}

string dayOnePartTwo() {
    auto inputVector = readIntLinesFromFile(R"(C:\Projects\AdventOfCode\2020\dayOnePartOneInput.txt)");

    auto sizeOfInput = inputVector.size();
    for (auto firstIndex = 0; firstIndex < sizeOfInput; firstIndex++) {
        auto firstValue = inputVector[firstIndex];
        for (auto secondIndex = firstIndex+1; secondIndex < sizeOfInput; secondIndex++) {
            auto secondValue = inputVector[secondIndex];
            for (auto thirdIndex = secondIndex+1; thirdIndex<sizeOfInput; thirdIndex++) {
                auto thirdValue = inputVector[thirdIndex];
                if (firstValue+secondValue+thirdValue == 2020) {
                    return to_string(firstValue*secondValue*thirdValue);
                }
            }
        }
    }
}

int main() {
    cout << dayOnePartTwo() << endl;
    return 0;
}