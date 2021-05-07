/*
                *********       Job Sequencing Problem        *********

Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.


Example 1:

Input:
N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output:
2 60
Explanation:
2 jobs can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = (1,2,100)(2,1,19)(3,2,27)
(4,1,25)(5,1,15)
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an Integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 100000
1 <= Deadline <= 100
1 <= Profit <= 500




*/






// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};


 // } Driver Code Ends

bool comp( Job a, Job b){
        return (a.profit>b.profit);
    }

class Solution
{
    public:
    //Function to find the maximum profit and the number of jobs done.


    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr,arr+n,comp);

       /* vector<int>final;
        // create a slot array as int or boolean;
        int slot[n];

         for(int i=0;i<n;i++){
             slot[i]=0;
         }

        int count=0;
        int profit=0;

        for(int i=0;i<n;i++){

            //start from the job with max profit
            //and if a particular slot is free
            //add the profit and make the slot as booked

            for(int j=arr[i].dead-1;j>=0;j--){

                if(slot[j]==0){
                    count++;
                    profit+=arr[i].profit;
                    slot[j]=1;
                    break;
                }

            }



        }

        final.push_back(count);
        final.push_back(profit);

        return final;*/

        	int maxi = arr[0].dead;

    	for(int i=1;i<n;i++) {
    		maxi = max(maxi, arr[i].dead);
    	}

    	int slot[maxi+1];

    	for(int i=0;i<=maxi;i++) {
    		slot[i] = -1;
    	}

    	int countJobs = 0, jobProfit = 0;

    	for(int i=0;i<n;i++) {

    		for(int j=arr[i].dead; j>0;j--) {

    			if(slot[j] == -1) {
    				slot[j] = i;
    				countJobs++;
    				jobProfit += arr[i].profit;
    				break;
    			}
    		}
    	}
    	vector <int> ans;
    	ans.push_back(countJobs);
    	ans.push_back(jobProfit);
    	return ans;



    }
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    //testcases
    cin >> t;

    while(t--){
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0;
}


  // } Driver Code Ends
