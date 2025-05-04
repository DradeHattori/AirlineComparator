#include <iostream>
#include <string>
#include <cctype>

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


int main(int argc, const char* argv[]) {

	std::string airline_left;
	std::string airline_right;

    // 1) запуск с аргументами командной строки (comparator airline_1 airline_2) 
	if (argc == 3) {
        airline_left = argv[1];
        airline_right = argv[2];
	}
    // 2) если аргументы командной строки не заданы - программа запрашивает ввод данных в консоль
    else {
        std::cout << "Enter airline code: ";
        std::getline(std::cin, airline_left);

        std::cout << "Enter another airline code to compare: ";
        std::getline(std::cin, airline_right);
    }

    airline_left = ParseAirlineCode(airline_left);
    airline_right = ParseAirlineCode(airline_right);

    if (airline_left == airline_right) {
        std::cout << "Same airline" << std::endl;
    }
    else {
        std::cout << "Different airlines" << std::endl;
    }
}