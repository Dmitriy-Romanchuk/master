// One of the weaknesses of C++ for writing business programs is that it does not contain a
// built - in type for monetary values such as $173, 698, 001.32.Such a money type should be
// able to store a number with a fixed decimal point and about 17 digits of precision, which
// is enough to handle the national debt in dollarsand cents.Fortunately, the built - in C++
// type long double has 19 digits of precision, so we can use it as the basis of a money
// class, even though it uses a floating decimal.However, we’ll need to add the capability to
// inputand output money amounts preceded by a dollar signand divided by commas into
// groups of three digits; this makes it much easier to read large numbers.As a first step
// toward developing such a class, write a function called mstold() that takes a money
// string, a string representing a money amount like
// “$1, 234, 567, 890, 123.99”
// as an argument, and returns the equivalent long double.
// You’ll need to treat the money string as an array of characters, and go through it character
// by character, copying only digits(1–9) and the decimal point into another string.Ignore
// everything else, including the dollar signand the commas.You can then use the
// _atold() library function(note the initial underscore—header file STDLIB.H or MATH.H) to
// convert the resulting pure string to a long double.Assume that money values will never
// be negative.Write a main() program to test mstold() by repeatedly obtaining a money
// string from the userand displaying the corresponding long double.

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

class money
{
private:
    std::string str{};
    long double summ = 0.0;
public:
    long double mstold();
    void display() const;
};

int main()
{
    money my_money;

    my_money.mstold();
    my_money.display();

    return EXIT_SUCCESS;
}

long double money::mstold()
{
    std::cout << "Enter summ (e.g. $1,234,567,890,123.99)" << std::endl;
    std::getline(std::cin, str);

    std::string number;

    for (int j = 0; j < str.length(); ++j)
        if(isdigit(str.at(j)) || str.at(j) == '.')
       	{
            number += str.at(j);
        }
    summ = stold(number);
    return summ;
}
void money::display()const
{
    std::cout << std::setiosflags(std::ios::fixed) << std::setiosflags(std::ios::showpoint) << std::setprecision(2) << summ << std::endl;
}