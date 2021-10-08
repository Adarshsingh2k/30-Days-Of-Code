class Solution {
public:
    int integerReplacement(long long int n) {
        
        if(n==0) return 1;
        
        if(n==1) return 0;
        
        long long int count=0;
        
        while(n!=1){
            if(n%2==0) {
                n=n/2;
               
            }
            else{
                if(n==3) n=2;
                
                else if((n+1)%4==0) n=n+1;
                
                else n=n-1;
                
            }
            
            count++;
            
        }
        
        return count;
        
    }
};