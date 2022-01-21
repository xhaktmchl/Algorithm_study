#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
[알고리즘잡스 ch12 03 O] 2색칠하기
풀이:
//1.그래프 인접리스트 입력
// 2.0번에서 dfs 시작 
// 3.dfs(현재 노드,칠하는 색)
시간복잡도: O(n+m)= 110000
*/
#define MAX 10010
int n,m; 
vector<int> graph[MAX];
bool visit[MAX];
int color[MAX]; // 색 배열, 0,1,번 색
bool flag=1;

//dfs
void dfs(int node,int curColor){// 3.dfs(현재 노드,칠하는 색)
  //방문처리, 
  visit[node]=1;
  //색칠 
  color[node]=curColor%2; 
  
  //인접 리스트 탐색
  for(int i=0;i<graph[node].size();i++){
    int nextNode = graph[node][i];
    if(visit[nextNode]==0){  // 방문 안했으면 탐색
      dfs(nextNode,curColor+1);
    }
    else{// 방문 했으면 색다른지 검사 , 같음면 NO
      if(color[nextNode]==curColor){
        flag = 0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>n>>m;
  //1.그래프 인접리스트 입력
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  // 2.0번에서 dfs 시작 
  // 3.dfs(현재 노드,칠하는 색)
  dfs(0,0);
  // 색칠 가능 출력
  if(flag == 1){
    cout<<"YES"<<'\n';
  }
  else{ cout<<"NO"<<'\n';}
  return 0;
}
