#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
#include <string> // getline
#include <vector>

using namespace std;
/*
[백준 10610 c++ V] 30
문제:  
접근: 3의 배수 -> 모든 자리의 숫자의 합이 3의 배수여야 함, 30의 배수-> 마지막 자리가==0이어야 함
시간복잡도: O()
풀이:
       //1.입력
    //2.가장큰수로 정렬
    //3.3의 배수인지 검사
    //4.출력 존재 or 미존재
*/
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    cin >> str;
    //2.가장큰수로 정렬
    sort(str.begin(), str.end(), greater<>());
    //3.3의 배수인지 검사
    int size = str.length();
    int sum = 0;

    if (str[size - 1] != '0') {
        cout << -1 << '\n';
        return 0;
    }
     for (int i = 0; i < size; i++) {
         sum += str[i] - '0';
     }
     //4.출력 존재 or 미존재
     if (sum % 3 == 0) cout << str << '\n';
     else cout << -1 << '\n';
    return 0;
}
