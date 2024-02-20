//***************************************************************************
//
// Jose Barron
// Z02013735
// Fall 2023 CSCI 340 - PE1 Data Struct Algorithm Analysis
// Assignment 07: This program is intended to implement the existing
// BinaryTree class using the provided "node.h" file to simulate a
// binary tree in the driver program found in the "binarytree.cc" file. 
// Due Date: 10/23/23
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//
//***************************************************************************

#ifndef H_BTREE
#define H_BTREE

#include "node.h"
#include <algorithm>


template <typename T> class BinaryTree{

public:
    BinaryTree(): root(nullptr) {} // default constructor
    unsigned int getSize() const { return _getSize(root); }  // returns size of tree
    unsigned int getHeight() const { return _getHeight(root); } // returns height of tree
    virtual void Insert(const T& x) { _Insert(root,x); }// inserts node in tree
    void Inorder(void (*p)(const T& x)) { _Inorder(root, p); } // inorder traversal of tree

protected:
    Node<T> *root; // root of tree

private:
    
    typedef enum {left_side, right_side } SIDE;

    SIDE rnd()
    { 
        return rand()%2 ? right_side : left_side;
    }// End of rnd()
    
    
    unsigned int _getSize(Node<T> *x) const    // private version of getSize()
    {
        if( x == nullptr) // Empty tree has no values
        {
            return 0;
        }
        int count = 1; // count is at 1 since it isnt a nullptr and it adds atleast one to the size
        int result_l = _getSize(x->left); // will return size of left child
        int result_r = _getSize(x->right); // will return size of right child

        count += result_l + result_r; // the resulting size of the left and right child
       
        return count;

    }               
    unsigned _getHeight(Node<T> *x) const // private version of getHeight()
    {
        if( x == nullptr )
        {
            return 1; // height of empty tree is one
        }
        int count = 1; // height is atleast one since node has atleast one child
        int result_l = _getHeight(x->left); // will return height of left child
        int result_r = _getHeight(x->right); // will return height of right child
        int result = std::max(result_l,result_r); // will choose the longest path 
                                                // between left and right child

        count += result;
        
        return count;
    }              
    
    void _Insert(Node<T> *& r, const T& x) // private version of Insert()
    {
        if( r == nullptr) // Tree is empty so the x becomes the new root
        {
            r = new Node<T>(x);
        }
        else
        {
            SIDE side = rnd(); // To randomly decide which subtree the value is inserted
            if ( side == left_side)
            {
                _Insert(r->left,x);
            }
            else
            {
                _Insert(r->right,x);
            }
        }
    }             
    void _Inorder(Node<T> *r, void (*p)(const T& x))   // private version of Inorder()
    {
        if ( r != nullptr) // If node is null then empty tree
        {
            _Inorder(r->left,p); // Visit Left Tree
            p(r->data); // Act on Node
            _Inorder(r->right, p); // Visit Right Tree 
        }
    }
};

#endif // End of H_BTREE
