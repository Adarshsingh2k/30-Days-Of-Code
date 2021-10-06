/*
1019. Next Greater Node In Linked List
Medium

1709

85

Add to List

Share
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109
Accepted
85.7K
Submissions
144.7K
Seen this question in a real interview before?

Yes

No





*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        // make 1 out vector and a vector stack
        
        vector<int> out,stack;
        
       // now push all the elements of linked list in vector and treat is array for further operations
        
       for(auto i=head;i!=NULL;i=i->next) out.push_back(i->val);
        
       // now iterate vector from back
        
        for(int i=out.size()-1;i>=0;i--){
            // store the last element
            // also the next greater element for last element is =0
            // and before last element stack will be empty so we will push it in stack
            // after this while operation will be performed
            auto store=out[i];
            
            //we will check that if stack is not empty and the top most element is grater or less than current element
            // if its is smaller than current elemnt pop it from stack
            // kyunki humko bade element hi chahiye
            while(!stack.empty() and stack.back()<=out[i]) stack.pop_back();
            
            if(stack.empty()){
                out[i]=0;
            }
            
            // if stack is not empty push the last element to output
            else{
                out[i]=stack.back();
            }
            
            // now add the current elemnt to stack
            
            stack.push_back(store);
            
        }
        
        return out;
        
      
    }
};