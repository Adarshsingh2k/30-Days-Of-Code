/*

Duplicate subtree in Binary Tree 
Medium Accuracy: 44.66% Submissions: 17950 Points: 4
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5

Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
 

Example 2 :

Input : 
               1
             /   \ 
           2       3

Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only arguement and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.

Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.


Constraints:
1<=length of string<=100

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
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
	Node *root = new Node(stoi(ip[0]));

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

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

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
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

 // } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/

void in(Node * root, vector<int>&v){
     if(!root) return;
     in(root->left,v);
     v.push_back(root->data);
     in(root->right,v);
}

void traverse(Node * root, map<vector<int>,int>&mp){
    if(!root) return;
    
    vector<int>v;
    
    in(root,v);
    sort(v.begin(),v.end());
    
    mp[v]++;
    
    traverse(root->left,mp);
    traverse(root->right,mp);
    
}

bool dupSub(Node *root)
{
     //your code here
     
     map<vector<int>,int>mp;
     
     traverse(root,mp);
     
     int flag=0;
     
     for(auto i :mp){
         if(i.second>=2){
             flag++;
             //break;
         }
     }
     
     if(flag%3==0 and flag>1){
         return 1;
         
     }
     
     else return 0;
     
}

// { Driver Code Starts.
int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		//Solution ob;
		cout << dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends