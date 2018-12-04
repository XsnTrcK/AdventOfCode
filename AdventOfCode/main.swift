//
//  main.swift
//  AdventOfCode
//
//  Created by Alberto Ayala on 12/1/18.
//  Copyright © 2018 XsnTrcK Studios. All rights reserved.
//

import Foundation

extension String {
    func readAllLines() -> [String] {
        return self.components(separatedBy: "\n")
    }
}

func adventPartOfDay() -> String? {
    print("Day part: ", terminator: "")
    let partOfDay = readLine()
    
    if partOfDay != "1" && partOfDay != "2" {
        print("Not a valid part of advent day")
        return nil
    }
    
    return partOfDay
}

var continueProgram = true
// Start of console application
print("Advent Day (press q/Q to quit)")

while continueProgram {
    print("advent> ", terminator: "")
    let adventDay = readLine()
    
    switch(adventDay) {
    case "1":
        if let partOfDay = adventPartOfDay() {
            if partOfDay == "1" {
                findTheFrequencyDrift()
            } else if partOfDay == "2" {
                findFirstRepeatedFrequency()
            }
        }
    case "1.1":
        findTheFrequencyDrift()
    case "1.2":
        findFirstRepeatedFrequency()
    case "2":
        if let partOfDay = adventPartOfDay() {
            if partOfDay == "1" {
                getRudimentaryCheckSum()
            } else if partOfDay == "2" {
                findCorrectProduct()
            }
        }
    case "2.1":
        getRudimentaryCheckSum()
    case "2.2":
        findCorrectProduct()
    case "q", "Q":
        continueProgram = false
    default:
        print("No challenge for that day")
        break;
    }
}
