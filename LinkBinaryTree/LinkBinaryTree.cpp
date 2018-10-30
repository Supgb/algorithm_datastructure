#include "LinkBinaryTree.hpp"

int main(int argc, char const *argv[]) {
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(100);
    root->leftNode = new BinaryTreeNode<int>(101);
    root->leftNode->leftNode = new BinaryTreeNode<int>(120);
    // root->rightNode = new BinaryTreeNode<int>(102);
    BinaryTreeNode<int>* root_s = new BinaryTreeNode<int>(200);
    try
    {
        LinkBinaryTree<int> tree(root);
        std::cout << "The height of tree is " << tree.height() << std::endl;
        std::cout << "The test of the second tree..." << std::endl;
        LinkBinaryTree<int> tree_s(tree);
        std::cout << "The height of the second tree is " << tree_s.height() << std::endl;
        std::cout << "[Test] operator== " << std::endl;
        std::cout << "Is tree == tree_s ? " << std::endl;
        std::cout << "Ans : " << (tree==tree_s?"true":"false") << std::endl;
        LinkBinaryTree<int> tree_t(root_s);
        std::cout << "Is tree == tree_t ? " << std::endl;
        std::cout << "Ans : " << (tree==tree_t?"true":"false") << std::endl;
    }
    catch(const BinaryTreeError& e)
    {
        e.print_error();
    }
    
    return 0;
}
