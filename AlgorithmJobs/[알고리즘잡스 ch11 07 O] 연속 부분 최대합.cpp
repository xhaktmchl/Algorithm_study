#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 07 O] 연속 부분 최대합
풀이: 
//1.배열 입력
  //2.점화식
  //dp[i]: i를 맨 오른쪽으로 하는 연속부분 합의 최댓값
  // dp[i] = max(dp[i-1]+a[i],d[i]);
  // 출력: dp중 최댓값
시간복잡도: O(n)
*/
#define MAX 100
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
  //2.점화식
  //dp[i]: i를 맨 오른쪽으로 하는 연속부분 합의 최댓값
  // dp[i] = max(dp[i-1]+a[i],d[i]);
  dp[0]=a[0];
  for(int i=1;i<n;i++){
    dp[i] = max(dp[i-1]+a[i],a[i]);
  }
  // 출력: dp중 최댓값
  int maxN=a[0];
  for(int i=0;i<n;i++){
    maxN = max(maxN,dp[i]);
  }
  cout<<maxN<<'\n';
  return 0;
}
