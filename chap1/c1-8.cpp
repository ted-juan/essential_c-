#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_data(vector<string> &seq)
{
	for(vector<string>::iterator it = seq.begin(); it != seq.end(); it++)
		cout << *it << endl ;
}

int main()
{
    vector<string> seq = {
    "Go on, make a guess.",
    "Oops! Nice but not quite it.",
    "Oh. Sorry. Wrong again.",
    "Ah, this is harder than it looks, no?",
    "It must be getting pretty frustrating by now!"
    };

	print_data(seq);
	srand(time(0));
	int num = rand() % seq.size();
	cout << "num=" << num << ": " <<  seq[num] << endl;
}
