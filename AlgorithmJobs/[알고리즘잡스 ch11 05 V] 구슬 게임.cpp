#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 05 V] 구슬 게임
풀이: DP: 
dp[i] : i번째에 이기는지 지는지
바텀업 전화식: dp[i] = if(dp[i-1]==1 && dp[i-2]==1 && dp[i-3]==1 ) 이김; else{ 짐}
쭉 진행해보니 n이 4로 나누어 떨어지면 진다.
시간복잡도: O(n)= 100만
*/
#define MAX 10000000+5
int n;
int dp[MAX];
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n;
  // dp[i] : i번째에 이기는지 지는지
  // 바텀업 전화식: dp[i] = if(dp[i-1]==1 && dp[i-2]==1 && dp[i-3]==1 ) 이김; else{ 짐}
  // 쭉 진행해보니 n이 4로 나누어 떨어지면 진다.
  dp[0]=0; dp[1] =1; dp[2]=1; dp[3]=1;
  for(int i=4;i<=n;i++){
    if(dp[i-1]==1 && dp[i-2]==1 && dp[i-3]==1 ){ dp[i]=0;} // 이김
    else { dp[i]=1;} // 짐
  }
  if(dp[n]==1){ cout<<"YES"<<'\n';}
  else {  cout<<"NO"<<'\n';}
  return 0;
}
