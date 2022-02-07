#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
/*
[알고리즘잡스 ch18 SKM 01 O] 밀기 알고리즘
풀이: 구현,완탐
  //1.회전판 배열입력
  //2.회전 명령 입력
  //x==1 오른방향 밀기
  //x==2 왼 밀기
  //3.밀린 배역 출력
시간복잡도: O(n*m*q)= 1억
*/
#define MAX 1010
int n,m,q,f,x,y;
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.회전판 배열입력
  cin>>n>>m>>q;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  //2.회전 명령 입력
  for(int i=0;i<q;i++){
    cin>>f>>x>>y;
    if(x==1){//x==1 오른방향 밀기
      for(int j=0;j<y;j++){
        // 오른 맨 끝 수 저장
        int tp=a[f+1][m];
        for(int p=m-1;p>=1;p--){
          a[f+1][p+1]=a[f+1][p];
        }
        a[f+1][1]=tp;
      }
    }
    else if(x==2){  //x==2 왼 밀기
      for(int j=0;j<y;j++){
        // 왼 맨 끝 수 저장
        int tp=a[f+1][1];
        for(int p=1;p<m;p++){
          a[f+1][p]=a[f+1][p+1];
        }
        a[f+1][m]=tp;
      }
    }
    //3.밀린 배역 출력
    for(int j=1;j<=m;j++){
      cout<<a[f+1][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
