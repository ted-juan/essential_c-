#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

inline bool is_even(int value) {
  return (!(value % 2) ? true : false);
}

void read_values(vector< int > &integer_vector) 
{
  cout << "Enter integer values: " << endl;
  istream_iterator< int > stream_start(cin);
  istream_iterator< int > end_of_stream;
  copy(stream_start, end_of_stream, back_inserter(integer_vector));
}

void write_evens_and_odds(const vector<int> &integer_vector, ofstream &odd_file, ofstream &even_file) 
{
  if (! odd_file || ! even_file) {
    cerr << "Error write_evens_and_odds(): Cannot open output files." << endl;
  }
  for (int i = 0; i < integer_vector.size(); i++) {
    if (is_even(integer_vector[i])) {
      even_file << integer_vector[i] << " ";
    } else {
      odd_file << integer_vector[i] << "\n";
    }
  }
}

template <typename type>
void display_vec(const vector<type> &vec) {
  for ( auto ix = vec.begin(); ix < vec.end(); ix++) {
    cout << *ix << endl;
  }
}

int main()
{
  vector< int > holder_vector;
  read_values(holder_vector);
  display_vec(holder_vector);
  ofstream odd_file("odd_numbers.txt");
  ofstream even_file("even_numbers.txt");
  write_evens_and_odds(holder_vector, odd_file, even_file);
  return 0;  
}
