#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream> //std::istringstream
#include <cctype> // std::toupper, std::tolower

/**
 * @var std::unordered_map<char, std::string> englishToMorse
 * @brief A map that stores English letters and digits and maps them to Morse Code
 */
std::unordered_map<char, std::string> englishToMorse = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."},
    {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."},
    {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"},
    {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, 
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, 
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."},
    {'\'', ".----."}, {'!', "-.-.--"}, {'/', "-..-."}, {'(', "-.--."}, {')', "-.--.-"}, {'&', ".-..."},
    {':', "---..."}, {';', "-.-.-."}, {'=', "-...-"}, {'+', ".-.-."}, {'-', "-....-"}, {'_', "..--.-"},
    {'\"', ".-..-."}, {'$', "...-..-"}, {'@', ".--.-."}, {'*', "-..-"}, {' ', "/"}
};

/**
 * @var std::unordered_map<std::string, char> morseToEnglish
 * @brief A map that stores Morse Code and maps it to English letters and digits
 * 
 * @note Flipped version of `englishToMorse`
 */
std::unordered_map<std::string, char> morseToEnglish;

/**
 * @brief Takes an input of English and translates it to Morse Code
 * 
 * @param input A string of English characters
 * @returns A string of Morse Code letters
 * 
 * @warning Does not have error handling, MUST input valid characters
 */
std::string toMorse(std::string input) {
    std::string output;
    for (char c : input) {
        c = toupper(c);
        if (englishToMorse.find(c) != englishToMorse.end()) {
            output += englishToMorse[c];
        }
        output += ' ';
    }
    return output;
}

/**
 * @brief Takes and input of Morse Code and translates it to English
 * 
 * @param input A string of Morse Code letters
 * @returns A string of English characters
 * 
 * @warning Does not have error handling, MUST input valid characters
 */
std::string toEnglish(std::string input) {
    std::istringstream iss(input);
    std::string s, output;
    while (iss >> s) {
        if (morseToEnglish.find(s) != morseToEnglish.end()) {
            output += morseToEnglish[s];
        }
    }
    return output;
}

int main(int argv, char* argc[]) {
    // Initialize englishToMorse by flipping morseToEnglish
    for (const auto& pair : englishToMorse) {
        morseToEnglish[pair.second] = pair.first;
    }

    std::cout << "Enter a string: ";
    std::string input;
    std::getline(std::cin, input);

    // Determine which function to use based on the first character
    if (input[0] == '.' || input[0] == '-') {
        input = toEnglish(input);
    } else {
        input = toMorse(input);
    }

    std::cout << input << std::endl;

    return 0;
}