#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    TreeNode* parent;
    TreeNode* leftChild;
    TreeNode* rightChild;
    wchar_t symbol;
    wstring str;
    double probability;

    TreeNode(wchar_t sym, double prob) {
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
        symbol = sym;
        probability = prob;
        str = wstring(1, sym);
    }

    bool isLeaf() {
        return leftChild == NULL && rightChild == NULL;
    }
};

class PriorityQueue {
private:
    TreeNode** heap;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) {
        heap = new TreeNode * [cap];
        capacity = cap;
        size = 0;
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    bool isEmpty() {
        return size == 0;
    }

    void showState() {
        std::wcout << "Priority Queue State:" << std::endl;
        std::wcout << "Size: " << size << ", Capacity: " << capacity << std::endl;
        std::wcout << "Elements (in dequeue order):" << std::endl;

        // Create a temporary copy of the heap array
        TreeNode** tempHeap = new TreeNode * [size];
        std::copy(heap, heap + size, tempHeap);

        // Save the current size and capacity of the priority queue
        int savedSize = size;
        int savedCapacity = capacity;

        // Dequeue and print the elements from the temporary heap
        while (!isEmpty()) {
            TreeNode* node = dequeue();
            std::wcout << "Symbol: " << node->str << ", Probability: " << node->probability << std::endl;
        }

        std::wcout << "-----------------------------------------" << endl;
        // Restore the saved state of the priority queue
        size = savedSize;
        capacity = savedCapacity;

        // Restore the original heap array
        delete[] heap;
        heap = tempHeap;
    }


    void enqueue(TreeNode* node) {
        if (size == capacity) {
            wcout << "Priority queue is full." << endl;
            return;
        }

        int i = size;
        while (i > 0 && heap[(i - 1) / 2]->probability > node->probability) {
            heap[i] = heap[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        heap[i] = node;
        size++;
    }

    TreeNode* dequeue() {
        if (isEmpty()) {
            wcout << "Priority queue is empty." << endl;
            return NULL;
        }

        TreeNode* minNode = heap[0];
        size--;

        if (size > 0) {
            TreeNode* lastNode = heap[size];
            int i = 0;
            while (i * 2 + 1 < size) {
                int leftChild = i * 2 + 1;
                int rightChild = i * 2 + 2;

                int smallerChild = leftChild;
                if (rightChild < size && heap[rightChild]->probability < heap[leftChild]->probability) {
                    smallerChild = rightChild;
                }

                if (lastNode->probability > heap[smallerChild]->probability) {
                    heap[i] = heap[smallerChild];
                    i = smallerChild;
                }
                else {
                    break;
                }
            }
            heap[i] = lastNode;
        }

        return minNode;
    }
};