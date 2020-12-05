#include <iostream>
#include "dayOne.h"
#include "dayTwo.h"
#include "dayThree.h"
#include "dayFour.h"

using namespace std;
using namespace AdventOfCode2020;

int main() {
    string inputPath;
    cout << "Path to Day 1 input:" << endl;
    cin >> inputPath;
    if (inputPath != "s") {
        cout << "Answer Day 1 Part 1: " << dayOnePartOne(inputPath) << endl;
        cout << "Answer Day 1 Part 2: " << dayOnePartTwo(inputPath) << endl;
    }

    cout << "Path to Day 2 input:" << endl;
    cin >> inputPath;
    if (inputPath != "s") {
        cout << "Answer Day 2 Part 1: " << dayTwo(inputPath, DayPart::One) << endl;
        cout << "Answer Day 2 Part 2: " << dayTwo(inputPath, DayPart::Two) << endl;
    }

    cout << "Path to Day 3 input:" << endl;
    cin >> inputPath;
    if (inputPath != "s") {
        cout << "Answer Day 3 Part 1: " << dayThreePartOne(inputPath) << endl;
        cout << "Answer Day 3 Part 2: " << dayThreePartTwo(inputPath) << endl;
    }

    cout << "Path to Day 4 input:" << endl;
    cin >> inputPath;
    if (inputPath != "s") {
        cout << "Answer Day 4 Part 1: " << dayFourPartOne(inputPath, DayPart::One) <<  endl;
        cout << "Answer Day 4 Part 2: " << dayFourPartOne(inputPath, DayPart::Two) <<  endl;
    }
    return 0;
}