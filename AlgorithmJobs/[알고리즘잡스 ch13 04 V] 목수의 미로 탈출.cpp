#include <iostream>
#include <algorithm>
#include <queue>
#include <vector> // pair
#include <cstring> // memset
using namespace std;
/*
[알고리즘잡스 ch13 04 V] 목수의 미로 탈출
풀이: bfs
  //1.그래프 배열 입력
  //2.s부터 bfs
  //3.e부터 bfs
  //4.출력: s부터e까지 최단거리
시간복잡도: O(v+e)= n*m =100만
*/
#define MAX 1050
int n,m;
int Map[MAX][MAX];
int dist1[MAX][MAX]; // s 부터 거리
int dist2[MAX][MAX]; // e부터의 거리
bool visit[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

//bfs
void bfs(int row,int col,int dist[MAX][MAX]){
  queue<pair<int,int>> q;//큐 생성
  q.push({row,col}); visit[row][col]=1;// 큐 푸쉬 , 방문처리, 거리저장
  dist[row][col]=0;
  // bfs시작
  while(!q.empty()){
    // 큐 팝
    row = q.front().first;
    col = q.front().second;
    q.pop();
    // 4방위 탐색
    for(int i=0;i<4;i++){
      int rr = row + dy[i];
      int cc = col + dx[i];
      
      if(rr<0 || rr>=n || cc<0 || cc>=m){ continue;}// 좌표범위 검사
      if(visit[rr][cc]==0){// 방문 안했는면 거리저장
        visit[rr][cc]=1; 
        dist[rr][cc]=dist[row][col]+1;
        
        if(Map[rr][cc]==0){// 방문 안했는데 벽 없으면 큐 푸쉬, 방문처리
          q.push({rr,cc});
          //q.push(make_pair(rr,cc));
        }
      }
    }
    
  }
}




int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.그래프 배열 입력
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>Map[i][j];
    }
  }
  //2.s부터 bfs
  bfs(n-1,0,dist1);
  memset(visit,0,sizeof(visit)); // 방문배열 초기화, 헤더 cstring
  //3.e부터 bfs
  bfs(0,m-1,dist2);
  
  //4.출력: s부터e까지 최단거리
  int minResult=987987987;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      // 방문 했으면 거리 최솟값 비교
      if(dist1[i][j]>0 && dist2[i][j]>0){
        minResult = min(minResult,dist1[i][j]+dist2[i][j]);
      }
    }
  }
  cout<<minResult<<'\n';
  return 0;
}
