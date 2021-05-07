
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;

        int x=a;
        int y=a*b;
        int z=x+y;

        if(z==x+y){
            cout<<"YES"<<endl;
            cout<<x<<" "<<y<<" "<<z;
        }
        else {
            cout<<"NO";
        }

    }

    cout<<endl;

}
