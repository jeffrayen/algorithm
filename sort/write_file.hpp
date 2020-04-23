#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::ofstream;

void write_file(const vector<int> vec, const std::string filename){
  ofstream file;
  file.open(filename.c_str(), ofstream::out);
  int size = sqrt(vec.size());
  for(int i=0; i<size; ++i){
    for(int j=0; j<size; ++j){
      file << vec.at(i*size+j) << ", ";
    } file << "\n";
  }
  file.close();
}
