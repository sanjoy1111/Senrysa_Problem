#include<bits/stdc++.h>
using namespace std;
int a[4][3];
void board()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j]=0;
        }
    }
    a[3][0]=1;
    a[3][2]=1;
    
}
void solveCountEveryKey(int n, int i, int j, int &s)
{
    if(n==1)
    {
        s=1;
        return;
    }
    
    int l=0;
    int p=1;
    for(int x=1;x<=n;x++)
    p=p*x;
    if(i>0 && a[i-1][j]==0)
    {
        a[i-1][j]=1;
        s+=p;
    }
    if(j>0 && a[i][j-1]==0)
    {
        
        a[i][j-1]=1;
        s+=p;
    
    }
    if(i<3 && a[i+1][j]==0)
    {
        a[i+1][j]=1;
        s+=p;
    }
    if(j<2 && a[i][j+1]==0)
    {
        a[i][j+1]=1;
        s+=p;
    }
    
    
}
int main()
{
    int n;
    cin>>n;
    board();
    int s=0,c=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            //board();
            if(a[i][j]==0)
            {
                solveCountEveryKey(n,i,j,s);
                c+=s;
                
            }   
        }
    }
    cout<<c;
}