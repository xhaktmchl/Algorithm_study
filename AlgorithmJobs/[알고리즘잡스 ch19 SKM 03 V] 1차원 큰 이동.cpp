#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch19 SKM 03 V] 1차원 큰 이동
풀이: 구현 이동
  //1.배역입력
  //2.d방향으로 t만큼 이동했을 때 좌우 맨 끝까지 넘어가는 경우 계속 
  // 우 이동 좌표 저장
  // 방향갱신
  // 좌 이동좌표 저저장/
  // 방향갱신
  // 3.마지막 남은 d방향으로 이동 저장
  //4.출력:위치 방향, 
시간복잡도: O()= 
*/
#define MAX 110
int n,x,d,t;
int result;
int dx[2]={-1,1};

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.배역입력
  cin>>n>>x>>d>>t;
  
  int cycle = 2*n-2;//주기: 2*n-2
  t%= cycle;
  //2.d방향으로 t만큼 이동했을 때 좌우 맨 끝까지 넘어가는 경우 계속 
  while(x+t*dx[d]<1 || x+t*dx[d]>n){
    // 좌 이동좌표 저저장/
    if(x+t*dx[d]<1){
      t-=x-1; // 이동횟수 감소
      x=1;
      d=1;// 방향갱신
    }
    else if(x+t*dx[d]>n){// 우 이동 좌표 저장
      t-=n-x;
      x=n;
      d=0;// 방향갱신
    }
  }
  
  // 3.마지막 남은 d방향으로 이동 저장
  x=x+t*dx[d];
  //4.출력:위치 방향, 
  cout<<x<<" "<<d<<'\n';
  return 0;
}
