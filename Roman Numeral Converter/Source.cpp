//
//  main.cpp
//  Roman Numeral Converter
//
//  Created by Alexander Gardell on 8/8/15.
//  Copyright (c) 2015 Alexander Gardell. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> breakdown;


void numToRoman(const int& num) {
	std::unordered_map<std::string, int> numeralTable;
	numeralTable = { { "I", 1 },{ "IV", 4 },{ "V", 5 },{ "IX", 9 },{ "X", 10 },
	{ "XL", 40 },{ "L", 50 },{ "LC", 90 },{ "C", 100 },{ "CD", 400 },{ "D", 500 },
	{ "DM", 900 },{ "M", 1000 } };

}

std::ostream& operator << (std::ostream& os, std::vector<std::string> vec) {
	for (auto i : vec)
		os << i;

	return os;
}

void countThousands(std::vector<std::string>& numeral, const int& count) {
	int i = 1;

	while (i <= count) {
		numeral.push_back(("M"));
		++i;
	}
}

void countHundreds(std::vector<std::string>& numeral, const int& count) {

	if (count >= 5) {
		if (count == 9)
			numeral.push_back("CM");
		else
			for (int x = 5; x <= count; ++x) {
				if (x == 5)
					numeral.push_back("D");
				else
					numeral.push_back("C");
			}
	}
	else {
		if (count == 4)
			numeral.push_back("CD");
		else {
			for (int x = 1; x <= count; ++x) {
				numeral.push_back("C");
			}
		}
	}
}

void countTens(std::vector<std::string>& numeral, const int& count) {

	if (count >= 5) {
		if (count == 9)
			numeral.push_back("XC");
		else
			for (int x = 5; x <= count; ++x) {
				if (x == 5)
					numeral.push_back("L");
				else
					numeral.push_back("X");
			}
	}
	else {
		if (count == 4)
			numeral.push_back("XL");
		else {
			for (int x = 1; x <= count; ++x) {
				numeral.push_back("X");
			}
		}
	}
}

void countOnes(std::vector<std::string>& numeral, const int& count) {

	if (count >= 5) {
		if (count == 9)
			numeral.push_back("IX");
		else
			for (int x = 5; x <= count; ++x) {
				if (x == 5)
					numeral.push_back("V");
				else
					numeral.push_back("I");
			}
	}
	else {
		if (count == 4)
			numeral.push_back("IV");
		else {
			for (int x = 1; x <= count; ++x) {
				numeral.push_back("I");
			}
		}
	}
}

std::vector<std::string> convert() {
	std::unordered_map<std::string, int>::iterator find;
	std::vector<std::string> numeral;

	find = breakdown.find("Thousands");
	int count = find->second;

	if (count > 0)
		countThousands(numeral, count);

	find = breakdown.find("Hundreds");
	count = find->second;

	if (count > 0)
		countHundreds(numeral, count);

	find = breakdown.find("Tens");
	count = find->second;

	if (count > 0)
		countTens(numeral, count);

	find = breakdown.find("Ones");
	count = find->second;

	if (count > 0)
		countOnes(numeral, count);

	return numeral;

}

std::vector<std::string> convertToRoman(int num) {

	breakdown.insert(std::pair<std::string, int>("Thousands", (num / 1000)));
	num -= ((num / 1000) * 1000);

	breakdown.insert(std::pair<std::string, int>("Hundreds", (num / 100)));
	num -= ((num / 100) * 100);

	breakdown.insert(std::pair<std::string, int>("Tens", (num / 10)));
	num -= ((num / 10) * 10);

	breakdown.insert(std::pair<std::string, int>("Ones", num));

	return convert();
}

int main() {
	int answer = 0;

	std::cout << "Type in a integer up to 4999 to be converted: ";
	std::cin >> answer;

	while (answer < 1) {
		std::cout << "Please enter a compatible number: ";
		std::cin >> answer;
	}

	std::cout << convertToRoman(answer);

	return 0;
}
