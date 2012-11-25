/*
 * testBinaryTree.cpp : C4J Aufgabe 2: binaryTree
 * Kai Mueller, Tim Jagodzinski
 */

#include <iostream>
#include <stdio.h>
#include "tree.h"

using namespace std;

int main()
{
    Tree* tree1 = new Tree();
    //std::cout << tree1->contains(50)<< endl;
    //std::cout << tree1->count()<< endl;
    //std::cout << tree1[0][80] << endl;
    //std::cout << tree1->end().value() << endl;
    //tree1->clear();
    tree1->insert(10,"aber");
    tree1->insert(13,"schon");
    tree1->insert(2,"hab");
    //std::cout << tree1->count()<< endl;
    //tree1->clear();
    //std::cout << tree1->count()<< endl;
    tree1->insert(12,"passt");
    tree1->insert(3,"keinen");
    tree1->insert(8,"gerade");
    tree1->insert(4,"Plan");
    tree1->insert(5,"was");
    tree1->insert(7,"hier");
    tree1->insert(9,"mache");
    tree1->insert(11,"das");
    tree1->insert(1,"ich");
    tree1->insert(6,"ich");
    tree1->deleteNode(6);
    //std::cout << "[6]:" << tree1[0][6] << endl;
    //std::cout << "[10]:" << tree1[0][10] << endl;
    //std::cout << "[80]:" << tree1[0][80] << endl;

    //std::cout << tree1->count()<< endl;
    //std::cout << tree1->contains(13)<< endl;
    //std::cout << tree1[0][13] << endl;

    std::cout << "Alles vorwaerts" << endl;
    for (TreeIterator i = tree1->first(); i != tree1->end(); i++) {
        std::cout << i.key() << ": " << i.value() << std::endl;
    }

    std::cout << "Alles rueckwaerts" << endl;
    for (TreeIterator i = tree1->last(); i != tree1->end(); i--) {
        std::cout << i.key() << ": " << i.value() << std::endl;
    }

    return 0;
}

