//
// Created by Daniel Shih on 12/18/17.
//

#include "BumpkinException.hpp"

BumpkinException::BumpkinException(std::string message): message{message}
{
}

std::string BumpkinException::getMessage() {
    return "BUMPKIN RUNTIME ERROR: " + message;
}