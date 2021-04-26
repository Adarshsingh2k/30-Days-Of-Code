#include <bits/stdc++.h>
using namespace std;

class node{
public:

    int data;
    node *left;
    node *right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;


    }



};

class bst{
public:
    int size;
    int max;
    int min;
    int ans;
    bool isbst;


};


bst largestbst(node * root){
    // root is null and size is 0
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }

    // leaf node condition
    if(root->left== NULL and root->right ==NULL){
            return{1,root->data,root->data,1,true};


    }

    bst left=largestbst(root->left);
    bst right=largestbst(root->right);

    bst curr;

    curr.size=(1+left.size+right.size);

    if(left.isbst and right.isbst and left.max<root->data and right.min>root->data){

        curr.min=min(left.min ,min(right.min,root->data));
        curr.max=max(right.max ,max(left.max,root->data));

        curr.ans=curr.size;
        curr.isbst=true;


        return curr;


    }

    curr.ans=max(left.ans,right.ans);
    curr.isbst=false;

    return curr;


}



int main(){

    /*

       15
      /  \
      20  30
      /
      5

      */

      node *root=new node(24);
      root->left=new node(20);
      root->right=new node(30);
      root->left->left=new node(5);

      cout<<"largest BST in BT: "<<largestbst(root).ans<<endl;


}
/*

class bst
{
public:
bool isbst;
int size;
int leftmax;
int rightmin;
};

bst helper(Node*root)
{ bst p;
if(root==NULL)
{
p.isbst=true;
p.size=0;
p.leftmax=INT_MIN;
p.rightmin=INT_MAX;

return p;
}

bst left=helper(root->left);
bst right=helper(root->right);

if(root->data > left.leftmax && root->data < right.rightmin && left.isbst && right.isbst)
{
p.isbst=true;
p.size=left.size+right.size+1;
p.leftmax=max(left.leftmax,max(right.leftmax,root->data));
p.rightmin=min(right.rightmin,min(left.rightmin,root->data));

}
else
{
p.isbst=false;
p.size=max(left.size,right.size);

}
return p;
}
int largestBst(Node *root)
{
bst p=helper(root);
return p.size;
}

*/


/*

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

int largestBst(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s;
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends



/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method
// Return the size of the largest sub-tree which is also a BST
bool isBST(Node *root, int min, int max)
{
if(root == NULL)
return true;
if(root->data < min || root->data > max)
return false;
return (isBST(root->left, min, root->data -1) && (isBST(root->right, root->data+1, max)));
}
int postorder(Node *root, int &ans)
{
if(root == NULL)
return 0;
int ls = postorder(root->left, ans);
int rs = postorder(root->right, ans);
if(isBST(root, INT_MIN, INT_MAX)){
ans = max(ans, ls+rs+1);}
return ls+rs+1;
}
class bst
{
public:
bool isbst;
int size;
int leftmax;
int rightmin;
};

bst helper(Node*root)
{ bst p;
if(root==NULL)
{
p.isbst=true;
p.size=0;
p.leftmax=INT_MIN;
p.rightmin=INT_MAX;

return p;
}

bst left=helper(root->left);
bst right=helper(root->right);

if(root->data > left.leftmax && root->data < right.rightmin && left.isbst && right.isbst)
{
p.isbst=true;
p.size=left.size+right.size+1;
p.leftmax=max(left.leftmax,max(right.leftmax,root->data));
p.rightmin=min(right.rightmin,min(left.rightmin,root->data));

}
else
{
p.isbst=false;
p.size=max(left.size,right.size);

}
return p;
}
int largestBst(Node *root)
{
bst p=helper(root);
return p.size;
}

 */
