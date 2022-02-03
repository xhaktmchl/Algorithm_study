#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 09 O] 연속 부분 최대합 L
풀이: dp , 
//1.배열 입력
  //2.테이블 정의 dp[i]= i번째 까지 연속부분 합의 최댓값
  //3.점화식 dp[i] = max(dp[i-1]+a[i],a[i]);
  // 초기값
  //4.출력: 최댓합
시간복잡도: O(n)= 100만
*/
#define MAX 1000010
int n;
int a[MAX];
int dp[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열 입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  //2.테이블 정의 dp[i]= i번째 까지 연속부분 합의 최댓값
  //3.점화식 dp[i] = max(dp[i-1]+a[i],a[i]);
  // 초기값
  dp[0] = a[0];
  for(int i=1;i<n;i++){
    dp[i] = max(dp[i-1]+a[i],a[i]);
  }
  //4.출력: 최댓합 
  int maxN=-2000000000;
  for(int i=0;i<n;i++){
    maxN = max(maxN,dp[i]);
  }
  cout<<maxN<<'\n';
  return 0;
}
