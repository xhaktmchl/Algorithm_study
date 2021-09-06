#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 1927 c++ V] 최소 힙
// 문제: 민 힙자료구조를 이용해 입력괴 출력을 하라
// 접근: 민힙 뼈대문제 -> 우선순위큐 stl 이용
// 시간복잡도: O(n*logn)
// 풀이:
// 최소힙 구현 
// 0 입력 -> 빈큐 아니면 최솟값 출력, 없으면 0출력
// 그 외 숫자 민힙에 푸쉬
//개념:
// priority_queue<int,vector<int>,greater<int>> minHeap; // priority_queue자체가 vector<int> 로 구현되기 때문에 자료형 추가하고 함수 넣어야 함
priority_queue<int,vector<int>,greater<int>> minHeap; // priority_queue자체가 vector<int> 로 구현되기 때문에 자료형 추가하고 함수 넣어야 함
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	while (n--) {
		int num; cin >> num;
		if (num == 0) { // 최솟값 출력
			if (!minHeap.empty()) { 
				cout << minHeap.top() << '\n';// 민힙 최소값
				minHeap.pop();
			}
			else { cout << 0 << '\n'; }// 빈 예외
		} // 민힙 푸쉬
		else { minHeap.push(num);}
	}
	return 0;
}
