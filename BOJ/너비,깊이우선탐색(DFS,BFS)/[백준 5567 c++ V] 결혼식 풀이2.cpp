#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<string> // c++ 문자열 클래스
#include<vector> // 동적배열 라이브러리
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>  // sort와 unique 사용
#include<cmath> // 제곱이나 루트함수 사용
#include<cstring> // memset 함수
#include <set>
#include <map> // map구조체
#include <numeric> //accumulate(v.begin(), v.end(), 0);

// [백준 5567 c++ V] 결혼식 
// 문제:  그래프 로 이어진 상근이 친구의 친구등 까지  명 수 세기
// 접근:  인접리스트 양방향 그래프로 bfs 탐색
// 특이점: dfs에서 depth를 이용하는 문제
// 풀이: 
// 인접리스트 양방향 그래프 입력
// bfs 탐색으로 상근이 친구 탐색하며 방문배열과 친구배열 최신화
// 최신화된 친구배열을 이용해 이접리스트 탐색하며 친구의 친구 탐색하며 방문처리
// 방문배열 탐색해서 동기의 수 출력
// 풀이2:
// dfs로 1(상근)부터 시작하는 것만 dfs 탐색 

using namespace std; // cin,cout 편하게 사용 라이브러리 
#define MAX 501

int n, m;
int arr[MAX][MAX];
int visited[MAX];
int FrOfFriend[MAX];

void dfs(int node,int cnt) {
	
	if (cnt == 2) { // 친구의 친구까지 탐색
		return;
	}
	for (int i = 2; i <= n; i++) {
		// 방문하지 않고 친구라면
		if (arr[node][i]==1 && visited[i] == 0) {
			visited[i] = 1;
			FrOfFriend[i] = 1; // 친구인 배열 표시
			dfs(i, cnt + 1);
			visited[i] = 0;
		}
	
	}
}


int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> n >> m;
	int n1, n2;
	// 인접리스트 입력
	for (int i = 1; i <= m; i++)
	{
		cin >> n1 >> n2;
		arr[n1][n2] = 1;
		arr[n2][n1] = 1;
	}

	//bfs();
	visited[1] = 1;
	dfs(1, 0); // 노드가 1번인 상근이부터 시작해서 뎁스가 2인 것까지만 dfs

	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (FrOfFriend[i] == 1) {
			c++;
		}
	}
	cout << c << '\n';

	return 0;
}
