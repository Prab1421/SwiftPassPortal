#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {};
};

class BST {
    node* root;

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        node* newNode = new node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        node* current = root;
        while (true) {
            if (val < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            } else if (val > current->data) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            } else {
                break;
            }
        }
    }

    void inorderTraversal() {
        stack<node*> s;
        node* current = root;
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    } 

    void preorderTraversal() {
        stack<node*> s;
        if (root != nullptr)
            s.push(root);
        while (!s.empty()) {
            node* temp = s.top();
            s.pop();
            cout << temp->data << " ";
            if (temp->right != nullptr)
                s.push(temp->right);
            if (temp->left != nullptr)
                s.push(temp->left);
        }
    }

    void postorderTraversal() {
        stack<node*> s;
        stack<node*> output;
        if (root != nullptr)
            s.push(root);
        while (!s.empty()) {
            node* temp = s.top();
            s.pop();
            output.push(temp);
            if (temp->left != nullptr)
                s.push(temp->left);
            if (temp->right != nullptr)         
                s.push(temp->right);
        }
        while (!output.empty()) {
            cout << output.top()->data << " ";
            output.pop();
        }
    }
};

int main() {
    BST bst;
    int n;
    cout << "Enter the number of data you want to insert: ";
    cin >> n;
    cout << "Enter " << n << " data items: " << endl;
    for (int i = 0; i < n; i++) {
        int data;
        cout << "Data " << i + 1 << " : ";
        cin >> data;
        bst.insert(data);
    }
    cout << "Inorder traversal of the BST: ";
    bst.inorderTraversal();
    cout << endl;

    cout << "Preorder traversal of the BST: ";
    bst.preorderTraversal();
    cout << endl;

    cout << "Postorder traversal of the BST: ";
    bst.postorderTraversal();
    cout << endl;

    return 0;
}
