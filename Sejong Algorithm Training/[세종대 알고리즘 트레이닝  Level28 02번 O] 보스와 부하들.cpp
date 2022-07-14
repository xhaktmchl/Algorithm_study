#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝  Level28 02번 O] 보스와 부하들
문제:
접근:
풀이: 인접행렬
	//1.입력
	//2.보스찾기
	//3.부하찾기
	//4.출력:
시간복잡도: O(n*n)=
*/
int n;
int ad[100][100];
vector<int> boss, under;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ad[i][j];
		}
	}

	//2.보스찾기
	for (int i = 0; i < n; i++) {
		if (ad[i][0] == 1) {
			boss.push_back(i);
		}
	}
	//3.부하찾기
	for (int i = 0; i < n; i++) {
		if (ad[0][i] == 1) {
			under.push_back(i);
		}
	}

	//4.출력:
	cout << "boss:";
	for (int i = 0; i < boss.size(); i++) {
		cout << boss[i] << " ";
	}cout << '\n';
	cout << "under:";
	for (int i = 0; i < under.size(); i++) {
		cout << under[i] << " ";
	}
	return 0;
}
