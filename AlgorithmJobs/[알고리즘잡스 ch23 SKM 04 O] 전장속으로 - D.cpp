#include <iostream>
#include <algorithm>
#include <cmath> // abs
#include <queue>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch23 SKM 04 O] 전장속으로 - D
풀이: bfs,
  //1.배열입력
  //2.요원의 위치에서 그래프 맵 bfs 탐색
  //큐 생성
  //첫 위치 큐 푸쉬, 방문처리
  
  //bfs시작
  //이동할 위치 팝
  //큐 팝
  
  //범위검사
  //적이면
  //요원보다 작은레벨 적이면 좌표 출력 , 중단.
  //적이 아니면 
  //계속 탐색
  
  //3.도달할 수 있는 적 중 우선순위높은 가장 최단거리, 가장 위 , 가장 왼쪽에 있는 적 좌표 출력, 중단.
시간복잡도: O(V+E)=n*n=400
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n,k;
int a[50][50];
int curRow,curCol;
int dist[50][50]; // 적까지의 거리저장 배열
int visit[50][50];
int dx[]={0,-1,1,0}; // 우선순위에 따라 상좌우하 순서
int dy[]={-1,0,0,1};
string b[50][50];
int minRow,minCol;

void bfs(int row,int col){
  queue<pair<int,int>> q;
  q.push({row,col}); visit[row][col]=1;
  dist[row][col]=0;
  //b[row][col]="*";
  
  while(!q.empty()){
    row = q.front().first;
    col= q.front().second;
    q.pop();
    
    // 4방면 상좌우하 순 탐색
    for(int i=0;i<4;i++){
      int rr=row+dy[i];
      int cc=col+dx[i];
      
      if(rr<1 || rr>n || cc<1 ||cc>n){continue;}
      if(visit[rr][cc]==0){
        if(a[rr][cc]!=0 && a[rr][cc]!=9){// 적일 때
          //요원보다 적은 레벨  적
          if(a[rr][cc] < k){
            q.push({rr,cc}); visit[rr][cc]=1;
            dist[rr][cc]=dist[row][col]+1;
            b[rr][cc]=to_string(dist[rr][cc]);
            minRow = rr;
            minCol=cc;
            return; 
          }
          //요원이랑 같은 레벨 적
          //요원보다 큰 레벨 적
        }
        else{//적이 아닐 때
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
  //2.요원의 위치에서 그래프 맵 bfs탐색 시작
  bfs(curRow,curCol);
  //3.도달할 수 있는 적 중 우선순위높은 가장 최단거리, 가장 위 , 가장 왼쪽에 있는 적 좌표 출력, 중단.
  cout<<minRow<<" "<<minCol;
  return 0;
}
