/*  DOCUMENT INSTRUCTION
1. Binary Tree Node struction
2. Binary Tree abstract class
 */

#ifndef __BINARYTREE_H
#define __BINARYTREE_H

/* The node struct for binaryTree
EVERY node contains:
leftNode, element, rightNode
Contructor:
    1. default:         initilize chain field with nullptr.
    2. element-only:    initilize element with provided one, and chain field filled with nullptr.
    3. complete:        initilize all field with provided params.*/
template <class T>
struct BinaryTreeNode
{
    T element;
    BinaryTreeNode<T> *leftNode;
    BinaryTreeNode<T> *rightNode;

    BinaryTreeNode() {
        leftNode = rightNode = nullptr;
    }

    BinaryTreeNode(const T& element) {
        this->element = element;
        leftNode = rightNode = nullptr;
    }

    BinaryTreeNode(const T& element,
                    const BinaryTreeNode<T> *leftNode,
                    const BinaryTreeNode<T> *rightNode) {
        this->element = element;
        this->leftNode = leftNode;
        this->rightNode = rightNode;
    }
};

/* INTERFACE NEED TO IMPLEMENT
1. Destructor
2. empty() const
3. size() const
4. height() const
5. erase() 
6. operator==(const BinaryTree<T>&) const
7. operator=(const BinaryTree<T>&)
8. */
template <class T>
class BinaryTree {
    public:
        virtual ~BinaryTree() {}
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual int height() const = 0;
        virtual void erase() = 0;
    
        virtual bool preOrder(const BinaryTreeNode<T>*, BinaryTreeNode<T>** origin = nullptr, int flags = 1) const = 0;
        virtual bool inOrder(const BinaryTreeNode<T>*, BinaryTreeNode<T>** origin = nullptr, int flags = 1) const = 0;
        virtual bool postOrder(const BinaryTreeNode<T>*, BinaryTreeNode<T>** origin = nullptr, int = 1) const = 0;
};

#endif // __BINARYTREE_H
