#include<stdio.h>
#include<stdlib.h>
  int visited[5]={0,0,0,0,0};
   int a[5][5]={
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1}, 
    {1, 0, 0, 1, 0}, 
    {0, 1, 1, 0, 0}, 
    {0, 1, 0, 0, 0},
   };
void DFS(int i){
    printf("%d",i);
     visited[i]=1;
    for (int j =0;j<5; j++)
    {
        if(a[i][j]==1&&!visited[j]){
            DFS(j);
        }
    }
    
}
int main(){

    // dfs implimentation
 

DFS(1);
 
    return 0;
}
