#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 06 O] 버튼 누르기
풀이: dp
// 1.버튼 점수 입력
// 2.dp[i][0] : i번째 빨강을 더했을 때 최대
  // dp[i][1] : i번째 초록을 더했을 때 최대
  //dp[i][2] : i번째 파랑을 더했을 때 최대
  // 바텀업 점화식:
  // dp[i][0] = max(dp[i-1][1],dp[i-1][2])+button[i][0];
  // dp[i][1] = max(dp[i-1][0],dp[i-1][2])+button[i][1];
  // dp[i][2] = max(dp[i-1][0],dp[i-1][1])+button[i][2];
시간복잡도: O(n) = 10만
*/
#define MAX 100010
int n;
int dp[MAX][3];
int button[MAX][3];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 1.버튼 점수 입력
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>button[i][0]>>button[i][1]>>button[i][2];
  }
  // 2.dp[i][0] : i번째 빨강을 더했을 때 최대
  // dp[i][1] : i번째 초록을 더했을 때 최대
  //dp[i][2] : i번째 파랑을 더했을 때 최대
  // 바텀업 점화식:
  // dp[i][0] = max(dp[i-1][1],dp[i-1][2])+button[i][0];
  // dp[i][1] = max(dp[i-1][0],dp[i-1][2])+button[i][1];
  // dp[i][2] = max(dp[i-1][0],dp[i-1][1])+button[i][2];
  dp[1][0]=button[1][0]; dp[1][1]=button[1][1]; dp[1][2]=button[1][2]; 
  for(int i=2;i<=n;i++){
    dp[i][0] = max(dp[i-1][1],dp[i-1][2])+button[i][0];
    dp[i][1] = max(dp[i-1][0],dp[i-1][2])+button[i][1];
    dp[i][2] = max(dp[i-1][0],dp[i-1][1])+button[i][2];
  }
  // 출력:점수 최댓값
  cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<'\n';
  return 0;
}
