#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch04 VOO] offset
풀이: 완탐으로 상하좌우 범위 및 크기비교
  //1.배열입력
  //2.완탐: 사방면 자기보다 모두 큰지 조회
  //크면 *로 출력
시간복잡도: O(5*5)=25
*/
#define MAX 10
char a[MAX][MAX];
char answer[MAX][MAX];

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  //1.배열입력
  for(int i=1;i<=5;i++){
    for(int j=1;j<=5;j++){
      cin>>a[i][j];
      answer[i][j]=a[i][j];
    }
  }
  //2.완탐: 사방면 자기보다 모두 큰지 조회
  for(int i=1;i<=5;i++){
    
    for(int j=1;j<=5;j++){
      bool ok=true;
      //상
      if(i-1>=1 && a[i][j]>=a[i-1][j]){ ok=false;}// 범위조건, 크기조건
      //하
      if(i+1<=5 && a[i][j]>=a[i+1][j]){ ok=false;}
      //좌
      if(j-1>=1 && a[i][j]>=a[i][j-1]){ ok=false;}

      //우
      if(j+1<=5 && a[i][j]>=a[i][j+1]){ ok=false;}
      
      if(ok){//크면 *로 출력
        answer[i][j]='*';
      }

    }
  }
  for(int i=1;i<=5;i++){
    for(int j=1;j<=5;j++){
      cout<<answer[i][j]<<" ";
    }cout<<'\n';
  }
  
  return 0;
}
