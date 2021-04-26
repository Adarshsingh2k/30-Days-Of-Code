/*

    Leaf at same level
Easy Accuracy: 49.76% Submissions: 14828 Points: 2
Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input:
            1
          /   \
         2     3

Output: 1

Explanation:
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.

Your Task:
You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns true/false depending on whether all the leaf nodes are at the same level or not.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 10^3
*/

bool check(Node *root)
{
    //Your code here
    queue<Node*>q;
    q.push(root);
    int res=-1;
    int level=0;
    int size;
    int i;
    Node*t;
    while(!q.empty())
    {
        level=level+1;
        size=q.size();
        for(i=0;i<size;i++)
        {
           t=q.front();
           q.pop();
           if(t->left)
           q.push(t->left);
           if(t->right)
           q.push(t->right);


           if(!t->right && !t->left)
           {
               if(res==-1)
               res=level;
               else
               {
                   if(res!=level)
                   return false;
               }
           }}
        }
        return true;


}

// <<<<<<<< OR >>>>>>>>

// C++ program to check if all leaves
// are at same level
#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to allocate
// a new tree node
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

/* Recursive function which checks whether
all leaves are at same level */
bool checkUtil(struct Node *root,
			int level, int *leafLevel)
{
	// Base case
	if (root == NULL) return true;

	// If a leaf node is encountered
	if (root->left == NULL &&
		root->right == NULL)
	{
		// When a leaf node is found
		// first time
		if (*leafLevel == 0)
		{
			*leafLevel = level; // Set first found leaf's level
			return true;
		}

		// If this is not first leaf node, compare
		// its level with first leaf's level
		return (level == *leafLevel);
	}

	// If this node is not leaf, recursively
	// check left and right subtrees
	return checkUtil(root->left, level + 1, leafLevel) &&
			checkUtil(root->right, level + 1, leafLevel);
}

/* The main function to check
if all leafs are at same level.
It mainly uses checkUtil() */
bool check(struct Node *root)
{
	int level = 0, leafLevel = 0;
	return checkUtil(root, level, &leafLevel);
}

// Driver Code
int main()
{
	// Let us create tree shown in third example
	struct Node *root = newNode(12);
	root->left = newNode(5);
	root->left->left = newNode(3);
	root->left->right = newNode(9);
	root->left->left->left = newNode(1);
	root->left->right->left = newNode(1);
	if (check(root))
		cout << "Leaves are at same level\n";
	else
		cout << "Leaves are not at same level\n";
	getchar();
	return 0;
}

// This code is contributed
// by Akanksha Rai
