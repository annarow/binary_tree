#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

TEST(tree, LCA){
    TreeNode<int>* root = new TreeNode<int>(4);

    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));

    BinaryTree<int> tree2(root);

    ASSERT_EQ(tree2.LCA(4, 4), 4);

      ASSERT_EQ(tree2.LCA(7, 7), 7);
      ASSERT_EQ(tree2.LCA(7, 3), 8);
      ASSERT_EQ(tree2.LCA(7, 8), 8);
      ASSERT_EQ(tree2.LCA(8, 6), 4);
      ASSERT_EQ(tree2.LCA(3, 2), 4);

}


TEST(tree, TraverseInOrder){
    TreeNode<int>* root = new TreeNode<int>(4);

    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));

    BinaryTree<int> tree(root);

    std::vector<int> orderTree = tree.traverseInOrder();

    std::vector<int> orderVector = {7, 8, 3, 4, 2, 6, 9};

    ASSERT_TRUE( orderVector == orderTree);

}

TEST(tree, TraversePostOrder){
    TreeNode<int>* root = new TreeNode<int>(4);

    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));

    BinaryTree<int> tree(root);

    std::vector<int> postTree = tree.traversePostOrder();
    std::vector<int> postVector = {7, 3, 8, 2, 9, 6, 4};
    ASSERT_TRUE(postTree == postVector);

}

