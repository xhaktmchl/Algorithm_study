#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 11279 c++ O] 최대 힙
// 문제: 맥스 힙자료구조를 이용해 입력괴 출력을 하라
// 접근: 맥스힙 뼈대문제 -> 우선순위큐 stl 이용
// 시간복잡도: O(n*logn)
// 풀이:
// 0 입력 -> 빈큐 아니면 최댓값 출력, 없으면 0출력
// 그 외 숫자 맥스힙에 푸쉬
priority_queue<int> maxHeap;
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	while (n--) {
		int num; cin >> num;
		if (num == 0) { // 최댓값 출력
			if (!maxHeap.empty()) {
				cout << maxHeap.top() << '\n';// 맥스힙 최댓값 
				maxHeap.pop();
			}
			else { cout << 0 << '\n'; }
		} // 맥스힙 푸쉬
		else { maxHeap.push(num);}
	}
	return 0;
}
