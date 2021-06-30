#include <string>
#include <vector>
#include <cmath>
// [프로그래머스 c++ V] 소수 찾기

// 문제: 
// 접근: 소수판별 -> 제곱근 -> 시간초과 (빅오 n)
// 접근2: 에라토스테네스 체 (빅오 nlog(n))
// 풀이: 
// 소수체크 배열이0이면 소수인것
// 2부터 n까지 탐색중 check[i]가 0이면 소수 -> 숫자의 배수들 모두 1로 대입

int check[1000001]; // 0이라면 소수인 것
int solution(int n) {
    int answer = 0;
    int c=0;
    
    for(int i=2;i<=n;i++)
    {
       if(check[i] == 0){ answer++;}
        // 에라토스테네스 체
        for(int j=i;j<=n;j+=i){ // 2가 소수면 2의 배수들은 소수아님
            check[j]=1;
        }
    }
    return answer;
}
