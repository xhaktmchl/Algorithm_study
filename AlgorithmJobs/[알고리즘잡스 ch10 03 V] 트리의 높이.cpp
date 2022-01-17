#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[알고리즘잡스 ch10 03 V] 트리의 높이
풀이: 트리의 높이 구하기 ->dfs 로 탐색하며 최대높이 저장 
시간복잡도: O(n)= 100
*/
#define MAX 110
int n,root,a,b,maxHeight=0;
vector<vector<int>> v(MAX,vector<int>());
bool visit[MAX];

void dfs(int node,int height){
  visit[node]=1; // 방문처리
  // 최대높이 저장
  maxHeight = max(maxHeight,height);
  
  // 탐색 재귀
  for(int i=0;i<v[node].size();i++){
    if(visit[v[node][i]] == 1){continue;} // 방문 예외처리
    dfs(v[node][i],height+1);
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 트리 입력
  cin>>n>>root;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  // 전위순회 -> 트리 높이 탐색
  dfs(root,0);
  // 출력
  cout<<maxHeight<<'\n';
  return 0;
}
