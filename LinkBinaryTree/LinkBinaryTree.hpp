/* 
This class is used to access a binary tree via a provided root pointer.
So, before you can use it,  you need to create a binary tree using BinaryTreeNode
which defined in BinaryTree.hpp
 */

#ifndef __LINKBINARYTREE_H
#define __LINKBINARYTREE_H

#include "BinaryTree.hpp"
#include <sstream>
#include <iostream>
#include <functional>

class BinaryTreeError {
    private:
        std::string err_msg;

    public:
        BinaryTreeError(std::string str):
        err_msg(str) {}
        void print_error() const {
            std::cout << err_msg << std::endl;
        }
};

template <class T>
class LinkBinaryTree : public BinaryTree<T> {
    // Define '__void_func_p' as an alias of function pointers.
    typedef void (*__void_func_p) (const BinaryTreeNode<T>*, BinaryTreeNode<T>**);

    private:
        int treeSize;
        BinaryTreeNode<T> *root;    // Root of binary tree.
        // mutable __void_func_p visit;    // functions pointer for accessing linking node.
        mutable std::function<void(const BinaryTreeNode<T>*, BinaryTreeNode<T>**)> visit;

    public:
        LinkBinaryTree(BinaryTreeNode<T>* root);
        LinkBinaryTree(const LinkBinaryTree<T>&);
        ~LinkBinaryTree();
        bool empty() const {return treeSize == 0;}
        int size() const {return treeSize;}
        int height() const;
        void erase();
        bool operator==(const LinkBinaryTree<T>&) const;
        LinkBinaryTree<T>& operator=(const LinkBinaryTree<T>&);
    
    protected:
        int height(const BinaryTreeNode<T>*) const;
        bool preOrder(const BinaryTreeNode<T>*, BinaryTreeNode<T>** origin = nullptr, int flags = 1) const;
        bool inOrder(const BinaryTreeNode<T>*, BinaryTreeNode<T>** origin = nullptr, int flags = 1) const;
        bool postOrder(const BinaryTreeNode<T>*, BinaryTreeNode<T>** origin = nullptr, int flags = 1) const;
};

template <class T>
LinkBinaryTree<T>::LinkBinaryTree(BinaryTreeNode<T>* theRoot):
treeSize(0)
{
    if(theRoot == nullptr) {
        throw BinaryTreeError("EMPTY TREE!");
    }
    root = theRoot;
}

template <class T>
LinkBinaryTree<T>::LinkBinaryTree(const LinkBinaryTree<T>& tree) {
    BinaryTreeNode<T>* p;
    tree.visit = [](const BinaryTreeNode<T>* t, BinaryTreeNode<T> **p){
        *p = new BinaryTreeNode<T>(t->element);
    };
    tree.preOrder(tree.root, &p, 0);
    this->root = p;
    this->treeSize = tree.treeSize;
}

template <class T>
LinkBinaryTree<T>::~LinkBinaryTree() {
    erase();
}

template <class T>
int LinkBinaryTree<T>::height() const {
    height(root);
}

template <class T>
int LinkBinaryTree<T>::height(const BinaryTreeNode<T>* node_p) const {
    if(node_p == nullptr) {
        return 0;
    }
    int h_left = height(node_p->leftNode);
    int h_right = height(node_p->rightNode);
    if(h_left > h_right) {
        return ++h_left;
    } else {
        return ++h_right;
    }
}

template <class T>
void LinkBinaryTree<T>::erase() {
    visit = [](const BinaryTreeNode<T>* t, BinaryTreeNode<T> **_) {
        std::cout << "Destroying element " << t->element << std::endl;
        delete t;
    };
    postOrder(root);
    treeSize = 0;
}

template <class T>
bool LinkBinaryTree<T>::preOrder(const BinaryTreeNode<T>* node, BinaryTreeNode<T>** origin, int flags) const {
    if(flags == 1) {
        if(node == nullptr) {
            return node->element;
        }
        visit(node, origin);
        preOrder(node->leftNode);
        preOrder(node->rightNode);
    } else {
        if() {
            // TODO: fix the bug when the size of two trees is not equal, while their height is equal.
            // access to nullptr (bug)
            //
        }
        visit(node, origin);
        preOrder(node->leftNode, &((*origin)->leftNode), 0);
        preOrder(node->rightNode, &((*origin)->rightNode), 0);
    }
}

template <class T>
bool LinkBinaryTree<T>::inOrder(const BinaryTreeNode<T>* node, BinaryTreeNode<T>** origin, int flags) const {
    if(node == nullptr) {
        return node->element;
    }
    if(flags == 1) {
        visit(node, origin);
        inOrder(node->leftNode);
        inOrder(node->rightNode);
    } else {
        inOrder(node->leftNode, &((*origin)->leftNode), 0);
        visit(node, origin);
        inOrder(node->rightNode, &((*origin)->rightNode), 0);
    }
}

template <class T>
bool LinkBinaryTree<T>::postOrder(const BinaryTreeNode<T>* node, BinaryTreeNode<T>** origin, int flags) const {
    if(node == nullptr) {
        return node->element;
    }
    if(flags == 1) {
        postOrder(node->leftNode);
        postOrder(node->rightNode);
        visit(node, origin);
    } else {
        postOrder(node->leftNode, &((*origin)->leftNode), 0);
        postOrder(node->rightNode, &((*origin)->rightNode), 0);
        visit(node, origin);
    }
}

template <class T>
bool LinkBinaryTree<T>::operator==(const LinkBinaryTree<T>& tree) const {
    if(this->height() != tree.height()) {
        return false;
    }
    bool isEqual = true;
    BinaryTreeNode<T>* p = root;
    visit = [&isEqual](const BinaryTreeNode<T>* node, BinaryTreeNode<T>** origin){
        if((node == nullptr && origin != nullptr) || 
            (node != nullptr && origin == nullptr)) {
                isEqual = false;
                return;
        }
        if(node->element != (*origin)->element) {
            isEqual = false;
        }
    };
    preOrder(tree.root, &p, 0);
    return isEqual;
}

template <class T>
LinkBinaryTree<T>& LinkBinaryTree<T>::operator=(const LinkBinaryTree<T>&) {

}

#endif // __LINKBINARYTREE_H
