// Refer back to the discussion of money strings in Exercise 6. Write a function called
// ldtoms() to convert a number represented as type long double to the same value
// represented as a money string.First you should check that the value of the original long
// double is not too large.We suggest that you don’t try to convert any number greater than
// 9, 999, 999, 999, 999, 990.00.Then convert the long double to a pure string(no dollar sign
// or commas) stored in memory, using an ostrstream object, as discussed earlier in this
// chapter.The resulting formatted string can go in a buffer called ustring.
// You’ll then need to start another string with a dollar sign; copy one digit from ustring at
// a time, starting from the left, and inserting a comma into the new string every three digits.
// Also, you’ll need to suppress leading zeros.You want to display $3, 124.95, for example,
// not $0, 000, 000, 000, 003, 124.95.Don’t forget to terminate the string with a ‘\0’ character.
// Write a main() program to exercise this function by having the user repeatedly input
// numbers in type long double format, and printing out the result as a money string.

#include <iostream>
#include <string>
#include <sstream>

class money
{
private:
    long double summ = 0.0;
public:
    std::string ldtoms();
    void display(std::string);
    void set_sum();
};

int main()
{
    money my_money;
    my_money.set_sum();
    std::string money_str = my_money.ldtoms();
    my_money.display(money_str);

    return EXIT_SUCCESS;
}

std::string money::ldtoms()
{
    std::string s = std::to_string(summ);
    return s;
}

void money::display(std::string summ)
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

void money::set_sum()
{
    const long double MAX = 9999999999999990.00;
    bool repeat = true;
    while (repeat)
    {
        std::cout << "Enter number: ";
        std::cin >> summ;
        if (summ < MAX)
        {
            repeat = false;
            return;
        }
        else
            std::cout << "Enter a lower value!" << std::endl;
    }
}