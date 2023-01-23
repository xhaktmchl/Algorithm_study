#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
#include <string> // getline
#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 1316 c++ OO] 그룹 단어 체커
접근1: 
시간복잡도: n*n
풀이: 
    //1.입력
    //2.완탐: 문자열 탐색하며 전과 다른 문자가 나왔는데 이미 그 문자가 나온적 있으면 그룹단어 아님
    //3.출력:
*/
int n;
string a;
int cnt[26 + 10];
int res = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    //1.입력
    cin >> n;
    //2.완탐: 문자열 탐색하며 전과 다른 문자가 나왔는데 이미 그 문자가 나온적 있으면 그룹단어 아님
    while (n--) {
        bool isGroup = 1;
        memset(cnt, 0, sizeof(cnt));
        cin >> a;
        
        cnt[a[0] - 'a']++;
        int size = a.size();
        for (int i = 1; i < size; i++) {
            if (cnt[a[i] - 'a'] == 0) cnt[a[i] - 'a']++;
            else if (a[i] != a[i - 1] && cnt[a[i]-'a']!=0) {
                isGroup = 0;
                break;
            }
        }

        if (isGroup) res++;
    }
    //3.출력:
    cout << res << '\n';
    return 0;
}
