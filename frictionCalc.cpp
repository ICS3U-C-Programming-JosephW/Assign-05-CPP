// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: May 20, 2025
/* This program calculates the static or
kinetic friction given the friction type,
coefficient of friction, and normal force. */

/* Include the algorithm library for
algorithmic functions. */
#include <algorithm>
/* Include the iostream library for
input and output functionalities. */
#include <iostream>
/* Include the iomanip library for
rounding numbers. */
#include <iomanip>
/* Include the map library for
associative arrays. */
#include <map>

/* Define a function to calculate
the resulting frictional force. */
float calculateFriction(float frictionCoefficient, float normalForce) {
    /* Simply return the product of the friction
    coefficient and the normal force. */
    return frictionCoefficient * normalForce;
}

// Runs the main function.
int main() {
    /* Create a constant map (associative array) for
    information based on the chosen friction type. */
    std::map<std::string, std::string> FRICTION_INFO = {
        {"static", "static friction (stiction)"},
        {"kinetic", "kinetic friction (dynamic friction)"},
    };

    // For text escape codes.
    const std::string LIGHT_RED = "\033[1;31m",
    LIGHT_GREEN = "\033[1;32m",
    LIGHT_BLUE = "\033[1;34m",
    LIGHT_PURPLE = "\033[1;35m",
    LIGHT_CYAN = "\033[1;36m",
    DARK_GRAY = "\033[1;30m",
    WHITE = "\033[0m";

    /* Declare the string variables for the user friction
    type and its corresponding lowercase type. */
    std::string userFrictType, lowercaseUserFrictType;

    /* Declare the string version of the
    user's friction coefficient input. */
    std::string userFrictCoefficientStr;
    /* Declare the float version of the
    user's friction coefficient input. */
    float userFrictCoefficientFloat;

    /* Declare the string version of
    the user's normal force input. */
    std::string userNormalForceStr;
    /* Declare the float version of
    the user's normal force input. */
    float userNormalForceFloat;

    // Display the greeting message to the user.
    std::cout << "\n" << LIGHT_GREEN << "Hello, user! This "
    << "program will calculate the frictional force based on\n"
    << "the entered static or kinetic coefficient of friction "
    << "and normal force." << WHITE << "\n\n";

    // Construct a do..while loop.
    do {
        /* Ask the user for the friction type,
        which can be static or kinetic. */
        std::cout << LIGHT_BLUE << "Enter the friction "
        << "type (static or kinetic): " << WHITE;
        /* Get the whole line of the user input and
        store it in the friction type variable. */
        std::getline(std::cin, userFrictType);

        /* Prepare the size of the lowercase string to
        match the size of the user's actual string input. */
        lowercaseUserFrictType.resize(userFrictType.size());

        /* Transform the user's string to lowercase
        to disregard the possible letter cases. */
        std::transform(userFrictType.begin(), userFrictType.end(),
        lowercaseUserFrictType.begin(), [](char scannedChar)
        { return std::tolower(scannedChar); });

        /* Check if the user entered static or
        kinetic, regardless of letter case. */
        if ((userFrictType != "static") && (userFrictType != "kinetic")) {
            /* Otherwise, notify the user that they entered an unrecognized
            friction type and that they must try again. */
            std::cout << "\n" << LIGHT_RED << userFrictType << " is not a "
            << "recognized type of friction. Please try again." << WHITE << "\n";
        }
    } while ((userFrictType != "static") && (userFrictType != "kinetic"));
}
