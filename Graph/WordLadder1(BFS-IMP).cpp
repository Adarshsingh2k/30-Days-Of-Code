/*
Word Ladder I 
Hard Accuracy: 41.66% Submissions: 6361 Points: 8
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
The second part of this problem can be found here.


Example 1:

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".
Example 2:

Input:
wordList = {"geek", "gefk"}
startWord = "gedk", targetWord= "geek", 
Output:
2
Explanation:
gedk -> geek
Example 3:

Input: 
wordList = {"poon", "plee", "same", "poie","plea","plie","poin"}
startWord = "toon", targetWord= "plea",
Output: 7 
Explanation:
toon -> poon -> poin -> poie -> plie -> plee -> plea 
 

Your Task:
You don't need to read or print anything, Your task is to complete the function wordLadderLength() which takes startWord, targetWord and wordList as input parameter and returns the length of the shortest transformation sequence from startWord to targetWord. If not possible return 0.


Expected Time Compelxity: O(N2 * M)
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|



*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        
        
        // code flow
        //  1. maintain a queue of worsds which are matching the words in aaray
        //  2. make a set of wordlist so that time complexity of traversal decreases
        //  3. now until queue is empty perform BFS
        //  4. for the first element of queue start checking the match according to conditions
        //  5. as we have to check smallest chain check by replacing each char of string 
        //     popped from queue and if a match is found in set push it in queue and 
        //     move on and increase the count of chain
        
        
        queue<string> q;
        q.push(startWord);
        
        int len=startWord.size();
        
        unordered_set<string>dict;
        for(int i=0;i<wordList.size();i++){
            dict.insert(wordList[i]);
        }
        
      //  if(word.find(targetWord)==word.end())return 0;
        
        int chain=1;
        
        while(!q.empty()){
            
            int n = q.size();
            for (int i = 0; i < n; i++) {
            
                string check=q.front();
                q.pop();
                
                if(check==targetWord) return chain;
                
                dict.erase(check);
                for(int j=0;j<check.size();j++){
                    char c= check[j];
                    
                    for(int k=0;k<26;k++){
                        check[j]='a'+k;
                        
                        if(dict.find(check)!=dict.end()){
                            q.push(check);
                        }
                        
                    }
                    check[j]=c;
                }
            
            }
            
            chain++;
        
 
        }
        
        return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends