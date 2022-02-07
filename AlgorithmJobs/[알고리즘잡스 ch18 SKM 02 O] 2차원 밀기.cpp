#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch18 SKM 02 O] 2차원 밀기
풀이: 구현,완탐
  //1.배열 입력
  //2.상 테두리 오른 밀기
  //오른 맨 끝 저장
  //밀밀기
  //우 테두리 아래밀기
  //아래맨 끝 저장
  //밀기
  //하 테두리 왼 밀기
  //왼아래 맨 끝 저장
  //좌 테두리 위 밀기
  //왼 위 맨 끝 저장
  
  //3.밀린 배열 출력
시간복잡도: O(2n+2m)= 400
*/
#define MAX 110
int n,m;
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열 입력
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  //2.상 테두리 오른 밀기
  int tp1 = a[1][m];//오른 맨 끝 저장
  for(int i=m-1;i>=1;i--){//밀밀기
    a[1][i+1]=a[1][i];
  }
  
  //우 테두리 아래밀기
  int tp2=a[n][m]; //아래맨 끝 저장
  for(int i=n-1;i>=2;i--){  //밀기
    a[i+1][m]=a[i][m];
  }
  a[2][m]=tp1;
 
  //하 테두리 왼 밀기
  int tp3=a[n][1];//왼아래 맨 끝 저장
  for(int i=1;i<m-1;i++){
    a[n][i] = a[n][i+1];
  }
  a[n][m-1]=tp2;
  
  //좌 테두리 위 밀기
  int tp4=a[1][1];//왼 위 맨 끝 저장
  for(int i=1;i<n-1;i++){
    a[i][1]=a[i+1][1];
  }
  a[n-1][1]=tp3;
  
  //3.밀린 배열 출력
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<a[i][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
