#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 하샤드 수
// 문제: 각 자리의 숫자를 더한 수로 나누어 지는 수인 하샤드 수 판별
// 접근: 반복문으로 숫자 각 자릿수 추출 후 합으로 원래의 수 나누기
// 접근2: 수를 문자열로 바꾼 후 각 문자 원소로 접근 (시도는 안 함)
// 풀이: 
// 반복문으로 10으로 나누고 숫자 각 자릿수 추출 후 합으로 원래의 수 나누어서 하샤드 수 판별
bool solution(int x) {
    bool answer = true;
    int sum=0,tp=x;
    while(tp>0){
        int n = tp%10;
        tp/=10;
        sum+= n;
    }
    if(x%sum == 0) { answer = true;}
    else { answer = false;}
    return answer;
}
