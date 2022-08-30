#include <vector>
#include <iostream>
using namespace std;

class MinHeap{
public:
    vector<int> heap;
    int size;
    int capacity;

    MinHeap(int _capacity){
        capacity = _capacity;
        heap = vector<int>(_capacity + 1);
        size = heap[0] = 0;
    }

    int size(){
        return size;
    }

    void add(int _element){
        size++;
        if (size > capacity){
            cout << "Size limit exceeded, cannot add more elements to Heap" << endl;
            size--;
        }
        heap[size] = _element;
        int i = size;
        int p = i / 2;
        while (heap[i] < heap[p] && i > 1){
            int v = heap[i];
            heap[i] = heap[p];
            heap[p] = v;
            i = p;
            p = i / 2;
        }
    }

    int pop(){
        if (size < 1){
            cout << "Heap is empty, cannot remove elements from it" << endl;
            return 0;
        }
        int r = heap[1];
        heap[1] = heap[size];
        size--;
        int i = 1;
        while (i <= size / 2){
            int left = i * 2;
            int right = (i * 2) + 1;
            if (heap[i] > heap[left] || heap[i] > heap[right]){
                int cur = heap[left] < heap[right] ? left : right;
                int v = heap[cur];
                heap[cur] = heap[i];
                heap[i] = v;
                i = cur;
            }
            else{
                break;
            }
        }
        return r;
    }

    int peek(){
        return heap[1];
    }
};

class MaxHeap{
public:
    vector<int> heap;
    int size;
    int capacity;

    MaxHeap(int _capacity){
        capacity = _capacity;
        heap = vector<int>(_capacity + 1);
        size = heap[0] = 0;
    }

    int size(){
        return size;
    }

    void add(int _element){
        size++;
        if (size > capacity){
            cout << "Size limit exceeded, cannot add more elements to Heap" << endl;
            size--;
        }
        heap[size] = _element;
        int i = size;
        int p = i / 2;
        while (heap[i] > heap[p] && i > 1){
            int v = heap[i];
            heap[i] = heap[p];
            heap[p] = v;
            i = p;
            p = i / 2;
        }
    }

    int pop(){
        if (size < 1){
            cout << "Heap is empty, cannot remove elements from it" << endl;
            return 0;
        }
        int r = heap[1];
        heap[1] = heap[size];
        size--;
        int i = 1;
        while (i <= size / 2){
            int left = i * 2;
            int right = (i * 2) + 1;
            if (heap[i] < heap[left] || heap[i] < heap[right]){
                int cur = heap[left] > heap[right] ? left : right;
                int v = heap[cur];
                heap[cur] = heap[i];
                heap[i] = v;
                i = cur;
            }
            else{
                break;
            }
        }
        return r;
    }

    int peek(){
        return heap[1];
    }
};