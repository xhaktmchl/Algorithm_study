#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 11724 c++ O] 연결 요소의 개수
// 문제: 양방향 그래프의 연결 요소(= 서로 연결되어있지 않은 집단) 의 개수를 구하라
// 접근1: 그래프-> dfs-> 기본 인접리스트로 구현 -> 모든 노드에 대해서 dfs탐색 시작(방문되지 않은 곳이 새로운 연결요소)
// 풀이: 
// 인접리스트 완성
// 1~n노드 탐색하며 방문하지 않은 곳에만 dfs시작
// 시간복잡도: O(n*간선의 갯수)
#define MAX 1001
int n, m;
vector<int> graph[MAX];
int visited[MAX];
int answer = 0;
void dfs(int node) {
	visited[node] = 1; // 방문처리
	// 연결된 노드 탐색
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (visited[next] == 0) { // 방문하지 않은곳만
			dfs(next);
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n >> m;
	// 인접리스트 그래프  입력
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	// 1~n노드 탐색하며 방문하지 않은 곳에만 dfs시작
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			dfs(i);
			answer++;
		}
	}

	cout << answer << '\n';
	return 0;
}
