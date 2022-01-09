#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 1024

inline bool is_size_ok(int pos)
{
	if ((pos <= 0) || (pos > MAX_SIZE)) {
		cout << "error ! invalid pos" << endl;
		return false;
	}
	return true;
}
void print_vec(vector<int> &seq, string msg)
{
	cout << "vector type is " << msg << endl;

	for(auto it = seq.begin(); it != seq.end(); it++)
		cout << *it << ' ';
	cout << endl;
}


bool pentagonal(int pos, vector<int> &seq, int &elem)
{
	if (pos > seq.size()) {
		for (int i=seq.size()+1; i<=pos; i++)
			seq.push_back(i*(3*i-1)/2);
	}
	elem = seq[pos-1];
	return true;
}


int main()
{
	static vector<int> seq;
	int pos, elem;

	cout << "Please enter a position" << endl;
	cin >> pos;

	if (is_size_ok(pos)) {
		if (pentagonal(pos, seq, elem) == true) {
				print_vec(seq, "int");
				cout << "elem = " << elem << endl;
		}
		else
			cout << "error, cannot calculate the data" << endl;
	}
}
