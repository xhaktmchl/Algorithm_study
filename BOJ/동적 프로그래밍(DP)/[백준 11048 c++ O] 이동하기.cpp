#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 11048 c++ O] 이동하기  
// 문제: 이차원 그래프의 n,m 위치까지 최대합을 구해라
// 접근: 이차원 그래프 최대합 -> bfs -> 될 것 같음 , 시도는 안 해봄
// 접근2: 이차원 그래프 위,왼 방향이 없어 뒤로 돌아가는 것 불가능 -> dp 
// i행j열 은 1.왼->오, 2.위->아래, 3.왼쪽 위 대각선 으로부터 이동
// dp점화식 , 
// dp[i][j]= (i,j) 까지의 최대합
// dp[i][j] = max(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) + graph[i][j]
// 시간복잡도: O(n*m) = 100만
// 풀이: 
// 그래프 입력
// 바텀업 dp구현
#define MAX 1001
int n, m;
int graph[MAX][MAX];
int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin>>graph[i][j];
		}
	}

	// 바텀업 dp 구현
	// dp점화식 , 
	// dp[i][j] = max(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) + graph[i][j]
	dp[1][1] = graph[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) { continue; }
			if (j - 1 >= 1) { dp[i][j] = max(dp[i][j],dp[i][j - 1] + graph[i][j]) ; } // 왼->오
			if(i-1>=1){ dp[i][j] = max(dp[i][j], dp[i - 1][j] + graph[i][j]); } // 위->아래
			if (i - 1 >= 1 && j-1>=1) { dp[i][j] = max(dp[i][j], dp[i - 1][j-1] + graph[i][j]); } // 왼쪽 위 대각선
		}
	}
	cout << dp[n][m] << '\n';
	return 0;
}



