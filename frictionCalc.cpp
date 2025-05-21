// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: May 20, 2025
/* This program calculates the static or
kinetic friction given the friction type,
coefficient of friction, and normal force. */

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

}
