#include "Calculator.h"

Calculator::Calculator()
{
}

double Calculator::calculate(string expression)
{
    regex expr_pow("(\\-?\\d+\\.?\\d*)(\\^)(\\-?\\d+\\.?\\d*)");
    expression = this->calc_operation(expr_pow, expression);

    regex expr_mult_devide("(\\-?\\d+\\.?\\d*)(\\*|\\/)(\\-?\\d+\\.?\\d*)");
    expression = this->calc_operation(expr_mult_devide, expression);
    
    regex expr_plus_minus("(\\-?\\d+\\.?\\d*)(\\-|\\+)(\\-?\\d+\\.?\\d*)");
    expression = this->calc_operation(expr_plus_minus, expression);

    return stod(expression);
}

string Calculator::calc_operation(regex rx, string expression)
{
    smatch found;

    while (regex_search(expression, found, rx))
    {
        double result = 0.0f;

        if (found[2] == "^")
            result = pow(stod(found[1]), stod(found[3]));
        else if (found[2] == "*")
            result = stod(found[1]) * stod(found[3]);
        else if (found[2] == "/")
            result = stod(found[1]) / stod(found[3]);
        else if (found[2] == "+")
            result = stod(found[1]) + stod(found[3]);
        else if (found[2] == "-")
            result = stod(found[1]) - stod(found[3]);
        
        regex local_exp(prepare_to_find(found[0].str()));
        expression = regex_replace(expression, local_exp, to_string(result));
    }
    return expression;
}

string Calculator::prepare_to_find(string str)
{
    regex mult("\\*");
    regex plus("\\+");
    regex devide("\\/");
    regex minus("\\-");
    regex pow("\\^");

    str = regex_replace(str, mult, "\\*");
    str = regex_replace(str, plus, "\\+");
    str = regex_replace(str, devide, "\\/");
    str = regex_replace(str, minus, "\\-");
    str = regex_replace(str, pow, "\\^");

    return str;
}
