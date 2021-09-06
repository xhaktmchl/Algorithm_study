#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [알고스팟 23.4 c++ V] 변화하는 중간값
// 문제: 수열에 수를 계속 추가하며 변화하는 중간값의 합을 출력
// 접근1: 벡터에 수 삽입-> 정렬 -> 중간값 구하기 ,  퀵정렬 시간초과
// 접근2: 수열 절반 최대힙, 수열절반 최소힙에 넣으면 최대힙의 루트가 중간값
// 시간복잡도: O(n*logn)
// 풀이:
// 수를 최대 최소힙에 번갈아 푸쉬 ( 문제에서 짝수일 때 중간값 ->  최소힙 최대힙 사이즈 같으면 최대힙에 넣으면 부조건 최대힙 루트가 중간값
// 최소힙에 넣어준 수가 최대힙 보다크면 두 수 스왑 -> 최대힙 루트가 중간값
// 중간갑 합 , 다음 순열값 계산
//개념:
// priority_queue<int,vector<int>,greater<int>> minHeap; // priority_queue자체가 vector<int> 로 구현되기 때문에 자료형 추가하고 함수 넣어야 함
int t,n,a,b;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		priority_queue<int> maxH;
		priority_queue<int, vector<int>, greater<int>> minH;

		long long medsum = 0; //중간  합
		long long seed = 1983; // 수열 수
		for (int i = 1; i <= n; i++) {
			if (maxH.size() == minH.size()) { //힙 사이즈 같은 경우
				maxH.push(seed);
			}
			else { minH.push(seed); } // 다른경우
			// 중간값 크기 조정
			if (!maxH.empty() && !minH.empty() && maxH.top() > minH.top()) { // 최소힙의 루크가 더 작은 경우
				int tp1 = maxH.top(), tp2 = minH.top();
				maxH.pop();
				minH.pop();
				maxH.push(tp2);
				minH.push(tp1);
			}
			
			medsum = (medsum + maxH.top()) % 20090711; // 중간 합
			seed = (seed * a + b) % 20090711; // 다음 수열
		}
		cout << medsum << '\n';
	}
	return 0;
}
