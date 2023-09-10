/**
 * Class: CS19
 * Author: Salvador Cornejo
 * Purpose: This program reads various lines of standard input and records how many tokens were input.
 * It find palindrome words and records how many found. Prints out tokens input, palindrome words found,
 * and longest palindrome that was input.
 * Version: 1.0 08/31/2018
 */
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main() {
    int numToken = 0;
    int numPalindrome = 0;
    std::vector<std::string> tokenV;
    std::vector<std::string> backwardToken;
    std::vector<std::string> palindrome;
    std::cout<< "Enter tokens, when done enter ctrl-D: ";

    // this function will only grab the tokens out of sentence
    for(std::string token; std::cin >> token;) {
        numToken++;
        if(token.length() > 1) {
            std::string temp = "";
            std:: string lowToken = "";
            for(unsigned i = 0; i < token.length(); i++) {
                temp = std::tolower(token[i]);
                lowToken += temp;
            }
            tokenV.push_back(lowToken);
        }
    }
    
    // now we put tokens backwards
    for(unsigned i = 0; i < tokenV.size(); i++) {
        std::string holder = tokenV[i];
        std::string backwards = "";
        for(unsigned j = tokenV[i].size(); j > 0; j--) {
            backwards += holder[j-1];
        }
        backwardToken.push_back(backwards);
    }

    // now we compare if they are palindrome
    for(unsigned i = 0; i < tokenV.size(); i++) {
        if(tokenV[i] == backwardToken[i]) {
            palindrome.push_back(tokenV[i]);
            numPalindrome++;
        }
    }

    // Now we set the biggest palindrome at the beginning of vector palindrome
    std::string temp = "";
    for(unsigned i = palindrome.size(); i > 0; i--) {
        for(unsigned j = 1; j < i; j++) {
            if(palindrome[j].length() > palindrome[j-1].length()) {
                temp = palindrome[j];
                palindrome[j]= palindrome[j-1];
                palindrome[j-1] = temp;
            }
        }
    }
    // prints
    std::cout << std::endl;
    if(palindrome.size() > 0) {
        std::cout << std::fixed;
        std::cout << std::setprecision(1);
        std::cout << "Total number of tokens entered: " << numToken << std::endl;
        std::cout << "Total number of palindromes found: " << numPalindrome << std::endl;
        std::cout << "Longest palindrome found: " << palindrome[0] <<  std::endl;
    } else {
        std::cout << "Total number of tokens entered: " << numToken << std::endl;
        std::cout << "Total number of palindromes found: " << numPalindrome << std::endl;
    }
}
