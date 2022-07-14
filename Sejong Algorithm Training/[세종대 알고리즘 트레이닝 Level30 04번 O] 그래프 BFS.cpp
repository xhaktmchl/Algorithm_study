#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level30 04번 O] 그래프 BFS
문제:
접근:
풀이: bfs
	//1.입력
	//2.인접행렬 bfs(노드)
	//1)큐 생성, 푸쉬
	//2)빈큐 일때 까지 반복
	//큐 팝 , 출력
	//인접 노드 모두 푸쉬
	//방문검사, 노드 있으면
	//큐 푸쉬, 방문처리
시간복잡도: O(n+m)=
*/
int n;
bool visit[100];
int ad[100][100] = {
	{0,0,0,0,1,0},
	{1,0,1,0,0,1},
	{1,0,0,1,0,0},
	{1,1,0,0,0,0},
	{0,1,0,1,0,1},
	{0,0,1,1,0,0}
};

void bfs(int node) {
	queue<int> q;
	q.push(node); visit[node] = 1;

	while (!q.empty()) {
		int cur = q.front();
		cout << cur << '\n';
		q.pop();

		for (int i = 0; i < 6; i++) {
			if(visit[i]==0 && ad[cur][i]==1){
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	//2.인접행렬 bfs(노드)
	//1)큐 생성, 푸쉬
	//2)빈큐 일때 까지 반복
	//큐 팝 , 출력
	//인접 노드 모두 푸쉬
	//방문검사, 노드 있으면 
	//큐 푸쉬, 방문처리
	bfs(n);

	return 0;
}
