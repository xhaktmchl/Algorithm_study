#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
/*
[백준 5568 c++ V] 카드 놓기
접근: 순열 -> next_permutation 
시간복잡도: 
접근2: 순열 -> dfs 
풀이:
    //1.입력
    //2.dfs: 순열 가지수 완탐
    //1) 기저: 마지막 숫자 -> set에 푸쉬
    //카운트
    //중단
    //2) 다음 숫자 탐색
개념;
// set<string> cardCnt;   정렬 불필요할때는 unordered가 성능에 유리 (중복제거만 사용)
*/
vector<string> v;
int n, k;
string num;
unordered_set<string> cardCnt;
//unordered_set<string> cardCnt;
// set<string> cardCnt;   정렬 불필요할때는 unordered가 성능에 유리 (중복제거만 사용)
int cnt = 0;
bool visit[15];

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
}
void dfs(int cnt, string curPath) {
    
    if (cnt == k) {
        cardCnt.insert(curPath);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            visit[i] = 1;
            dfs(cnt + 1, curPath + v[i]);
            visit[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    input();
    //2.dfs: 순열 가지수 완탐
    //1) 기저: 마지막 숫자 -> set에 푸쉬
    //카운트
    //중단
    //2) 다음 숫자 탐색
    dfs(0, "");
    cout << cardCnt.size() << '\n';
    return 0;
}
