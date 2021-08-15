#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2562 c++ O] 최댓값 
// 문제: 
// 접근: 기본 구현
// 시간복잡도: 
// 풀이: 
// 개념: max_element()
vector<int> a;

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	cout << *max_element(a.begin(), a.end()) << '\n';
	cout << max_element(a.begin(), a.end())-a.begin()+1 << '\n';
	return 0;
}



