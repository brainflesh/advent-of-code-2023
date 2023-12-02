#include <iostream>
#include <fstream>
#include <string>

// is_numeric returns true if the given char is a numeric character (0-9).
bool is_numeric(char value)
{
    return value >= 48 && value <= 57;
}

int main()
{
    std::ifstream infile("real_data.txt");
    if(!infile.is_open()) {
        std::cout << "Error opening input file.";
        return 1;
    }
    std::string line;
    std::vector<int> line_codes{}; 
    while(std::getline(infile, line)) {
        std::string::iterator left = line.begin();
        std::string::iterator right = line.end();
        while(!is_numeric(*left) && !is_numeric(*right) && left != right) {
            left++;
            right--;
        }
        while(!is_numeric(*left) && left <= line.end()) {
            left++;
        }
        while (!is_numeric(*right) && right >= line.begin()) {
            right--;
        }
        int line_code = (((*left) - '0') * 10) + ((*right) - '0');
        std::cout << line << " " << line_code << std::endl;
        line_codes.push_back(line_code);
    }
    infile.close();
    int sum_of_line_codes = 0;
    for(int code : line_codes) {
        sum_of_line_codes += code;
    }
    std::cout << "Sum of codes: " << sum_of_line_codes << std::endl;
    return 0;
}