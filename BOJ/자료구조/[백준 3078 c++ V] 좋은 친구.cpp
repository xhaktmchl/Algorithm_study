#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // memset 헤더
using namespace std;
// [백준 3078 c++ V] 좋은 친구 
// 문제: 등수가 k 이내에 있는 친구중 이름의 길이가 같은 좋은 친구 짝의 수 를 구하라
// 접근1: 직접 완탐 O(n*k) = 30만*30만 시간초과예상 
// 접근2: 등수=큐 -> 이름의 길이별로 큐에 등수를 저장 , 등수가 k 보다 크면 앞의 친구 팝(좋은 친구만 남김)
// 시간복잡도: 
// 풀이: 
// 이름입력, 이름의 길이에 해당하는 큐에 좋은 친구만 남을 때 까지 팝
// 좋은 친구의 쌍 구하고 현재 학생 큐에 삽입
// 끝나고 좋은 친구 쌍 출력
// 주의: 좋은 친구의 쌍 long long 
#define MAX 22
int n, k;
queue<int> q[MAX]; // 이름길이 별 큐
long long cnt = 0;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		int len = name.size();
		// 좋은 친구만 남기기
		while (!q[len].empty() && i - q[len].front() > k) {
			q[len].pop();
		}
		cnt += q[len].size(); // 좋은친구 쌍 구하기
		q[len].push(i);
	}
	cout << cnt << '\n';
	return 0;
}
