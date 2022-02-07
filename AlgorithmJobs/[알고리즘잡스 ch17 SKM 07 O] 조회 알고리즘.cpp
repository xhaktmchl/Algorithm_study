#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch17 SKM 07 O] 조회 알고리즘
풀이: 완탐
  //1.배열입력
  //2.경계처리 패딩
  //상하 -1로 패패딩
  //좌우 맨 끝 열로 패딩
  //3.완탐으로 상하좌우 일치 검사
  //상
  //하
  //좌
  //우
  //일치하면 1,불일치는 0
  //4.출력: 결과배열
시간복잡도: O(n*m)=10000 
*/
#define MAX 110
int n,m;
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
  //2.경계처리 패딩
  //상하 -1로 패딩
  for(int i=1;i<=m;i++){
    a[0][i]=-1;
    a[n+1][i]=-1;
  }
  //좌우 맨 끝 열로 패딩
  for(int i=1;i<=n;i++){
    a[i][0]=a[i][m];
    a[i][m+1]=a[i][1];
  }
  //3.완탐으로 상하좌우 일치 검사
  //상
  //하
  //좌
  //우
  //일치하면 1,불일치는 0
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]==a[i-1][j] || a[i][j]==a[i+1][j] || a[i][j]==a[i][j-1] || a[i][j]==a[i][j+1]){
        answer[i][j]=1;
      }
      else {
        answer[i][j]=0;
      }
    }
  }
  
  //4.출력: 결과배열
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<answer[i][j]<<" ";
    }  cout<<'\n';
  }
  return 0;
}
