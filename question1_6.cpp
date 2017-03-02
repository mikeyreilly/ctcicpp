#include <iostream>
#include <sstream>
#include <string>
#include <array>


std::string compress(const std::string &s){
  int len=s.length();
  if(len==0){
    return s;
  }
  char curr = s[0];
  char prev = curr;
  
  std::ostringstream os;
  int count = 1;
  for (int i=1;i<len;i++){
    curr = s[i];
    if(curr!=prev){
      os << prev << count;
      if(os.tellp()>len){
	return s;
      }
      count = 0;
    }
    count++;
    prev = curr;
  }
  os << curr << count;
  if(os.tellp()>len){
	return s;
  }
  return os.str();
}


int main (int argc, char *argv[]){
  std::string a;
  
  
  if (argc > 1) {
    a = argv[1];
    
  } else {
    std::cerr << "missing arg" << std::endl;
    return -1;
  }
  
  std::cout << compress(a) << std::endl;
  return 0;
}


