#include <iostream>
#include "dayOne.h"
#include "dayTwo.h"
#include "dayThree.h"

using namespace std;
using namespace AdventOfCode2020;

int main() {
    string dayOneInput;
    cout << "Path to Day 1 input:" << endl;
    cin >> dayOneInput;
    if (dayOneInput != "s") {
        cout << "Answer Day 1 Part 1: " << dayOnePartOne(dayOneInput) << endl;
        cout << "Answer Day 1 Part 2: " << dayOnePartTwo(dayOneInput) << endl;
    }

    string dayTwoInput;
    cout << "Path to Day 2 input:" << endl;
    cin >> dayTwoInput;
    if (dayTwoInput != "s") {
        cout << "Answer Day 2 Part 1: " << dayTwo(dayTwoInput, DayPart::One) << endl;
        cout << "Answer Day 2 Part 2: " << dayTwo(dayTwoInput, DayPart::Two) << endl;
    }

    string dayThreeInputPath;
    cout << "Path to Day 3 input:" << endl;
    cin >> dayThreeInputPath;
    if (dayThreeInputPath != "s") {
        cout << "Answer Day 3 Part 1: " << dayThreePartOne(dayThreeInputPath) << endl;
        cout << "Answer Day 3 Part 2: " << dayThreePartTwo(dayThreeInputPath) << endl;
    }
    return 0;
}