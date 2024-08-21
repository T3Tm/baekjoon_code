/* Online C++ Compiler and Editor */
#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
   int v,e;cin >> v >> e;
   int graph[402][402];
   memset(graph, 0x3f, sizeof graph);
   
   for(int i=0;i<e;i++){
       int a,b,c;cin >> a >> b >>c;
       graph[a][b] = c;
   }
   
   for(int k = 1; k<=v;k++){
       for(int i=1;i<=v;i++){
           for(int j=1;j<=v;j++){
               if(i == j)continue;
               if(graph[i][j] > graph[i][k] + graph[k][j]){
                   graph[i][j] = graph[i][k] + graph[k][j];
               }
           }
       }
   }
   int result{INF};
   for(int i=1;i<=v;i++){
       for(int j=1;j<=v;j++){
           if(i == j)continue;
           if(graph[i][j] + graph[j][i] < result){
               result = graph[i][j] + graph[j][i];
           }
       }
   }
   cout << (result == INF ? -1 : result);
       
   return 0;
}