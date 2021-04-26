/*
    Print all k-sum paths in a binary tree
Difficulty Level : Hard
 Last Updated : 02 Nov, 2020
A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k.
A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.

Examples:

Input : k = 5
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5
        /   / \     \
       1   1   2     6

Output :
3 2
3 1 1
1 3 1
4 1
1 -1 4 1
-1 4 2
5
1 -1 5
Source : Amazon Interview Experience Set-323

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
Kindly note that this problem is significantly different from finding k-sum path from root to leaves. Here each node can be treated as root, hence the path can start and end at any node.

The basic idea to solve the problem is to do a preorder traversal of the given tree. We also need a container (vector) to keep track of the path that led to that node. At each node we check if there are any path that sums to k, if any we print the path and proceed recursively to print each path.




Below is the implementation of the same.
filter_none
edit
play_arrow

brightness_4
// C++ program to print all paths with sum k.
#include <bits/stdc++.h>
using namespace std;

//utility function to print contents of
//a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
    for (int j=i; j<v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

// binary tree node
struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// This function prints all paths that have sum k
void printKPathUtil(Node *root, vector<int>& path,
                                           int k)
{
    // empty node
    if (!root)
        return;

    // add current node to the path
    path.push_back(root->data);

    // check if there's any k sum path
    // in the left sub-tree.
    printKPathUtil(root->left, path, k);

    // check if there's any k sum path
    // in the right sub-tree.
    printKPathUtil(root->right, path, k);

    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too
    int f = 0;
    for (int j=path.size()-1; j>=0; j--)
    {
        f += path[j];

        // If path sum is k, print the path
        if (f == k)
            printVector(path, j);
    }

    // Remove the current element from the path
    path.pop_back();
}

// A wrapper over printKPathUtil()
void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}

// Driver code
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printKPath(root, k);

    return 0;
}


Output:
3 2
3 1 1
1 3 1
4 1
1 -1 4 1
-1 4 2
5
1 -1 5

*/
#include <bits/stdc++.h>
using namespace std;

class Node{

public:
    int data;
    Node*left;
    Node*right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};

Node* build(){

    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    Node*root=new Node(d);

    root->left=build();
    root->right=build();

}

void printkpath(Node*root, vector<int>&path,int k){

    if(!root){
        return;
    }

    path.push_back(root->data);
    printkpath(root->left,path,k);
    printkpath(root->right,path,k);

    int sum=0;

    for(int i=path.size()-1;i>=0;i--){

        sum+=path[i];

        if(sum==k){
            for(int i=0;i<path.size();i++){
                cout<<path[i]<<" "<<endl;
            }
        }
    }

    path.pop_back();

}

int main(){

    Node*root=build();

    vector<int>path;

    printkpath(root,path,5);

}
