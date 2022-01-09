#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int val, sum=0 ,avg;
	vector<int> seq;

	cout << "Please input number" << endl;
	while (cin >> val)
		seq.push_back(val);

	for(vector<int>::iterator it = seq.begin(); it != seq.end(); it++)
		sum += *it;

	avg = sum/seq.size();
	cout << "sum = " << sum << endl;
	cout << "avg = " << avg << endl;
}
