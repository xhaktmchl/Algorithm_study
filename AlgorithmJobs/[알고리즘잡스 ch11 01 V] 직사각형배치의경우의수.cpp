#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 01 V] 직사각형배치의경우의수
풀이: DP: 바텀업 점화식: dp[i] = dp[i-1]+dp[i-2]
시간복잡도: O(n)=100
주의: 
*/
#define MAX 105
int dp[MAX];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  cin>>n;
  
  // 1.바텀업 점화식: dp[i] = dp[i-1]+dp[i-2]
  dp[1]=1;
  dp[2]=2;
  for(int i=3;i<=n;i++){
    dp[i] = (dp[i-1]+dp[i-2])%1000007;// 조건: 1,000,007 로 나눈 나머지
  }
  cout<<dp[n]<<'\n';
  return 0;
}
