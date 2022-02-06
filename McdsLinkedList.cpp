#include <iostream>
using namespace std;

class LinkNode {
public:

    int value;
    LinkNode* link;
    
    LinkNode(int _value, LinkNode* _link = nullptr)
    : value(_value), link(_link)
    {
    }
}

int main() {
    // Old School Initialization
    LinkNode* A;
    LinkNode* n = (LinkNode*)malloc(sizeof(LinkNode));
    (*n).value = 4;
    (*n).link = nullptr;
    A = n;

    // Actual Initialization
    LinkNode* head = new LinkNode(4);
}