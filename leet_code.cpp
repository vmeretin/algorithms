#include <iostream>
#include <map>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string roman;
        std::map<int, std::string> map = {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"}
        };

        for (auto entry = map.rbegin(); entry != map.rend(); ++entry) {
            const int currentInt = entry->first;
            const std::string currentRoman = entry->second;

            while (num >= currentInt) {
                num -= currentInt;
                roman += currentRoman;
            }
        }

        return roman;
    }
};
