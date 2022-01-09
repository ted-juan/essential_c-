#include <string>
#include <iostream>

using namespace std;

int main()
{
	string first_name, last_name;
	cin >> first_name >> last_name;
	if (first_name.size() <= 2 || last_name.size() <= 2)
		cout << "error: size is too short" << endl;
	else
		cout << first_name << " " << last_name << endl;
}
