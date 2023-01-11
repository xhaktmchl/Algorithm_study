#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;
/*
[백준 10828 c++ OO] 스택
접근: 일반 스택 구현  c++은 스택 자료형 , 파이썬은 리스트 이용
풀이: 명령은 string 형 스택 자료형 이용해서 푼다.
*/
stack<int> st;
int n,num;
string op;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;

        if (op == "push") {
            cin >> num;
            st.push(num);
        }
        else if (op == "pop") {
            if (st.size() == 0) {
                cout << -1 << '\n';
                continue;
            }
            cout << st.top() << '\n';
            st.pop();
        }
        else if (op == "size") {
            cout << st.size() << '\n';
        }
        else if (op == "empty") {
            if (st.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (op == "top") {
            if (st.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << st.top() << '\n';
        }
    }
    return 0;
}
