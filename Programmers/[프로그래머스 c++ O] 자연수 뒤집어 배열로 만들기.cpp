#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 자연수 뒤집어 배열로 만들기
// 문제: 주어진 수 n 을 뒤집어 각 자리 숫자를 배열의 원소로 대입 후 반환
// 접근: 완전탐색 : 숫자 작은 자릿수 부터 10으로 나눈 나머지 구하기
// 풀이: 
// 반복문으로 n을 10으로 계속 나누면서 나머지는 배열에 푸쉬
vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n>0){
        answer.push_back(n%10);
        n/=10;
    }
    return answer;
}
