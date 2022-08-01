class LinkedList {
public:
    int data;
    LinkedList* next;
    LinkedList* head;
    
    LinkedList()
    : data(0), next(nullptr), head(nullptr) // Initialize everything with default values, otherwise they will not be null but undefined which will cause undefined behaviour when checking for null
    {
    }
    LinkedList(int _data, LinkedList* _link = nullptr)
    : data(_data), next(_link), head(nullptr)
    {
    }
    
    LinkedList* getNode(int index) {
        // Always check if head is uninitialized
        if (head != nullptr) {
            // Go through the Linked List
            LinkedList* node = head;
            int i = 0;
            // Check for the element directly
            while(node != nullptr) {
                // If element is found, return it
                if (index == i) {
                    return node;
                }
                node = node->next;
                i++;
            }
        }
        return nullptr;
    }
    
    int get(int index) {
        LinkedList* node = getNode(index);
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
            LinkedList* node = head;
            head = new LinkedList(val, node);
        }
        // If there is no head initialize one
        else {
            head = new LinkedList(val, nullptr);
        }
    }
    
    void addAtTail(int val) {
        // Always check if head is uninitialized
        if (head != nullptr) {
            // Go through the Linked List
            LinkedList* node = head;
            // Check for the next element. If there is no next element, we have found the tail
            while(node->next != nullptr) {
                node = node->next;
            }
            node->next = new LinkedList(val, nullptr);
        }
    }
    
    void addAtIndex(int index, int val) {
        // Search for the previous element to the target element
        LinkedList* node = getNode(index - 1);
        // If previous element is found, add new element after it. Essentially adding new element before the target element
        if (node != nullptr) {
            LinkedList* next = node->next;
            node->next = new LinkedList(val, next);
        }
        // /!\ This method does not check if the target element is the head or the tail
    }
    
    void deleteAtIndex(int index) {
        // Search for the previous element to the target element
        LinkedList* prev = getNode(index - 1);
        // If previous element is found, delete element after it. Essentially deleting our target element
        if (prev != nullptr) {
            LinkedList* node = prev->next;
            prev->next = node->next;
            delete node;
        }
        // /!\ This method does not check if the target element is the head or the tail
    }
};