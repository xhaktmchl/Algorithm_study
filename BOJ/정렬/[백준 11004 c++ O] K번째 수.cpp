#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 11004 c++ O] K번째 수  
// 문제: n개의 수 중 오름차순으로 k번째 수를 출력
// 접근: 단순 sort 후 k 번째 수 출력 -> 통과 하지만 시간 2배
// 접근2: nth_element 로 정렬
// 시간복잡도: O(n) , 입력n, 정렬nlog(n) , 
// 풀이: 
// 벡터에 수 입력
// 정렬 후 k번재 출력
// 개념:
// nth_element(v.begin(), v.begin()+ 0, v.end()); : 원하는 인덱스 까지만 정렬
int n, k;
vector<int> a;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int num; 
		cin >> num;
		a.push_back(num);
	}

	nth_element(a.begin(), a.begin()+ k-1, a.end()); // k번째 까지만 정렬
	cout << a[k - 1] << '\n';
	return 0;
}
