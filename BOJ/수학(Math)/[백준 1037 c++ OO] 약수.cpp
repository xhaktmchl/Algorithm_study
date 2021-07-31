#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 1037 c++ OO] 약수 
// 문제: 약수가 주어질 때 약수를 가지는 수를 구하라
// 접근: 약수 중 1을 제외한 제일 작은 값과 제일 큰값 또는 약수 2개의 짝을 곱하면 = 원래의 수
// n = a*c
// 풀이: 
#define MAX 1000001
int len;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> len;
	for (int i = 0; i < len; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	cout << v[0] * v[len - 1] << '\n';
	return 0;
}
