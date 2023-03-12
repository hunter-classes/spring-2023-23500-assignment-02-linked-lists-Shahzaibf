#include <iostream>
#include "OList.h"

OList::OList(){
    head = nullptr;
}

OList::~OList(){
    Node* walker = head;
    Node* trailer = nullptr;
    while(walker != nullptr){
        trailer = walker;
        walker = walker->getNext();
        delete trailer;
    }
}

