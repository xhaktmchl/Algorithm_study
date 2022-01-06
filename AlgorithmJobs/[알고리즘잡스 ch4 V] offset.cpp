#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch4 V] offset
풀이: 완탐으로 상하좌우 범위 및 크기비교
시간복잡도: O()
*/
#define MAX 26
char a[MAX][MAX],b[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  // 배열 입력
  for(int i=0;i<5;i++){
    for(int k=0;k<5;k++){
      cin>>a[i][k];
      b[i][k]=a[i][k];
    }
  }
  // 배열 완탐
  for(int i=0;i<5;i++){
    for(int k=0;k<5;k++){
      // 범위검사
      if(i-1 >=0 && a[i-1][k] <= a[i][k]){continue; }//상
      if(i+1 < 5 && a[i+1][k] <= a[i][k]){ continue; } //하
      if(k-1 >=0 && a[i][k-1] <= a[i][k]){ continue; }//좌
      if(k+1 < 5 && a[i][k+1] <= a[i][k]){ continue; }//우
      b[i][k] = '*';
    }
  }
  
  // 배열 출력
  for(int i=0;i<5;i++){
    for(int k=0;k<5;k++){
      cout<<b[i][k]<<" ";
    }cout<<'\n';
  }
  return 0;
}
