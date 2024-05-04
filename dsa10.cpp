#include <iostream>

class Node {
public:
    int data;
    Node(int value) : data(value) {}
};

class Heap {
private:
    Node** heapArray;
    int capacity;
    int size;
    
    int getParentIndex(int index) { return (index - 1) / 2; }
    int getLeftChildIndex(int index) { return 2 * index + 1; }
    int getRightChildIndex(int index) { return 2 * index + 2; }
    
    void swap(Node*& a, Node*& b) {
        Node* temp = a;
        a = b;
        b = temp;
    }
    
    void heapifyUp(int index) {
        int parentIndex = getParentIndex(index);
        if (parentIndex >= 0 && heapArray[index]->data > heapArray[parentIndex]->data) {
            swap(heapArray[index], heapArray[parentIndex]);
            heapifyUp(parentIndex);
        }
    }
    
    void heapifyDown(int index) {
        int maxIndex = index;
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        
        if (leftChildIndex < size && heapArray[leftChildIndex]->data > heapArray[maxIndex]->data) {
            maxIndex = leftChildIndex;
        }
        
        if (rightChildIndex < size && heapArray[rightChildIndex]->data > heapArray[maxIndex]->data) {
            maxIndex = rightChildIndex;
        }
        
        if (index != maxIndex) {
            swap(heapArray[index], heapArray[maxIndex]);
            heapifyDown(maxIndex);
        }
    }
    
public:
    Heap(int capacity) : capacity(capacity), size(0) {
        heapArray = new Node*[capacity];
    }
    
    ~Heap() {
        for (int i = 0; i < size; ++i) {
            delete heapArray[i];
        }
        delete[] heapArray;
    }
    
    void insert(int value) {
        if (size == capacity) {
            std::cout << "Heap is full!\n";
            return;
        }
        Node* newNode = new Node(value);
        heapArray[size++] = newNode;
        heapifyUp(size - 1);
    }
    
    int extractMax() {
        if (size == 0) {
            std::cout << "Heap is empty!\n";
            return -1;
        }
        int max = heapArray[0]->data;
        delete heapArray[0];
        heapArray[0] = heapArray[--size];
        heapifyDown(0);
        return max;
    }
    
    int getMax() {
        if (size == 0) {
            std::cout << "Heap is empty!\n";
            return -1;
        }
        return heapArray[0]->data;
    }
    
    int getMin() {
        if (size == 0) {
            std::cout << "Heap is empty!\n";
            return -1;
        }
        int min = heapArray[0]->data;
        for (int i = 1; i < size; ++i) {
            if (heapArray[i]->data < min) {
                min = heapArray[i]->data;
            }
        }
        return min;
    }
};

int main() {
    Heap marksHeap(10); // Assuming a capacity of 10 for demonstration
    bool continueInsertion = true;
    while (continueInsertion) {
        char cont;
        int o;
        std::cout << "Do you want to insert marks? (y/n): ";
        std::cin >> cont;
        if (cont == 'n') {
            continueInsertion = false;
        } else {
            std::cout << "Enter marks: ";
            std::cin >> o;
            marksHeap.insert(o);
        }
    }
    std::cout << "Maximum marks: " << marksHeap.getMax() << std::endl;
    std::cout << "Minimum marks: " << marksHeap.getMin() << std::endl;
    return 0;
}
