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

// [백준 2583  c++ O] 영역 구하기
// 문제: 배열에서 직사각형을 제외한 영역의 개수와 영격 원소의 개수를 정렬시켜 구하는 문제
// 접근: 기본 dfs 로 탐색
// 풀이: 배열 입력받고
// 기본 완전탐색 dfs 하면서 영역의 개수와 영역원소의 개수 같이 덧셈
// 영역원소의 개수는 벡터에 저장 후 정렬
using namespace std; // cin,cout 편하게 사용 라이브러리
#define MAX 101

int graph[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int h, k, w;
vector<int> v;
int cnt = 0;
int block = 0;
void dfs(int row, int col)
{
	for (int i = 0; i < 4; i++)
	{
		int nrow = row + dy[i];
		int ncol = col + dx[i];
		// 범위 안에 있고 방문하지 않은 곳에 직사각형 없으면
		if (nrow >= 0 && ncol >= 0 && nrow < h && ncol < w)
		{
			if (visited[nrow][ncol] == 0 && graph[nrow][ncol] == 0)
			{
				visited[nrow][ncol] = 1;
				cnt++;
				dfs(nrow, ncol);
			}
		}
	}
}
int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> h >> w >> k;
	for (int i = 0; i < k; i++)
	{
		int xs, xe, ys, ye;
		cin >> xs >> ys >> xe >> ye;
		for (int j = ys; j < ye; j++)
		{
			for (int p = xs; p < xe; p++)
			{
				graph[j][p] = 1;
			}
		}

	}
	// 깊이우선탐색
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visited[i][j] == 0 && graph[i][j] == 0)
			{
				block++;
				cnt = 1;
				visited[i][j] = 1;
				dfs(i, j);
				v.push_back(cnt);
				
			}
		}
	}

	sort(v.begin(), v.end());
	
	cout << block << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}

	return 0;
}



