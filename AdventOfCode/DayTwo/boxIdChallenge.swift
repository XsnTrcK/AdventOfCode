//
//  boxIdChallenge.swift
//  AdventOfCode
//
//  Created by Alberto Ayala on 12/3/18.
//  Copyright © 2018 XsnTrcK Studios. All rights reserved.
//

import Foundation

private let pathToBoxIdInput = "Documents/Learn/iOS/AdventOfCode/AdventOfCode/DayTwo/Resources/boxIds.txt"

private func getBoxIdInput() -> [String]? {
    var urlToBoxIds = FileManager.default.homeDirectoryForCurrentUser
    urlToBoxIds.appendPathComponent(pathToBoxIdInput)
    
    guard let boxIds = try? String(contentsOf: urlToBoxIds, encoding: .utf8).readAllLines() else {
        print("Failed to load file")
        return nil
    }
    
    return boxIds
}

func getRudimentaryCheckSum() {
    guard let boxIds = getBoxIdInput() else {
        return
    }
    
    var boxIdsWithLettersRepeatedTwice: [String]
    var boxIdsWithLettersRepeatedThreeTimes: [String]
    
    boxIdsWithLettersRepeatedTwice = boxIds.compactMap({ (boxId) -> String? in
        for letter in boxId {
            let letterCount = boxId.filter({$0 == letter}).count
            if letterCount == 2 {
                return boxId
            }
        }
        return nil
    })
    
    boxIdsWithLettersRepeatedThreeTimes = boxIds.compactMap({ (boxId) -> String? in
        for letter in boxId {
            if boxId.filter({$0 == letter}).count == 3 {
                return boxId
            }
        }
        return nil
    })
    
    let rudimentaryCheckSum = boxIdsWithLettersRepeatedTwice.count * boxIdsWithLettersRepeatedThreeTimes.count
    
    print("Rudimentary checksum: \(rudimentaryCheckSum)")
}

func findCorrectProduct() {
    guard let boxIds = getBoxIdInput() else {
        return
    }
    
    for boxId in boxIds {
        let difference = boxIds.filter({ zip(boxId, $0).filter({ $0 != $1 }).count == 1 })
        if difference.count == 1 {
            var productId = ""
            for characterLocation in 0..<boxId.count {
                let index = boxId.index(boxId.startIndex, offsetBy: characterLocation)
                if boxId[index] == difference.first![index] {
                    productId.append(boxId[index])
                }
            }
            print("Box ID: \(productId)")
            break
        }
    }
}
