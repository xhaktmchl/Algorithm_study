#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 1707 c++ V] 이분 그래프
// 문제:각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할된 이분 그래프  인지 검사
// 접근1:기본 그래프-> dfs  -> 인접리스트로 구현 -> 그룹을 나누는 color 정보가 추가됨
// color 가 0이면 방문 않안 것, 1=A그룹 , 2=B그룹 ,// 그룹은 3-그룹번호 하면 1,2,1,2, 번갈아 됨
// dfs탐색 시 인접 노드 중 같은 그룹의 노드 있으면 이분그래프 아님
// 풀이: 
// 인접리스트 완성
// 1~n노드 탐색하며 방문하지 않은 곳에만 dfs시작 
// 이분그래프인지 출력
// 시간복잡도: O()??
#define MAX 20001
int t, v, e;
vector<int> graph[MAX];
int color[MAX];
int answer = 0;

//dfs
void dfs(int node,int col) {
	color[node] = col;
	
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (color[next] == 0) {
			dfs(next, 3 - col); // 현재가 1그룹->다음은 3-1=2그룹, 그룹 번갈아 지도록
		}
		else if (color[next] == color[node]) { // 다음 노드가 현재 노드와 같은 그룹이면 이분그래프 아님
			answer = 1;
			return;
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >>t;
	for (int i = 0; i < t; i++) {
		cin >> v >> e;
		// 테스트 케이스 마다 변수 초기화
		answer = 0;
		memset(color, 0, sizeof(color));
		for (int j = 1; j <= v; j++) {
			graph[j].clear();
			
		}
		
		// 인접 리스트 입력
		for (int j = 0; j < e; j++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// 모든 노드에서 이분그래프인지 검사
		for (int j = 1; j <= v; j++) {
			if (color[j] == 0) { // 그룹이 정해지지 안했으면
				dfs(j,1); //
				if (answer == 1) { break; } // 이분그래프가 아니면 중단
			}
		}
		
		string a = answer == 0 ? "YES" : "NO";
		cout << a << '\n';
	}
	return 0;
}
