#include <iostream>
#include <algorithm> //sort
#include <queue> 
#include <cstring>
/*
[알고리즘잡스 ch13 03 VO] 깊이우선탐색과 너비우선탐색
풀이: 인접리스트 dfs, bfs 탐색 구현, 
시간복잡도: O(n+m)=  101000
*/
using namespace std;

#define MAX 1010
int n,m;
vector<int> graph[MAX];
bool visit[MAX];

//2.0부터 dfs 탐색
// 방문처리, 출력
// 인접리스트 탐색
// 방문 안했으면 dfs재귀
void dfs(int node){
  visit[node]=1; 
  cout<<node<<" ";
  
  for(int i=0;i<graph[node].size();i++){
    int nextN = graph[node][i];
    if(visit[nextN]==0){
      dfs(nextN);
    }
  }
}

//3.0부터 bfs탐색
//큐 생성
// 큐 푸쉬, 방방문처리, 노드 출력
// bfs 시작
// 큐 프론트값 조회, 팝
// 인접 리스트 탐색
// 방문안했으면 큐 푸쉬, 방방문처리
void bfs(int node){
  queue<int> q;
  q.push(node); visit[node]=1;
  cout<<node<<" ";
  
  while(!q.empty()){
    node = q.front();
    q.pop();
    
    for(int i=0;i<graph[node].size();i++){
      int nextN = graph[node][i];
      if(visit[nextN]==0){
        q.push(nextN); visit[nextN]=1;
        cout<<nextN<<" ";
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);
  
  //1.그래프 인접리스트 입력
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  // 작은 정점부터 출력하기 위한 그래프 정렬
  for(int i=0;i<n;i++){
    sort(graph[i].begin(),graph[i].end());
  }
  //2.0부터 dfs 탐색
  dfs(0);
  // 방문배열 초기화
  memset(visit,0,sizeof(visit));
  cout<<'\n';
  //3.0부터 bfs탐색
  bfs(0);
  
  return 0;
}
