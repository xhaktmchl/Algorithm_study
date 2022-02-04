#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*
[알고리즘잡스 ch16 SKM 03 V] 회전 알고리즘
풀이: 
  //1.수열 입력
  //2.회전 알고리즘
  //d=1 이면 (x+y)%n 인덱스 원소값 출력
  //d=2 이면 양수일땐 (x-y)%n 인덱스 원소값 ,음수이면 n-abs(x-y)%n 출력
시간복잡도: O(1) 
*/
#define MAX 110
int n,q,d,y,x;
int a[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.수열 입력
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  //2.회전 알고리즘
  //d=1 이면 (x+y)%n 인덱스 원소값 출력
  //d=2 이면 양수일땐 (x-y)%n 인덱스 원소값 ,음수이면 n-abs(x-y)%n 출력
  x=0;
  int idx=0;
  for(int i=0;i<q;i++){
    cin>>d>>y;
    if(d==1){
      cout<<a[(x+y)%n]<<'\n';
      x=(x+y)%n;
    }
    if(d==2){
      if((x-y)%n<0){
        idx = n-abs(x-y)%n;
      }
      else idx = (x-y)%n;
      cout<<a[idx]<<'\n';
      x=(idx);
    }
  }
  
  return 0;
}
