#include <iostream>
#include "dayOne.h"
#include "dayTwo.h"

using namespace std;
using namespace AdventOfCode2020;

int main() {
    string dayOneInput;
    cout << "Path to Day 1 input:" << endl;
    cin >> dayOneInput;
    cout << "Answer Day 1 Part 1: " << dayOnePartOne(dayOneInput) << endl;
    cout << "Answer Day 1 Part 2: " << dayOnePartTwo(dayOneInput) << endl;

    string dayTwoInput;
    cout << "Path to Day 2 input:" << endl;
    cin >> dayTwoInput;
    cout << "Answer Day 2 Part 1: " << dayTwo(dayTwoInput, DayPart::One) << endl;
    cout << "Answer Day 2 Part 2: " << dayTwo(dayTwoInput, DayPart::Two) << endl;
    return 0;
}