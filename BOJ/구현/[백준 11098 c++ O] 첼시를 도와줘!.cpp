#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 11098 c++ O] 첼시를 도와줘!
// 문제: 
// 접근: 
// 풀이: 
// 테스트케이스 마다 벡터에 페어로 가격,이름 저장
// 벡터 정렬 -> 최대가격의 이름 출력
int t, n;

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<pair<int, string>> a;
		for (int j = 0; j < n; j++) {
			int num; string name;
			cin >> num >> name;
			a.push_back({ num,name });
		}
		sort(a.begin(), a.end());
		cout << a[a.size()-1].second << '\n';
	}
	return 0;
}
