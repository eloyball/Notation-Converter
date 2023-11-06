#ifndef __NOTATION_CONVERTER_
#define __NOTATION_CONVERTER_

#include "NotationConverterInterface.hpp"
#include "Deque.hpp"
#include <iostream>
#include <string>

class NotationConverter : public NotationConverterInterface {
    public:
        NotationConverter();        
        std::string postfixToInfix(std::string inStr);
        std::string postfixToPrefix(std::string inStr);

        std::string infixToPostfix(std::string inStr);
        std::string infixToPrefix(std::string inStr);

        std::string prefixToInfix(std::string inStr);
        std::string prefixToPostfix(std::string inStr);
    private:
        Deque dq;
};

#endif