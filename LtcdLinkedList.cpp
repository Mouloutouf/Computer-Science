#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class MyLinkedList {
public:
    int val;
    
    MyLinkedList* next;
    MyLinkedList* prev;
    
    MyLinkedList* head;
    
    MyLinkedList() : val(0), next(NULL), prev(NULL)
    {
        head = this;
    }
    MyLinkedList(int _val, MyLinkedList* _next = nullptr, MyLinkedList* _prev = nullptr)
    : val(_val), next(_next), prev(_prev)
    {
    }
    
    MyLinkedList* getNode(int _index) {
        MyLinkedList* node = head;
        for (int i = 0; i < _index; i++) {
            if (node->next == nullptr) {
                return nullptr;
            }
            node = node->next;
        }
        return node;
    }
    
    int get(int _index) {
        MyLinkedList* node = getNode(_index);
        if (node == nullptr) {
            return -1;
        }
        return node->val;
    }
    
    void addAtHead(int _val) {
        MyLinkedList* newHead = new MyLinkedList(_val, this);
        prev = newHead;
        head = newHead;
    }
    
    void addAtTail(int _val) {
        MyLinkedList* newNode = new MyLinkedList(_val);
        int c = 0;
        MyLinkedList* n = getNode(c);
        while (n->next != nullptr) {
            c++;
        }
        n->next = newNode;
        newNode->prev = n;
    }
    
    void addAtIndex(int _index, int _val) {
        MyLinkedList* prevNode = getNode(_index);
        if (prevNode == nullptr) {
            return;
        }
        if (prevNode->next == nullptr) {
            addAtTail(_val);
            return;
        }
        MyLinkedList* nextNode = prevNode->next;
        MyLinkedList* newNode = new MyLinkedList(_val, nextNode, prevNode);
        prevNode->next = newNode;
        nextNode->prev = newNode;
    }
    
    void deleteAtIndex(int _index) {
        MyLinkedList* delNode = getNode(_index);
        if (delNode == nullptr) {
            return;
        }
        if (delNode->next == nullptr && delNode->prev == nullptr) {
            delete this;
            return;
        }
        else if (delNode->next == nullptr) {
            MyLinkedList* prevNode = delNode->prev;
            prevNode->next = nullptr;
        }
        else if (delNode->prev == nullptr) {
            MyLinkedList* nextNode = delNode->next;
            nextNode->prev = nullptr;
            nextNode->head = nextNode;
        }
        else {
            MyLinkedList* nextNode = delNode->next;
            MyLinkedList* prevNode = delNode->prev;
            nextNode->prev = prevNode;
            prevNode->next = nextNode;
        }
        delete delNode;
    }
};