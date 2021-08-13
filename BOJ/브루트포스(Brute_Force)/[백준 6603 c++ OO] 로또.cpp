#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 6603 c++ OO] 로또
// 접근: 로또 수 조합 구하기-> 완탐(재귀,순열) -> 중복없는 조합(방문배열) -> 완전탐색 재귀이용
// 재귀인자(현재 뽑은 수 객수, 중복방지 오름차순을 위한 start인자, 현재까지 뽑은 조합)
// 시간복잡도: O(2^k) : 2^13 = 8천 
// 접근2: 수열 -> 구현방법 잘 모르겠음
// 풀이:
// 수열 입력받기
// 완전탐색 재귀로 가능한조합 구해서 출력
// 재귀- 순서대로 탐색 - 조합 완성되면 출력
#define MAX 50
int k;
vector<int> a;
vector<int> v; // 뽑은 조합 배열
bool visit[MAX];
 
void re(int idx, int cnt) {// 재귀인자(저체 숫자중 탐색 인덱스,현재 뽑은 수 객수, )
    // 종료조건, 조합 완성시
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << v[i] << " ";
        }cout << '\n';
        return;
    }
    // 불가능한 경우
    if (idx == k) { return; }
 
    //재귀
    //  k까지 탐색
    for (int i = idx; i < k; i++) {
        if (visit[i]) continue;
        visit[i] = 1; v.push_back(a[i]);
        re(i+1, cnt + 1);
        visit[i] = 0; v.pop_back();
    }
}
 
int main()
{
    ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
    cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
 
    while (1) {
        cin >> k;
        if (k == 0) break;
        a.clear(); v.clear();
        for (int i = 0; i < k; i++) {
            int num;
            cin >> num;
            a.push_back(num);
        }
        re(0, 0);
        cout << '\n';
 
    }
    return 0;
}
 
 
