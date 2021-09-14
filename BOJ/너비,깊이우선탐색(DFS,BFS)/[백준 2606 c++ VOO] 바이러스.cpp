#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 2606 c++ VOO] 바이러스
// 문제: 1번 컴퓨터를 통해 감염되는 컴퓨터의 갯수 구하기
// 접근1: 기본 인접행렬 dfs : 연결된 노드탐색 
// 풀이: 
// 2차원 연결리스트 인접행렬 만들기
// 1부터 시작해서 dfs 탐색하며 감염 컴퓨터의 수 구하기
#define MAX 101
int n, edge,cnt=0;
vector<int> gr[MAX];
bool visit[MAX];

void dfs(int node) {
	visit[node] = 1;
	cnt++;

	for (int i = 0; i < gr[node].size(); i++) {
		int nxt_node = gr[node][i];
		if (!visit[nxt_node]) {
			dfs(nxt_node);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> edge;
	for (int i = 0; i < edge; i++) {
		int a, b;
		cin >> a >> b;
		
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1);
	cout << cnt-1 << '\n';
	return 0;
}
