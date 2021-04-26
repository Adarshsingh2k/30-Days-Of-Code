/*


    Given a binary tree of size N, your task is to complete the function printAllDups(), that finds and prints all duplicate subtrees from the given binary tree.
For each duplicate subtrees, you only need to print the root node value of any one of them.
Two trees are duplicate if they have the same structure with same node values.
Example:

Input :

Output :  and
Explanation: Above Trees are two duplicate subtrees.
Therefore, you need to return above trees root in the
form of a list.
Input:
The function takes a single argument as input, the reference pointer to the root node of the binary tree.
There will be T, test cases and for each test case the function will be called separately.

Output:
The function should print space separated root node value of all the duplicate subtrees. If no duplicate subtree is present in the binary tree print "-1 ".
Note: Need not print new line at the end.
Note: Print the nodes values in sorted order(ascending).

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
3
5
10 20 L 20 25 L 10 30 R 30 20 L 20 25 L
6
1 2 L 1 3 R 2 4 L 3 2 L 2 4 L 3 4 R
6
10 8 L 8 3 L 10 2 R 2 9 L 9 4 R 2 6 R
Output:
20 25
2 4
-1

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

*/

void inOrder(Node* root,vector<int> &v)
{
    if(root==NULL)
     return;

    inOrder(root->left,v);

    v.push_back(root->data);

    inOrder(root->right,v);
}
void traverse(Node* root,map<vector<int>,int> &mp)
{
    if(root==NULL)
      return;

    vector<int> v;
    inOrder(root,v);
    sort(v.begin(),v.end());
    mp[v]++;

    traverse(root->left,mp);

    traverse(root->right,mp);

}
void printAllDups(Node* root)
{
    // Code here
    map<vector<int>,int> mp;
    traverse(root,mp);
    int flag=0;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        if(i->second>1)
        {
            vector<int> v=i->first;
            cout<<v[0]<<" ";
            flag=1;
        }
    }
    if(flag==0)
     cout<<"-1"<<" ";
}
