/*
Add 1 to a number represented as linked list 
Easy Accuracy: 51.33% Submissions: 67322 Points: 2
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000

*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* rev(Node * head){
        Node * cur=head;
        Node *prev=nullptr;
        Node *next=nullptr;
        
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        head=rev(head);
        
        Node * temp=head;
        while(temp){
            // 1. Condition-> agar elemnt 9 hai aur woh null ko point krr raha hai 
            // Matlab Last element hai tab bas data ko 1 krdo aur list ke last mein 0 add krdo
            if(temp->next==NULL and temp->data==9){
                temp->data=1;
                Node *nu=new Node(0);
                nu->next=head;
                head=nu;
                temp=temp->next;
            }
            
            // 2. Condition-> agar elemnt 9 hai toh ussme 0 daaldo aur pointer ko uske aage baha do
            
            else if(temp->data==9){
                temp->data=0;
                temp=temp->next;
            }
            
            // 3. condition-> if element is not 9 toh ussme bas 1 add krdo
            else{
                temp->data=temp->data+1;
                temp=temp->next;
                break;
            }
        }
       
       
       head=rev(head);
       return head;
        
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends