#include <iostream>

using namespace std;

int main()
{
	const float ratio = 7.481f;
	float user_input;

	cout << "Enter the number of gallons:" << endl;
	cin >> user_input;
	cout << user_input << " gallons = " << user_input / ratio << " cubic pounds";



	return 0;
}