/*
Given a Binary Tree, the task is to print all the root to leaf path sum of the given Binary Tree.

Examples: 

Input:
                 30
              /      \
            10        50
           /  \      /  \
          3   16   40    60
Output: 43 56 120 140
Explanation:
In the above binary tree
there are 4 leaf nodes. 
Hence, total 4 path sum are
present from root node to the
leaf node. 
(i.e., 30-10-3, 30-10-16,
       30-50-40, 30-50-60) 
Therefore, the path sums from
left to right would be
(43, 56, 120, 140).

Input:
                 11
              /      \
            12        5
              \      /  
              16   40
Output: 39 56
Explanation:
In the above binary tree
there are 2 leaf nodes. 
Hence, total 2 path sum are
present from root node to
the leaf node.
(i.e 11-12-16, 11-5-40) 
Therefore, the path sums from
left to right would be (39 56).

*/

#include <bits/stdc++.h>
using namespace std;

class node{

public:
	int data;
	node * left;
	node * right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;

	}

};

void getPath(node * root,int sum,vector<int >& pathSum){

	if(!root) return;

	// for each root add its value to sum
	sum+=root->data;

	// if we reach to leaf node push sum into vector
	if(root->left==NULL and root->right ==NULL){
		pathSum.push_back(sum);
		return;
	}

	//do dfs to left and right
	getPath(root->left,sum,pathSum);
	getPath(root->right,sum,pathSum);

	
}


int main(){
	node * root=new node(30);
	root->left=new node(10);
	root->right=new node(50);
	root->left->left = new node(3);
    root->left->right = new node(16);
    root->right->left = new node(40);
    root->right->right = new node(60);

	int sum=0;

	vector<int>pathSum;



	getPath(root,sum,pathSum);

	for(int i:pathSum){
		cout<<i<<"->"<<" ";
	}

}
