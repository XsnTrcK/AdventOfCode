//
//  frequencyChallenge.swift
//  AdventOfCode
//
//  Created by Alberto Ayala on 12/3/18.
//  Copyright © 2018 XsnTrcK Studios. All rights reserved.
//

import Foundation

private let pathToInputFrequencies = "Documents/Learn/iOS/AdventOfCode/AdventOfCode/DayOne/Resources/frequencyChanges.txt"

private func getFrequencyInput() -> [Int]? {
    var urlToFrequencies = FileManager.default.homeDirectoryForCurrentUser
    urlToFrequencies.appendPathComponent(pathToInputFrequencies)
    
    guard let frequencies = try? String(contentsOf: urlToFrequencies, encoding: .utf8).readAllLines() else {
        print("Failed to load file")
        return nil
    }
    
    return frequencies.compactMap { Int($0) }
}

func findTheFrequencyDrift() {
    guard let frequencies = getFrequencyInput() else {
        return
    }
    
    let totalFrequencyChange = frequencies.reduce(0, +)
    print("You're frequency change is: \(totalFrequencyChange)")
}

func findFirstRepeatedFrequency() {
    guard let frequencies = getFrequencyInput() else {
        return
    }
    var currentFrequency = 0
    var frequenciesAchieved = [currentFrequency: 1]
    var keepLookingForRepeatedFrequency = true
    while keepLookingForRepeatedFrequency {
        for frequency in frequencies {
            currentFrequency += frequency
            if frequenciesAchieved[currentFrequency] == nil {
                frequenciesAchieved[currentFrequency] = 1
            } else {
                keepLookingForRepeatedFrequency = false
                print("Firest repeated frequency is: \(currentFrequency)")
                break
            }
        }
    }
}
