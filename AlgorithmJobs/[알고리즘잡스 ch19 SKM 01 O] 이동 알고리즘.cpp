#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch19 SKM 01 O] 이동 알고리즘
풀이: 구현,완탐
  //1.배열 입력
  //2.질문 q번 입력
  //d방향으로 r만큰 이동
  //좌표범위 검사
  //다음 이동칸이-1 면 중지
  // 3.이동 끝나면 원소 출력
시간복잡도: O(n*q)= 100*100=10000 
*/
#define MAX 110
int n,m,q,d,r,y=0,x=0;
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.배열 입력
  cin>>n>>m>>q;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  //2.질문 q번 입력
  for(int i=0;i<q;i++){
    cin>>d>>r;
    //d방향으로 r만큰 이동
    if(d==0){//동
      for(int i=1;i<=r;i++){
        if(x+i>=m || a[y][x+i]==-1){ //좌표범위 검사//다음 이동칸이-1 면 중지
          x=x+i-1;
          cout<<a[y][x]<<'\n';
          break;
        }
        if(i==r){// 3.이동 끝나면 원소 출력
          x=x+i;
          cout<<a[y][x]<<'\n';
        }
      
      }
    }
    if(d==1){//서
      for(int i=1;i<=r;i++){
        if(x-i<0 || a[y][x-i]==-1){ 
          x=x-i+1;
          cout<<a[y][x]<<'\n';
          break;
        }
        if(i==r){
          x=x-i;
          cout<<a[y][x]<<'\n';
        }
      
      }
    }
    if(d==2){//남
      for(int i=1;i<=r;i++){
        if(y+i>=n || a[y+i][x]==-1){ 
          y=y+i-1;
          cout<<a[y][x]<<'\n';
          break;
        }
        if(i==r){
          y=y+i;
          cout<<a[y][x]<<'\n';
        }
      
      }
    }
    if(d==3){//북
      for(int i=1;i<=r;i++){
        if(y-i<0 || a[y-i][x]==-1){ 
          y=y-i+1;
          cout<<a[y][x]<<'\n';
          break;
        }
        if(i==r){
          y=y-i;
          cout<<a[y][x]<<'\n';
        }
      }
    }
  }
  
  
  
  
  return 0;
}
