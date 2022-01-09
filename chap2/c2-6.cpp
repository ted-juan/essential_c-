#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 1024

template <typename Type>
inline Type my_max(Type t1, Type t2)
{
	return (t1 > t2) ? t1 : t2;
}

template <typename Type>
inline Type my_max(const vector<Type> &vec)
{
	return *max_element(vec.begin(), vec.end());
}

template <typename Type>
inline Type my_max(const Type *array, int size)
{
	return *max_element(array, array+size);
}

void print_vec(vector<int> &seq, string msg)
{
	cout << "vector type is " << msg << endl;

	for(auto it = seq.begin(); it != seq.end(); it++)
		cout << *it << ' ';
	cout << endl;
}


int main()
{
	int intArray[] = { 5, 10, 15, 20, 25 };
	vector<int> intVec(intArray, intArray + 5);
	double douArray[] = { 5.1, 5.5, 10.3, 15.6, 20.8 };
	vector<double> douVec(douArray, douArray + 5);
	string strArray[] = { 
		"we", 
		"were", 
		"going", 
		"to", 
		"school"
	};

	vector<string> strVec(strArray, strArray + 5);
	int intMax = my_max(my_max(intVec), my_max(intArray, 5));
	double douMax = my_max(my_max(douVec), my_max(douArray, 5));
	string strMax = my_max(my_max(strVec), my_max(strArray, 5));
	cout << "The max of integers is " << intMax << endl;
	cout << "The max of doubles is " << douMax << endl;
	cout << "The max of strings is " << strMax << endl;
	return 0;
}
