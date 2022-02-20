#include <iostream>
#include <algorithm>
#include <cstring> // memset
using namespace std;
/*
[알고리즘잡스 ch21 SKM 02 OV] 수영장 청소 - B_풀이2
풀이: 구현,완탐
  //1.배열입력
  //2.완탐
  //1~5수도꼭지 찾으면 물줄기 퍼짐
  //1번
  //2번
  //3번
  //4번
  //5번
  //장애물, 또는 범위 검사 , 중단
  //3.출력: 
시간복잡도: O(n*m)=5*5
풀이2: 수도꼭지 이동 방향배열,dir 과 좌표이동배열 dy,dx를 이용해서 물 퍼짐 구현

런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n,m;
int a[10][10];
int dir[6][4]={
  //상하좌우
  {0,0,0,0},
  {1,0,0,0},
  {1,1,0,0},
  {1,0,0,1},
  {1,0,1,1},
  {1,1,1,1}
};
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.배열입력
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  //2.완탐
  //1~5수도꼭지 찾으면 물줄기 퍼짐
  //장애물, 또는 범위 검사 , 중단
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]>=1 && a[i][j]<=5){ // 수도꼭지 존재하면
        int valNum= a[i][j]; // 수도꼭지 번호
        
        
        
        for(int p=0;p<4;p++){
          if(dir[valNum][p]==1){// 이 방향인지 알려줌
            int currow = i;
            int curcol = j; 
            //방향으로 끝까지 이동
            while(1){
              currow = currow+dy[p];
              curcol = curcol+dx[p];
              
              if(currow<1 || currow>n || curcol<1 || curcol>m){ break; }//범위 검사
              if(a[currow][curcol]==6){break;} // 장애물 중단.
              if(a[currow][curcol]==0){//물 퍼짐
                a[currow][curcol]=8;
              }
            }
          }
        }
        
        
      }
    }
  }
  //3.출력: 
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<a[i][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
