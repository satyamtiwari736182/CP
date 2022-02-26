#include<bits/stdc++.h>
using namespace std;
#define N 8
int isSafe(int x,int y,int sol[N][N])
{
    return x>=0 && x<N && y>=0 && y<N && sol[x][y] == -1;
}
int solveKT_Util(int x,int y,int movei,int sol[N][N],int xmove[N],int ymove[N])
{
    int next_x,next_y;
    if(movei==N*N)
        return 1;
    for(int k=0;k<N;k++)
    {
        next_x = x + xmove[k];
        next_y = y + ymove[k];
        if(isSafe(next_x,next_y,sol))
        {
            sol[next_x][next_y] = movei;
            if(solveKT_Util(next_x,next_y,movei+1,sol,xmove,ymove))
                return 1;
            else 
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}
void solveKT()
{
    int sol[N][N];

    for(int x=0;x<N;x++)
        for(int y=0;y<N;y++)
            sol[x][y] = -1;

    int xmove[]={2,1,-1,-2,-2,-1,1,2},
        ymove[]={1,2,2,1,-1,-2,-2,-1};

        sol[0][0]=0;
        
        if(solveKT_Util(0,0,1,sol,xmove,ymove))
        {
            cout<<"\n\nSolution Exist\n\n";
            return;
        }
        cout<<"\n\nNO Solution Exist\n\n";
        return;
}
int main()
{
    solveKT();
    return 0;
}
