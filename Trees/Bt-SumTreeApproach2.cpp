/*
Sum Tree 
Medium Accuracy: 33.33% Submissions: 86540 Points: 4
Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return 0.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

 

Example 1:

Input:
    3
  /   \    
 1     2

Output: 1
Explanation: The sum of left subtree and right subtree
is 1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.

Example 2:

Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation: The given tree is not a sum
tree. For the root node, sum of elements
in left subtree is 40 and sum of elements
in right subtree is 30. Root element = 10
which is not equal to 30+40.

Your Task: 
You dont need to read input or print anything. Complete the function isSumTree() which takes root node as input parameter and returns true if the tree is a SumTree else it returns false.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the Tree)


Constraints:
1 ≤ number of nodes ≤ 104

 

Company Tags
Topic Tags
Related Courses

*/

// C++ program to check if Binary tree
// is sum tree or not
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, 
   left child and right child */
struct node
{
    int data;
    node* left;
    node* right;
};

/* Utillity function to check if 
the given node is leaf or not */
int isLeaf(node *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

/* returns 1 if SumTree property holds for the given
    tree */
int isSumTree(node* node)
{
    int ls; // for sum of nodes in left subtree
    int rs; // for sum of nodes in right subtree

    /* If node is NULL or it's a leaf node then
       return true */
    if(node == NULL || isLeaf(node))
        return 1;

    if( isSumTree(node->left) && isSumTree(node->right))
    {
      
        // Get the sum of nodes in left subtree
        if(node->left == NULL)
            ls = 0;
        else if(isLeaf(node->left))
            ls = node->left->data;
        else
            ls = 2 * (node->left->data);

        // Get the sum of nodes in right subtree
        if(node->right == NULL)
            rs = 0;
        else if(isLeaf(node->right))
            rs = node->right->data;
        else
            rs = 2 * (node->right->data);

        /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
        return(node->data == ls + rs);
    }
    return 0;
}

/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers.
*/
node* newNode(int data)
{
    node* node1 = new node();
    node1->data = data;
    node1->left = NULL;
    node1->right = NULL;
    return(node1);
}

/* Driver code */
int main()
{
    node *root  = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
    return 0;
}

// This code is contributed by rutvik_56