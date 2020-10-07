#pragma once
#include "pch.h"
//header function containing any global functions required in main
//two formatting functions here
void string_layout(const std::string& title) {
    int console_half_width = 40;
    int length = title.length() / 2;
    int position = console_half_width + length;
    std::cout << std::setw(position) << std::right << title << std::endl;
}
void char_layout(const char& char_in) {
    int console_width = 80;
    for (int i = 0; i < console_width; i++) {
        std::cout << char_in;
    }
    std::cout << std::endl;
}
//three overloads of the error_handle function
void error_handle(double& value_in) {
    while (std::cin.fail() || value_in <= 0) {
        std::cout << "Error: Invalid input. Please enter a number that is greater than 0.\n\n";
        std::cout << "Please enter your value: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> value_in;
    }
}
void error_handle(int& value_in) {
    while (std::cin.fail() || value_in < 0) {
        std::cout << "Error: Invalid input. Please enter a number that is greater or equal to 0.\n\n";
        std::cout << "Please enter your value: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> value_in;
    }
}
void error_handle(int& value_in, const int& lower_limit, const int& higher_limit) {
    while (std::cin.fail() || value_in < lower_limit || value_in > higher_limit) {
        std::cout << "Error: Invalid input. Please enter a number between " << lower_limit << " and " << higher_limit << ".\n\n";
        std::cout << "Please select another option: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> value_in;
    }
}