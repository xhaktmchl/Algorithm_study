#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch19 SKM 04 O] 2차원 큰 이동
풀이: 구현 이동
  //1.입력
  //2.이동횟수 d방향으로 배열의 주기로 나눈 나머지 저장
  //3.y행,x열에서 이동 시 배열의 맨 끝에 도착했을 경우 계속반복
  //상
  //하
  //좌
  //우
  //4.남은 횟수 d방향으로 이동
  //5.출력 y,x
시간복잡도: O()= 
주의: 이동 문제에선 if if if로 하면 갱신된 것이 다시 if 로 검사돼서 elseif로 해야 함
*/
int n,m,y,x,d,t;
int dx[]={0,0,-1,1}; // 상하좌우 순
int dy[]={-1,1,0,0};

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.입력
  cin>>n>>m>>y>>x>>d>>t;
  //2.이동횟수 d방향으로 배열의 주기로 나눈 나머지 저장
  if(d==0 || d==1){
    t=t%(2*n-2);
  }
  else{
    t=t%(2*m-2);
  }
  //3.y행,x열에서 이동 시 배열의 맨 끝에 도착했을 경우 계속반복
  while(y+t*dy[d]<1 || y+t*dy[d]>n || x+t*dx[d]<1 || x+t*dx[d]>m){
    //상
    if(d==0){
      t-=y-1;
      y=1;
      d=1;
    }
    //하
    else if(d==1){
      t-=n-y;
      y=n;
      d=0;
    }
    //좌
    else if(d==2){
      t-=x-1;
      x=1;
      d=3;
    }
    //우
    else if(d==3){
      t-=m-x;
      x=m;
      d=2;
    }
  }
  
  //4.남은 횟수 d방향으로 이동
  x=x+dx[d]*t;
  y=y+dy[d]*t;
  //5.출력 y,x
  cout<<y<<" "<<x<<'\n';
  return 0;
}
