#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[알고리즘잡스 ch12 01 O] 이분 그래프 판별
풀이: dfs
// 그래프 인접리스트 입력
// 2.dfs 시작, 이분 그래프인지 탐색
시간복잡도: O(n+m) = 1000+100000 = 101000
*/
#define MAX 1010
int n,m;
vector<int> graph[MAX];
bool visit[MAX];
int color[MAX]; // 색 배열 0,1 
bool flag=1;

//dfs
void dfs(int node,int curColor){
  visit[node]=1;//방문처리
  color[node]=curColor%2;// 색칠하기
  
  // 인접리스트 탐색
  for(int i=0;i<graph[node].size();i++){
    int nextNode = graph[node][i];
    if(visit[nextNode]==0){// 방문하지 않으면
      dfs(nextNode,curColor+1);
    }
    else{// 방문해쓰면 색 비교
      if(color[nextNode] == curColor){
        flag=0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 그래프 인접리스트 입력
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);

  }
  // 2.dfs 시작, 이분 그래프인지 탐색
  dfs(1,0);
  // 출력
  if(flag==1){cout<<"Yes"<<'\n';}
  else{cout<<"No"<<'\n';}
  return 0;
}
