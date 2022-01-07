#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch3 O] Card game
풀이1: 완탐으로 각 좌표에서 유닛까지의 거거리계산
시간복잡도:O(n*n)=10000
*/
int cntA=0,cntB=0;
int a[10],b[10];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  // a,b 제시카드 입력
  for(int i=0;i<10;i++){
    cin>>a[i];
  }
  for(int i=0;i<10;i++){
    cin>>b[i];
  }// 이긴 경기 카운트
  for(int i=0;i<10;i++){
    if(a[i] > b[i]) { cntA++;}
    else if(a[i] < b[i]){ cntB++;}
  }
  // 결과 출력
  if(cntA==cntB){ cout<<"D"<<'\n';}
  else if(cntA>cntB){cout<<"A"<<'\n';}
  else if(cntB>cntA){cout<<"B"<<'\n';}
  
  return 0;
}
