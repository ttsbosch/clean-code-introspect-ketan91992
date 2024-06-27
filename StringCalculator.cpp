#include "StringCalculator.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <algorithm>

int StringCalculator::add(string input){
        if (input.empty()) return 0;

        std::string delimiter = ",";
        std::string numString = input;

        // Handle custom delimiter
        if (input.substr(0, 2) == "//") {
            size_t newlinePos = input.find("\n");
            delimiter = input.substr(2, newlinePos - 2);
            numString = input.substr(newlinePos + 1);
        }

        // Replace newlines with the delimiter
        std::replace(numString.begin(), numString.end(), '\n', delimiter[0]);

        // Split the numbers by the delimiter
        std::vector<std::string> tokens = split(numString, delimiter);
        return sum(tokens);
}
