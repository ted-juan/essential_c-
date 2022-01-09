#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void print_vec(vector<int> &seq, string msg)
{
	cout << "vector type is " << msg << endl;

	for(auto it = seq.begin(); it != seq.end(); it++)
		cout << *it << ' ';
	cout << endl;
}

#define MAX_SIZE 1024

bool pentagonal(int pos, vector<int> &seq)
{
	if ((pos <= 0) || (pos > MAX_SIZE)) {
		cout << "error ! invalid pos" << endl;
		return false;
	}

	for (int i=1; i<=pos; i++)
		seq.push_back(i*(3*i-1)/2);

	return true;
}

int main()
{
	vector<int> seq;
	int pos;

	cout << "Please enter a position" << endl;
	cin >> pos;

	if (pentagonal(pos, seq) == true)
		print_vec(seq, "int");
	else
	    cout << "error, cannot calculate the data" << endl;
}
