#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch5 V] tetris
풀이: 완탐
시간복잡도: O(n*n*n)=20^3
*/
#define MAX 22
int x,y,maxN=0,maxc=0,cnt=0;
int a[MAX][MAX],b[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 1.배열 입력
  cin>>x>>y;
  for(int i=1;i<=y;i++){
    for(int k=1;k<=x;k++){
      cin>>a[i][k];
      b[i][k]=a[i][k];
    }
  }
  // 2.각 열에서 테트리스 놓아보기
  for(int i=1;i<=x;i++){
    // 각 열에서 가장 밑으로 내려감
    int row=0,col=0;
    for(int k=1;k<=y;k++){
      row=k;
      col=i;
      if(a[k][i] == 1){break;} // 1이면 중단
    }
    // 테트리스 놓을 수 있는지
    if(row >= 5){
      // 테트리스 채우기
      for(int k=row-4;k<=row;k++){
        b[k][i] = 1;
      }
      // 수평선 검사
      cnt=0;
      for(int k=1;k<=y;k++){
        bool ok = true;
        for(int p=1;p<=x;p++){
          if(b[k][p] == 0){ ok=false;}
        }
        if(ok==true){ cnt++;}
      }
      // 최대 열과 수평선 갯수 저장
      if(cnt > maxN){ 
        maxc = i;
        maxN =cnt;
      }
      // 테트리스 비우기
      for(int k=row-4;k<=row;k++){
        b[k][i] = 0;
      }
    }
  }
  cout<<maxc<<" "<<maxN<<'\n';

  return 0;
}
