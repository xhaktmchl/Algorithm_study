#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 3085 c++ O] 사탕 게임
// 접근: 이차원 최대길이 ->완탐,dfs,bfs -> 스왑하고 비교하고 하려면 dfs,bfs애매 -> 완탐
// 시간복잡도: O(이차원 전체 탐색 * 한칸 바꾸고 최대 행,렬 탐색)=O(n*n*(n*n)) , n=50이라 가능
// 풀이: 
// 완전탐색으로 가로,세로 교환할 때 각 사탕의 최대개수 중 큰 수를 출력
// 개념:
//: swap(ar[i][j], ar[i][j + 1]); 두 값을 교환, #include <algorithm> 헤더
#define MAX 50
int n;
vector<string> ar;
int maxN = 0;

void check(vector<string>& ar) {
	// 행 최대길이 검사
	for (int i = 0; i < n; i++) {
		int c = 1;
		for (int j = 1; j < n; j++) {
			if (ar[i][j] == ar[i][j - 1]) {
				c++;
				maxN = max(maxN, c);
			}
			else { c = 1; } // 주의: 문자열 길이라 초기화 =1
		}
	}
	// 열 최대길이 검사
	for (int i = 0; i < n; i++) {
		int c = 1;
		for (int j = 1; j < n; j++) {
			if (ar[j][i] == ar[j-1][i]) {
				c++;
				maxN = max(maxN, c);
			}
			else { c = 1; }
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		ar.push_back(str);
	}
	// 이차원 그래프 완전탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 오른쪽
			if (j + 1 < n && ar[i][j] != ar[i][j + 1]) {
				swap(ar[i][j], ar[i][j + 1]);
				check(ar);
				swap(ar[i][j], ar[i][j + 1]);
			}
			//  아래
			if (i + 1 < n && ar[i][j] != ar[i+1][j]) {
				swap(ar[i][j], ar[i + 1][j]);
				check(ar);
				swap(ar[i][j], ar[i + 1][j]);
			}
		}
	}
	cout << maxN ;
	return 0;
}
