#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node* left, * right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Function to check if a given binary tree is a min-heap or not
bool isHeap(Node* root)
{
    //End recursion successfully when the whole tree is traversed
    if (root == nullptr) {
       return true;
    }


    //Check if the left or right child less than its parent
    if ( (root->left != nullptr && root->left->data < root->data) || 
            (root->right != nullptr && root->right->data < root->data) ) {
        return false;
    }

    //Recursively call for left and right child until whole tree is traversed
    return isHeap(root->left) && isHeap(root->right);
}

int main()
{
    /* Construct the following tree
               2
             /   \
            /     \
           3       4
          / \     / \
         /   \   /   \
        5     6 8    10
    */

    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(8);
    root->right->right = new Node(10);

    if (isHeap(root)) {
        cout << "The given binary tree is a min-heap";
    }
    else {
        cout << "The given binary tree is not a min-heap";
    }

    return 0;
}
