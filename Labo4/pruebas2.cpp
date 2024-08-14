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

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() {
        root = NULL;
    }

    TreeNode* getRoot() {
        return root;
    }

    TreeNode* createNode(wchar_t symbol, double probability) {
        return new TreeNode(symbol, probability);
    }

    void insertNode(TreeNode* newNode) {
        if (root == NULL) {
            root = newNode;
        }
        else {
            TreeNode* currentNode = root;
            while (true) {
                if (newNode->probability < currentNode->probability) {
                    if (currentNode->leftChild == NULL) {
                        currentNode->leftChild = newNode;
                        newNode->parent = currentNode;
                        break;
                    }
                    else {

                        currentNode = currentNode->leftChild;
                    }
                }
                else {
                    if (currentNode->rightChild == NULL) {
                        currentNode->rightChild = newNode;
                        newNode->parent = currentNode;
                        break;
                    }
                    else {
                        currentNode = currentNode->rightChild;
                    }
                }
            }
        }
    }

    void showState() {
        showStateHelper(root);
    }

    void showStateHelper(TreeNode* node) {
        if (node != NULL) {
            // Print the symbol and probability of the current node
            wcout << "Symbol: " << node->str << ", Probability: " << node->probability << endl;

            if (node->parent != NULL) {
                wcout << "\tParent: Symbol: " << node->parent->str << ", Probability: " << node->parent->probability << endl;
            }

            else {
                wcout << "\tParent: NULL" << endl;
            }
            // Print the left child of the current node
            if (node->leftChild != NULL) {
                wcout << "\tLeft Child: Symbol: " << node->leftChild->str << ", Probability: " << node->leftChild->probability << endl;
            }
            else {
                wcout << "\tLeft Child: NULL" << endl;
            }

            // Print the right child of the current node
            if (node->rightChild != NULL) {
                wcout << "\tRight Child: Symbol: " << node->rightChild->str << ", Probability: " << node->rightChild->probability << endl;
            }
            else {
                wcout << "\tRight Child: NULL" << endl;
            }

            // Recursively call showStateHelper for the left and right child nodes
            showStateHelper(node->leftChild);
            showStateHelper(node->rightChild);
        }
    }


    void createPriorityQueue(PriorityQueue& pq) {
        createPriorityQueueHelper(pq, root);
    }

private:
    void createPriorityQueueHelper(PriorityQueue& pq, TreeNode* node) {
        if (node != NULL) {
            pq.enqueue(node);
            createPriorityQueueHelper(pq, node->leftChild);
            createPriorityQueueHelper(pq, node->rightChild);
        }
    }


    TreeNode* findSuccessor(TreeNode* node) {
        TreeNode* current = node->rightChild;

        while (current != NULL && current->leftChild != NULL) {
            current = current->leftChild;
        }

        return current;
    }
};


void traverseHuffmanTree(TreeNode* node, string code, wchar_t* letters, string* lettercode) {
    if (node->isLeaf()) {
       // wcout << "Symbol: " << node->str << ", Code: " << code << endl;
        for (int i = 0; i < 30; i++) {
            if (letters[i] == node->symbol) {
                lettercode[i] = code;
                break;
            }
        }
    }
    else {
        traverseHuffmanTree(node->leftChild, code + "0", letters, lettercode);
        traverseHuffmanTree(node->rightChild, code + "1", letters, lettercode);
    }
}

void printHaffmanSentence(wstring sentence, wchar_t* letters, string* lettercode) {
    for (int i = 0; i < sentence.length(); i++) {
        wchar_t c = sentence[i];
        // Find the corresponding index of the character in the letters array
        int index = -1;
        for (int j = 0; j < 30; j++) {
            if (letters[j] == c) {
                index = j;
                break;
            }
        }

        // If the character is found in the letters array, print its corresponding letter code
        if (index != -1) {
            cout << lettercode[index];
        }
    }
    wcout << std::endl;
}

void buildHuffmanTree( wchar_t *letters, double *frequencies) {
    // Count character frequencies


    // Create nodes for characters and their frequencies
    PriorityQueue priorityQueue(256);
    for (int i = 0; i < 30; i++) {
        
        wchar_t symbol = letters[i];
        double probability = frequencies[i];
        TreeNode* node = new TreeNode(symbol, probability);
        priorityQueue.enqueue(node);
        
    }

    BinaryTree binaryTree;
    while (!priorityQueue.isEmpty()) {
        TreeNode* node1 = priorityQueue.dequeue();
        TreeNode* node2 = priorityQueue.dequeue();

        wstring str1 = wstring(1, node1->symbol) + wstring(1, node2->symbol);

        double combinedProbability = node1->probability + node2->probability;
        TreeNode* combinedNode = new TreeNode('\0', combinedProbability);
        combinedNode->leftChild = node1;
        combinedNode->rightChild = node2;
        combinedNode->str = node1->str + node2->str;

        node1->parent = combinedNode;
        node2->parent = combinedNode;

        if (!priorityQueue.isEmpty()) {
            priorityQueue.enqueue(combinedNode);
        }
        else {
            priorityQueue.enqueue(combinedNode);
            break;
        }

    }

    TreeNode* rootNode = priorityQueue.dequeue();
    string lettercode[30];
    string code = "";
    traverseHuffmanTree(rootNode, code, letters, lettercode);
}