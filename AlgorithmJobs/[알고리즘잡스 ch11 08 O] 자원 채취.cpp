#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch11 08 O] 자원 채취
풀이1: dfs 오른, 아래 방향으로만 탐색 , 접근만 생각
시간복잡도: O(V+E)=n*m = 100만
풀이2: dp 
  //1.배열 입력
  //2.테이블 정의 dp[i][j]= i행,j열 까지 자원의 합의 최최대값
  //3.점화식 dp[i][j] = max(dp[i-1][j], dp[i][j-1])+a[i][j];
  // 초기값
  //4.출력: dp[n-1][m-1] 출력
시간복잡도: O(n*m)= 100만
*/
#define MAX 1010
int n,m;
int a[MAX][MAX];
int dp[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열 입력
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  //2.테이블 정의 dp[i][j]= i행,j열 까지 자원의 합의 최최대값
  //3.점화식 dp[i][j] = max(dp[i-1][j], dp[i][j-1])+a[i][j];
  // 초기값
  dp[0][0]=a[0][0];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(i-1>=0 && i-1<=n-2){ dp[i][j] = max(dp[i-1][j]+a[i][j],dp[i][j]);}
      if(j-1>=0 && j-1<=m-2){ dp[i][j] = max(dp[i][j-1]+a[i][j],dp[i][j]);}
    }
  }
  //4.출력: dp[n-1][m-1] 출력
  cout<<dp[n-1][m-1]<<'\n';
  return 0;
}
