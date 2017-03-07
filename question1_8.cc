#include <iostream>
#include <array>
#include <vector>
#include <bitset>
using std::cout;
using std::endl;
using std::array;
using std::bitset;

template<size_t M, size_t N>
void zero_matrix(array<array<int,M>,N>& m){
  bitset<M> cols {};
  bitset<N> rows {};
  for(unsigned int r=0;r<N;r++){
    for(unsigned int c=0;c<M;c++){
      if(m[r][c]==0){
	cols.set(c);
	rows.set(r);
      }
    }
  }
  for(unsigned int r=0;r<N;r++){
    for(unsigned int c=0;c<M;c++){
      if(rows.test(r) || cols.test(c)){
	m[r][c]=0;
      }
    }
  }
}

int main(){
  array<array<int,5>,6> data {{{1,2,3,4,5},
	{1,2,3,4,5},
	  {1,2,3,4,5},
	    {1,2,3,0,5},
	      {1,2,3,4,5},
		{1,2,3,4,5}}};
  zero_matrix(data);
  
  for(auto row:data){
    for(auto n:row){
      cout << n << ' ';
    }
    cout << endl;
  }
  
}
