/*
Leaves to DLL 
Medium Accuracy: 50.08% Submissions: 16249 Points: 4
Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List strating from the left most leaf. Modify the original tree to make the DLL thus removing the leaf nodes from the tree. Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.

Example 1:

Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    

Output: 
Modified Tree :
        1
      /   \
     2     3

Doubly Link List :
4 <-> 5 <-> 6 <-> 7

Explanation:
The leaf nodes are modified to form the DLL 
in-place. Thus their links are removed from 
the tree.
Example 2:

Input :
        1
      /   \
     2     3
    / \   
   4   5 

Output: 
Modified Tree :
        1
      /   
     2    

Doubly Link List :
4 <-> 5 <-> 3

Your Task:  
You dont need to read input or print anything. Complete the function convertToDLL() which takes root of the given tree as input parameter and returns the head of the doubly link list.

Note:
The generated output will contain the inorder traversal of the modified tree, the DLL from left to right and the DLL from right to left.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 10^4


*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
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
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inOrder(Node *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


 // } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
// return the head of the DLL and remove those node from the tree as well.

Node * convertUtil(Node *root, Node *&head,Node* &tail){
    
   
    
    if(!root) return NULL;
    
    // for leaf node
    if(!root->left and !root->right){

        // if there is no head i.e. its the first element
        // add root to it
        if(!head){
           head=root;
        }

        // else the left of root will be the tail and tail's right will be root

        else{
            root->left=tail;
            tail->right=root;
        }
        
        // att end new tail will be newly added root
        tail=root;

        // to remove leaf nodes from tree we return NULL
        return NULL;
        
    }
    root->left=convertUtil(root->left, head,tail);
    root->right=convertUtil(root->right, head,tail);
    return root;
    
}



Node * convertToDLL(Node *root){
    // add code here.
    Node * head=NULL;
    Node * tail=NULL;
    convertUtil(root,head,tail);
     
     return head;
    
    
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Node* head = convertToDLL(root);
        inOrder(root);
        cout << "\n";
        Node *curr = head, *last = head;
        while (curr) {
            cout << curr->data << " ";
            last = curr;
            curr = curr->right;
        }
        cout << "\n";
        curr = last;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->left;
        }
        cout << "\n";
    }
    return 0;
}

  // } Driver Code Ends