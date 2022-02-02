/**
 * @file binary-search-tree.cpp
 * @author nirmeet baweja
 * @brief Binary search tree (BST) is a binary tree where the value of each
 *  node is larger or equal to the values in all the nodes in that node's left
 * subtree and is smaller than the values in all the nodes in that node's right
 * subtree.
 * Write a function that, efficiently with respect to time used, checks if a
 * given binary search tree contains a given value.
 * For example, for the following tree:
 * n1 (Value: 1, Left: null, Right: null)
 * n2 (Value: 2, Left: n1, Right: n3)
 * n3 (Value: 3, Left: null, Right: null)
 * Call to contains(n2, 3)
 * should return true since a tree with root at n2 contains number 3.
 *
 * @version 0.1
 * @date 2022-02-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
    Node(int value, Node *left, Node *right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node *getLeft() const
    {
        return left;
    }

    Node *getRight() const
    {
        return right;
    }

private:
    int value;
    Node *left;
    Node *right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node &root, int value)
    {
        int node_value = root.getValue();
        if (node_value == value)
        {
            return true;
        }
        else if (node_value < value)
        {
            Node *right = root.getRight();
            if (right == NULL)
            {
                return false;
            }
            return contains(*right, value);
        }
        else
        {
            Node *left = root.getLeft();
            if (left == NULL)
            {
                return false;
            }
            return contains(*left, value);
        }
    }
};

#ifndef RunTests
int main()
{
    std::cout << "Binary Search.\n";
    Node n1(1, NULL, NULL);
    Node n3(3, NULL, NULL);
    Node n2(2, &n1, &n3);

    std::cout << BinarySearchTree::contains(n2, 3);
}
#endif