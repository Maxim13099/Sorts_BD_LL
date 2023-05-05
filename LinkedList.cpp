#include "LinkedList.h"
#include "realize.h"
using namespace std;

Node::Node(double data){
    this->data = data;
    this->next = nullptr;
}


    OneLinkedList::OneLinkedList(){
        this->head = this->tail = nullptr;
    }
    OneLinkedList::~OneLinkedList(){
        while(head != nullptr){
            delete_first();
        }
    }
    void OneLinkedList::delete_first(){
        if(head == nullptr) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node  = head;
        head = node->next;
        delete node;
    }
    void OneLinkedList::push_back(double data){
        Node* node = new Node(data);
        if (head == nullptr){
            head = node;
        }
        if(tail != nullptr){
            tail->next = node;
        }
        tail = node;
    }
    void OneLinkedList::push_first(double data){
        Node* node = new Node(data);
        node->next = head;
        head = node;
        if(tail == nullptr) tail = node;
    }
    void OneLinkedList::delete_last(){
        if (tail == nullptr) return;
        if (head == tail){
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        for(;node->next != tail; node = node->next);
        node->next = nullptr;
        delete tail;
        tail = node;
    }
    Node* OneLinkedList::getAt(int ElNumber){
        if (ElNumber < 0) return nullptr;
        Node* node = head;
        int n = 0;
        while(node && n != ElNumber && node->next){
            node = node->next;
            n++;
        }
        if(n == ElNumber) return node;
        else{return nullptr;}
    }
    void OneLinkedList::Insert(int ElNumber, double data){
        Node* left = getAt(ElNumber);
        if (left == nullptr) return;
        Node* right = left->next;
        Node* node = new Node(data);
        left->next = node;
        node->next = right;
        if(right == nullptr) tail = node;
    }
    void OneLinkedList::deleteMidleV(int ElNumber){
        if(ElNumber < 0) return;
        if(ElNumber == 0) {delete_first(); return;}
        Node* left = getAt(ElNumber - 1);
        Node* node = left->next;
        if(node == nullptr) return;
        Node* right = node->next;
        left->next = right;
        if(node == tail) tail = nullptr;
        delete node;
    }
