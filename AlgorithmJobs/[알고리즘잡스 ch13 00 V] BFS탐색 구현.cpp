#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
[알고리즘잡스 ch13 00 V] BFS탐색 구현
풀이: 
시간복잡도: O()= 
*/

#define MAX 100
vector<int> graph[MAX];
queue<int> q;
bool visit[MAX];

void bfs(int node){
  q.push(node); visit[node]=1; // 처음 큐에 푸쉬 및 방문

  while(!q.empty()){
    node = q.front();
    cout<<node<<'\n';
    q.pop();
    //인접리스트 탐색
    for(int i=0;i<graph[node].size();i++){
      int nextN = graph[node][i];
      if(visit[nextN] ==0){
        visit[nextN]=1;
        q.push(nextN);
      }
    }
    
  }
  
}

int main() {
  
  // 그래프 입력
  graph[1].push_back(2);
  graph[1].push_back(3);
  
  graph[2].push_back(1);
  graph[2].push_back(3);
  graph[2].push_back(6);
  
  graph[3].push_back(1);
  graph[3].push_back(2);
  graph[3].push_back(7);
  
  graph[4].push_back(2);
  graph[4].push_back(5);
  graph[4].push_back(7);
  graph[4].push_back(8);
  
  graph[5].push_back(4);
  graph[5].push_back(6);
  
  graph[6].push_back(2);
  graph[6].push_back(5);
  
  graph[7].push_back(3);
  graph[7].push_back(4);
  graph[7].push_back(8);
  
  graph[8].push_back(4);
  graph[8].push_back(7);
  graph[8].push_back(9);
  
  graph[9].push_back(8);
  
  //bfs
  bfs(1);
  return 0;
}
