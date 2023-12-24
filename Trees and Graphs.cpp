#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enQueue(Node* newNode) {
        if (rear == nullptr) {
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deQueue() {
        if (front == nullptr) {
            cout << "Queue is empty";
            return;
        }
        else {
            Node* t = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete t;
        }
    }

    int size() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->data << "  ";
            inOrder(root->right);
        }
    }

    void preOrder(Node* root) {
        if (root != nullptr) {
            cout << root->data << "  ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(Node* root) {
        if (root != nullptr) {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << "  ";
        }
    }

    Node* levelOrderPoint(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Queue q;
        q.enQueue(root);
        Node* current = nullptr;

        while (q.front != nullptr) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                current = q.front;
                q.deQueue();

                if (current->left) {
                    q.enQueue(current->left);
                }
                if (current->right) {
                    q.enQueue(current->right);
                }
            }
        }

        return current;
    }
};

int main() {
    BinaryTree bt;
    bt.root = new Node(10);
    bt.root->left = new Node(20);
    bt.root->right = new Node(30);
    bt.root->right->left = new Node(40);
    bt.root->right->right = new Node(50);

    cout << "Pre Order :";
    bt.preOrder(bt.root);
    cout << endl;

    cout << "Post Order :";
    bt.postOrder(bt.root);
    cout << endl;

    cout << "In Order :";
    bt.inOrder(bt.root);
    cout << endl;

    Node* lastNode = bt.levelOrderPoint(bt.root);
    if (lastNode) {
        cout << "Last node in level order traversal: " << lastNode->data << endl;
    }
    else {
        cout << "Tree is empty!" << endl;
    }

    delete bt.root->right->left;
    delete bt.root->right->right;
    delete bt.root->right;
    delete bt.root->left;
    delete bt.root;

    return 0;
}
