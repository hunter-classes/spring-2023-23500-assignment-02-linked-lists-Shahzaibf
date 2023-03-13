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

void OList::insert(std::string value){
    Node * walker;
    Node * trailer;
    walker = this->head;
    trailer = nullptr;
    while(walker != nullptr && value > walker->getData()){
        trailer = walker;
        walker = walker->getNext();
    }
    Node* New = new Node(value);
    if(trailer == nullptr){
        New->setNext(head);
        head = New;
    } else {
        trailer->setNext(New);
        New->setNext(walker);
    }
}

std::string OList::toString(){
    Node *tmp = this->head;
    std::string result = "";
    while (tmp != nullptr){
        result = result + tmp->getData();
        result = result + "-->";
        tmp = tmp->getNext();
    }
    result = result + "nullptr";
    return result;
}

bool OList::contains(std::string value){
    Node *walker = head;
    while(walker != nullptr){
        if(walker->getData() == value){
            return true;
        }
        walker = walker->getNext();
    }
    return false;
}

std::string OList::get(int loc){
    Node* walker = this->head;
    while(loc > 0 && walker != nullptr){
        walker = walker->getNext();
        loc = loc - 1;
    }
    if(walker == nullptr){
        return "Out of range error.";
    }
    return walker->getData();
}

void OList::remove(int loc){
    Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;
    trailer=walker;
    walker = walker->getNext();
  }

  if (walker == nullptr){
    throw std::out_of_range("Tried to remove out of range");
  }

  if (trailer == nullptr){
    // we're removing the first item in the list
    head = walker->getNext();
    delete walker;
  } else {
    // general case of having a node before the
    // node to delete
    trailer->setNext(walker->getNext());
    delete walker;
  }
}

void OList::reverse(){
    Node* prev = this->head;
    Node* newh = nullptr;
    Node* tmp = nullptr;
    while(prev != nullptr){
        newh = prev;
        prev = prev->getNext();
        newh->setNext(tmp);
        tmp = newh;
    }
    this->head = newh;
}