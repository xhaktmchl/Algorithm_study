#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [알고스팟 28.2 c++ X] 고대어 사전
// 문제: 새로운 알파벳 순서를 계산해 출력,
// 접근: 인접행렬 dfs 위상정렬?
// 시간복잡도: O(정점의 갯수*간선) = O(26*26) = 
// 풀이: 
// 단일방향 그래프 생성
// 위상정렬을 통해 알파벳의 순서를 구하고
// 반대방향 간선이 존재하면 -> 틀림, 없으면 -> 위상정렬된 알파벳 순서 출력
#define MAX 26
int t,n;
vector<vector<int>> alphabet; // 알파벳 그래프 인접행렬
vector<bool> visit;
vector<int> order;

// 단일방향 그래프 생성
void makeGraph(vector<string>& words) {
	
	alphabet = vector<vector<int>>(26, vector<int>(26, 0)); // 알파벳 26 개 인접행렬 생성
	// 인접한 2개의 단어중 공통된 순서의 알파벳 끼리 순서 검사
	for (int j = 1; j < n; j++) {
		int i = j -1;
		int len = min(words[i].size(), words[j].size());
		
		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) { // 알파벳 다르면 i->j 순서임
				
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';

				alphabet[a][b] = 1; // i->j 간선 생성
				break; 
			}
		}
	}
}

void dfs(int node) {
	
	visit[node] = 1;
	for (int i = 0; i < alphabet.size(); i++) {
		int nxt_node = i;
		if (alphabet[node][nxt_node] && !visit[nxt_node]) {
			dfs(nxt_node);
		}	
	}
	order.push_back(node); // 마지막 것 부터 넣어야 알파벳 탐색순서 반대로 푸쉬
}
//위상정렬
vector<int> topologicalSort() {

	visit = vector<bool>(MAX, 0); // 방문
	order.clear(); // 방문순서

	for (int i = 0; i < alphabet.size(); i++) {
		if (!visit[i]) {
			dfs(i);
		}
	}
	// 탐색순서 역으로 올바르게 해준 다음 , 역방향 간선있으며 빈벡터 반환, 
	reverse(order.begin(), order.end()); 
	for (int i = 0; i < alphabet.size(); i++) {
		for (int j = i + 1; j < alphabet.size(); j++) {
			if (alphabet[order[j]][order[i]]) {
				return vector<int>();
			}
		}
	}
	return order; // 반대방향 간선 없으면 알파벳 순서 벡터 반환
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	while (t--) {
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++) {
			cin >> words[i];
		}

		makeGraph(words);
		// 위상정렬
		vector<int> result = topologicalSort();

		if (result.empty()) { // 틀린 알파벳이면
			cout << "INVALID HYPOTHESIS" << '\n';
		}
		else { // 알파벳 순서 맞으면
			for (int i = 0; i < result.size(); i++) {
				cout << (char)(result[i] + 'a');
			}cout << '\n';
		}
	}

	return 0;
}
