/*
Add two numbers represented by linked lists 
Easy Accuracy: 30.12% Submissions: 100k+ Points: 2
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000

Company Tags
Topic Tags
Related Courses

*/

// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    Node * rev(Node * head){
        Node * prev=NULL;
        Node* revNext;
        
        while(head){
            revNext=head->next;
            head->next=prev;
            prev=head;
            head=revNext;
        }
        
        head=prev;
        return head;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=rev(first);
        second= rev(second);
        int carry=0;
        int sum=0;
        
        Node*resL=NULL;
        Node*cur=NULL;
        Node *temp;
        
        
        while(first or second){
            sum=carry+(first?first->data:0)+(second?second->data:0);
            // sum>10 hoga tabhi caary hoga nahi toh carry 0
            carry=(sum>=10)?1:0;
            
            sum=sum%10;
            temp=new Node(sum);
            
            // if we ad node for the first time in result 
            // list then it will be equal to temp
            if(!resL) resL=temp;
            
            // cur is used to iterate through result list
            // so if there is elemnt in LL cur which was NULL 
            // its next will point temp i.e. new node
            //and now cur will be updated to temp
            else cur->next=temp;
            cur=temp;
            if(first) first=first->next;
            if(second) second= second->next;
        }
        // this  if will be executed int the case there is anyy carry left 
        // for ex
        //cary 1 1
        //       9 9
        //       + 1
        //    =1 0 0
        if(carry>0){
            
            temp=new Node(carry);
            cur->next=temp;
            cur=temp;
            
            
        }
        
        resL=rev(resL);
        return resL;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends