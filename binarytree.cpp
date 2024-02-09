#include<bits/stdc++.h>
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
    node* insertion(node* Node, int val) {
        if(Node == nullptr) {
            return new node(val);
        }
        if(val < Node->data) {
            Node -> left = insertion(Node-> left, val);
        } else if(val > Node->data) {
            Node -> right = insertion(Node-> right, val);
        }
        return Node;
    }
    
    void inorder(node* Node) {
        if(Node != nullptr) {
            inorder(Node->left);
            cout << Node->data << " ";
            inorder(Node->right);
        }
    } 

    void preorder(node* Node) {
        if(Node != nullptr) {
           cout << Node->data << " ";
            preorder(Node->left);
            preorder(Node->right);
        }
    }

    void postorder(node* Node) {
        if(Node != nullptr) {
            postorder(Node->left);
            postorder(Node->right);
            cout << Node->data << " ";
        }
    }

    public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertion(root, val);
    }

    void inordertraversal() {
        inorder(root);
    }

    void preordertraversal() {
        preorder(root);
    }

    void postordertraversal() {
        postorder(root);
    } 

};
int main() {
    BST bst;
    int n;
    cout << "Enter the number of data you want to insert: ";
    cin >> n;
    cout <<"Enter " << n << " data items: " << endl;
    for(int i=0; i<n; i++) {
        int data;
        cout <<"Data " << i+ 1 << " : ";
        cin >> data;
        bst.insert(data);
    }
    cout << "Inorder traversal of the BST: ";
    bst.inordertraversal();
    cout << endl;

    cout << "Preorder traversal of the BST: ";
    bst.preordertraversal();
    cout << endl;

    cout << "postorder traversal of the BST: ";
    bst.postordertraversal();
    cout << endl;

    return 0;
}