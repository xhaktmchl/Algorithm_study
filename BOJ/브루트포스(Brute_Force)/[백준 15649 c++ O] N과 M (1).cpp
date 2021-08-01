#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 15649 c++ O] N과 M (1) 
// 접근1: dp[n] = dp[n-1]+dp[n-2]+dp[n-3] -> 이번엔 완전탐색으로 구현
// 접근2: 완전탐색 -> 재귀dfs -> 재귀중간 순열 체크하면 방문한것 초기화 해야함
// 시간복잡도: n*(n-1)*...1 가지 경우의 수 = O(n!)
// 풀이1: 
// 수 입력
// 재귀로 모든 수열 탐색

#define MAX 10
int n,m;
bool visited[MAX]; // int말고  bool 형이 메모리 적음

// 완전탐색 dfs
void dfs(int num,int cnt,vector<int> v) {
	visited[num] = 1; v.push_back(num); // 방문처리, 수열 추가
	// 원하는 길이가 되면 수열 출력
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}
	// 1~n까지 탐색
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0){
			dfs(i, cnt + 1,v);
			visited[i] = 0; // 재귀 이므로 방문 초기화
		}
		
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> m;
	// 완전탐색 dfs
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited)); // 방문배열 초기화
		vector<int> v;
		dfs(i, 1,v);
	}
	return 0;
}
