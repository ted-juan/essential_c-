#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void print_data(vector<string> &seq)
{
	for(vector<string>::iterator it = seq.begin(); it != seq.end(); it++)
		cout << *it << ' ';
	cout << endl;
}

void save_data(ofstream& outfile, vector<string> &seq)
{
	for(vector<string>::iterator it = seq.begin(); it != seq.end(); it++)
		outfile << *it << ' ';
	outfile << endl;
}

int main()
{
	vector<string> seq;
	ifstream infile("seq.txt");
	ofstream outfile("sorted_seq.txt");

	if (!infile || !outfile) {
		cout << "error: file exist" << endl;
		return 0;
	}
	else {
		string line;

		while (infile >> line)
			seq.push_back(line);
	}

	print_data(seq);
	sort(seq.begin(), seq.end());
	cout << "sort:" << endl;
	print_data(seq);
	save_data(outfile, seq);
}
