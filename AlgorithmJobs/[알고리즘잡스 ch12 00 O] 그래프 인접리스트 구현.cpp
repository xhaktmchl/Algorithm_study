#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
[알고리즘잡스 ch12 00 O] 그래프 인접리스트 구현
풀이: 
시간복잡도: 
*/
#define MAX 100+5
vector<int> graph[MAX]; // 인접 리스트
int n,m;

int isConnected(int a,int b){
  for(int i=0;i<graph[a].size();i++){
    if(graph[a][i] == b){
      return 1;
    }
  }
  return 0;
}

void adj(int node){
  for(int i=0;i<graph[node].size();i++){
    cout<<graph[node][i]<<" ";
  }cout<<'\n';
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n>>m;
  /*for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a][b]=1; // 양방향 그래프
    graph[b][a]=1;
  }*/
  graph[1].push_back(2); // 양방향 그래프
  graph[2].push_back(1);
  graph[1].push_back(3);
  graph[3].push_back(1);
  graph[2].push_back(3);
  graph[3].push_back(2);
 
  // Q1) 노드 연결되어 있는지
  cout<<isConnected(1,2)<<'\n';
  // Q2) 인접한 노드 출력
  adj(2);
  return 0;
}
