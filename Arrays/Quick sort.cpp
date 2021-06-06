/**
 * Quick Sort 
Medium Accuracy: 46.8% Submissions: 54293 Points: 4
Quick Sort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position low and its ending position high.

Implement the partition() and quickSort() functions to sort the array.


Example 1:

Input: 
N = 5 
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9
Example 2:

Input: 
N = 9
arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7}
Output:
1 1 2 3 4 6 7 9 10

Your Task: 
You don't need to read input or print anything. Your task is to complete the functions partition()  and quickSort() which takes the array arr[], low and high as input parameters and partitions the array. Consider the last element as the pivot such that all the elements less than(or equal to) the pivot lie before it and the elements greater than it lie after the pivot.


Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 103
1 <= arr[i] <= 104

Company Tags
Topic Tags
Related Courses
Related Interview Experiences
 * */

// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    //void swap(a)
    
    void quickSort(int arr[], int low, int high)
    {
        // code here
        
        if(low<high){
         int p=partition(arr,low,high);
         
         //abb lagega divide and conquer
         
         // first half will be pivot-1
         quickSort(arr,low,p-1);
         
         // 2nd half hoga pivot +1 se leke uske end tak
         
         quickSort(arr,p+1,high);
            
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       
       int pivot=arr[high];
       
       int i=low-1;
       for(int j=low;j<high;j++){
           if(arr[j]<pivot){
               i++;
               swap(arr[i],arr[j]);
           }
           
       }
       
       swap(arr[i+1],arr[high]);
       
       return(i+1);
    }
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends