#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 1037 c++ O] 약수 
// 문제: 약수가 주어질 때 약수를 가지는 수를 구하라
// 접근: 약수 중 1을 제외한 제일 작은 값과 제일 큰값을 곱하면 = 원래의 수
// 풀이: 
int n;
vector<int> ar;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		ar.push_back(num);
	}
	sort(ar.begin(), ar.end());  // 정렬해야 자긍ㄴ 약수, 큰 약수 구함
	cout << ar[0] * ar[n - 1];
	return 0;
}
