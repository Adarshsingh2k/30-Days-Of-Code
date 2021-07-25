/*
Segregate even and odd nodes in a Link List 
Easy Accuracy: 64.55% Submissions: 12780 Points: 2
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.


Example 1:

Input: 
N = 7
Link List = 
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 17,15,8,9 are odd so they appear 
first and 2,4,6 are the even numbers that appear later.

Example 2:

Input:
N = 4
Link List = 1 -> 3 -> 5 -> 7

Output: 1 3 5 7

Explaination: There is no even number. 
So ne need for modification.

Your Task:
You do not need to read input or print anything. Your task is to complete the function divide() which takes N and head of Link List as input parameters and returns the head of modified link list.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 10000 

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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        
      /*  Node * cur=head;
        Node*d=NULL;
        vector<int>v;
        vector<int>vi;
        while(cur){
            if(cur->data%2==0){
                int x=cur->data;
                
                v.push_back(x);
                
            }
            else{
                vi.push_back(cur->data);
            }
            
            cur=cur->next;
        }
        
       
        for(int i:v){
            cout<<i<<" ";
        }
        
        for(int i:vi){
            cout<<i<<" ";
        }
        
     
        
        return d;*/
        
        
        // By using linked list segreegation
        // we segrgate linked list to even and odd
        //and att end point evenTail to odd lists head
        
        
        Node * eHead=nullptr;
        Node * eTail=nullptr;
        Node * oHead=nullptr;
        Node * oTail=nullptr;
        
        Node * cur= head;
        
        if(!head) return NULL;
        
        while(cur){
            int x=cur->data;
            
            if(x%2==0){
                // agar even list khali hai toh
                // ussme node ko pint krrenge
                if(!eHead){
                    eHead=cur;
                    eTail=eHead;
                }
                // aur agar ek elemnt pele se hai
               else {
                    eTail->next=cur;
                    eTail=eTail->next;
                }
            }
            
            else{
                // same every thing for odd nodes
                if(!oHead){
                    oHead=cur;
                    oTail=oHead;
                }
                // aur agar ek elemnt pele se hai
                else{
                    oTail->next=cur;
                    oTail=oTail->next;
                }
            }
            
            cur=cur->next;
        }
        
        if(!oHead or !eHead){
            return head ;
        }
        
        // merging even and odd list
        
        
        eTail->next=oHead;
        oTail->next=NULL;
        
      
        return eHead;
        
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends