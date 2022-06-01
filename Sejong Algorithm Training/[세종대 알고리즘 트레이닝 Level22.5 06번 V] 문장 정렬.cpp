#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22.5 06번 V] 문장 정렬
문제:
접근: 
풀이:
	//1.입력
	//2.정렬
	//3.출력
시간복잡도: O(n*n)=
*/
vector<string> v;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 4; i++) {
		string tp;
		cin >> tp;
		v.push_back(tp);
	}
	//2.정렬
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (v[j].size() > v[j + 1].size()) {
				string tp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tp;
			}
			else if (v[j].size() == v[j + 1].size() && v[j] > v[j + 1]) {
				string tp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tp;
			}
		}
	}
	//3.출력
	for (int i = 0; i < 4; i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
