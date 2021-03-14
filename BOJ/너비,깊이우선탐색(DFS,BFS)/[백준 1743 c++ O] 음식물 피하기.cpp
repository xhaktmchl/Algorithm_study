#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<string> // c++ 문자열 클래스
#include<vector> // 동적배열 라이브러리
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>  // sort와 unique 사용
#include<cmath> // 제곱이나 루트함수 사용
#include<cstring> // memset 함수
#include <set>
#include <map> // map구조체
#include <numeric> //accumulate(v.begin(), v.end(), 0);

// [백준 1743 c++ O] 음식물 피하기 
// 문제: 배열중 인접해있는 음식물의 크기의 합이 가장 큰 음식물의 크기를 출력
// 접근: 4방향인접하면 하나의 음식물로 본다 -> 기본 dfs 탐색
// 풀이: 배열의 크기와 음식물 위치 입력
// 기본 완전탐색 dfs 
// 음식물의 최대크기 최신화
// 음식물 최대크기 출력

using namespace std; // cin,cout 편하게 사용 라이브러리
#define MAX 101

int n, m, k;
int ar[MAX][MAX];
int visited[MAX][MAX];
int cnt = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int max_n = 0;
// 기본dfs
void dfs(int row, int col)
{
	visited[row][col] = 1;
	cnt++;
	
	for (int i = 0; i < 4; i++) {
		int nrow = row + dy[i];
		int ncol = col + dx[i];

		if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
			if (visited[nrow][ncol] == 0 && ar[nrow][ncol] == 1) {
				dfs(nrow, ncol);
			}
		}
	}
}

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int ro, co;
		cin >> ro >> co;
		ar[ro-1][co-1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && ar[i][j] == 1) {
				dfs(i, j);
				max_n = max(max_n, cnt);
				cnt = 0;
			}
		}
	}

	cout << max_n;
	
	return 0;
}

