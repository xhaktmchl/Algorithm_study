#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch18 SKM 06 O] 밀기 알고리즘 2
풀이: 구현
  //1.배열 입력
  //2.0~u행 까지 배열 시계방향 밀기
  //왼쪽 위 원소 저장
  //좌 테두리 위 밀기
  //하 테두리 왼 밀기
  //우 테두리 아래 밀밀기
  //상 테두리 오른 밀기
  // (0,1) 에 저장해둔 원소 대입
  //3.d~n-1행 까지 배열 반시계방향 밀밀기
  //상 테두리 왼 밀기
  //우 테두리 위 밀기
  //하 테두리 오른 밀밀기
  //좌 테두리 아래 밀기
  //(d+1,0) 에 저장해둔 원소 대입
  //4.출력: 밀린배열
시간복잡도: O(n*m)=10000 
*/
#define MAX 110
int n,m,u,d;
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.배열 입력
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  cin>>u>>d;
  //2.0~u행 까지 배열 시계방향 밀기
  //왼쪽 위 원소 저장
  int tp1 = a[0][0];
  //좌 테두리 위 밀기
  for(int i=1;i<=u;i++){
    a[i-1][0]=a[i][0];
  }
  //하 테두리 왼 밀기
  for(int i=0;i<=m-2;i++){
    a[u][i]=a[u][i+1];
  }
  //우 테두리 아래 밀밀기
  for(int i=u;i>=1;i--){
    a[i][m-1]=a[i-1][m-1];
  }
  //상 테두리 오른 밀기
  for(int i=m-1;i>=2;i--){
    a[0][i]=a[0][i-1];
  }
  // (0,1) 에 저장해둔 원소 대입
  a[0][1]=tp1;
  //3.d~n-1행 까지 배열 반시계방향 밀밀기
  //왼쪽 위 원소 저장
  int tp2=a[d][0];
  //상 테두리 왼 밀기
  for(int i=0;i<=m-2;i++){
    a[d][i] = a[d][i+1];
  }
  //우 테두리 위 밀기
  for(int i=d;i<=n-2;i++){
    a[i][m-1]=a[i+1][m-1];
  }
  //하 테두리 오른 밀밀기
  for(int i=m-1;i>=1;i--){
    a[n-1][i]=a[n-1][i-1];
  }
  //좌 테두리 아래 밀기
  for(int i=n-1;i>=d+1;i--){
    a[i][0]=a[i-1][0];
  }
  //(d+1,0) 에 저장해둔 원소 대입
  a[d+1][0]=tp2;
  //4.출력: 밀린배열
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<a[i][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
