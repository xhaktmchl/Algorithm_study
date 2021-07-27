#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring> // memset 헤더
using namespace std;
// [백준 13023 c++ V] ABCDE  
// 문제: A-B, B-C, C-D, D-E와 같은 연속 4쌍의 친구 관계가 있는지 확인하는 문제
// 접근1: 그래프 인접리스트 친구관계 -> dfs로 그래프 탐색해서 연속 4관계 있는지 검사
// 풀이: 
// 그래프 인접 리스트로 입력
// 각 노드마다 dfs탐색
// 시간복잡도: O(노드의 개수* 간선의 갯수)
#define MAX 2001
int n, m;
int answer=0;
int visited[MAX];
vector<int> v[MAX];

//dfs 탐색
void dfs(int node, int cnt) {
	
	if (cnt == 4) {
		answer = 1;
		return;
	}
	visited[node] = 1;
	int size = v[node].size();
	for (int i = 0; i < size; i++) {
		int node_idx = v[node][i];
		if (visited[node_idx] == 0) {
			//visited[node_idx] = 1;
			dfs(node_idx, cnt + 1);
		}
	}
	visited[node] = 0;
}
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 그래프 입력
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
		
	}

	//dfs탐색
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, 0);
		if (answer == 1) { break; }
	}
	cout << answer << '\n';
	return 0;
}
