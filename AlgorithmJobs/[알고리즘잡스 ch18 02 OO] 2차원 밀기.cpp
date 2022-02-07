#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch18 02 OO] 2차원 밀기
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
풀이2: 답지 중간에 저장해놓는 원소 간단, 구현,완탐
  //1.배열 입력
  //2.(1,1) 원소 저징
  //3.좌 테두리 위 밀기
  //4.하테두리 왼 밀기
  //5.우테두리 아래 밀밀기
  //6.상테두리 오른 밀기
  //7.(1,2) 저장해두었던 원소 대입
  //밀린 배열 출력
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
  //2.(1,1) 원소 저징
  int tp =a[1][1];
  //3.좌 테두리 위 밀기
  for(int i=1;i<=n-1;i++){
    a[i][1]=a[i+1][1];
  }
  //4.하테두리 왼 밀기
  for(int i=1;i<=m-1;i++){
    a[n][i]=a[n][i+1];
  }
  //5.우테두리 아래 밀밀기
  for(int i=n;i>=2;i--){
    a[i][m]=a[i-1][m];
  }
  //6.상테두리 오른 밀기
  for(int i=m;i>=3;i--){
    a[1][i]=a[1][i-1];
  }
  //7.(1,2) 저장해두었던 원소 대입
  a[1][2]=tp;
  //밀린 배열 출력
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<a[i][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
