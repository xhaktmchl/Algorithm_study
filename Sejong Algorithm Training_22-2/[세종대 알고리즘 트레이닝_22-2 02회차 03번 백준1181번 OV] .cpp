#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 02회차 03번 백준1181번 OV] 
문제:
접근:
풀이: 
	//1.입력 및 벡터에 푸쉬
	//2.정렬 (길이, 사전순)
	//3.중복제거
	//4.출력
시간복잡도: O(nlogn)= 
개념:
 v.erase(unique(v.begin(), v.end()), v.end()); // 벡터 중복값 제거
*/
int n;
string str;
vector<string> v;

bool mysort(string a, string b) {
	if (a.size() != b.size()) { return a.size() < b.size(); }
	else {
		return a < b;
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력 및 벡터에 푸쉬
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	//2.정렬 (길이, 사전순)
	sort(v.begin(), v.end(), mysort);
	//3.중복제거
	v.erase(unique(v.begin(), v.end()), v.end());
	//4.출력
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
