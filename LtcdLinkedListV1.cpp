#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class LinkedList {
public:
    int val;
    
    LinkedList* next;
    LinkedList* prev;
    
    LinkedList* head;
    
    LinkedList() : val(0), next(NULL), prev(NULL)
    {
        head = this;
    }
    LinkedList(int _val, LinkedList* _next = nullptr, LinkedList* _prev = nullptr)
    : val(_val), next(_next), prev(_prev)
    {
    }
    
    LinkedList* getNode(int _index) {
        LinkedList* node = head;
        for (int i = 0; i < _index; i++) {
            if (node->next == nullptr) {
                return nullptr;
            }
            node = node->next;
        }
        return node;
    }
    
    int get(int _index) {
        LinkedList* node = getNode(_index);
        if (node == nullptr) {
            return -1;
        }
        return node->val;
    }
    
    void addAtHead(int _val) {
        LinkedList* newHead = new LinkedList(_val, this);
        prev = newHead;
        head = newHead;
    }
    
    void addAtTail(int _val) {
        LinkedList* newNode = new LinkedList(_val);
        int c = 0;
        LinkedList* n = getNode(c);
        while (n->next != nullptr) {
            c++;
        }
        n->next = newNode;
        newNode->prev = n;
    }
    
    void addAtIndex(int _index, int _val) {
        LinkedList* prevNode = getNode(_index);
        if (prevNode == nullptr) {
            return;
        }
        if (prevNode->next == nullptr) {
            addAtTail(_val);
            return;
        }
        LinkedList* nextNode = prevNode->next;
        LinkedList* newNode = new LinkedList(_val, nextNode, prevNode);
        prevNode->next = newNode;
        nextNode->prev = newNode;
    }
    
    void deleteAtIndex(int _index) {
        LinkedList* delNode = getNode(_index);
        if (delNode == nullptr) {
            return;
        }
        if (delNode->next == nullptr && delNode->prev == nullptr) {
            delete this;
            return;
        }
        else if (delNode->next == nullptr) {
            LinkedList* prevNode = delNode->prev;
            prevNode->next = nullptr;
        }
        else if (delNode->prev == nullptr) {
            LinkedList* nextNode = delNode->next;
            nextNode->prev = nullptr;
            nextNode->head = nextNode;
        }
        else {
            LinkedList* nextNode = delNode->next;
            LinkedList* prevNode = delNode->prev;
            nextNode->prev = prevNode;
            prevNode->next = nextNode;
        }
        delete delNode;
    }
};