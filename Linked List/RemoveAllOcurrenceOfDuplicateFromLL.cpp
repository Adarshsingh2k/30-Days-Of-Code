/*
Remove all occurences of duplicates in a linked list 
Medium Accuracy: 54.5% Submissions: 2073 Points: 4
Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list. 

Example 1:

Input: 
N = 8
Linked List = 23->28->28->35->49->49->53->53
Output: 
23 35
Explanation:
The duplicate numbers are 28, 49 and 53 which 
are removed from the list.
Example 2:

Input:
N = 6
Linked List = 11->11->11->11->75->75
Output: 
Empty list
Explanation:
All the nodes in the linked list have 
duplicates. Hence the resultant list 
would be empty.
Your task:
You don't have to read input or print anything. Your task is to complete the function removeAllDuplicates() which takes the head of the linked list, removes all the occurences of duplicates in the linked list and returns the head of the modified linked list.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
 
Constraints:
1 ≤ N ≤ 10^5
*/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

 // } Driver Code Ends
//User function Template for C++

/* Linked List node structure
    
struct Node {
	int data;
	struct Node *next;
};

*/

class Solution
{
    public:
    Node* removeAllDuplicates(struct Node* head)
    {
        //code here
        
        if(!head) return head;
         
        Node*store = new Node(0) ;
        store->next=head;
        
        Node * prev=store;
        //Node * current=head;
        
        while(head){
            while(head->next and head->data==head->next->data){
                head=head->next;
            }
            
            //  jab head mein duplictae ka last element hoga
            // aur prev bhi usko point krr raha hoga
            // increment prev
            if(prev->next==head) prev=prev->next;
            
            else {
                prev->next=head->next;
               
            }
            
             head=head->next;
        }
        
         return store->next;
         //return head;
    }
};

// { Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;


	while (T--)
	{
		int N;

		cin >> N ;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		Solution ob;
		head = ob.removeAllDuplicates(head);
		printList(head);

		cout << "\n";


	}
	return 0;
}
  // } Driver Code Ends