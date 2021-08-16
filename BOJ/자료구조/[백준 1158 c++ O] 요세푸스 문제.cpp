#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 1158 c++ O] 요세푸스 문제
// 문제: 
// 접근1: 벡터로 순환 탐색 -> 맞음
// 접근2: 큐 로 순환 탐색 -> 맞음
// 시간복잡도: 
// 풀이: 
// 개념: 큐로 순환
int n, k;
queue<int> q;

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	// 반복해서 k번째 사람 빼기
	cout << '<';
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		if (q.size() != 1) { cout << ", "; }
		q.pop();
	}
	cout << '>';
	return 0;
}
