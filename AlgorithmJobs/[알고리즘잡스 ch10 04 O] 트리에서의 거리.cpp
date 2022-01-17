#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[알고리즘잡스 ch10 04 O] 트리에서의 거리
풀이: 트리 노드 사이의 거리 구하기 -> 트리 dfs 탐색
시간복잡도: O(n*n) = 100만????
*/
#define MAX 1010
int n,x,y,a,b;
vector<vector<int>> v(MAX,vector<int>());
bool visit[MAX];

void dfs(int node,int cnt){
  // 방문처리
  visit[node]=1;
  // 기저사례: 목적노드이면 거리 출력
  if(node == y){
    cout<<cnt<<'\n';
    return;
  }
  
  // 인접노드 탐색 재귀
  for(int i=0;i<v[node].size();i++){
    if(visit[v[node][i]]==1){ continue;}
    dfs(v[node][i],cnt+1);
  }
}


int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 1.트리 이차배열 입력
  cin>>n>>x>>y;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  // 2.시작 노드부터 목적노드까지 dfs로 탐색 및 거리 카운트
  dfs(x,0);
  // 3. 거리 출력
  return 0;
}
