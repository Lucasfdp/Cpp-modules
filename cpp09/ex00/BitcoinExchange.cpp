#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// ─── Helpers ─────────────────────────────────────────────────────────────────

static double toDouble(const std::string& str)
{
	std::istringstream ss(str);
	double val;
	ss >> val;
	return val;
}

static int toInt(const std::string& str)
{
	std::istringstream ss(str);
	int val;
	ss >> val;
	return val;
}

// ─── Orthodox Canonical Form ─────────────────────────────────────────────────

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

// ─── Database Loading ────────────────────────────────────────────────────────

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date = line.substr(0, comma);
		std::string valueStr = line.substr(comma + 1);

		double value = toDouble(valueStr);
		_db[date] = value;
	}
}

// ─── Input Processing ────────────────────────────────────────────────────────

void BitcoinExchange::processInput(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipe);
		std::string valueStr = line.substr(pipe + 1);

		// trim trailing whitespace from date
		while (!date.empty() && date[date.size() - 1] == ' ')
			date.erase(date.size() - 1);
		// trim leading whitespace from value
		while (!valueStr.empty() && valueStr[0] == ' ')
			valueStr.erase(0, 1);

		std::string errMsg;
		double value;

		if (!parseDate(date, errMsg))
		{
			std::cerr << "Error: " << errMsg << std::endl;
			continue;
		}
		if (!parseValue(valueStr, value, errMsg))
		{
			std::cerr << "Error: " << errMsg << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << value * getRate(date) << std::endl;
	}
}

// ─── Rate Lookup ─────────────────────────────────────────────────────────────

double BitcoinExchange::getRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

	// exact match
	if (it != _db.end() && it->first == date)
		return it->second;

	// date is before entire database
	if (it == _db.begin())
		return 0.0;

	// step back to closest lower date
	--it;
	return it->second;
}

// ─── Parsing ─────────────────────────────────────────────────────────────────

bool BitcoinExchange::parseDate(const std::string& date, std::string& errMsg) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		errMsg = "bad input => " + date;
		return false;
	}

	for (std::size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
		{
			errMsg = "bad input => " + date;
			return false;
		}
	}

	int month = toInt(date.substr(5, 2));
	int day   = toInt(date.substr(8, 2));

	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		errMsg = "bad input => " + date;
		return false;
	}

	return true;
}

bool BitcoinExchange::parseValue(const std::string& str, double& outVal, std::string& errMsg) const
{
	if (str.empty())
	{
		errMsg = "bad input => empty value.";
		return false;
	}

	std::size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	bool hasDot = false;
	for (std::size_t i = start; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDot) { errMsg = "bad input => " + str; return false; }
			hasDot = true;
		}
		else if (!std::isdigit(str[i]))
		{
			errMsg = "bad input => " + str;
			return false;
		}
	}

	outVal = toDouble(str);

	if (outVal < 0)
	{
		errMsg = "not a positive number.";
		return false;
	}
	if (outVal > 1000)
	{
		errMsg = "too large a number.";
		return false;
	}

	return true;
}