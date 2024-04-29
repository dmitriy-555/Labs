#include <iostream>

using namespace std;

namespace Node {
    template<typename T>
    class TreeNode {
    public:
        T data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
    };
}

using namespace Node;

template<typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

    void prefix(TreeNode<T>* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        prefix(node->left);
        prefix(node->right);
    }

    void infix(TreeNode<T>* node) {
        if (node == nullptr) return;
        infix(node->left);
        cout << node->data << " ";
        infix(node->right);
    }

    void postfix(TreeNode<T>* node) {
        if (node == nullptr) return;
        postfix(node->left);
        postfix(node->right);
        cout << node->data << " ";
    }

public:
    void destroyTree(TreeNode<T>* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroyTree(root);
    }

    void insert(T val) {
        TreeNode<T>* newNode = new TreeNode<T>{ val };
        if (root == nullptr) {
            root = newNode;
            return;
        }

        TreeNode<T>* current = root;
        TreeNode<T>* parent;
        while (true) {
            parent = current;
            if (val < current->data) {
                current = current->left;
                if (current == nullptr) {
                    parent->left = newNode;
                    return;
                }
            }
            else {
                current = current->right;
                if (current == nullptr) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
    void prefixPrint() {
        prefix(root);
        cout << endl;
    }

    void infixPrint() {
        infix(root);
        cout << endl;
    }

    void postfixPrint() {
        postfix(root);
        cout << endl;
    }
};

int main() {

    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(7);
    tree.insert(3);

    tree.prefixPrint();
    tree.infixPrint();
    tree.postfixPrint();

    return 0;
}





