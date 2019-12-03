#pragma once
using namespace std;
#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"
#include <iostream>

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->getLeft()), height(root->right));
    }

    TreeNode<T>* LCA(TreeNode<T>* root, T node1, T node2){
        if (root == nullptr){
            return nullptr;
        }
        if (root->val == node1 || root->val == node2){
            return root;
        }
        TreeNode<T>* left = LCA(root->getLeft(), node1, node2);
        TreeNode<T>* right = LCA(root->right, node1, node2);
        if(left ==nullptr && right ==nullptr){
            return nullptr;
        }
        if(left != nullptr && right!=nullptr){
            return root;
        }
        if(left == nullptr){
            return right;
        }
        else{
            return left;
        }

    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {
        // homework, to be done iteratively

        LinkedStack<TreeNode<T>*> stackList;
        std::vector<T> list;
        TreeNode<T>* currentNode = root;
        while(currentNode != nullptr || !stackList.isEmpty()){
            while(currentNode != nullptr){
                stackList.push(currentNode);
                currentNode = currentNode->getLeft();
            }
            currentNode = stackList.peek();
            stackList.pop();
            list.push_back(currentNode->val);
            currentNode = currentNode->right;
        }
        return list;

    }

    void traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {
        // homework, to be done iteratively
        LinkedStack<TreeNode<T>*> stackList;
        LinkedStack<TreeNode<T>*> stackFinal;
        std::vector<T> list;
        TreeNode<T>* currentNode = root;
        stackList.push(currentNode);
        while(!stackList.isEmpty()){
            currentNode = stackList.peek();
            stackList.pop();
            stackFinal.push(currentNode);

            if(currentNode->getLeft() != nullptr){
                stackList.push(currentNode->getLeft());
            }
            if(currentNode->right != nullptr){
                stackList.push(currentNode->right);
            }
        }
        int i = 0;
        while(!stackFinal.isEmpty()){
            list.push_back(stackFinal.peek()->val);
            stackFinal.pop();
            i++;
            }
        return list;

    }

    virtual ~BinaryTree() {
        // homework
        recursively_delete_tree(this->root);
    }

    void recursively_delete_tree(TreeNode<T>* node){
        TreeNode<T>* left = node->getLeft();
        TreeNode<T> *right = node->getRight();

        delete node;
        if(left != nullptr){
            recursively_delete_tree(left);
        }

        if(right != nullptr){
            recursively_delete_tree(right);
        }

    }

    T LCA(T node1, T node2) {
        // homework
        TreeNode<T>* node = LCA(root, node1, node2);
        return node == nullptr ? -1 : node->val;


    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
