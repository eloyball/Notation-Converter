// Group 15: Eloy Ballesteros and Akylbek Khamitov
// Programming Project 2: Notation Converter

/* This converter was implemented using a double-ended queue (also known as deque).
It able to perform six types of mathematical notation for arithmetic conversion:
Postfix to Infix, Postfix to Prefix, Infix to Postfix, Infix to Prefix, Prefix to Infix and Prefix to Postfix.
It only accepts certain characters for the notation and throws an error whenever the input is invalid.*/

#include "NotationConverter.hpp"
#include <iostream>

// Invalid character dectected exception
class InvalidChar { 
    public:
        InvalidChar(const std::string& err) : errMsg(err) { } 
        std::string getError() { return errMsg; } // access error message
    private:
        std::string errMsg; // error message
};

// Check whether char is an alphabetic letter (upper or lower case)
bool isLetter(char c){
   return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Check whether char is a parenthesis
bool isParenthesis(char c){
   return (c == '(' || c == ')');
}

// Check whether char is a valid opperator
bool isOperator(char c){
   return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Check whether character input is valid
bool isValidChar(char c){
   return isLetter(c) || isParenthesis(c) || isOperator(c);
}

// Constructor
NotationConverter::NotationConverter() {
    dq = Deque();
    dq.insertBack("");
    dq.insertBack("");
}

// Convert Postfix to Infix
std::string NotationConverter::postfixToInfix(std::string inStr) {
    int i;

    // Loop through string characters
    for (i = 0; i < inStr.size(); i++) {

        // Ignore blank spaces
        if(inStr[i] == ' ')
            continue;
        
        // Character validation
        if(!isValidChar(inStr[i]))
            throw InvalidChar("Invalid input");

        // Re-organize deque to create output string
        if(isLetter(inStr[i])) {
            std::string s;
            s += inStr[i];
            dq.insertBack(s);
        } else {
            std::string s1 = dq.back();
            dq.removeBack();

            std::string s2 = dq.back();
            dq.removeBack();

            std::string s3 = "(" + s2 + " " + inStr[i] + " " + s1 + ")";
            dq.insertBack(s3);
        }
    }

    return dq.back();
};

// Convert Postfix to Prefix
std::string NotationConverter::postfixToPrefix(std::string inStr) {
    // postfix to infix
    // infix to prefix
    return infixToPrefix(postfixToInfix(inStr));
};

// Convert Infix to Postfix
std::string NotationConverter::infixToPostfix(std::string inStr) {
    // infix to prefix
    // prefix to postfix
    return prefixToPostfix(infixToPrefix(inStr));
};

// Convert Infix to Prefix
std::string NotationConverter::infixToPrefix(std::string inStr) {
    int i;

    // Loop through string characters
    for (i = 0; i < inStr.size(); i++) {
        
        // Ignore blank spaces
        if(inStr[i] == ' ')
            continue;

        // Character validation
        if(!isValidChar(inStr[i]))
            throw InvalidChar("Invalid input");
        
        // Re-organize deque to create output string
        if(!isParenthesis(inStr[i])) {
            std::string s;
            s += inStr[i];
            dq.insertBack(s);
        }
        
        if(inStr[i] == ')') {
            std::string s1 = dq.back();
            dq.removeBack();

            std::string s2 = dq.back();
            dq.removeBack();

            std::string s3 = dq.back();
            dq.removeBack();

            std::string s4 = s2 + " " + s3 + " " + s1;
            dq.insertBack(s4);
        }
    }

    return dq.back();
};

// Convert Prefix to Infix
std::string NotationConverter::prefixToInfix(std::string inStr) {
    // prefix to postfix
    // postfix to infix
    return postfixToInfix(prefixToPostfix(inStr));
};

// Convert Prefix to Postfix
std::string NotationConverter::prefixToPostfix(std::string inStr) {
    int i;

    // Loop through string characters
    for (i = inStr.size() - 1; i >= 0; i--) {
        
        // Ignore blank spaces
        if(inStr[i] == ' ')
            continue;
        
        // Character validation
        if(!isValidChar(inStr[i]))
            throw InvalidChar("Invalid input");

        // Re-organize deque to create output string
        if(isLetter(inStr[i])) {
            std::string s;
            s += inStr[i];
            dq.insertBack(s);
        } else {
            std::string s1 = dq.back();
            dq.removeBack();

            std::string s2 = dq.back();
            dq.removeBack();

            std::string s3 = s1 + " " + s2 + " " + inStr[i];
            dq.insertBack(s3);
        }
    }

    return dq.back();
};