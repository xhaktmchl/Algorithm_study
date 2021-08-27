#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 2304 c++ V] 창고 다각형
// 문제:
// 접근: 최소넓이 -> 스택문제인데 스택으로 안떠오름
// 접근2: 완탐
// 시간복잡도: 
// 풀이:  
// 좌표의 기둥 높이 입력
// a[i][0] = i 좌표의 높이 저장 , a[i][1] = i까지 왼->오 최댓값 저장, a[i][2] = 오->왼 최댓값저장
// 왼->오 최대값 저장
// 오-> 왼 최갯값 저장
// 최소넓이 구하기: 2방향의 최댓값 중 작은 값이 최소넓이를 구하는 기둥의 넓이 합
#define MAX 1001
int a[MAX][3];
int n;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		a[x][0] = y; // 각 좌표의 높이 저장
	}
	// 왼->오 최대값 저장
	int maxN = 0;
	for (int i = 1; i <= 1000; i++) {
		maxN = max(maxN, a[i][0]);
		a[i][1] = maxN;
	}
	// 오-> 왼 최대값 저장
	maxN = 0;
	for (int i = 1000; i >= 1; i--) {
		maxN = max(maxN, a[i][0]);
		a[i][2] = maxN;
	}

	//최소 넓이 구하기
	int sum = 0;
	for (int i = 1; i <= 1000; i++) {
		sum += min(a[i][1], a[i][2]);
	}
	cout << sum << '\n';
    return 0;
}
