#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch8 04 V] division
풀이: 재귀: 큰 수부터 각 자리의 숫자를 탐색
시간복잡도: O()=??
*/
#define MAX 25
int n,c=0;
int result[MAX];// 더한 결과 배열
bool visit[MAX];// 방문 배열

// 재귀: 더하는 숫자
void re(int idx,int sum,int num){
  // 기저사례: 
  if(sum >= n){
    for(int i=0;i<idx-1;i++){
      cout<<result[i]<<"+";
    }cout<<result[idx-1]<<'\n';
    c++; // 자연수의 개수 카운트
    return;
  }
  // 숫자 1~ n 탐색
  for(int i=num;i>=1;i--){
    // 예외처리: 합이 n보다 작을 때만
    if(sum+i > n){continue;}
    if(i<= num){ // 내림차순으 합만 구하기
      result[idx]=i;
      re(idx+1,sum+i,i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n;
  re(0,0,n-1);
  cout<<c<<'\n';
  return 0;
}
