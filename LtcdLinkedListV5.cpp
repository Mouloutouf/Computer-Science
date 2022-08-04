class LinkedList {
public:
    struct Node {
        int data;
        Node *next, *prev;

        Node()
        : data(-1), next(nullptr), prev(nullptr)
        {
        }
        Node(int _data, Node *_next, Node*_prev)
        : data(_data), next(_next), prev(_prev)
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
        head = new Node(val, node, nullptr);
    }
    
    void addAtTail(int val) {
        Node* node = head;
        if (node == nullptr){
            head = new Node(val, nullptr, nullptr);
            return;
        }
        while (node != nullptr && node->next != nullptr){
            node = node->next;
        }
        node->next = new Node(val, nullptr, node);
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0){
            addAtHead(val);
        }
        Node* node = getNode(index - 1);
        if (node != nullptr){
            Node* prev = node;
            Node* next = node->next;
            Node* cur = new Node(val, next, prev);
            if (next != nullptr){
                next->prev = cur;
            }
            prev->next = cur;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index == 0){
            head = head->next;
            if (head != nullptr){
                head->prev = nullptr;
            }
        }
        Node* node = getNode(index);
        if (node != nullptr){
            Node* prev = node->prev;
            Node* next = node->next;
            if (next != nullptr){
                next->prev = prev;
            }
            if (prev != nullptr){
                prev->next = next;
            }
        }
    }
};