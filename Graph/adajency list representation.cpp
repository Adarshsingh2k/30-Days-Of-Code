#include <bits/stdc++.h>
using namespace std;

class graph{

    int v;
    // Array of list
    list<int >*l;

public:
    graph(int v){

        this->v=v;
        //list of lists
        l=new list<int>[v];
    }


    void addedge(int x,int y){

        l[x].push_back(y);
        l[y].push_back(x);

    }

    void print(){

        for(int i=0;i<v;i++){
            cout<<"Vertex of"<<i<<"->";
            for(int nbr:l[i]){

                cout<<nbr<<",";
            }cout<<endl;
        }


    }



};

int main(){
    graph g(4);

    g.addedge(0,2);
    g.addedge(0,4);
    g.addedge(2,3);
    g.addedge(1,3);
    g.print();

}
