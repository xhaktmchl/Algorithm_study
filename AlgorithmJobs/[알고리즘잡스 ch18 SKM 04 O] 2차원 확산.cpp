#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch18 SKM 04 O] 2차원 확산
풀이: 구현,완탐
  //1.배열입력
  //경계처리: 상하좌우 0으로 패딩
  //2.t번 확산 반복
  //완탐으로 상하좌우 값 더해주기
  // 원래배열을 임시배열로 최신화
  //3.출력
시간복잡도: O(n*m*t)= 10000*10
*/
#define MAX 110
int n,m,t;
int a[MAX][MAX];
int answer[MAX][MAX];

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
  cin>>t;
  //경계처리: 상하좌우 0으로 패딩
  
  //2.t번 확산 반복
  for(int i=0;i<t;i++){
    //완탐으로 상하좌우 값 더해주기
    for(int j=1;j<=n;j++){
      for(int p=1;p<=m;p++){
        answer[j][p] = a[j][p]+a[j-1][p]+a[j+1][p]+a[j][p-1]+a[j][p+1];
      }
    }
    // 원래배열을 임시배열로 최신화
    for(int j=1;j<=n;j++){
      for(int p=1;p<=m;p++){
        a[j][p]=answer[j][p];
      }
    }
  }
  
  //3.출력
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<a[i][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
