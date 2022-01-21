#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch12 01 OO] 이분 그래프 판별
풀이: dfs
// 그래프 인접리스트 입력
// 2.dfs 시작, 이분 그래프인지 탐색
시간복잡도: O(n+m) = 1000+100000 = 101000
*/

#define MAX 1010
int n,m;
vector<int> graph[MAX];
bool visit[MAX];
int group[MAX];
bool flag=1;

//dfs
void dfs(int node,int curGroup){
  // 방문처리, 그룹 저장
  visit[node]=1; group[node]=curGroup;
  
  // 인접 리스트 완전탐색
  for(int i=0;i<graph[node].size();i++){
    int nextN = graph[node][i];
    if(visit[nextN]==0){// 방문안했으먄 , 
      dfs(nextN,(curGroup+1)%2);
    }
    else {// 방문했으고 인접 리스트의 그룹이 같으면 이분 그래프 아님
      if(curGroup == group[nextN]){
        flag=0;
      }
    }
  }
  
  
  
}
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 1.그래프 인접리스트 입력
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  // 2.1번 노드에서 dfs시작
  dfs(1,0);
  
  // 
  // 3.출력: 이분 그래프인지 아닌지
  if(flag == 1){
    cout<<"Yes"<<'\n';
  }
  else{ cout<<"No"<<'\n';}
  return 0;
}
