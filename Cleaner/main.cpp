#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>
#include <thread>


std::string ParseAirlineCode (const std::string& airline) {
    std::string result;
    for (char ch : airline) {
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= '1' && ch <= '9')) {
            result += ch;
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = toupper(ch); // приведение кодов авиалиний к общему upercase формату
            result += ch;
        }
    }
    return result;
}

void ProcessFile(const std::string& input_path, const std::string& output_path) {
    std::ifstream input(input_path);
    std::ofstream output(output_path);

    if (!input) {
        std::cerr << "Failed to open input file: " << input_path << std::endl;
        return;
    }

    if (!output) {
        std::cerr << "Failed to open output file: " << output_path << std::endl;
        return;
    }

    std::set<std::string> airline_codes;
    std::string code;

    while (std::getline(input, code)) {
        std::string parsed = ParseAirlineCode(code);
        if (!parsed.empty()) {
            airline_codes.insert(parsed);
        }
    }

    for (const auto& airline : airline_codes) {
        output << airline << '\n';
    }
}

int main() {
    std::thread t1(ProcessFile, "../resourcefiles/1_in.txt", "../resourcefiles/1_out.txt");
    std::thread t2(ProcessFile, "../resourcefiles/2_in.txt", "../resourcefiles/2_out.txt");

    t1.join();
    t2.join();

    return 0;
}