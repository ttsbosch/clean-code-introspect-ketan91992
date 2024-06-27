#include "StringCalculator.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <algorithm>

int StringCalculator::add(string numbers) {
        if (numbers.empty()) return 0;
        
        std::string delimiter = ",";
        std::string numString = numbers;
        
        // Handle custom delimiter
        if (numbers.substr(0, 2) == "//") {
            size_t newlinePos = numbers.find("\n");
            delimiter = parseCustomDelimiter(numbers.substr(2, newlinePos - 2));
            numString = numbers.substr(newlinePos + 1);
        }
        
        // Replace newlines with delimiter
        std::replace(numString.begin(), numString.end(), '\n', delimiter[0]);
        
        // Split numbers and sum them
        return sum(split(numString, delimiter));
}

std::string StringCalculator::parseCustomDelimiter(const std::string& delimiterSection) {
        if (delimiterSection[0] == '[' && delimiterSection.back() == ']') {
                return delimiterSection.substr(1, delimiterSection.length() - 2);
        }
        return delimiterSection;
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
            int num = parseNumber(numStr);
            if (isNegative(num)) {
                negatives.push_back(num);
            } else if (isValid(num)) {
                total += num;
            }
        }
        
        if (!negatives.empty()) {
            throwNegativeException(negatives);
        }
        
        return total;
}

int StringCalculator::parseNumber(const std::string& numStr) {
        if (numStr.empty()) return 0;
        return std::stoi(numStr);
}

bool StringCalculator::isNegative(int num) {
        return num < 0;
}

bool StringCalculator::isValid(int num) {
        return num <= 1000;
}

void StringCalculator::throwNegativeException(const std::vector<int>& negatives) {
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
