/*

Flatten binary tree to linked list 
Hard Accuracy: 81.5% Submissions: 1927 Points: 8
Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed. After flattening, left of each node should point to NULL and right should contain next node in preorder.

Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
Example 2:

Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5  
Explanation : 
After flattening, the tree looks 
like this 
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 3 4 2 5.
Your task:
You don't have to read input or print anything. Your task is to complete the function flatten() which takes the root of the tree and flattens the tree into a linkes list without using any auxiliary space.
Note : The driver code prints the inorder traversal of the flattened binary tree.
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
 
Constraints :
1<=n<=10^5

*/


// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        //BAse Case
        if(!root ) return;
        
        if(root->left){
            // flatten left subtree
            flatten(root->left);
            // stoe right sub tree in a temp so that we can 
            //  add left sub tree to right
            Node * storeRight= root->right;
            
            // add left sub treee to right
            root->right=root->left;
            // and now make left side of root as NULL kyunki kuch nahi hai wahan
            
            root->left=nullptr;
            
            // now we need to traverse to the tail element of right subtree
            // so we can add right sub tree to it
            
            Node * goTail=root->right;
            while(goTail->right){
                goTail=goTail->right;
            }
            // yahan pe hum apne left sub tree jo naya nay right bana hai
            // uske tail element mein already present right ko add krr rahe hain
            goTail->right =storeRight;
            
        }
        
        flatten(root->right);
        
    }
};

// { Driver Code Starts.
int main() {

    int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);
	
		Node *root = buildTree(str);
		Solution ob;
		ob.flatten(root);
		inorder(root);


		cout << "\n";
	}

	return 0;
}
  // } Driver Code Ends