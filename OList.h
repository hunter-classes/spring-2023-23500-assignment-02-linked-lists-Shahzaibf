#pragma once
#include "Node.h"

class OList {
    private:
        Node * head;
    public:
        OList();
        ~OList();
        void insert(std::string data);
        std::string toString();
        bool contains(std::string value);
        std::string get(int loc);
        void remove(int loc);
        void reverse();
};