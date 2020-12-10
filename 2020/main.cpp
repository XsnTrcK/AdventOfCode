#include <iostream>
#include "dayOne.h"
#include "dayTwo.h"
#include "dayThree.h"
#include "dayFour.h"
#include "dayFive.h"
#include "daySix.h"
#include "daySeven.h"
#include "dayEight.h"
#include "dayNine.h"

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

    cout << "Path to Day 5 input:" << endl;
    cin >> inputPath;
    if (inputPath != "s") {
        cout << "Answer Day 5 Part 1: " << dayFive(inputPath, DayPart::One) <<  endl;
        cout << "Answer Day 5 Part 2: " << dayFive(inputPath, DayPart::Two) <<  endl;
    }

    cout << "Path to Day 6 input:" << endl;
    cin >> inputPath;
    if (inputPath != "s") {
        cout << "Answer Day 6 Part 1: " << daySix(inputPath, DayPart::One) <<  endl;
        cout << "Answer Day 6 Part 2: " << daySix(inputPath, DayPart::Two) << endl;
    }

    cout << "Path to Day 7 input:" << endl;
    cin >> inputPath;
    if (inputPath != "s") {
        cout << "Answer Day 7 Part 1: " << daySeven(inputPath, DayPart::One) <<  endl;
        cout << "Answer Day 7 Part 2: " << daySeven(inputPath, DayPart::Two) << endl;
    }

    cout << "Path to Day 8 input:" << endl;
    cin >> inputPath;
    if (inputPath != "s") {
        cout << "Answer Day 8 Part 1: " << dayEight(inputPath, DayPart::One) <<  endl;
        cout << "Answer Day 8 Part 2: " << dayEight(inputPath, DayPart::Two) << endl;
    }

    cout << "Path to Day 9 input:" << endl;
    cin >> inputPath;
    if (inputPath != "s") {
        cout << "Answer Day 9 Part 1: " << dayNine(inputPath, DayPart::One) <<  endl;
        cout << "Answer Day 9 Part 2: " << dayNine(inputPath, DayPart::Two) << endl;
    }
    return 0;
}