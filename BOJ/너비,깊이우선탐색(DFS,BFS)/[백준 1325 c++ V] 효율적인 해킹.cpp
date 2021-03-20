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

// [백준 1325 c++ V] 효율적인 해킹
// 문제: 컴퓨터를 노드라 생각하면 가장 많은 노드 탐색하는 컴퓨터 번호 오름차순으로 출력
// 가장 기본 그래프 탐색 문제
// a가 b 신뢰 = b->a 로의 단일방향 엣지를 의미
// 접근1: 컴퓨터를 노드라 생각하면 각 노드에서의 dfs로 탐색 개수 구함
// 풀이: 각 노드에서의 기본 dfs
// 컴퓨터의 수가 최대값보다 크면 check벡터 clear후 저장
// 컴퓨터의 수가 최댓값과 같으면 check벡터에 추가
// 벡터정렬 후 출력

using namespace std; // cin,cout 편하게 사용 라이브러리
#define MAX 10001

int n, m;
vector<int> ar[MAX];
int visited[MAX];
int end_node, start_node;
int maxn=0;
vector<int> check;
int cnt = 0;

void dfs(int node)
{
	visited[node] = 1;

	for (int i = 0; i < ar[node].size(); i++) {
		if (visited[ar[node][i]] == 0) {
			cnt++;
			dfs(ar[node][i]);
		}
	}

}
int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> n>>m ;
	for (int i = 0; i < m; i++) {
		// 벡터에 엣지 추가
		cin >> end_node >> start_node;
		ar[start_node].push_back(end_node);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		dfs(i);

		if (cnt > maxn) {
			maxn = cnt;
			check.clear();
			check.push_back(i);
			
		}
		else if (cnt == maxn) {
			check.push_back(i);
		}

	}
	
	sort(check.begin(), check.end());
	for (int i = 0; i < check.size(); i++) {
		cout << check[i]<<" ";
	}
	
	return 0;
}

