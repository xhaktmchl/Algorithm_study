#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch8 04 VO] division
풀이: 재귀: 큰 수부터 각 자리의 숫자를 탐색
시간복잡도: O(n^n)=20^20?? 헷갈림
*/
#define MAX 25
int n,cnt=0;
int result[MAX];

//완탐 재귀: 
void re(int idx,int sum,int curNum){
  // 기저사례: 총 합이 n이 되면 출력
  if(sum>=n){
    cout<<result[0];
    for(int i=1;i<idx;i++){
      cout<<"+"<<result[i];
    }cout<<'\n';
    cnt++;
    return;
  }
  // idx번째 숫자 1~n-1 까지 탐색
  for(int i=curNum;i>=1;i--){
    if(sum+i>n){continue;}// 백트랙킹: 합이 n보다 크면 재귀 안함
    
    result[idx] = i;
    re(idx+1,sum+i,i);
  }
}
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>n;
  re(0,0,n-1);
  cout<<cnt<<'\n';
  return 0;
}
