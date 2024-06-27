#include<iostream>
#include<string>

using namespace std;
class StringCalculator{
    public:
    int add(string input);
    std::vector<std::string> split(const std::string& str, const std::string& delimiter);
    int sum(const std::vector<std::string>& numbers);
};
