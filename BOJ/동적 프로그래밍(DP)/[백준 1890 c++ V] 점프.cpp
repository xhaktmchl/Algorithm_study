#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[백준 1890 c++ V] 점프
문제: 2차원 그래프에서 해당 인덱스의 숫자만큰 오른쪽,아래 이동해서 맨 오른쪽 아래까지 경로의 수를 구하라
접근: 2차원 그래프 오른쪽/아래 방향으로 뒤로 돌아갈수 없음 -> 2차원 dp로 그 위치까지의 경로의 갯수 저장하며 반복문 완탐 
점화식: dp[i][j]: i행j열 까지 이동경로의 수
이동할 칸의 경로 수 = 새로 이동할 칸의 경로 수 + 새롭게 추가될 경로수
(i,j) 일 때 1.오른쪽 이동 dp[i][j + a[i][j]] =  dp[i][j + a[i][j]]+ dp[i][j];
2. 아래쪽 이동 dp[i + a[i][j]][j] += dp[i][j];
주의: 처음에 점화식을 경로가 +1 되는 것으로 생각해 틀림
시간복잡도: O(n*n) = 1만
풀이1: 
그래프 입력
dp 구현
*/
#define MAX 101
int n;
int a[MAX][MAX];
long long dp[MAX][MAX];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// 바텀업 dp 구현
	// dp[i][j]: 그 칸으로 이돌할 수 있는 경로의 갯수
	dp[0][0] = 1; // 처음에 1로 설정해서 다음 이동경로 계산 하게 함
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) { continue; } // a[i][j]=0 일때 값이 더해져서 예외처리
			if (dp[i][j] != 0) {
				if (j + a[i][j] < n) { dp[i][j + a[i][j]]+= dp[i][j]; } // 열 범위 안에 있으면 오른쪽 이동 칸 dp 증가
				if (i + a[i][j] < n) { dp[i + a[i][j]][j] += dp[i][j]; } // 행 범위 안에 있으면 아래쪽 이동 칸 dp 증가
			}
		}
	}
	cout << dp[n - 1][n - 1] << '\n';
	return 0;
}
