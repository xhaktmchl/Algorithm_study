#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18 07번] 한줄로 알파벳 정렬하기 V
문제:
접근: 완탐,
풀이:
시간복잡도: O(5*3)=
*/
char alpha[5][3] = {
    {'A', 'B', 'C'},
    {'A', 'G', 'H'},
    {'H', 'I', 'J'},
    {'K', 'A', 'B'},
    {'A', 'B', 'C'}
};
int cnt[100];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

    
	//1.완탐: 알페벳 배열 탐색하며 각 갯수 카운트
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            //cout << (int)alpha[i][j] << '\n';
            cnt[alpha[i][j]]++; // 문자 아스키코드를 인덱스를 바로 활용
        }
    }
    //2.출력:작은 알파벳부터 출력
    int len = 'Z' - 'A' + 1;
    for (int i = 65; i < 65+len; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << (char)i;
        }
    }
	return 0;
}
