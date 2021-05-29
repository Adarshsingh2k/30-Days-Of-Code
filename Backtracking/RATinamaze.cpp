#include<iostream>
using namespace std;
bool ratmaze(char maze[1000][1000],int solution[1000][1000],int i,int j,int n,int m)
{
    int count=0;
  if(i==n && j==m)
  { count++;
    solution[m][n]=1;
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=m;j++)
      {
        cout<<solution[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
    return true;
  }//cout<<count;
  if(i>n || j>m)
  {
    return false;
  }
  if(maze[i][j]=='X')
  {
    return false;
  }
  solution[i][j]=1;
  bool rightSuccess=ratmaze(maze,solution,i,j+1,n,m);
  bool downSuccess=ratmaze(maze,solution,i+1,j,n,m);

   //and to backtrack from final pt we make slon array elements as 0

  solution[i][j]=0;
  if(rightSuccess || downSuccess)
  {
    return true;
  }
  return false;

}
int main()
{
	int n,m;
	cout<<"enter size of array"<<endl;
	cin>>n>>m;
	cout<<"enter the maze"<<endl;
	char maze[1000][1000];
	int solution[1000][1000]={0};
	for(int i=0;i<n;i++)
	{
	  for(int j=0;j<m;j++)
	  {
	    cin>>maze[i][j];
	  }
	}
	bool y=ratmaze(maze,solution,0,0,n-1,m-1);
	if(y==0)
	{
	  cout<<"-1";
	}
	return 0;
}
