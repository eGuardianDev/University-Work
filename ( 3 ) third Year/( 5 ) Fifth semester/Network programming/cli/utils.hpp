#ifndef UTILS_HPP__
#define UTILS_HPP__

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

int castToNumber(std::string &inputCLI, bool &status){
    int value = 0;
    status = false;    
    try {
        size_t pos;
        value = std::stoi(inputCLI, &pos);
        if (pos != inputCLI.size()) {
            std::cerr << "Error: Extra characters after number!\n";
        }else {
            status = true;
        }

    }
    catch (const std::invalid_argument&) {
        std::cerr << "Error: Not a valid integer!\n";
    }
    catch (const std::out_of_range&) {
        std::cerr << "Error: Number out of range for int!\n";
    }
    return value;
}

std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return s;
}


std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> result;
    std::string current;

    for (char c : s) {
        if (c == delimiter) {
            result.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }
    result.push_back(current);
    return result;
}


#endif //UTILS_HPP__