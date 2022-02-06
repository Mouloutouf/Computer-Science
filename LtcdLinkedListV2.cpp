class MyLinkedList {
public:
    int data;
    MyLinkedList* link;
    
    MyLinkedList()
    {
    }
    MyLinkedList(int _data, MyLinkedList* _link)
    : data(_data), link(_link)
    {
    }
    
    int get(int index) {
        MyLinkedList* node = this;
        int i = 0;
        while(node->link != nullptr) {
            if (index == i) {
                return node->data;
            }
            node = node->link;
            i++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        
    }
    
    void addAtTail(int val) {
        
    }
    
    void addAtIndex(int index, int val) {
        
    }
    
    void deleteAtIndex(int index) {
        
    }
};