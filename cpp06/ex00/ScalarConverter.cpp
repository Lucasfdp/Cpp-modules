#include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter()
// {

// }

// ScalarConverter::ScalarConverter(const ScalarConverter& other)
// {
// 	(void)other;
// }

// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
// {
// 	(void)other;
// 	return (*this);
// }

// ScalarConverter::~ScalarConverter()
// {

// }

bool isPseudoLiteral(const std::string& s)
{
    return (s == "-inff" || s == "+inff" || s == "nanf" ||
            s == "-inf"  || s == "+inf"  || s == "nan");
}
 
// ─── Pseudo-literal handler ──────────────────────────────────────────────────
 
void handlePseudo(const std::string& s)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible"  << std::endl;
 
    if (s == "-inff" || s == "-inf")
    {
        std::cout << "float: -inff"  << std::endl;
        std::cout << "double: -inf"  << std::endl;
    }
    else if (s == "+inff" || s == "+inf")
    {
        std::cout << "float: +inff"  << std::endl;
        std::cout << "double: +inf"  << std::endl;
    }
    else // nanf or nan
    {
        std::cout << "float: nanf"   << std::endl;
        std::cout << "double: nan"   << std::endl;
    }
}
 
// ─── Type detection ───────────────────────────────────────────────────────────
 
/*  Rules (applied in this order so there is no ambiguity):
 *   CHAR   – exactly "'x'" where x is a single printable character
 *   INT    – optional leading sign, then digits only, no dot, no 'f'/'F'
 *   FLOAT  – has a dot OR an 'f'/'F' suffix (or both); ends in 'f'/'F'
 *   DOUBLE – has a dot, no 'f'/'F' suffix
 *   INVALID – everything else
 */
Type detectType(const std::string& s)
{
    if (s.empty())
        return INVALID;
 
    // CHAR: 'x'
    if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
        return CHAR;
 
    // Check if the string is a valid integer
    {
        size_t i = 0;
        if (s[i] == '-' || s[i] == '+') ++i;
        bool hasDigit = false;
        bool hasDot   = false;
        bool hasF     = false;
        for (; i < s.size(); ++i)
        {
            if (std::isdigit(s[i]))      { hasDigit = true; }
            else if (s[i] == '.')
            {
                if (hasDot) return INVALID;  // reject 1.2.3
                hasDot = true;
            }
            else if (s[i] == 'f' || s[i] == 'F')
            {
                // 'f' must be the last character
                if (i != s.size() - 1)   return INVALID;
                hasF = true;
            }
            else return INVALID;          // unexpected character
        }
        if (!hasDigit) return INVALID;
        if (hasF)      return FLOAT;
        if (hasDot)    return DOUBLE;
        return INT;
    }
}
 
// ─── String → double ─────────────────────────────────────────────────────────
 
double parseToDouble(const std::string& s, Type type)
{
    try
    {
        if (type == CHAR)
            return static_cast<double>(s[1]);   // middle character of 'x'
 
        if (type == INT)
            return static_cast<double>(std::stoi(s));
 
        if (type == FLOAT)
        {
            // Parse as double to preserve full range, then range-check in printAll
            std::string tmp = s.substr(0, s.size() - 1);
            return std::stod(tmp);
        }
 
        // DOUBLE
        return std::stod(s);
    }
    catch (const std::out_of_range&)
    {
        throw;   // let convert() catch and print "impossible"
    }
    catch (const std::invalid_argument&)
    {
        throw;
    }
}
 
// ─── Print all four conversions ───────────────────────────────────────────────
 
void printAll(double value)
{
    // --- char ---
    if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
 
    // --- int ---
    if (std::isnan(value) || std::isinf(value)
        || value > static_cast<double>(std::numeric_limits<int>::max())
        || value < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
 
    // --- float ---
    float fval = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1);
    if (std::isinf(value) || std::isinf(fval))
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
    else if (std::isnan(fval))
        std::cout << "float: nanf" << std::endl;
    else
        std::cout << "float: " << fval << "f" << std::endl;
 
    // --- double ---
    if (std::isinf(value))
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    else if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}
 
// ─── Public entry point ───────────────────────────────────────────────────────
 
void ScalarConverter::convert(const std::string& s)
{
    if (isPseudoLiteral(s))
    {
        handlePseudo(s);
        return;
    }
 
    Type type = detectType(s);
    if (type == INVALID)
    {
        std::cout << "char: impossible"   << std::endl;
        std::cout << "int: impossible"    << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
 
    double value;
    try
    {
        value = parseToDouble(s, type);
    }
    catch (...)
    {
        std::cout << "char: impossible"   << std::endl;
        std::cout << "int: impossible"    << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
 
    printAll(value);
}
 