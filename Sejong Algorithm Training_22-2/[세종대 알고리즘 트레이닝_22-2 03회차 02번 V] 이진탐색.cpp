#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 03회차 02번 V] 이진탐색
문제:
접근: 
풀이: 
	//1.입력
	//2.이진탐색: 반복문 이용
	//1) 시작 끝 점 차가 >0 일때는 계속 반복
	//중간점이 목표값보다 작으면 s = mid+1
	// 아니면 e = mid
	//2)반환: e+1
	//3.출력: 마지막 탐색 인덱스
시간복잡도: O(logn)= 
개념:
*/
int n,k;
int a[1000010];

int binarySearch(int s, int e) {
	int mid = 0;
	
	while (e - s > 0) {
		mid = (s + e) / 2;
		if (a[mid] < k) { s = mid + 1; }
		else e = mid;
	}
	return e+1;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;
	//2.이진탐색: 반복문 이용
	//1) 시작 끝 점 차가 >0 일때는 계속 반복
	//중간점이 목표값보다 작으면 s = mid+1
	// 아니면 e = mid
	//2)반환: e+1
	int result = binarySearch(0, n);
	//3.출력: 마지막 탐색 인덱스
	cout << result << '\n';
	return 0;
}
