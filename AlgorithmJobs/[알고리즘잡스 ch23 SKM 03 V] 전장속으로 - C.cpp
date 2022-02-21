#include <iostream>
#include <algorithm>
#include <cmath> // abs
#include <queue>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch23 SKM 03 V] 전장속으로 - C
풀이: bfs,
  //1.배열입력
  //2.요원의 위치에서 그래프 맵 bfs 탐색
  //큐 생성
  //첫 위치 큐 푸쉬, 방문처리
  
  //bfs시작
  //이동할 위치 팝
  //큐 팝
  
  //범위검사
  //잡을 수 있는 적이면 거리 저장
  //큐에푸쉬 ,방문처리
  //같은레벨이면  .저장
  //더큰 적이면 x저장, 방문처리
  
  //3.도달하지 못하는 적 그대로 출력
시간복잡도: O(n*n)=400
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n,k;
int a[50][50];
int curRow,curCol;
bool visit[50][50];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int dist[50][50]; // 요원으로부터 거리 배열
string b[50][50];

void bfs(int row,int col){
  queue<pair<int,int>> q;
  q.push({row,col}); visit[row][col]=1;
  dist[row][col]=0;
  b[row][col]="*";
  
  while(!q.empty()){
    row = q.front().first;
    col = q.front().second;
    q.pop();
    
    for(int i=0;i<4;i++){
      int rr = row+dy[i];
      int cc = col+dx[i];
      
      if(rr<1 || rr>n || cc<1 || cc>n){continue;}
      if(visit[rr][cc]==0){
        if(a[rr][cc]!=0 && a[rr][cc]!=9){// 적니면
          // 요원보다 낮은 레벨 적이면
          if(a[rr][cc]<k){
            q.push({rr,cc}); visit[rr][cc]=1;
            dist[rr][cc]=dist[row][col]+1;
            b[rr][cc]=to_string(dist[rr][cc]);
          }
          //요원과 같은 레벨 적
          else if(a[rr][cc]==k){
            q.push({rr,cc}); visit[rr][cc]=1;
            dist[rr][cc]=dist[row][col]+1;
            b[rr][cc]=".";
          }
          //요원보다 높은 레벨 적
          else if(a[rr][cc] > k){
            visit[rr][cc]=1;
            b[rr][cc]="X";
          }
        }
        //적이 아니면
        else if(a[rr][cc]==0){
          q.push({rr,cc}); visit[rr][cc]=1;
          dist[rr][cc]=dist[row][col]+1;
          b[rr][cc]="0";
        }
        
      }
    }
    
    
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열입력
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>a[i][j];
      if(a[i][j]==9){// 요원의 위치 저장
        curRow=i;
        curCol=j;
        
      }
    }
  }
  //2.요원의 위치에서 그래프 맵 bfs 탐색
  //큐 생성
  //첫 위치 큐 푸쉬, 방문처리
  
  //bfs시작
  //이동할 위치 팝
  //큐 팝
  
  //4방면 탐색
  //범위검사
  //잡을 수 있는 적이면 거리 저장
  //큐에푸쉬 ,방문처리
  //같은레벨이면  .저장
  //더큰 적이면 x저장, 방문처리
  //아무것도 없으면 
  bfs(curRow,curCol);
  
  // 도달하지 못하는 곳은 -1 저장
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(visit[i][j]==0){
        b[i][j]="-1";
      } 
    }
  }
  
  //3.출력: 
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cout<<b[i][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
