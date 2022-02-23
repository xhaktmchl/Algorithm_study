#include <iostream>
#include <algorithm>
#include <cmath> // abs
#include <queue>
#include <cstring> // memset
#include <string>
using namespace std;
/*
[알고리즘잡스 ch23 SKM 05 V] 전장속으로 - E
풀이1: bfs이용해서 상좌우하 순으로 탐색 -> 나중 결과를 보면 운선순위와 다르게 탐색해서 답 틀림
풀이2: 완탐,구현
  //1.배열입력
  // 요원의 위치 저장
  //반복
  //요원으로부터 모든 거리 구하기
  //최솟거리 ,좌표 저장
  //적이있으면 이동, 요원위치 갱신, 거리 합
  //4.출력:요원 이동거리의 합
시간복잡도: O(n*n)=n*n=400
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n;
int a[50][50];
int curRow,curCol; // 요원의 위치
int dist[50][50]; // 적까지의 거리저장 배열
int dx[]={0,-1,1,0}; // 우선순위에 따라 상좌우하 순서
int dy[]={-1,0,0,1};
int resultSum=0;
int minDist=987987987;
int minRow,minCol;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열입력
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>a[i][j];
      if(a[i][j]==9){// 요원의 위치 저장
        curRow=i;
        curCol=j;
      }
    }
  }
  //반복
  //요원으로부터 모든 거리 구하기
  //최솟거리 ,좌표 저장
  //적이있으면 이동, 요원위치 갱신, 거리 합
  while(1){
    //초기화
    memset(dist,0,sizeof(dist));
    minDist=987987987;
    //요원으로부터 모든 거리 구하기
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(a[i][j]!=0 &&a[i][j]!=9){
          dist[i][j]=abs(i-curRow)+abs(j-curCol);
        }
        else{
          dist[i][j]=987987987;
        }
      }
    }
    //최솟거리 ,좌표 저장
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(minDist > dist[i][j]){
          minDist = dist[i][j];
          minRow=i;
          minCol=j;
        }
      }
    }
    //적이있으면 이동, 요원위치 갱신, 거리 합
    if(minDist!= 987987987){
      a[curRow][curCol]=0; // 전의 위치에 0 갱신
      curRow=minRow;
      curCol=minCol;
      resultSum+=minDist;
      a[curRow][curCol]=0; // 적을 섬별한 곳 0갱신
      
    }
    else{break;}
  }
  
  //4.출력:요원 이동거리의 합
  cout<<resultSum<<'\n';
  return 0;
}
