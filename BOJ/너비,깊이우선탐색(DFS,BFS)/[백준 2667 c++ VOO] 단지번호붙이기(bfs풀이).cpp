#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 2667 c++ VOO] 단지번호붙이기 
// 문제: 각 단지별로 단지의 갯수와 단지마다의 아파트 갯수 구하기
// 접근: 각 단지의 행렬 구역 탐색 -> 2차원 그래프 dfs또는 bfs -> dfs선택
// 시간복잡도: O(n*n+간선의 갯수)?? 
// 풀이1 :dfs 
// 이차원 배열과 방문배열 저장하고 dfs로 단지 모든 정점 탐색
// 방문 않한 단지 있는 곳만 탐색
// 풀이2 :bfs
// 주의: 
//: ios::sync_with_stdio(false); 사용시 cin,scanf 같이 쓰면 오류
//: 여기선 모든 정점 1번씩만 방문하므로 방문배열 초기화 필요없음 
#define MAX 26
int n;
int graph[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0,group=0;
vector<int> v;

void bfs(int row, int col) {
	queue<pair<int,int>> q;
	q.push({ row,col }); visited[row][col] = 1; // 푸쉬 및 방문처리
	cnt++;

	while (!q.empty()) {
		
		for (int i = 0; i < 4; i++) {
			int currow = q.front().first + dy[i];
			int curcol = q.front().second + dx[i];
			// 범위검사
			if (currow < 0 || currow >= n || curcol < 0 || curcol >= n) { continue; }
			if (visited[currow][curcol] == 0 && graph[currow][curcol] == 1) { // 방문하지 않았는데 단지 있으면
				q.push({ currow,curcol }); visited[currow][curcol] = 1;
				cnt++;
			}
		}
		q.pop();
	
	}
}
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 그래프 입력
	scanf("%d", &n);
	//cin >> n; // 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	// 모든 정점 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && graph[i][j] == 1) {
				group++;
				cnt = 0;
				//dfs(i, j);
				bfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	// 단지 출력
	sort(v.begin(), v.end());
	cout << group << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
