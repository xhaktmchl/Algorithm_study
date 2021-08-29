#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 15828 c++ O] Router 
// 문제: 
// 접근: 라우터 패킷 처리 순서대로 -> 큐
// 라우터의 버퍼는 패킷의 갯수! , 패킷의 데이터 합이라 생각해 애먹음
// 시간복잡도: O() = 
// 풀이: 
// 패킷을 입력
// -1 종료
// 0 이면 버퍼에서 팝
// 버퍼초과한 경우 입력무시
// 그외 경우 라우터 큐에 푸쉬
// 큐에 남아있는 수 출력
int n,pack,sum=0;
queue<int> q;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	
	while (1) {
		cin >> pack;
		if (pack == -1) { break; }
		if (pack == 0) { 	q.pop(); continue; }
		if (q.size()+1 > n) { continue; } // 버퍼초과
		q.push(pack);
	}
	if (q.empty()) { cout << "empty" << '\n'; }
	else {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
	}
	return 0;
}
