class MyLinkedList {
public:
    int data;
    MyLinkedList* link;
    MyLinkedList* head;
    
    MyLinkedList()
    : data(0), link(nullptr), head(nullptr) // Initialize everything with default values, otherwise they will not be null but undefined which will cause undefined behaviour when checking for null
    {
    }
    MyLinkedList(int _data, MyLinkedList* _link = nullptr)
    : data(_data), link(_link), head(nullptr)
    {
    }
    
    MyLinkedList* getNode(int index) {
        // Always check if head is uninitialized
        if (head != nullptr) {
            // Go through the Linked List
            MyLinkedList* node = head;
            int i = 0;
            // Check for the element directly
            while(node != nullptr) {
                // If element is found, return it
                if (index == i) {
                    return node;
                }
                node = node->link;
                i++;
            }
        }
        return nullptr;
    }
    
    int get(int index) {
        MyLinkedList* node = getNode(index);
        // If element is found, return its data
        if (node != nullptr) {
            return node->data;
        }
        // Otherwise
        return -1;
    }
    
    void addAtHead(int val) {
        // If there is a head, replace it
        if (head != nullptr) {
            MyLinkedList* node = head;
            head = new MyLinkedList(val, node);
        }
        // If there is no head initialize one
        else {
            head = new MyLinkedList(val, nullptr);
        }
    }
    
    void addAtTail(int val) {
        // Always check if head is uninitialized
        if (head != nullptr) {
            // Go through the Linked List
            MyLinkedList* node = head;
            // Check for the next element. If there is no next element, we have found the tail
            while(node->link != nullptr) {
                node = node->link;
            }
            node->link = new MyLinkedList(val, nullptr);
        }
    }
    
    void addAtIndex(int index, int val) {
        // Search for the previous element to the target element
        MyLinkedList* node = getNode(index - 1);
        // If previous element is found, add new element after it. Essentially adding new element before the target element
        if (node != nullptr) {
            MyLinkedList* next = node->link;
            node->link = new MyLinkedList(val, next);
        }
        // /!\ This method does not check if the target element is the head or the tail
    }
    
    void deleteAtIndex(int index) {
        // Search for the previous element to the target element
        MyLinkedList* prevNode = getNode(index - 1);
        // If previous element is found, delete element after it. Essentially deleting our target element
        if (prevNode != nullptr) {
            MyLinkedList* node = prevNode->link;
            prevNode->link = node->link;
            delete node;
        }
        // /!\ This method does not check if the target element is the head or the tail
    }
};