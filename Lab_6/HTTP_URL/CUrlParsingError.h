#pragma once
#include <stdexcept>
#include <string>

class CUrlParsingError :
    public std::invalid_argument
{
public:
    using _Mybase = invalid_argument;

    explicit CUrlParsingError(const std::string& _Message) : _Mybase(_Message.c_str()) {}

    explicit CUrlParsingError(const char* _Message) : _Mybase(_Message) {}
};

