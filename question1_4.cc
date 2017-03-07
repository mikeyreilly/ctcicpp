#include <iostream>
#include <string>
#include <array>

using namespace std;

/* If I have an even number of every letter then I have a
   palindrome. I'm assuming 8-bit chars. Empty string is considered a
   palindrome.*/



array<int,256> character_frequency(const string &text){
  array<int,256> r {0};
  for(char c : text) {
    r[c]++;
  }
  return r;
}

bool is_palindrome_anagram(const string &text){
  array<int, 256> freq = character_frequency(text);
  for(int i : freq){
    if(i & 1){
      return false;
    }
  }
  return true;
}

int main (int argc, char *argv[]){
  std::string text;
  if (argc > 1) {
    text = argv[1];
  } else {
    cerr << "missing arg" << endl;
    return -1;
  }
  
  cout << std::boolalpha << text << " is palindrome anagram? " << is_palindrome_anagram(text) << endl;
  return 0;
}
