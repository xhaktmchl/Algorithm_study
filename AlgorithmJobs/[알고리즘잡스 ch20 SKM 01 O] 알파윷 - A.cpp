#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch20 SKM 01 O] 알파윷 - A
풀이: 완탐 재귀
  // 1.입력
  //2.재귀: 1~10 번 윷 결과
  //기저조건: 10회 모두 던젔으면 결과 출력 , 종료
  //완탐 재귀: idx번째 회차 4가지 말 배정 경우 
  //3.k번 째 결과 출력
시간복잡도: O(4^10)=
*/
#define MAX 2000000
int k,cnt=0;
int a[15];

//2.재귀: 1~10 번 윷 결과
void re(int idx){
  if(idx>=10){//기저조건: 10회 모두 던젔으면 결과 출력 , 종료
    cnt++;
    if(cnt==k){//3.k번 째 결과 출력
      for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
      }cout<<'\n';
    }
    return;
  }
  //완탐 재귀: idx번째 회차 4가지 말 배정 경우 
  for(int i=1;i<=4;i++){
    a[idx]=i;
    re(idx+1);
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 1.입력
  cin>>k;
  //2.재귀: 1~10 번 윷 결과
  re(0);
  //기저조건: 10번이 모두 4 이면 종료
  //1~10번 윷 재귀
  //3.k번 째 결과 출력
  return 0;
}
