#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <vector>
using namespace std;
/*
[백준 2960 c++ V] 에라토스테네스의 체
문제:  
접근: 소수 -> 에라토스테네스의체
시간복잡도: O()
풀이:

*/
int n, k, cnt=0;
int prime[1000 + 10];

void eratos() {

    for (int i = 2; i<=n; i++) {
        if (prime[i] == 1) continue;

            for (int j = i; j <= n; j += i) {
                    prime[j] = 1;
                    cnt++;
                    if (cnt == k) {
                        cout << j << '\n';
                        return;
                    }
            }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    eratos();
    return 0;
}
