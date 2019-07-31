// Author: Cody Wright
// Lab: Lab 7
// Purpose: Implementation of new functions to Binary Search Tree ADT
// Data Structures: BinaryNode.h (Unchanged), bst.h (search tree header) , bst.cpp (search tree implementation)
// Date: 5/4/2018

/*----------------------
  Requirements Checklist
  ----------------------*/
// Added the required functions getHeight(), getNumberOfNodes(), getNumberofLeaves() and accompanying helper functions in bst.h && bst.cpp
// Also added Error messages if you try to add an existing number, or remove a number that's not in the tree
// Used the same input as stated in the example
// Removed 60 (top root), observed that the tree prioritized the most efficient or least required reorginization over trying to decrease the levels
// 2-Pt. Bonus : Built a balanced tree of 5 levels and then removed the top root, again, the program chose to bubble up the node that would cause the least amount
//       of rearrangement to the tree. (demo output in text file)
// Did not attempt "pretty tree" bonus

// Wasn't an explicit requirement but I also added in input validation so the program wouldn't crash if given invalid input

#include <iostream>
using namespace std;

#include "bst.h"

// Input Validation Function
template <typename T>
T get_input(const string &prompt, const string &errmsg, T min, T max)
{
  T value{};
  bool good_input{false};
  while(not good_input) {
    cout<<prompt;
    if (cin>>value and value>=min and value <= max) {
      good_input=true;
    }
    else {
      cout<<errmsg;
      cin.clear(); cin.ignore(INT_MAX, '\n');
    }
  }
  return value;
}

int main()
{
    // Testing Constructor and empty()
    BST<int> intBST;            // test the class constructor
    cout << "Constructing empty BST\n";
    cout << "BST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n";
    
    // Testing inorder
    cout << "\nInorder Traversal of BST: \n";
    intBST.inorder(cout);
    
    // Testing preorder
    cout << "\nPreorder Traversal of BST: \n";
    intBST.preorder(cout);
    
    // Testing postorder
    cout << "\nPostorder Traversal of BST: \n";
    intBST.postorder(cout);
    
    cout << "\nBST height is : " << intBST.getHeight();
    cout << "\nBST # of nodes is : " << intBST.getNumberOfNodes();
    cout << "\nBST # of leaves is : " << intBST.getNumberOfLeaves()<<endl;
        
    // Testing insert
    cout << "\nNow insert a bunch of integers into the BST."
    "\nTry items not in the BST and some that are in it:\n";
    int number;
    for (;;)
    {
        number = get_input("\nItem to insert (-999 to stop): ", "  Invalid Entry", -999, INT_MAX);
        if (number == -999) break;
        intBST.add(number);
        
        cout << "\nBST height is : " << intBST.getHeight();
        cout << "\nBST # of nodes is : " << intBST.getNumberOfNodes();
        cout << "\nBST # of leaves is : " << intBST.getNumberOfLeaves();
    }
    cout << "\n";
    intBST.graph(cout);
    
    cout << "\nBST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n";
    
    cout << "Inorder Traversal of BST: \n";
    intBST.inorder(cout);
    cout << endl;
    
    cout << "\nPreorder Traversal of BST: \n";
    intBST.preorder(cout);
    cout << endl;
    
    cout << "\nPostorder Traversal of BST: \n";
    intBST.postorder(cout);
    cout << endl;
    
    // Testing search()
    cout << "\n\nNow testing the contains() operation."
    "\nTry both items in the BST and some not in it:\n";
    for (;;)
    {
        number = get_input("\nItem to insert (-999 to stop): ", "  Invalid Entry", -999, INT_MAX);
        if (number == -999) break;
        cout << (intBST.contains(number) ? "Found" : "Not found") << endl;
    }
    
    // Testing remove()
    cout << "\nNow testing the remove() operation."
    "\nTry both items in the BST and some not in it:\n";
    for (;;)
    {
        number = get_input("\nItem to insert (-999 to stop): ", "  Invalid Entry", -999, INT_MAX);
        if (number == -999) break;
        intBST.remove(number);
        intBST.graph(cout);
    }
    cout << "\nInorder Traversal of BST: \n";
    intBST.inorder(cout);
    cout << endl;
    
    cout << "\nPreorder Traversal of BST: \n";
    intBST.preorder(cout);
    cout << endl;
    
    cout << "\nPostorder Traversal of BST: \n";
    intBST.postorder(cout);
    cout << endl;
    
    cout << "\nBST height is : " << intBST.getHeight();
    cout << "\nBST # of nodes is : " << intBST.getNumberOfNodes();
    cout << "\nBST # of leaves is : " << intBST.getNumberOfLeaves();

}
