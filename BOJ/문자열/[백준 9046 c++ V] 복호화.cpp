#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
#include <string> // getline
#include <cstring> // memset, strok
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 9046 c++ V] 복호화 
접근1: 
시간복잡도: n
풀이: 
    //1.입력
    //2.완탐: 알파벳 갯수 메모이제이션
    //3.출력: 가장 최빈 알파벳 출력
개념: cin.ignore(); // 줄바꿈 제거
*/
int T;
string str;
int cnt[26+4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(0); 

    //1.입력
    cin >> T; cin.ignore(); // 줄바꿈 제거
    while (T--) {
        memset(cnt, 0, sizeof(cnt)); // 초기화
        getline(cin, str);
        //2.완탐: 알파벳 갯수 메모이제이션
        //3.출력: 가장 최빈 알파벳 출력
        int len = str.size();
        for (int i = 0; i < len; i++) {
            
            if (str[i] != ' ') {
                cnt[str[i] - 'a'] += 1;
            }
        }

        auto it = max_element(cnt, cnt + 26);
        int maxCnt = *it;
        int alCnt = 0;
        for (int i = 0; i < 26; i++) {
            if (maxCnt == cnt[i]) alCnt += 1;
            if (alCnt >= 2) break;
        }
        
        if (alCnt >= 2) cout << "?" << '\n';
        else {
            char ans = 'a' + (it - cnt);
            cout << ans << '\n';
        }
    }
    return 0;
}
