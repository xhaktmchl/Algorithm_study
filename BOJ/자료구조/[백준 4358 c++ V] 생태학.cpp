#include <iostream>
#include <algorithm>
#include <map> // 중복 x 
#include <string> // getline

using namespace std;
/*
[백준 4358 c++ V] 생태학 
문제:
접근: 나무이름에 따른 갯수저장 ->해시 mao stl이용
시간복잡도: 
풀이:
    //1.나무 입력
    //2.소수점 자리 고정
    //3.비율 계산
*/
map<string, float> m;
string tree;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (getline(cin, tree)) {
       
        if (m.find(tree) != m.end()) {
            m[tree] += 1;
        }
        else m[tree] = 1;
        cnt++;
    }

    // 비율 계산
    cout << fixed;
    cout.precision(4);
    for (auto it = m.begin(); it != m.end(); it++) {
        float per= (it->second * 100) / cnt;
        
        cout << it->first << " ";
        cout << per << '\n';
    }
    return 0;
}
