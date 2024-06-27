#include "StringCalculator.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <algorithm>

int StringCalculator::add(string input) {
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

 std::vector<std::string> StringCalculator::split(const std::string& str, const std::string& delimiter) {
        std::vector<std::string> tokens;
        size_t start = 0;
        size_t end = str.find(delimiter);

        while (end != std::string::npos) {
            tokens.push_back(str.substr(start, end - start));
            start = end + delimiter.length();
            end = str.find(delimiter, start);
        }
        tokens.push_back(str.substr(start));
        return tokens;
    }

    int StringCalculator::sum(const std::vector<std::string>& numbers) {
        int total = 0;
        std::vector<int> negatives;

        for (const std::string& numStr : numbers) {
            if (!numStr.empty()) {
                int num = std::stoi(numStr);
                if (num < 0) {
                    negatives.push_back(num);
                } else if (num <= 1000) {
                    total += num;
                }
            }
        }

        if (!negatives.empty()) {
            std::stringstream ss;
            ss << "negatives not allowed: ";
            for (size_t i = 0; i < negatives.size(); ++i) {
                ss << negatives[i];
                if (i != negatives.size() - 1) {
                    ss << ", ";
                }
            }
            throw std::runtime_error(ss.str());
        }

        return total;
    }
