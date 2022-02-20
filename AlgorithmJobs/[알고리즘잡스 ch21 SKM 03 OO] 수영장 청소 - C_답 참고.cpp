#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch21 SKM 03 O] 수영장 청소 - C
풀이: 구현,완탐
  //1.수영장 배열입력
  //2.완탐: k번째 수도꼭지를 T회 회전, 
  //1~5번에 해당하는 수도꼭지 물 퍼지기
  //1번
  //2번
  //3번
  //4번
  //5번
  //범위검사, 장애물 만나면 중지
  //물 퍼지는 영역 카운트
  //3.출력
시간복잡도: O(n*m)=5*5
풀이2: 수도꼭지 이동 방향배열,dir 과 좌표이동배열 dy,dx를 이용해서 물 퍼짐 구현
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n,m,K,T;
int a[10][10];
int cnt=0;
int result=0;
int dir[6][4]={
  //상우하좌, 회전 순서도 맞춰야 함
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
  cin>>n>>m>>K>>T;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  //2.완탐: k번째 수도꼭지를 T회 회전, 
  //1~5번에 해당하는 수도꼭지 물 퍼지기
  //범위검사, 장애물 만나면 중지
  //물 퍼지는 영역 카운트
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]>=1 && a[i][j]<=5){cnt++;}
      if(cnt==K){
        int valNum=a[i][j];
        // T회 회전 , 방향배열 밀기
            int myDir[4]={0,};
            for(int q=0;q<4;q++) myDir[q]=dir[valNum][q];// 회전할 배열 복사
            for(int q=0;q<T;q++){
              int tp=myDir[3];
              for(int k=3;k>=1;k--){
                myDir[k]=myDir[k-1];
              }
              myDir[0]=tp;
            }
        
        //어느방향인지 검사
        for(int p=0;p<4;p++){
          if(myDir[p]==1){// 이 방향일 때만 실행
            int row=i;
            int col=j;
            
            // 방향으로 물 퍼지기
            while(1){
              row = row+dy[p];
              col= col+dx[p];
              
              if(row<1 || row>n || col<1 || col>m){break;}//범위검사
              if(a[row][col]==6){break;}// 장애물 검사
              if(a[row][col]==0){// 물 퍼짐
                a[row][col]=8;
              }
            }
            
          }
          
          
         
        }
        
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]==8){
        result++;
      }
    }
  }
  //3.출력
  cout<<result<<'\n';
  return 0;
}
