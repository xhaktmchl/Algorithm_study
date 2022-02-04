#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch16 SKM 06 O] 경계 처리 알고리즘
풀이: 
  //1.배열입력
  //2.동서남북+r 이동
  //범위처리: 범위 넘어가면 그 방향 제일 끝의 값을 출력
시간복잡도: O(1)
*/
#define MAX 110
int n,m,y,x,d,r,result=0;
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열입력
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  cin>>y>>x>>d>>r;
  //2.동서남북+r 이동
  //범위처리: 범위 넘어가면 그 방향 제일 끝의 값을 출력
  //동
  if(d==0){
    if(x+r>=m){ result = a[y][m-1];}
    else{ result = a[y][x+r];}
  }
  //서
  if(d==1){
    if(x-r<0){ result = a[y][0];}
    else{ result = a[y][x-r];}
  }
  //남
  if(d==2){
    if(y+r>=n){ result = a[n-1][x];}
    else{ result = a[y+r][x];}
  }
  //북
  if(d==3){
    if(y-r<0){ result = a[0][x];}
    else{ result = a[y-r][x];}
  }
  cout<<result<<'\n';
  return 0;
}
