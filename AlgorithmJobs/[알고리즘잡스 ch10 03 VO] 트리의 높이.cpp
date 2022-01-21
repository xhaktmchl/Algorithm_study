#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch10 03 VO] 트리의 높이
풀이: 트리의 높이 구하기 ->dfs 로 탐색하며 최대높이 저장 
시간복잡도: O(n+m)= 100+99
*/
#define MAX 110
int n,r,maxH=0;
vector<int> graph[MAX];
bool visit[MAX];

//dfs
void dfs(int node,int height){
  // 방문처리, 높이 최댁값 비교
  visit[node]=1; 
  maxH = max(maxH,height);
  
  // 인접리스트 탐색
  for(int i=0;i<graph[node].size();i++){
    int nextN = graph[node][i];
    // 방문안했으면 
    if(visit[nextN]==0){
      dfs(nextN,height+1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.트리 그래프 인접리스트 입력
  cin>>n>>r;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  //2.루트노드부터 dfs
  dfs(r,0);
  //3.출력 높이
  cout<<maxH<<'\n';
  return 0;
}
