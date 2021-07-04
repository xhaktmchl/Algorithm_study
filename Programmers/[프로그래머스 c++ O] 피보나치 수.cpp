#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// [프로그래머스 c++ O] 피보나치 수
// 문제: n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴
// 접근: 일반 반복문으로 피보나치 수열 구현
// 풀이: 
// 반복문으로 피보나치 수열 구현
// 주의: 문제에서 1234567로 나눈 나머지를 반환 = 피보나치 수열 계산할 때 에도 적용 해야 함
 long long fibo[100001];
int solution(int n) {
    int answer = 0;
    // 피보나치 수열
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2;i<=n;i++){
        fibo[i] = (fibo[i-2]+ fibo[i-1])%1234567; // 문제에서 1234567로 나눈 나머지를 반환하라 함
    }
    answer = fibo[n];
    return answer;
}
