#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
/*
[알고리즘잡스 ch13 02 V] 미로 찾기
풀이: 
 //1.그래프 배열 입력
 //2.bfs
 //큐 생성
// 큐 푸쉬, 방문처리
//bfs시작
// 큐 팝
// 4방면 탐색
// 좌표 범위검사
// 방문 안했으면 큐 푸쉬, 방문처리

 //3.최단거리 출력
시간복잡도: O(v+e)= n*m = 100만
주의: 패딩할 때 채워주는 값고려 안하면 똑같이 런타임 에러 남
*/
#define MAX 1050
int n,m,cnt=0;
int Map[MAX][MAX];
bool visit[MAX][MAX];
int dx[]= {0,0,1,-1};
int dy[]={1,-1,0,0};
int dist[MAX][MAX];

//bfs
void bfs(int row,int col){
  queue<pair<int,int>> q;//큐 생성
  q.push(make_pair(row,col) ); visit[row][col]=1;// 큐 푸쉬, 방문처리
  dist[row][col]=0;
  //bfs시작
  while(!q.empty()){
    // 큐 팝
    row = q.front().first;
    col = q.front().second;
    q.pop();
    
    // 4방면 탐색
    for(int i=0;i<4;i++){
      int rr = row+dy[i];
      int cc = col+dx[i];
      
      if(rr<0 || rr>=n || cc<0 || cc>=m){ continue;} // 좌표 범위검사
      if(!visit[rr][cc] && Map[rr][cc]==0){// 방문 안했으면 큐 푸쉬, 방문처리
        q.push(make_pair(rr,cc)); visit[rr][cc]=1;
        dist[rr][cc]=dist[row][col]+1;
        
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
  //2.bfs
  bfs(n-1,0);
  //3.최단거리 출력
  cout<<dist[0][m-1]<<'\n';
  return 0;
}
