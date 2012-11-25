/*
 * tree.cpp : C4J Aufgabe 2: binaryTree
 * Kai Mueller, Tim Jagodzinski
 */

#include "tree.h"

/*
 ************
 * TreeNode *
 ************
 */
class TreeNode {
private:
    TreeNode* m_left;
    TreeNode* m_right;
    TreeNode* m_up;
    nsTree::KeyType m_key;
    nsTree::ValueType m_value;
public:

    /*
     * standard constructor
     */
    TreeNode(TreeNode* parent = 0,
                 const nsTree::KeyType& key = nsTree::KeyType(),
                 const nsTree::ValueType& value = nsTree::ValueType())
            : m_left(0), m_right(0), m_up(parent),
              m_key(key), m_value(value)
        {}

    /*
     * getter and setter
     */
    nsTree::KeyType& key() { return m_key; }
    nsTree::ValueType& value() { return m_value; }
    TreeNode* getParent() { return m_up; }
    void setLeftNode(TreeNode* node) { m_left = node; }
    void setRightNode(TreeNode* node) { m_right = node; }

    /*
     * returns true if the node has no parent
     */
    bool isRoot() {
        if (m_up == 0) { return true; }
        return false;
    }

    /*
     * returns true if the node is a left child of an other node
     */
    bool isLeftChild() {
        if(!isRoot() && m_up->m_left == this) { return true; }
        return false;
    }

    /*
     * returns true if the node is a right child of an other node
     */
    bool isRightChild() {
        if(!isRoot() && m_up->m_right == this) { return true; }
        return false;
    }

    /*
     * returns the root node of the tree
     */
    TreeNode* findRoot() {
        if (isRoot()) { return this; }
        return m_up->findRoot();
    }

    /*
     * returns the node with the lowest m_value in the tree,
     * must be called from the root to cover whole tree
     */
    TreeNode* findFirst() {
        if (m_left == 0) { return this; }
        return m_left->findFirst();
    }

    /*
     * returns the node with the highest m_value in the tree,
     * must be called from the root to cover whole tree
     */
    TreeNode* findLast() {
        if (m_right == 0) { return this; }
        return m_right->findLast();
    }

    /*
     * returns the next node in the tree, determined by key
     */
    TreeNode* findNext() {
        if (m_right != 0) { return m_right->findFirst(); }
        if (m_up == 0) {
            return createDummyNode();
        }
        TreeNode* parentNode = m_up;
        while (key() > parentNode->key()) {
            if (parentNode->m_up == 0) { return createDummyNode(); }
            parentNode = parentNode->m_up;

        }
        return parentNode;
    }

    /*
     * returns the previous node in the tree, determined by key
     */
    TreeNode* findPrevious() {
        if (m_left != 0) { return m_left->findLast(); }
        if (m_up == 0) {
            return createDummyNode();
        }
        TreeNode* parentNode = m_up;
        while (key() < parentNode->key()) {
            if (parentNode->m_up == 0) { return createDummyNode(); }
            parentNode = parentNode->m_up;
        }
        return parentNode;
    }

    /*
     * returns a dummy node for the iteration end
     */
    TreeNode* createDummyNode() { return new TreeNode(findLast(),0,"THIS IS A DUMMY NODE TO DETERMINATE THE END"); }

    /*
     * returns the node with the searched key,
     * returns 0 if searched key is not in tree,
     * must be called from the root to cover whole tree
     */
    TreeNode* find(const nsTree::KeyType& key) {
        if (key < m_key) {
            if (m_left == 0) { return 0; }
            return m_left->find(key);
        } else if (key > m_key) {
            if (m_right == 0) { return 0; }
            return m_right->find(key);
        } else {
            return this;
        }
    }

    /*
     * inserts a new node into the tree,
     * overwrites the old node if it is already in the tree,
     * must be called from the root to work correct
     */
    void insert(const nsTree::KeyType& key, const nsTree::ValueType& value) {
        if(key < m_key) {
            if (m_left != 0) { return m_left->insert(key, value); }
            m_left = new TreeNode(this, key, value);
        } else if (key > m_key) {
            if (m_right != 0) { return m_right->insert(key, value); }
            m_right = new TreeNode(this, key, value);
        } else {
            m_key = key;
            m_value = value;
            return;
        }
    }

    /*
     * deletes the node and all subnodes from the tree
     */
    void deleteNode() {
        if (m_left != 0) { m_left->deleteNode(); }
        if (m_right != 0) { m_right->deleteNode(); }
        if (!isRoot()) {
            TreeNode* parentNode = m_up;
            if (isLeftChild()) {
                parentNode->m_left = 0;
            } else {
                parentNode->m_right = 0;
            }
        }
        delete this;
        return;
    }

    /*
     * deletes only this exact node, the childs stay untouched,
     * returns the node which will take its position, 0 if it had no childs
     */
    TreeNode* deleteNodeFromTree() {
        unsigned int childCount = 0;
        if (m_left != 0) { childCount++; }
        if (m_right != 0) { childCount++; }

        switch (childCount) {
        case 0:
            delete this;
            return 0;
        case 1:
            if (m_left != 0) {
                TreeNode* replacingNode = m_left;
                replacingNode->m_up = m_up;
                delete this;
                return replacingNode;
            } else {
                TreeNode* replacingNode = m_right;
                replacingNode->m_up = m_up;
                delete this;
                return replacingNode;
            }
        case 2:
            TreeNode* replacingNode = m_left->findLast();
            m_value = replacingNode->m_value;
            m_key = replacingNode->m_key;
            TreeNode* parent = replacingNode->m_up;
            if (replacingNode->isLeftChild()) {
                parent->setLeftNode(replacingNode->deleteNodeFromTree());
            } else {
                parent->setRightNode(replacingNode->deleteNodeFromTree());
            }
            return this;
        }
    }
};

/*
 ****************
 * TreeIterator *
 ****************
 */

/*
 * standard constructor
 */
TreeIterator::TreeIterator(TreeNode* node = 0)
    : m_currentNode(node)
{}

/*
 * copy constructor
 */
TreeIterator::TreeIterator(const TreeIterator& rhs)
    : m_currentNode(rhs.m_currentNode)
{}

/*
 * getter
 */
nsTree::ValueType& TreeIterator::value() { return m_currentNode->value(); }
nsTree::KeyType& TreeIterator::key() { return m_currentNode->key(); }

/*
 * operator overload
 */
TreeIterator& TreeIterator::operator=(const TreeIterator& rhs) {
    m_currentNode = rhs.m_currentNode;
    return *this;
}

bool TreeIterator::operator!=(const TreeIterator &rhs) { return !(*this == rhs); }

bool TreeIterator::operator==(const TreeIterator &rhs) {
    return m_currentNode->value() == rhs.m_currentNode->value() && m_currentNode->key() == rhs.m_currentNode->key();
}

TreeIterator TreeIterator::operator++(int) {
    TreeIterator temp = *this;
    m_currentNode = m_currentNode->findNext();
    return temp;
}

TreeIterator TreeIterator::operator--(int) {
    TreeIterator temp = *this;
    m_currentNode = m_currentNode->findPrevious();
    return temp;
}

TreeIterator& TreeIterator::operator++() {
    m_currentNode = m_currentNode->findNext();
    return *this;
}

TreeIterator& TreeIterator::operator--() {
    m_currentNode = m_currentNode->findPrevious();
    return *this;
}

/*
 ********
 * Tree *
 ********
 */

/*
 * standard constructor
 */
Tree::Tree()
    : m_root(0), m_count(0)
{}

/*
 * getter
 */
unsigned int Tree::count() const { return m_count; }

/*
 * operator overload
 */
nsTree::ValueType& Tree::operator[](const nsTree::KeyType& key) {
    if (contains(key) == 0) { m_root->insert(key, "CAUTION: INVALID INDEX IN OPERATOR [], NEW NODE CREATED"); }
    return m_root->find(key)->value();
}

/*
 * deletes a single node from the tree
 */
void Tree::deleteNode(const nsTree::KeyType& key) {
    TreeNode* node = m_root->find(key);
    if (node != 0) {
        m_count--;
        if (node->isRoot()) {
            m_root = node->deleteNodeFromTree();
        } else {
            TreeNode* parent = node->getParent();
            if (node->isLeftChild()) {
                parent->setLeftNode(node->deleteNodeFromTree());
            } else {
                parent->setRightNode(node->deleteNodeFromTree());
            }
        }
    }
    return;
}

/*
 * deletes all nodes in the tree
 */
void Tree::clear() {
    if (m_root == 0) { return; }
    m_root->deleteNode();
    m_root = 0;
    m_count = 0;
    return;
}

/*
 * returns true if the searched key is in the tree
 */
bool Tree::contains(const nsTree::KeyType& key) { return m_root != 0 && m_root->find(key) != 0; }

/*
 * inserts a new node into the tree
 */
void Tree::insert(const nsTree::KeyType &key, const nsTree::ValueType &value) {
    if (m_root == 0) {
        m_root = new TreeNode(0, key, value);
        m_count++;
    } else {
        if (contains(key) == false) { m_count++; }
        m_root->insert(key, value);
    }
    return;
}

/*
 * returns a new TreeIterator which "points" to the node with the lowest key of the tree
 */
TreeIterator Tree::first() { return TreeIterator(m_root->findFirst()); }

/*
 * returns a new TreeIterator which "points" to the node with the highest key of the tree
 */
TreeIterator Tree::last() { return TreeIterator(m_root->findLast()); }

/*
 * returns a new TreeIterator which "points" to a dummy node
 */
TreeIterator Tree::end() { return TreeIterator( m_root->createDummyNode() ); }

/*
 * returns a new TreeIterator which "points" to the searched node of the tree
 */
TreeIterator Tree::find(const nsTree::KeyType& key) { return TreeIterator(m_root->find(key)); }






























