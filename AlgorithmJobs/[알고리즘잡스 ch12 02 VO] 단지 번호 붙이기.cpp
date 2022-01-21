#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch12 02 VO] 단지 번호 붙이기
풀이: dfs
//1.2차원 그래프 입력
//2.반복 완탐으로 각 위치에서 집 있고 방문 안했으면 dfs
//3.단지 수, 각 단지의 집 수 오름차순출력
시간복잡도: O(V+E)= 
*/

#define MAX 30
int n,groupCnt=0,homeCnt=0;
int graph[MAX][MAX];
bool visit[MAX][MAX];
vector<int> cnt;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

//dfs
void dfs(int row,int col){
  // 방문처리, 집 카운트
  visit[row][col]=1; homeCnt++;
  
  // 4방면 인접 노드 탐색
  for(int i=0;i<4;i++){
    int rrow = row+dy[i];
    int ccol = col+dx[i];
    
    if(rrow<0 || rrow>=n || ccol<0 || ccol>=n){continue;}// 범위예외
    if(graph[rrow][ccol]==1 && visit[rrow][ccol]==0){// 방문예외,집 있으면 dfs
      dfs(rrow,ccol);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1. 이차원 그래프 입력
  cin>>n;
  for(int i=0;i<n;i++){
    string num;
    cin>>num;
    for(int j=0;j<n;j++){
      graph[i][j]=num[j]-'0';
    }
  }
  //2.반복 완탐으로 각 좌표 집있는지 검사
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(graph[i][j]==1 && visit[i][j]==0){// 방문 안했고 집 있으면 ,dfs 시작
        homeCnt=0;
        dfs(i,j);
        groupCnt++;// 단지 카운트
        cnt.push_back(homeCnt);
      }
    }
  }
  // 출력
  cout<<groupCnt<<'\n';
  sort(cnt.begin(),cnt.end());
  for(int i=0;i<cnt.size();i++){
    cout<<cnt[i]<<'\n';
  }
  return 0;
}
