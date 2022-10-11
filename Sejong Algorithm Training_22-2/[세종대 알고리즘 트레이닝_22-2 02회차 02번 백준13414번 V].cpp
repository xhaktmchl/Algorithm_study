#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 02회차 02번 백준13414번 V] 
문제:
접근: 
풀이: 
	//1.입력 및 unordered_map에 인서트해서 중복 제거
	//2.벡터로 푸쉬 후
	//3.순서로 정렬
	//4.출력: 최대수강 만큼
시간복잡도: O(logn)= 
개념:
unordered_map : 해시 맵 , 따라서 정렬 안돼고 , 중복된 값은 나중 값으로 최신화
*/
int k, l;
string str;
unordered_map<string, int> um;
vector<pair<string, int>> v;

bool mysort(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력 및 unordered_map에 인서트해서 중복 제거
	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		cin >> str;
		um[str] = i; // 키가 학번, 값이 순서
	}
	//2.벡터로 푸쉬 후
	for (auto i : um) {
		v.push_back(i);
	}
	//3.순서로 정렬
	sort(v.begin(), v.end(), mysort);
	//4.출력: 최대수강 만큼
	for (int i = 0; i < v.size(); i++) {
		if (i >= k) break;
		cout << v[i].first << '\n';
	}
	return 0;
}
