#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch21 SKM 04 O] 수영장 청소 - D
풀이: 구현,완탐
//1.수영장 배열입력
//회전 횟수 입력
//2.완탐: 각 수도꼭지 정해진 횟수만큼 회전
  // 1~5에 해당하는 회전배열인지 찾기
  // 3.수도꼭지 회전
  // 4.물 퍼뜨리기// 영역 끝까지 물 퍼짐 탐색
  // 범위검사
  // 장애물 중단
  // 빈곳에만 물 퍼짐
  // 5.물 영역 카운트
  // 출력: 물 영역

시간복잡도: O(n*m)=5*5
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n,m;
int a[10][10];
int T[6];
int valCnt=0;
int result=0;
int dir[6][4]={
  //상우하좌
  {0,0,0,0},
  {1,0,0,0},
  {1,0,1,0},
  {1,1,0,0},
  {1,1,0,1},
  {1,1,1,1}
};
int dx[]={0,1,0,-1};//상우하좌
int dy[]={-1,0,1,0};

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.수영장 배열입력
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
      if(a[i][j]>=1 && a[i][j]<=5){valCnt++;}
    }
  }
  //회전 횟수 입력
  for(int i=0;i<valCnt;i++){
    cin>>T[i];
  }
  //2.완탐: 각 수도꼭지 정해진 횟수만큼 회전
  // 1~5에 해당하는 회전배열인지 찾기
  // 범위검사
  // 장애물 검사
  // 원하는 방향으로 물 퍼지기
  valCnt=-1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]>=1 && a[i][j]<=5){// 수도꼭지 찾으면 
        valCnt++;
        int valNum=a[i][j];
        //수도꼭지 회전
        int myDir[4]={0,};
        for(int p=0;p<4;p++) myDir[p]=dir[valNum][p];
        for(int p=0;p<T[valCnt];p++){// valCnt 번째 수도꼭지 
          int tp=myDir[3];// 맨뒤 원소
          for(int q=3;q>=1;q--){
            myDir[q]=myDir[q-1];
          }
          myDir[0]=tp; // 앞으로 넣어주기
        }
        
        //물 퍼뜨리기
        for(int p=0;p<4;p++){
          if(myDir[p]==1){
            int row=i;
            int col=j;
            
            // 영역 끝까지 물 퍼짐 탐색
            while(1){
              row+=dy[p];
              col+=dx[p];
              
              if(row<1 || row>n || col<1 || col>m){break;}// 범위검사
              if(a[row][col]==6){break;} // 장애물 중단
              if(a[row][col]==0){// 빈곳에만 물 퍼짐
                a[row][col]=8;
              }
            }
          }
        }
        
      }
    }
  }
  // 물 영역 카운트
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]==8){ result++;}
    }
  }
  // 출력: 물 영역
  cout<<result<<'\n';
  return 0;
}
