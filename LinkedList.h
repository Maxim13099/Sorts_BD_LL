#pragma once
#include <iostream>
struct Node{
    double data;
    Node* next;
    
    Node(double data);
};

class OneLinkedList{
public:
    Node* head;
    Node* tail;
public:
    OneLinkedList();
    ~OneLinkedList();
    void delete_first();
    void push_back(double data);
    void push_first(double data);
    void delete_last();
    Node* getAt(int ElNumber);
    void Insert(int ElNumber, double data);
    void deleteMidleV(int ElNumber);
};
