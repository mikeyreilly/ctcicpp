#include <iostream>
#include <string>
#include <array>
#include <algorithm> 

using std::array;
using std::cout;
using std::endl;

std::array<int,32> convert_string(std::string s){
  std::array<int,32> r {};
  auto convert_char=[](unsigned char c){return static_cast<int>(c);};
  std::transform(s.begin(),s.end(),r.begin(), convert_char);
  return r;
}

/*The exersize is about ints. The ints I'm using to test are char
codes of a piece of text.
*/

std::array<std::array<int,32>,32> int_matrix(){
  std::array<std::string,32> l{
    "No sooner had the warm liquid mi",
      "xed with the crumbs touched my p",
      "alate than a shudder ran through",
      " me and I stopped, intent upon t",
      "he extraordinary thing that was ",
      "happening to me. An exquisite pl",
      "easure had invaded my senses, so",
      "mething isolated, detached, with",
      " no suggestion of its origin. An",
      "d at once the vicissitudes of li",
      "fe had become indifferent to me,",
      " its disasters innocuous, its br",
      "evity illusory - this new sensat",
      "ion having had on me the effect ",
      "which love has of filling me wit",
      "h a precious essence; or rather ",
      "this essence was not in me it wa",
      "s me. ... Whence did it come? Wh",
      "at did it mean? How could I seiz",
      "e and apprehend it? ... And sudd",
      "enly the memory revealed itself.",
      " The taste was that of the littl",
      "e piece of madeleine which on Su",
      "nday mornings at Combray (becaus",
      "e on those mornings I did not go",
      " out before mass), when I went t",
      "o say good morning to her in her",
      " bedroom, my aunt Leonie used  t",
      "o give me, dipping it first in h",
      "er own cup of tea or tisane. The",
      " sight of the little madeleine h",
      "ad recalled nothing to my mind b"
      };
  std::array<std::array<int,32>,32> r {};
  std::transform(l.begin(),l.end(),r.begin(), convert_string);
  return r;
}


template <std::size_t N>
void print_int_matrix_as_strings(const array<array<int,N>,N>& m){
  for(auto s:m){
    for(auto c:s){
      cout << static_cast<char>(c);
    }
    cout << endl;
  }
}

template <std::size_t N>
void rotate_int_matrix(array<array<int,N>,N>& m){
  for(unsigned int y = 0; y<N/2-1; y++){
    for(unsigned int x = y; x<N-1-y; x++ ){
      int temp = m[y][x] ;
      m[y][x] = m[x][N-1-y];
      m[x][N-1-y] = m[N-1-y][N-1-x];
      m[N-1-y][N-1-x] = m[N-1-x][y];
      m[N-1-x][y] = temp;
    }
  }
}

int main (){
  std::array<std::array<int,32>,32> m = int_matrix();
  rotate_int_matrix(m);
  print_int_matrix_as_strings(m);
  cout << endl;
  rotate_int_matrix(m);
  print_int_matrix_as_strings(m);
  cout << endl;
  rotate_int_matrix(m);
  print_int_matrix_as_strings(m);
  cout << endl;
  rotate_int_matrix(m);
  print_int_matrix_as_strings(m);
  cout << endl;
}


