#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 03 O] 제곱수의 합
풀이: DP: 
1.구하는 값 : 1~m의 제곱수를 더해 n을 만드는 경우 중 제곱수의 최소 갯수
2.바텀업 점화식: dp[i] = min(dp[i-1*1]+dp[i-2*2]...dp[i-m*m])+1
시간복잡도: O(n*sqrt(n))=1억보다 작음
*/
#define MAX 100000+5
int n;
int dp[MAX];


int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n;
  // 1.구하는 값 : 1~m의 제곱수를 더해 n을 만드는 경우 중 제곱수의 최소 갯수
  // 2.바텀업 점화식: dp[i] = min(dp[i-1*1]+dp[i-2*2]...dp[i-m*m])+1
  dp[0]=0;
  dp[1]=1;
  dp[2]=2;
  for(int i=2;i<=n;i++){
    int minN=MAX; // 그때 그때 더해지는 j가 달라져서 초기화 해야 함
    for(int j=1;j*j<=i;j++){
      minN = min(minN,dp[i-j*j]);
    }
    dp[i]=minN+1;
  }
  cout<<dp[n]<<'\n';
  return 0;
}
