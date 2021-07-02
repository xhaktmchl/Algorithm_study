#include <string>
#include <vector>
#include <cmath>
using namespace std;
// [프로그래머스 c++ O] 정수 제곱근 판별
// 문제: n 이 x의 제곱인지 확인하고 x가 없으면 -1반환
// 접근: sqrt 이용해서 제곱근 유무 확인
// 풀이: 

long long solution(long long n) {
    long long answer = 0;
    
    long long sqrtNum = sqrt(n); // n의 제곱근
    if(sqrtNum*sqrtNum == n){ answer = (sqrtNum+1)*(sqrtNum+1);} // n의 제곱근을 다시 제곱해서 n 과 같은지 확인
    else { answer=-1;} // 안 맞으면 -1 대입
    return answer;
}
