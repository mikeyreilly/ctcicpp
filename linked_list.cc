#include <iostream>
#include <string>
#include <array>
using std::cout;
using std::endl;
using std::string;
using std::array;

template<typename T>
class Node{
  T* value;
  Node<T>* next;
public:
  Node(T* v, Node<T>* n): value(v), next(n){}
  ~Node(){}
  auto get_next(){
    return next;
  }
  
  auto get_value(){
    return value;
  }
};

template<typename T>
class LinkedList{
  Node<T>* head;
public:
  LinkedList() : head(NULL) {}
  ~LinkedList(){
    head = NULL;
  }

  void add(T* v){
    cout << "adding "<< *v << endl;
    Node<T>* n = new Node<T>(v, head);
    head = n;
    auto nxt = head->get_next();
    if (nxt!=NULL){
      auto val=nxt->get_value();
      cout << "next=" << *val << endl;}
    
  }

  Node<T>* get_head(){
    return head;
  }
  
};

int main(){
  LinkedList<string> n;
  array<string,5> a {"one","two","three","four", "five"};
  for(auto s:a){
    n.add(&s);
  }

  auto h = n.get_head();
  auto hp = &h;
  int i=0;
  
  while(true){
    string* v=(*hp)->get_value();
    cout << "v=" << *v << endl;
    auto nx=(*hp)->get_next();
    *hp = nx;
    if(i++==3)break;
  }
  
  


  
  return 0;
}
