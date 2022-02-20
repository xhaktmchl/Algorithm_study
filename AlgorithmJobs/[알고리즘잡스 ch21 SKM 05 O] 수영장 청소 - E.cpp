#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch21 SKM 05 O] 수영장 청소 - E
풀이: 구현,완탐
//1.수영장 배열입력
//2.완탐: 수도꼭지 있으면 
  // 3.0~3번 회전 하고 
  // 4.물 퍼짐
  // 5.영역 갯수 카운트
  //영역 최댓값 갱신
  //6.출력: 최댓값

시간복잡도: O(n*m)=5*5
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n,m;
int a[10][10];
int dir[6][4]={
  //상우하좌
  {0,0,0,0},
  {1,0,0,0},
  {1,0,1,0},
  {1,1,0,0},
  {1,1,0,1},
  {1,1,1,1}
};
int dx[]={0,1,0,-1}; // 상우ㅈ하좌
int dy[]={-1,0,1,0};
int result=0;
int resultMax=0;


int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.수영장 배열입력
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  //2.완탐: 수도꼭지 있으면 
  // 3.0~3번 회전 하고 
  // 4.물 퍼짐
  // 5.영역 갯수 카운트
  //영역 최댓값 갱신
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]>=1 && a[i][j]<=5){// 수도꼭지 찾으면
        int valNum=a[i][j];
        // 3.0~3번 회전 하고 
        int myDir[4]={0,};
        for(int p=0;p<4;p++) myDir[p]=dir[valNum][p];
        
        
        for(int p=0;p<4;p++){// 회전 번째
          result=0;
          // 4.물 퍼짐
          for(int q=0;q<4;q++){
            if(myDir[q]==1){// 벨브 방향 확인
              int row = i;
              int col=j;
              
              while(1){
                row+=dy[q];
                col+=dx[q];
                
                if(row<1 || row>n || col<1 || col>m){break;} // 범위검사
                if(a[row][col]==6){break;} // 장애물 중단
                if(a[row][col]==0){
                  //a[row][col]=8;
                  result++;
                }
              }
            }
          }
          // 5.영역 갯수 카운트
          // 영역 최댓값 갱신
          resultMax = max(resultMax,result);
          //회전 ,배열 밀기
          int tp=myDir[3];
          for(int q=3;q>=1;q--){
            myDir[q]=myDir[q-1];
          }
          myDir[0]=tp;
          
        }
      }
    }
  }
  //6.출력: 최댓값
  cout<<resultMax<<'\n';
  return 0;
}
