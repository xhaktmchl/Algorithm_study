#include <iostream>
#include <algorithm> //sort
#include <queue>
#include <cstring>
#include <vector>
/*
[알고리즘잡스 ch13 04 VV] 목수의 미로 탈출
풀이: bfs
  //1.그래프 배열 입력
  //2.s부터 bfs
  //3.e부터 bfs
  //4.출력: s부터e까지 최단거리
시간복잡도: O(v+e)= n*m =100만
*/
using namespace std;

#define MAX 1050
int n,m;
int Map[MAX][MAX];
bool visit[MAX][MAX];
int lenAr1[MAX][MAX];
int lenAr2[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

//2.s(n-1,0)부터 bfs 시작
//큐(pair) 생성
//큐 푸쉬, 방문처리
// 거리배열에 저저장

//bfs 시작
//4방위 탐색
//범위검사
//방문안했고 벽 없으면 큐 푸쉬, 방문처리
//방문안했고 벽 있으면 방문처리만
// 거리 배열에 저장
void bfs(int row,int col,int lenAr[MAX][MAX]){
  queue<pair<int,int>> q;
  q.push({row,col}); visit[row][col]=1;
  lenAr[row][col]=0;
  
  while(!q.empty()){
    row = q.front().first;
    col = q.front().second;
    q.pop();
    
    for(int i=0;i<4;i++){
      int rr = row+dy[i];
      int cc = col+dx[i];
      
      if(rr<0 || rr>=n || cc<0 || cc>=m){ continue;}
      if(visit[rr][cc]==0){
        visit[rr][cc]=1;
        lenAr[rr][cc]=lenAr[row][col]+1;
        
        if(Map[rr][cc]==0){
          q.push({rr,cc});
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);
  
  //1.그래프 맵 입력
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>Map[i][j];
    }
  }
  //2.s(n-1,0)부터 bfs 시작
  // 방문배열 초기화
   //3.s(0,m-1)부터 bfs 시작
  bfs(n-1,0,lenAr1);
  memset(visit,0,sizeof(visit));
  bfs(0,m-1,lenAr2);
  // 방문을 했다면 완탐으로 각 좌표에서 거리 구하기=
  //3.츨력: 최단거리
  int minL=999999990;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(lenAr1[i][j]>0 && lenAr2[i][j]>0){
        minL = min(minL,lenAr1[i][j]+lenAr2[i][j]);
      }
    }
  }
  cout<<minL<<'\n';
  return 0;
}
