#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

inline bool less_than(string string_1, string string_2) {
  return (string_1.size() < string_2.size() ? true : false);
}

vector<string> 
create_sorted_vector(ifstream &input_file) {

  vector<string> vec;
  if (! input_file) {
    cerr << "Cannot access input file.";
  }
  
  string entry;
  while (input_file >> entry) {
    vec.push_back(entry);
  }

  sort(vec.begin(), vec.end(), less_than);
  return vec;
}

template <typename type>
void display_vec(const vector<type> &vec) {
  for ( auto ix = vec.begin(); ix < vec.end(); ix++) {
    cout << *ix << endl;
  }
}


int main()
{
  ifstream input_file("word_list.txt");
  vector<string> vec = create_sorted_vector(input_file);

  display_vec(vec);
  return 0;
}
