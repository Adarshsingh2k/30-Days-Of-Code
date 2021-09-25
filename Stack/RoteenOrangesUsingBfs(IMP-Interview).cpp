// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        // 1. Make a queue to stor the index of all rotten orange at
        //    1st iteration
        // 2. After that check wether the next element in any of 4 direction is 1
        // 3. if its make it 2 anf push to queue
        // 4. after every iteration push (-1,-1) as delimiter for next iteration and
        //    and remove the previous rottten orange from queue
        // 5. At lastcheck is there any element still left unrotted
        
        
        queue< pair<int,int> > q;
        int r=grid.size();
        int c=grid[0].size();
        
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int count=0;
        
        // push [-1,-1] as delimiter
        
        q.push({-1,-1});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            if(i==-1 and j==-1 and q.size()==1){
                q.pop();
                break;
            }
            
            else if(i==-1 and j==-1 and q.size()>1){
                count++;
                q.pop();
                q.push({-1,-1});
            }
            else{
                if((i-1)>=0 and grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                 if((j-1)>=0 and grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                 if((i+1)<r and grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if((j+1)<c and grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                
                q.pop(); 
            }
            
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        
        
        return count;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends