#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename key, typename value>
void display_vmap(const map<key, value> &key_value_map) {
  typename map<key, value>::const_iterator map_begin = key_value_map.begin();
  typename map<key, value>::const_iterator map_end = key_value_map.end();
  for ( ; map_begin != map_end; ++map_begin) {
    cout << "family name: " << map_begin -> first << endl;
    cout << map_begin -> second.size() << " children: " << endl;
    vector<string>::const_iterator vector_begin = map_begin -> second.begin();
    vector<string>::const_iterator vector_end = map_begin -> second.end();
    for ( ; vector_begin != vector_end; ++vector_begin) {
        cout << (*vector_begin) << ", ";
    }
    cout << endl;
  }
}

template<typename key, typename value>
void queery_map(const map<key, value> &key_value_map, const key &queery) {
  typename map<key, value>::const_iterator map_end = key_value_map.end();
  typename map<key, value>::const_iterator queery_position;

  queery_position = key_value_map.find(queery);
  if (queery_position != map_end) {
    cout << "Found " << queery_position -> first << "!" << endl;
    cout << "Occurs " << queery_position -> second << " times." << endl;
  } else {
    cout << queery << " was not found." << endl;
  }
}

typedef vector<string> vstring;
map<string, vstring> create_family_map(ifstream &input_file) 
{

  if (! input_file) {
    cerr << "Cannot access input file.";
  }

  map<string, vstring> name_map;
  string family_name, line, word;
  vector<string> children;
  stringstream ss;

  while(getline(input_file, line, '\n'))
  {
      if (line.size()==0)
        break;

      ss.str(line);
      ss >> family_name;
      while(ss >> word) {
          children.push_back(word);
      }
      if (! name_map.count(family_name)) {
        name_map[family_name] = children;
      } 
      else {
        cerr << "Error fill_name_map(): \"" << family_name << "\" already present in map.\n";
      }
      line.clear();
      ss.clear();
      children.clear();
  }
  return name_map;
}


int main()
{
  //ToDo: pass extra exclusion set as parameter.
  ifstream input_file("family.txt");
  map<string, vstring> family_name = create_family_map(input_file);

//  queery_map(occurrence_count, string("text"));
  display_vmap(family_name);
  return 0;
}
