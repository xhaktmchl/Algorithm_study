#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 04 V] 카드 놀이
풀이: dp , 처음 더해지는 경우의 수를 하나 빼먹어서 고생
// 1.카드 점수 입력
// 2.dp[i][0]: i번째 수 안더한 경우
  // dp[i][1]: i번째 수 더하고, i-1번째 수 안더한 합의 최대값
  // dp[i][2]: i번째 수 더하고, i-1번째 수 더하고, i-2번재 수 안더한 합의 최대값
  // 바텀업 점화식: 
  //dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
  //dp[i][1] = dp[i-1][0]+a[i];
  //dp[i][2] = dp[i-2][0]+a[i-1]+a[i];
시간복잡도: O(n)= 10만
*/
#define MAX 100010
int n;
long long dp[MAX][3];
long long a[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 1.카드 점수 입력
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  // 2.dp[i][0]: i번째 수 안더한 경우
  // dp[i][1]: i번째 수 더하고, i-1번째 수 안더한 합의 최대값
  // dp[i][2]: i번째 수 더하고, i-1번째 수 더하고, i-2번재 수 안더한 합의 최대값
  // 바텀업 점화식: 
  //dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
  //dp[i][1] = dp[i-1][0]+a[i];
  //dp[i][2] = dp[i-2][0]+a[i-1]+a[i];
  dp[1][0]=0; dp[1][1]= a[1]; dp[1][2]=a[1];
  dp[2][0]=a[1]; dp[2][1]= a[2]; dp[2][2]=a[1]+a[2];
  for(int i=3;i<=n;i++){
    dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
    dp[i][1] = dp[i-1][0]+a[i];
    dp[i][2] = dp[i-2][0]+a[i-1]+a[i];
  }
  
  cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<'\n';
  return 0;
}
