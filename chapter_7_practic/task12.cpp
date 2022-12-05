//Create a class called bMoney.It should store money amounts as long doubles.Use the
//function mstold() to convert a money string entered as input into a long double, and
//the function ldtoms() to convert the long double to a money string for display. (See
//	Exercises 6 and 10.) You can call the inputand output member functions getmoney()
//	and putmoney().Write another member function that adds two bMoney amounts; you can
//	call it madd().Adding bMoney objects is easy : Just add the long double member data
//	amounts in two bMoney objects.Write a main() program that repeatedly asks the user to
//	enter two money strings, and then displays the sum as a money string.Here’s how the
//	class specifier might look :
//class bMoney
//{
//private:
//	long double money;
//public:
//	bMoney();
//	bMoney(char s[]);
//	void madd(bMoney m1, bMoney m2);
//	void getmoney();
//	void putmoney();
//};

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

class bmoney
{
private:
    long double money{};
public:
    bmoney()
    {}
    bmoney(char s[])
    {}
    void madd(bmoney m1, bmoney m2);
    void getmoney(std::string summ);
    std::string putmoney();
    std::string ldtoms();
    void mstold(std::string m);
};

int main()
{
    bmoney m1;
    bmoney m2;
    bmoney m3;

    m1.mstold(m1.putmoney());
    m2.mstold(m2.putmoney());
    m3.madd(m1, m2);
    m3.getmoney(m3.ldtoms());

    return EXIT_SUCCESS;
}

std::string bmoney::ldtoms()
{
    std::string s = std::to_string(money);
    return s;
}

void bmoney::getmoney(std::string summ)
{
    char result[32];
    char comma = ',';
    int n_summ = 0;
    int n_result = 0;

    for (int i = 0; i < summ.length(); ++i)
    {
        if (0 == n_result) // writing the $ sign to result[0]
            result[n_result++] = '$';
        else if (1 == n_result) // first digit record
            result[n_result++] = summ[n_summ++];
        else if (n_result > 1)
        {
            if (summ[n_summ] == '.') // if dot then write dot and two characters after dot
            {
                result[n_result++] = '.';
                result[n_result++] = summ[++n_summ];
                result[n_result++] = summ[++n_summ];
                result[n_result] = '\0';
                std::cout << result << std::endl;
                return;
            }

            if ((summ.length() - i) % 3 == 0)  // comma
            {
                result[n_result++] = comma;
            }
            result[n_result++] = summ[n_summ++];
        }
    }
}

void bmoney::mstold(std::string m)
{
    money = stold(m);
}

std::string bmoney::putmoney()
{
    std::string user_input;
    std::cout << "Enter summ (e.g. $1,234,567,890,123.99)" << std::endl;
    std::getline(std::cin, user_input);

    std::string number;

    for (int j = 0; j < user_input.length(); ++j)
        if (isdigit(user_input.at(j)) || user_input.at(j) == '.')
        {
            number += user_input.at(j);
        }
    return number;
}

void bmoney::madd(bmoney m1, bmoney m2)
{
    money = m1.money + m2.money;
}
