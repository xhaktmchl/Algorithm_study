#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
/*
[알고리즘잡스 ch13 03 V] 깊이우선탐색과 너비우선탐색
풀이: 인접리스트 dfs, bfs 탐색 구현, 
시간복잡도: O(n+m)=  101000
*/

#define MAX 1010
int n,m;
vector<int> graph[MAX];
bool visit[MAX];

//dfs
void dfs(int node){
  //방문처리
  visit[node]=1;
  cout<<node<<" ";
  
  // 인접리스트 탐색
  // 방문 안했으면 재귀
  for(int i=0;i<graph[node].size();i++){
    int next = graph[node][i];
    if(visit[next]==0){
      dfs(next);
    }
  }
}

//bfs
void bfs(int node){
  // 큐 생성, 푸쉬, 방문처리
  queue<int> q;
  q.push(node); visit[node]=1;
  cout<<node<<" ";
  
  // bfs 시작
  while(!q.empty()){
    // 큐 팝 , 출력
    node = q.front();
    q.pop();
    
    // 인접리스트 탐색
    for(int i=0;i<graph[node].size();i++){
      int next=graph[node][i];
      if(visit[next]==0){// 방문 안했으면 방문 및 큐에 푸쉬
        q.push(next); visit[next]=1; 
        cout<<next<<" ";
      }
    }
  }
}



int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.그래프 인접리스트 입력
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  //작은 정점부터 출력하기 위한 정렬
  for(int i=0;i<n;i++){
    sort(graph[i].begin(),graph[i].end());
  }
  
  //2.DFS
  dfs(0);
  cout<<'\n';
  memset(visit,0,sizeof(visit)); // 방문배열 초기화
  //3.bfs
  bfs(0);
  return 0;
}
