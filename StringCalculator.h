#include<iostream>
#include<string>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <algorithm>

using namespace std;
class StringCalculator{
    public:
    int add(string numbers);
    std::string parseCustomDelimiter(const std::string& delimiterSection);
    std::vector<std::string> split(const std::string& str, const std::string& delimiter);
    int sum(const std::vector<std::string>& numbers);
    void throwNegativeException(const std::vector<int>& negatives);
};
