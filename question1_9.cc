#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

/* Return true iff s2 is a rotatation of s1*/
bool is_rotation(const string& s1, const string& s2){
  if(s1.length()!=s2.length()){ return false;}
  return (s1 + s1).find(s2) != string::npos;
}

int main(){
  cout << std::boolalpha << is_rotation("waterbottle","terbottlewa") << endl;
}
