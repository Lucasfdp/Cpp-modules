#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();

	void loadDatabase(const std::string& filename);
	void processInput(const std::string& filename) const;

private:
	std::map<std::string, double> _db;

	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	bool parseDate(const std::string& date, std::string& errMsg) const;
	bool parseValue(const std::string& str, double& outVal, std::string& errMsg) const;
	double getRate(const std::string& date) const;
};