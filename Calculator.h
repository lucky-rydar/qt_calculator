#pragma once
#include <regex>
#include <cmath>
#include <iostream>

using namespace std;

class Calculator
{
public:
	Calculator();
	
	double calculate(string expression);
private:
	string prepare_to_find(string str);
	string calc_operation(regex rx, string expression);
};

