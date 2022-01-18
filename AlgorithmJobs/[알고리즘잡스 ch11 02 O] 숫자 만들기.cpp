#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 02 O] 숫자 만들기
풀이: DP: 더하느 경우의 수+1,+2,+3 세가지, n이 되기 위해선 n-1+1,n-2+2,n-3+3
1.구하는 값 : n을 만드는 경우의 수
2.바텀업 점화식: dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
시간복잡도: O(n)=100000
*/
#define MAX 100000+5
int n;
int dp[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n;
  // 1.구하는 값 : n을 만드는 경우의 수
  // 2.바텀업 점화식: dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
  dp[1]=1;
  dp[2]=2;
  dp[3]=4;
  for(int i=4;i<=n;i++){
    dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%1000007 ;
  }
  cout<<dp[n]<<'\n';
  return 0;
}
