#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printIn(node*root){
    if(root==NULL){
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node*root){
    if(root==NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

void printklevel(node*root,int k){
    if (root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printklevel(root->left,k-1);
    printklevel(root->right,k-1);
}
int height(node*root){
    if(root==NULL){
        return 0;
    }

    int ls=height(root->left);
    int rs=height(root->right);

    return max(ls,rs)+1;
}

int diameter(node * root){

    if(root==NULL){
        return 0;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    int ld=diameter(root->left);
    int rd=diameter(root->right);

    return max(lh+rh+1,max(ld,rd));

}

void printalllevels(node*root){
    int h=height(root);

    //reverse level order print

    /*for(int i=h;i>=0;i--){
        printklevel(root,i);
        cout<<endl;
    }*/

    // level order print
    for(int i=1; i<=h;i++){
        printklevel(root,i);
        cout<<endl;
    }

    return;
}

void bfs(node*root){

    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*element=q.front();
        cout<<element->data<<",";
        q.pop();

        if(element->left){
            q.push(element->left);
        }

        if(element->right){
            q.push(element->right);
        }
    }

    return;

}

int main(){
    node* root = buildTree();
    /*print(root);
    cout<<endl;

    printIn(root);
    cout<<endl;
    printPost(root);*/
    printalllevels(root);
    cout<<endl;
    cout<<"BFS Traversal"<<endl;

    bfs(root);

    cout<<endl<<"Diameter of tree is="<<diameter(root)<<endl;



return 0;
}











