#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch5 VVO] tetris
풀이: 완탐
시간복잡도: O(n*n*n*n)=20^4
주의: 열에서 맨 밑으로 내려갈 때 마지막 row값에서 애먹음
*/
#define MAX 24
int row,col,maxN=0,maxCol=0;
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // 배열 입력
  cin>>col>>row;
  for(int i=1;i<=row;i++){
    for(int j=1;j<=col;j++){
      cin>>a[i][j];
    }
  }
  // 이중 반복문 완탐: 각 열에서 4칸이 모두 0이면
  for(int i=1;i<=col;i++){
    // 밑까지 내려가기
    int curRow=0;
    int curCol=0;
    for(int j=1;j<=row;j++){
      curRow = j;
      curCol=i;
      if(a[j][i] == 1){ curRow--; break;} //****** 마지막 행의 값 0으로 통일
    }
    
    // 범위 검사
    if(curRow >=4){
      // 테트리스 채워넣기
      for(int j=curRow-3;j<=curRow;j++){
        a[j][i]=1;
      }
      // 수평선 검사
      int cnt=0;
      for(int j=1;j<=row;j++){
        bool ok=true;
        for(int k=1;k<=col;k++){
          if(a[j][k]==0){ok=false;}
        }
        if(ok == true){
          cnt++;
        }
      }
      // 최대값, 열 저장
      if(cnt > maxN){
        maxN = cnt;
        maxCol=i;
      }
      // 테트리스 비우기
      for(int j=curRow-3;j<=curRow;j++){
        a[j][i]=0;
      }
    }
  }
  
  // 출력
  cout<<maxCol<<" "<<maxN<<'\n';
  return 0;
}
