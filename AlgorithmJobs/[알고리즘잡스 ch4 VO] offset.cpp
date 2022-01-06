#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch4 VO] offset
풀이: 완탐으로 상하좌우 범위 및 크기비교
시간복잡도: O(5*5)=25
*/
#define MAX 26
int a[MAX][MAX],b[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  // 배열 입력
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      cin>>a[i][j];
      b[i][j] = a[i][j];
    }
  }
  // 배열 완탐
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      // 상하좌우 크기비교
      bool ok=true;
      if(i-1>=0 && a[i-1][j]<=a[i][j]){ ok=false;} // 상
      if(i+1<5 && a[i+1][j]<=a[i][j]){ ok=false;} // 하
      if(j-1>=0 && a[i][j-1]<=a[i][j]){ ok=false;} // 좌
      if(j+1<5 && a[i][j+1]<=a[i][j]){ ok=false;} // 우
      if(ok== true){ b[i][j]=-1;} 
    }
  }
  
  // 배열 출력
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(b[i][j] != -1) {cout<<b[i][j]<<" ";}
      else { cout<<"* "; }
    }cout<<'\n';
  }
  return 0;
}
