//
//  randomNumberPulse.swift
//  AudioKit
//
//  Created by Aurelius Prochazka, revision history on Github.
//  Copyright © 2016 AudioKit. All rights reserved.
//

import Foundation

extension AKOperation {

    /// Loosely based off of the Csound opcode randomh. The design is equivalent to
    /// scaled noise sent through a classic sample and hold module.
    ///
    /// - returns: AKOperation
    /// - parameter minimum: Minimum value to use. (Default: 0)
    /// - parameter maximum: Maximum value to use. (Default: 1)
    /// - parameter updateFrequency: Frequency of randomization (in Hz) (Default: 10)
     ///
    public static func randomNumberPulse(
        minimum minimum: AKParameter = 0,
        maximum: AKParameter = 1,
        updateFrequency: AKParameter = 10
        ) -> AKOperation {
            return AKOperation("(\(minimum) \(maximum) \(updateFrequency) randh)")
    }
}
