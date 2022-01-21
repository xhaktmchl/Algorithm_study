#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch12 04 OO] 웜 바이러스
풀이: dfs
//1.그래프 인접리스트 입력
//2.1번에서 dfs
//3.감염 컴퓨터 수 출력
시간복잡도: O(V+E)= n+m = 약 200
*/

#define MAX 110
int n,m,cnt=0;
vector<int> graph[MAX];
bool visit[MAX];

//dfs
void dfs(int node){
  // 방문 처리
  visit[node]=1; cnt++; // 컴퓨터 카카운트
  
  // 인접 리스트 탐색
  for(int i=0;i<graph[node].size();i++){
    int nextN = graph[node][i];
    if(visit[nextN]==0){// 방문 안했으면
      dfs(nextN);
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
  //2.dfs 1번 노드부터 시작
  dfs(1);
  //dfs중 컴퓨터 카운트
  // 출력
  cout<<cnt-1<<'\n';
  return 0;
}
