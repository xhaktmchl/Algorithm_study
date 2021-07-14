#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<vector> // 동적배열 라이브러리
#include<algorithm>
#include <string.h>

using namespace std; // cin,cout 편하게 사용 라이브러리 

// [백준 1012 c++ VO] 유기농 배추 
// 문제: 각 배추가 모여있는 집단의 개숫를 구하라
// 접근: 각 집단의 행렬 구역 탐색 -> 2차원 그래프 dfs또는 bfs
// 풀이: 
// 이차원 배열과 방문배열 저장하고 dfs로 모든 단지 탐색
// 주의
// : 테스트 케이스가 여러개 일 수 있으니 배열들 초기화 해야 함
// : 중간에 입력받는 배열의 row,col 문제랑 반대로 해야 함= 문제 틀림
// 개념:
// memset(배열,값,sizeof(배열) : 1,2차원 배열 초기화 , #include <string.h>
#define MAX 51
int t, n, m, k;
int visited[MAX][MAX];
int graph[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int row,int col) {
	// 방문처리
	visited[row][col] = 1;

	// 사방면 탐색
	for (int i = 0; i < 4; i++) {
		int currow = row + dy[i];
		int curcol = col + dx[i];
		// 범위 조건 검사
		if (currow >= 0 && curcol >= 0 && currow < n && curcol < m) {
			// 배추 있는데 방문하지 않았으면
			if (visited[currow][curcol] == 0 && graph[currow][curcol] == 1) {
				dfs(currow, curcol);
			}
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		// 이차원 그래프 입력
		for (int j = 0; j < k; j++) {
			int row, col;
			cin >> col >> row;
			graph[row][col] = 1;
		}

		int c = 0;
		for (int j = 0; j < n; j++) {
			for (int q = 0; q < m; q++) {
				if (visited[j][q] == 0 && graph[j][q] == 1) {
					c++;
					dfs(j, q);
				}
			}
		}
		cout << c << '\n';
		// 방문,그래프 초기화
		memset(visited, 0, sizeof(visited));
		memset(graph, 0, sizeof(graph));
	}
	
	
	return 0;
}
