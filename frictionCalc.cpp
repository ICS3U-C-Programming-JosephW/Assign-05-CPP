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
/* Include the string library to
adhere to style guidelines. */
#include <string>

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
    << "and normal force." << WHITE << "\n";

    // Construct a do..while loop.
    do {
        /* Ask the user for the friction type,
        which can be static or kinetic. */
        std::cout << LIGHT_BLUE << "\nEnter the friction "
        << "type (static or kinetic): " << WHITE;
        /* Get the whole line of the friction type input
        and store it in the friction type variable. */
        std::getline(std::cin, userFrictType);

        /* Prepare the size of the lowercase friction type to match
        the size of the user's actual friction type input. */
        lowercaseUserFrictType.resize(userFrictType.size());

        /* Transform the user's string to lowercase
        to disregard the possible letter cases. */
        std::transform(userFrictType.begin(), userFrictType.end(),
        lowercaseUserFrictType.begin(), [](char scannedChar)
        { return std::tolower(scannedChar); });

        /* Check if the user did not enter static
        or kinetic, regardless of letter case. */
        if ((lowercaseUserFrictType != "static")
        && (lowercaseUserFrictType != "kinetic")) {
            /* Notify the user that they entered an unrecognized
            friction type and that they must try again. */
            std::cout << "\n" << LIGHT_RED << userFrictType
            << " is not a " << "recognized type of friction. "
            << "Please try again." << WHITE << "\n";
        }
    /* Loop through the process while the
    user has not entered static or kinetic. */
    } while ((lowercaseUserFrictType != "static")
    && (lowercaseUserFrictType != "kinetic"));

    // Construct an infinite while loop.
    while (true) {
        // Ask the user for the friction coefficient.
        std::cout << LIGHT_PURPLE << "\nEnter the "
        << "coefficient of friction (dimensionless): "
        << WHITE;
        /* Get the whole line of the friction coefficient
        input as a string and store it in the friction
        coefficient string variable. */
        std::getline(std::cin, userFrictCoefficientStr);

        /* Try to validate and proceed with
        the friction coefficient input. */
        try {
            /* Attempt to convert the entered
            string into a float. */
            userFrictCoefficientFloat =
            std::stof(userFrictCoefficientStr);

            /* Check if the friction coefficient
            float is negative. Also, look for the
            weird -0 exception and assume it is
            negative for safety. */
            if ((userFrictCoefficientFloat < 0)
            || (userFrictCoefficientStr[0] == '-')) {
                /* Notify the user that the coefficient
                of friction cannot be negative and that
                they must try again. */
                std::cout << "\n" << LIGHT_RED
                << "Coefficient of friction cannot be "
                << "negative. Please try again."
                << WHITE << "\n";
            } else {
                /* Otherwise, the friction
                coefficient is non-negative. */
                /* Nest another infinite while
                loop for the successive input. */
                while (true) {
                    // Ask the user for the normal force.
                    std::cout << LIGHT_CYAN << "\nEnter the "
                    << "normal force (N): " << WHITE;
                    /* Get the whole line of the normal force
                    input as a string and store it in the normal
                    force string variable. */
                    std::getline(std::cin, userNormalForceStr);

                    /* Try to validate and proceed
                    with the normal force input. */
                    try {
                        /* Attempt to convert the entered
                        string into a float. */
                        userNormalForceFloat =
                        std::stof(userNormalForceStr);

                        /* Check if the normal force float is negative.
                        Look for the same -0 exception for safety. */
                        if ((userNormalForceFloat < 0)
                        || (userNormalForceStr[0] == '-')) {
                            /* Notify the user that the
                            normal force cannot be negative
                            and that they must try again. */
                            std::cout << "\n" << LIGHT_RED
                            << "Normal force cannot be "
                            << "negative. Please try again."
                            << WHITE << "\n";
                        } else {
                            /* Otherwise, the normal
                            force is non-negative. */
                            /* Break out of the inner
                            infinite while loop. */
                            break;
                        }
                    /* Runs if std::stof() cannot convert the
                    user's normal force input into a float. */
                    } catch (std::invalid_argument) {
                        /* Notify the user that they entered an
                        invalid number for the normal force. */
                        std::cout << "\n" << LIGHT_RED
                        << userNormalForceStr << " is "
                        << "not a valid number. "
                        << "Please try again." << WHITE;
                    }
                    // Break out of the outer infinite while loop.
                    break;
                }
            }
        /* Runs if std::stof() cannot convert the user's
        friction coefficient input into a float. */
        } catch (std::invalid_argument) {
            /* Notify the user that they entered an invalid
            number for the friction coefficient. */
            std::cout << "\n" << LIGHT_RED << userFrictCoefficientStr
            << " is not a valid number. Please try again." << WHITE;
        }
    }
    /* Determine the friction result by assigning it
    to the function with the validated user inputs. */
    float frictionResult = calculateFriction(
    userFrictCoefficientFloat, userNormalForceFloat);
    /* Finally, display the type of friction
    with information and the resulting value,
    rounded to two decimal places. */
    std::cout << "\n" << DARK_GRAY << "The resulting "
    << FRICTION_INFO[lowercaseUserFrictType] << " is "
    << std::setprecision(2) << std::setfill('0')
    << frictionResult << " N." << WHITE;
}
