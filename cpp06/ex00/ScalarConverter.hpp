#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdexcept>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:
        static void convert(const std::string& s);
};