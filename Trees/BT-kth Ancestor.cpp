/*

    Kth Ancestor in a Tree
Easy Accuracy: 39.56% Submissions: 9085 Points: 2
Given a binary tree of size  N, a node and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.


Example 1:



Input:
     K = 2
     Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.


Example 2:

Input:
k=1
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)



Constraints:
1<=N<=104
1<= K <= 100

*/


Node * kthAncestorutil(Node* root,int &k,int node,int &v)
{
    if(!root)
    return NULL;

    if(root->data==node || kthAncestorutil(root->left,k,node,v) || kthAncestorutil(root->right,k,node,v))
    {
        if(k>0)
        k=k-1;
        else if(k==0)
        {
            v=root->data;
            return NULL;
        }

        return root;
    }
}
int kthAncestor(Node *root, int k, int node)
{

 int v=0;
 Node *temp=kthAncestorutil(root,k,node,v);

 if(temp)
 return -1;

 return v;

}
