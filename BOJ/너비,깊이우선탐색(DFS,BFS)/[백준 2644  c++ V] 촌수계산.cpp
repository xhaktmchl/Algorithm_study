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

// [백준 2644  c++ V] 촌수계산
// 문제: 부모와 자식의 촌수를 1로 해서 주어진 두 사람의 촌수를 구하는 문제
// 접근: 인접행렬방식 dfs 로 부모와 자식의 관계를 양방향 그래프로 표현
// 풀이: 벡터배열로 2차원 배열에 양방향 그래프 입력
// 찾기만 하고 초기화 않해줘도 되는 기본 dfs 이용해서 인접리스트 그래프 탐색

using namespace std; // cin,cout 편하게 사용 라이브러리
#define MAX 101

vector<int> graph[MAX];
int visited[MAX];
int n, target1, target2, m;
int ans = -1;

void dfs(int p, int c,int cnt)
{
	visited[p] = 1;
	// 종료조건
	if (p == c) {
		ans = cnt; return;
	}
	
	for (int i = 0; i < graph[p].size(); i++)
	{
		if (visited[graph[p][i]] == 0)
		{
			dfs(graph[p][i], c, cnt + 1);
		}
	}
}
int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> n >> target1 >> target2 >> m;
	for (int i = 0; i < m; i++)
	{
		int par, child;
		cin >> par >> child;
		// 양방향 그래프 삽입
		graph[par].push_back(child);
		graph[child].push_back(par);

	}
	dfs(target1, target2, 0);
	cout << ans;

	return 0;
}



