#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 00 O] 피보나치 구현
풀이: dp: dp[i] = dp[i-1] + dp[i-2]
시간복잡도: O(n)= 
*/
#define MAX 100005
int dp[MAX];
int n;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n;
  // 1.구하려는 값 dp[i]
  // 2.점화식: dp[i] = dp[i-1] + dp[i-2]
  dp[0]=1;
  dp[1] = 1;
  for(int i=2;i<=n;i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  cout<<dp[n]<<'\n';
  return 0;
}
