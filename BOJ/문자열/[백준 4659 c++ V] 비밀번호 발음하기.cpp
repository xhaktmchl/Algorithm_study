#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 4659 c++ V] 비밀번호 발음하기
접근1: 
시간복잡도: 
풀이: 
    //1.입력
    //end이면 종료
    //2.비번 검사
    //1) 모음 나오면 카운트
    //2) 연속 문자 2개(ee, oo 제외)
    //3) 연속 모음, 자은 3개 이상 예외
    //3.출력
*/
string s;
int c = 0, c2=0, c3=0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    //1.입력
    //end이면 종료
    //2.비번 검사
    //1) 모음 나오면 카운트
    //2) 연속 문자 2개(ee, oo 제외)
    //3) 연속 모음, 자은 3개 이상 예외
    //3.출력
    while (1) {
        bool moOk = 0, ok = 1;
        c = 1; c2 = 0; c3 = 0;
        cin >> s;
        if (s == "end") break;

        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') moOk = 1;//1) 모음 나오면 카운트
            if (i > 0) {//2) 연속 문자 2개(ee, oo 제외)
                if (s[i] == s[i - 1]) c++;
                else c = 1;

                if (c == 2 && s[i] != 'e' && s[i] != 'o') {ok = 0; break; }
            }
            //3) 연속 모음, 자은 3개 이상 예외
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                c2 += 1; 
                c3 = 0;
            }
            //else c2 = 0;
            if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
                c3 += 1;
                c2 = 0;
            }
            //else c3 = 0;

            if (c2 >= 3) {ok = 0; break; }
            if (c3 >= 3) {ok = 0;break;}
        }
        if (moOk && ok) cout << "<" << s << "> is acceptable." << '\n';
        else cout << "<" << s << "> is not acceptable." << '\n';
    }
    return 0;
}
