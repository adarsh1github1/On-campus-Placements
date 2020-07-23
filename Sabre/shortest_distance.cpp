#include<bits/stdc++.h>
using namespace std;
#define N 4
#define M 4
class gvar{
    public:
    int row,col,dist;
    gvar(int x,int y,int z){
        row = x;
        col = y;
        dist = z;
    }
};

int mindistance(char grid[N][M]){
    gvar source(0,0,0);
    bool visited[N][M];
    for(int i=0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(grid[i][j] == '0'){
                visited[i][j] = true;
            }
            else {
                visited[i][j] = false;
            }
            if(grid[i][j] == 'S'){
                source.row = i;
                source.col = j;
            }
        }
    }
    queue<gvar> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty())
    {
        gvar temp = q.front();
        q.pop();
        // destination found
        if(grid[temp.row][temp.col] == 'd'){
            return temp.dist;
        }
        // up
        if(temp.row - 1 >= 0 && !visited[temp.row-1][temp.col]){
            q.push(gvar(temp.row-1,temp.col,temp.dist +1));
            visited[temp.row-1][temp.col] = true;
        }
        // down
        if(temp.row + 1 <N && !visited[temp.row+1][temp.col]){
            q.push(gvar(temp.row+1,temp.col,temp.dist +1));
            visited[temp.row+1][temp.col] = true;
        }
        // left
        if(temp.col-1 >= 0 && !visited[temp.row][temp.col-1]){
            q.push(gvar(temp.row,temp.col-1,temp.dist +1));
            visited[temp.row][temp.col-1] = true;
        }
        // right
        if(temp.col+1 < M && !visited[temp.row][temp.col+1]){
            q.push(gvar(temp.row,temp.col+1,temp.dist +1));
            visited[temp.row][temp.col+1] = true;
        }
    }
    return -1;
}

int main(){
    char grid[N][M];
    for(int i=0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin>>grid[i][j];
        }
    }
    cout<<mindistance(grid);
    return 0;
}