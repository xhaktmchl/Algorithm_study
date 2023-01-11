#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
[백준 10845 c++ OO] 큐
접근: queue STL로 구현 
시간복잡도:
풀이: 
*/
int n,num;
string op;
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;

        if (op == "push") {
            cin >> num;
            q.push(num);
        }
        else if (op == "pop") {
            if (q.size() == 0) {
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
            q.pop();
        }
        else if (op == "size") {
            cout << q.size() << '\n';
        }
        else if (op == "empty") {
            if (q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (op == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
        }
        else if (op == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << q.back() << '\n';
        }
    }
    return 0;
}
