// Copyright (c) 2022 Ketia Gaelle Kaze All rights reserved.
//
// Created by: Ketia Gaelle Kaze
// Created on: Jan. 24, 2022
// This program asks the user for an operation and two numbers.
// then it calculates the answer using another function.

#include <iostream>
#include <iomanip>
#include <cmath>

// calculate the answer of two numbers
double calculate(char sign, float firstNum, float secondNum) {
    float answer;

    if (sign == '%') {
        answer = fmod(firstNum, secondNum);
    } else if (sign == '/') {
        answer = firstNum / secondNum;
    } else if (sign == '*') {
        answer = firstNum * secondNum;
    } else if (sign == '-') {
        answer = firstNum - secondNum;
    } else {
        answer = firstNum + secondNum;
    }

    return answer;
}


// checks for invalid input and calls
// function to determine result of two numbers
int main() {
    // displays opening message
    std::cout << "This program performs calculations between two numbers.";
    std::cout << std::endl;
    std::cout << std::endl;

    // declares variables
    char signUser;
    std::string firstNumString, secondNumString;
    float firstNumFloat, secondNumFloat;
    double answerUser;

    // gets operation from user
    std::cout << "Enter the operation you want to perform (+, -, *, /, %): ";
    std::cin >> signUser;

    // checks if invalid operator is entered
    if (signUser == '+' || signUser == '-' || signUser == '*' \
        || signUser == '/' || signUser == '%') {
        std::cout << "Enter the first number: ";
        std::cin >> firstNumString;

        try {
            // convert the user's input to a float
            firstNumFloat = std::stof(firstNumString);

            std::cout << "Enter the second number: ";
            std::cin >> secondNumString;

            try {
                // convert the user's input to a float
                secondNumFloat = std::stof(secondNumString);

                // assigns variable to call the function that gives return value
                answerUser = calculate(signUser, firstNumFloat, secondNumFloat);

                // displays results to user
                std::cout << std::endl;
                std::cout << "The answer of " << firstNumFloat << "";
                std::cout << signUser <<  "" << secondNumFloat;
                std::cout << " is " << answerUser;

            // determines if the input is valid
            } catch (std::invalid_argument) {
            // tells user did the input is not a number
            std::cout << secondNumString << " is not a valid input.";
            }

        // determines if the input is valid
        } catch (std::invalid_argument) {
        // tells user did the input is not a number
        std::cout << firstNumString << " is not a valid input.";
        }
    } else {
        std::cout << signUser << " is not a valid sign.";
    }
}
