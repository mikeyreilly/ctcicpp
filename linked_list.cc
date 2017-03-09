#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template<typename T>
class  Node {
  const T value;
  const Node<T> *next;
  public:
  Node(T v, Node<T>* n) : value(v), next(n){};
  const T getValue(){return value;}
  Node<T>* getNext(){return next;}
};

template<typename T>
class LinkedList{
  Node<T> *head; 
public:
  LinkedList(){
    head = NULL; 
  }

  void addValue(T val){
    head = new Node<T>(val, head);           
  }

  T popValue(){
    Node<T> *n = head;
    T ret = n->value;

    head = head->next;
    delete n;
    return ret;
  }

  Node<T>* getHead(){
    return head;
  }
};

int main() {
  LinkedList<string> list;

  list.addValue("red");
  list.addValue("green");
  list.addValue("blue");
  
  for(Node<string>* c=list.getHead();c!=NULL;c=c->getNext()){
    cout << c->getValue() << endl;
    
  }
  return 0;
}
