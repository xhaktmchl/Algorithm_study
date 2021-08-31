#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 11724 c++ OO] 연결 요소의 개수
// 문제: 양방향 그래프의 연결 요소(= 서로 연결되어있지 않은 집단) 의 개수를 구하라
// 접근1: 1차원 그래프-> dfs-> 기본 인접리스트로 구현 -> 모든 노드에 대해서 dfs탐색 시작(방문되지 않은 곳이 새로운 연결요소)
// 시간복잡도: O(n+간선의 갯수) : 모든 노드 방문n, 모든 간선 방문 m
// 풀이: 
// 인접리스트 완성
// 1~n노드 탐색하며 방문하지 않은 곳에만 dfs시작
#define MAX 1001
int n,m,u, v;
vector<int> gr[MAX];
bool visit[MAX];

void dfs(int node) {
	// 방문처리
	visit[node] = 1;
	// 인접 노드 탐색
	for (int i = 0; i < gr[node].size(); i++) {
		int node_idx = gr[node][i];
		if (!visit[node_idx]) {
			dfs(node_idx);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 인접 리스트 입력
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	// 1~n 노드에서 dfs 로 연결요소 구하기
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
			c++;
		}
	}
	cout << c << '\n';
	return 0;
}
