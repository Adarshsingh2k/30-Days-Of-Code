/*
895. Maximum Frequency Stack
Hard

2185

39

Add to List

Share
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
 

Example 1:

Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
 

Constraints:

0 <= val <= 109
At most 2 * 104 calls will be made to push and pop.
It is guaranteed that there will be at least one element in the stack before calling pop.
Accepted
79.7K
Submissions
124.4K

*/

class FreqStack {
public:
    
    // code flow
    // 1. maintain a hashmap for storing max frequency of each element
    // 2. maintain a hashmap of stacks and max frequency so tht when ever new max freq is found a new stack is ready
    // 3. push=> in push check wether current frequency is MAX or not if it is update MAxFreq and
    //      push the value in stack according to its frequency
    // 4. pop=> check the top most element  in accordance to stack with max frequency and pop it 
    //      also decrease the maxFrequency of the Popped Element
    
    // https://www.youtube.com/watch?v=KVg4Y0sI4Iw
    //https://leetcode.com/problems/maximum-frequency-stack/discuss/163410/C%2B%2BJavaPython-O(1)
    FreqStack() {
        
    }
    
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>m;
    
    int maxFreq=INT_MIN;
    
    void push(int val) {
        
        maxFreq=max(maxFreq,++freq[val]);
        m[freq[val]].push(val);
        
        
    }
    
    int pop() {
        
        int out=m[maxFreq].top();
        m[maxFreq].pop();
        
        if(m[freq[out]--].size()==NULL) maxFreq--;
        return out;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */