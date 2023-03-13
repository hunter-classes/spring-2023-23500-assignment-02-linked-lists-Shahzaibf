#include <iostream>
#include "List.h"
#include "OList.h"

int main()
{
  List *l = new List();
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"a");
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"b");
  l->insert(0,"c");
  l->insert(0,"d");
  try {
    l->insert(10,"x");
  } catch (std::exception e){
    std::cout << "Insert x didn't work\n";
  }
  std::cout << l->toString() << "\n";
  l->insert(2,"inserted at 2");
  std::cout << l->toString() << "\n";
  l->insert(5,"inserted at end");
  std::cout << l->toString() << " " << l->length() << "\n";
  //PART 2 -------------------------------------------------

  OList* a = new OList();
  a->insert("5");
  a->insert("10");
  a->insert("-11");
  std::cout << a->toString() << "\n"; 
  a->reverse();
  std::cout << a->toString() << "\n";
  std::cout << a->contains("5");
  return 0;
}