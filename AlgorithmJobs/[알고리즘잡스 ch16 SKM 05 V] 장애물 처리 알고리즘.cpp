#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch16 SKM 05 V] 장애물 처리 알고리즘
풀이: 
  //1.배역입력
  //2.이동하기 전 이동할 원소값이 -1이면 -1바로 전 이동 값 출력
  //-1 아니면 동서남북 방향+r 인덱스의 원소값 출력
  //동 방향
  //서 방향
  //남 방향
  //북 방향
시간복잡도: O(n)=100 
*/
#define MAX 110
int n,m,y,x,d,r;
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배역입력
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  cin>>y>>x>>d>>r;
  //2.이동하기 전 이동할 원소값이 -1이면 -1바로 전 이동 값 출력
  //-1 아니면 동서남북 방향+r 인덱스의 원소값 출력
  int result=0;
  if(d==0){//동 방향
    for(int i=1;i<=r;i++){
      if(a[y][x+i]==-1){
        result=a[y][x+i-1];
        break;
      }
      else { result =a[y][x+r];}
    }
    
  }
  if(d==1){//서 방향
    for(int i=1;i<=r;i++){
      if(a[y][x-i]==-1){
        result=a[y][x-i+1];
        break;
      }
      else { result = a[y][x-r];}
    }
  }
  if(d==2){//남 방향
    for(int i=1;i<=r;i++){
    if(a[y+i][x]==-1){
      result=a[y+i-1][x];
      break;
    }
    else { result = a[y+r][x];}
    }
  }
  if(d==3){//북 방향
    for(int i=1;i<=r;i++){
    if(a[y-i][x]==-1){
      result=a[y-i+1][x];
      break;
    }
    else { result = a[y-r][x];}
    }
  }
  cout<<result<<'\n';
  return 0;
}
