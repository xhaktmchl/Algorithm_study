#include <string>
#include <vector>
#include <iostream>
using namespace std;
// [프로그래머스 c++ O] 콜라츠 추측
// 문제: 콜라츠 추측 계산 횟수 구하기
// 접근: 기본 규칙 구현
// 풀이: 
// 짝수/ 홀수 인경우 각각 계산
// 숫자가 1이되면 계산 횟수 출력
// 아니면 -1 반환
// 주의:int로 주어진 num 계산하다보면 범위 초과되서 long long으로 해야 함

int solution(int num) {
    int answer = 0;
    int c=0; // 계산 횟수
    long long Num = num; // 주의 : int로 하면 범위 넘어가서 에러
    
    for(int i=0;i<500;i++){
         if(Num == 1)break; // 1이면 중단
        if(Num%2 == 0) {Num/=2;} // 짝수
        else { Num = Num*3+1;}// 홀수
        c++;
       
    }
    if(Num != 1) answer = -1; // 1일 아닌경우
    else {answer = c;}
    return answer;
}
