#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<vector> // 동적배열 라이브러리
#include<algorithm>

using namespace std; // cin,cout 편하게 사용 라이브러리 

// [백준 2667 c++ VO] 단지번호붙이기 
// 문제: 각 단지별로 단지의 갯수와 단지마다의 아파트 갯수 구하기
// 접근: 각 단지의 행렬 구역 탐색 -> 2차원 그래프 dfs또는 bfs
// 풀이: 
// 이차원 배열과 방문배열 저장하고 dfs로 단지 모든 정점 탐색
// 주의: 
// 여기선 모든 정저 1번씩만 방문하므로 방문배열 초기화 필요없음 

#define MAX 100
int n,c=0;
int visited[MAX][MAX];
int graph[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

// dfs
void dfs(int row, int col) {
	// 방문처리
	visited[row][col] = 1;
	c++;

	// 사방면 검사
	for (int i = 0; i < 4; i++) {
		int currow = row + dy[i];
		int curcol = col + dx[i];
		// 범위조건 검사
		if (currow >= 0 && currow < n && curcol >= 0 && curcol < n) {
			// 아파트있고 방문하지 않았으면
			if (visited[currow][curcol] == 0 && graph[currow][curcol] == 1) {
				//visited[currow][curcol] = 1;
				//c++;
				dfs(currow, curcol);
			}
		}
		
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> n;
	// 이차원 그래프 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			 scanf("%1d",&graph[i][j]);
		}
	}

	int grpCnt = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && graph[i][j] == 1) {
				//visited[i][j] = 1;
				c = 0;
				dfs(i, j);
				v.push_back(c); 
				grpCnt++;
			}
		}
	}
	cout << grpCnt << '\n';
	// 단지갯수 오름차순 출력
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
