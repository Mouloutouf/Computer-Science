class LinkedList {
public:
    int data;
    LinkedList *next, *head;
    
    LinkedList()
    : data(-1), next(nullptr), head(nullptr)
    {
    }
    LinkedList(int _data, LinkedList* _next = nullptr)
    : data(_data), next(_next), head(nullptr)
    {
    }
    
    LinkedList* getNode(int index) {
        LinkedList* node = head;
        int i = 0;
        while (node != nullptr){
            if (index == i){
                return node;
            }
            node = node->next;
            i++;
        }
        return nullptr;
    }
    
    int get(int index) {
        LinkedList* node = getNode(index);
        if (node != nullptr){
            return node->data;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        LinkedList* node = head;
        head = new LinkedList(val, node);
    }
    
    void addAtTail(int val) {
        LinkedList* node = head;
        if (node == nullptr){
            head = new LinkedList(val, nullptr);
            return;
        }
        while (node != nullptr && node->next != nullptr){
            node = node->next;
        }
        node->next = new LinkedList(val, nullptr);
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0){
            addAtHead(val);
        }
        LinkedList* node = getNode(index - 1);
        if (node != nullptr){
            LinkedList* next = node->next;
            node->next = new LinkedList(val, next);
        }
    }
    
    void deleteAtIndex(int index) {
        if (index == 0){
            head = head->next;
        }
        LinkedList* prev = getNode(index - 1);
        if (prev != nullptr){
            LinkedList* node = prev->next;
            if (node != nullptr){
                prev->next = node->next;
            }
        }
    }
};