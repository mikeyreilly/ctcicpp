#include <iostream>
#include <string>
#include <array>

//using namespace std;

/* A string is one edit away from another string if one can be
   transformed into the other by adding, removing or replacing one
   char, or by doing nothing.

   The algorithm presented here counts all the chars starting at the
   first and going forward until two corresponding chars are not alike.

   If all chars are alike then return true.

   Then count all the chars that going backwards until two are not equal.

   If the difference between (forward + backward) and strlen1 is < 2 then
*/
// template <typename T>
// T min(T a, T b){
//   return a<b?a:b;
// }

// template <typename T>
// T abs(T a){
//   return a<0?-a:a;
// }

bool is_one_away(const std::string &a, const std::string &b){
  size_t len_a=a.length();
  size_t len_b=b.length();
  if (abs(len_a - len_b)>1){
    return false;
  }
  size_t limit = std::min(len_a,len_b);
  size_t forward = 0;
  while (forward < limit && a[forward]==b[forward]){
    forward++;
  }
  if (abs(forward-len_a)<2){
    return true;
  }
  size_t back=0;
  while (back < limit && a[len_a-back-1]==b[len_b-back-1]){
    back++;
  }
  return abs(static_cast<long>(forward + back) - static_cast<long>(len_a)) < 2;
}


int main (int argc, char *argv[]){
  std::string a;
  std::string b;
  
  if (argc > 2) {
    a = argv[1];
    b = argv[2];
  } else {
    std::cerr << "missing arg" << std::endl;
    return -1;
  }
  
  std::cout << std::boolalpha << " is one away? " << is_one_away(a, b) << std::endl;
  return 0;
}

int _main(){
  size_t forward = 4;
  size_t back=0;
  size_t len_a=5;
  std::cout << "?= " << abs(static_cast<long>(forward + back)
			    - static_cast<long>(len_a)) << std::endl;
  
  return 0;
}
