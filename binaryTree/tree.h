/*
 * tree.h : C4J Aufgabe 2: binaryTree
 * Kai Mueller, Tim Jagodzinski
 */

#ifndef TREE_H
#define TREE_H

#include <string>

namespace nsTree {
    typedef unsigned int KeyType;
    typedef std::string ValueType;
}

class TreeNode;

class TreeIterator {
private:
    TreeNode* m_currentNode;
public:
    TreeIterator(TreeNode* node);
    TreeIterator(const TreeIterator& rhs);
    TreeIterator& operator=(const TreeIterator& rhs);
    nsTree::ValueType& value();
    nsTree::KeyType& key();
    TreeIterator operator++(int);
    TreeIterator operator--(int);
    TreeIterator& operator++();
    TreeIterator& operator--();
    bool operator==(const TreeIterator &rhs);
    bool operator!=(const TreeIterator &rhs);
};

class Tree {
private:
    TreeNode* m_root;
    unsigned int m_count;
    Tree(const Tree& rhs);
    Tree& operator=(const Tree& rhs);
public:
    Tree();
    unsigned int count() const;
    void deleteNode(const nsTree::KeyType& key);
    void clear();
    bool contains(const nsTree::KeyType& key);
    nsTree::ValueType& operator[](const nsTree::KeyType& key);
    void insert(const nsTree::KeyType& key, const nsTree::ValueType& value);
    TreeIterator first();
    TreeIterator last();
    TreeIterator end();
    TreeIterator find(const nsTree::KeyType& key);
};

#endif // TREE_H
