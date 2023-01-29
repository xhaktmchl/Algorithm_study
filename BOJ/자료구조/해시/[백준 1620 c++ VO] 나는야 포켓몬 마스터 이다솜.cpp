#include <iostream>
#include <algorithm> // fill_n, min,max, swap
#include <map> // 중복 x 
#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 1620 c++ VO] 나는야 포켓몬 마스터 이다솜  
문제: 
접근:
시간복잡도:
풀이1: 해시맵 이용
    //1.입력
    //2.해시에 저장(이름, 번호)
    //3.해시 탐색 및 출력
개념: stoi(문자열) : 문자열을 숫자로(string형 가능)
개념: string 자료형은 == 원소나 문자열 바교나 참조 가능하지만 원소를 바꿀 순 없다
개념: map<key자료형,value자료형> : map[key] = value 값 나옴
*/
int n, m;
string na,op;
map<string, int> ma1;
map<int, string> ma2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    //2.해시에 저장(이름, 번호)
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> na;
        ma1.insert({ na, i });
        ma2.insert({ i, na });
    }
    //3.해시 탐색 및 출력
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op[0] >= '0' && op[0] <= '9') {
            int num = stoi(op);
            auto it = ma2.find(num);
            cout << it->second << '\n';
        }
        else {
            auto it = ma1.find(op);
            cout << it->second << '\n';
        }
    }
    return 0;
}  
