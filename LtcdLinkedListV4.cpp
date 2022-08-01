class LinkedList {
public:
    struct Node {
        int data;
        Node* next;

        Node()
        : data(-1), next(nullptr)
        {
        }
        Node(int _data, Node *_next)
        : data(_data), next(_next)
        {
        }
    };

    Node *head;
    
    LinkedList()
    : head(nullptr)
    {
    }
    
    Node* getNode(int index) {
        Node* node = head;
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
        Node* node = getNode(index);
        if (node != nullptr){
            return node->data;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* node = head;
        head = new Node(val, node);
    }
    
    void addAtTail(int val) {
        Node* node = head;
        if (node == nullptr){
            head = new Node(val, nullptr);
            return;
        }
        while (node != nullptr && node->next != nullptr){
            node = node->next;
        }
        node->next = new Node(val, nullptr);
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0){
            addAtHead(val);
        }
        Node* node = getNode(index - 1);
        if (node != nullptr){
            Node* next = node->next;
            node->next = new Node(val, next);
        }
    }
    
    void deleteAtIndex(int index) {
        if (index == 0){
            head = head->next;
        }
        Node* prev = getNode(index - 1);
        if (prev != nullptr){
            Node* node = prev->next;
            if (node != nullptr){
                prev->next = node->next;
            }
        }
    }
};