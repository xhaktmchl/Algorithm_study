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

// [백준 2644 c++ VV] 촌수계산
// 문제: 가족 구성원 사이의 촌수 계산 ,가족을 노드라 하고 찾고자 하는 가족의 촌수 계산하고 없으면 -1출력 탐색 문제
// 가족 관계는 양방향 그래프라 생각해야 함
// 접근1: 가족을 노드라 하고 기본 인접행렬 그래프 dfs탐색 , 인접행렬은 벡터로 구현
// 풀이: 가족관계 벡터 인접행렬에 저장
// 찾고자 하는 가족노드에서 dfs 시작하고
// 다른 풀이들은 dfs함수에서 visited 노드 초기화 않해주는데 여러 경로 존재할 시 초기화 해야한다고 생각해서 해줌
// 목표 가족 찾으면 뎁스 저장 후 출력

using namespace std; // cin,cout 편하게 사용 라이브러리
#define MAX 101

int n, node1, node2,m;
vector<int> ar[MAX];
int visited[MAX];
int cnt = 0;
int ans = -1;

void dfs(int start, int end,int cnt)
{
	if (start == end) { ans = cnt; return; }
	for (int i = 0; i < ar[start].size(); i++) {
		if (visited[ar[start][i]] == 0) {
			visited[start] = 1;
			dfs(ar[start][i], end,cnt+1);
			visited[start] = 0; // 여러 경로일 때 경우 노드방문 초기화 해야함
		}
	} 
}

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> n>> node1>>node2>>m;
	for (int i = 0; i < m; i++) {
		int pa, ch;
		cin >> pa >> ch;
		ar[pa].push_back(ch);
		ar[ch].push_back(pa);
	}

	visited[node1] = 1;
	dfs(node1, node2,0);
	cout << ans;
	
	return 0;
}

