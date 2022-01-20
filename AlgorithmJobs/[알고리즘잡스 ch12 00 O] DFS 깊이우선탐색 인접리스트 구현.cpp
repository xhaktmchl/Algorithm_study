#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch12 00 O] DFS 깊이우선탐색 인접리스트 구현
풀이: 
시간복잡도: 
*/
#define MAX 110
bool visit[MAX];
vector<int> graph[MAX]; 

void dfs(int node){
  visit[node] = 1; // 방문 표시
  cout<<node<<" ";
  
  // 인접 리스트 탐색
  for(int i=0;i<graph[node].size();i++){
    int nextNode = graph[node][i];
    if(visit[nextNode] == 0){ // 방문 안한 노드만 탐색
      dfs(nextNode);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  // 그래프 인접리스트 연결
  graph[1].push_back(2);
  graph[1].push_back(3);
  graph[2].push_back(1);
  graph[2].push_back(3);
  graph[2].push_back(4);
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
  
  // dfs
  // 1 2 3 7 4 5 6 8 9  순으로 탐색
  dfs(1);
  return 0;
}
