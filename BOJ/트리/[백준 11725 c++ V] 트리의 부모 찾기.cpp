#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 11725 c++ V] 트리의 부모 찾기
// 문제: 루트노드 1 이라 하고 모든 노드의 부모노드를 출력
// 접근1: 트리 -> 구조체 직접 구현 -> 시도는 안함
// 접근2: 트리 -> 연결리스트 양방향 벡터로 구현-> dfs 탐색 , 부모노드= 배열에 저장
// 시간복잡도: O(정점갯수+간선갯수) = n+n = 20만 
// 풀이1: 
// 트리를 연결리스트로 입력
// 루트노드무터 dfs
// dfs하면서 부모노드 저장
// 모든 부모노드 출력
#define MAX 100001
int n;
vector<int> tree[MAX];
bool visit[MAX];
int parent[MAX];

void dfs(int node) {
	visit[node] = 1;
	 
	for (int i = 0; i < tree[node].size(); i++) {
		int nxt = tree[node][i];

		if (!visit[nxt]) {
			visit[nxt] = 1;
			parent[nxt] = node; // 자식노드에 부모노드 기록
			dfs(nxt);
		}
	}
 }

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 트리 그래프 입력
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	dfs(1); // 루트 1 노드부터 탐색
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}
