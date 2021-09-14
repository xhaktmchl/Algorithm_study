#include <string>
#include <vector>
using namespace std;
// [프로그래머스 c++ O] 타겟 넘버
// 문제: 주어진 숫자를 더하거나 빼서 원하는 값이 나오는 경우의 수 구하기
// 접근: 더하거나 빼는 모든 경우 -> 완탐 재귀 1.더한경우, 2.뺀경우
// 시간복잡도: O(2^20) = 100만
// 풀이: 
// 재귀로 완탐(숫자배열의 인덱스, 합) 인자
// 종료조건: 모든 숫자 계산완료되면 
// 더한경우 뺀경우 재귀
int tar,n,cnt=0;
vector<int> number;

void re(int idx,int sum){
    // 종료조건 모든 숫자 계산완료되면 
    if(idx == n ){
        if(sum == tar){  cnt++; }
        return;
    }
    
    re(idx+1,sum+number[idx]); // 더한경우
    re(idx+1,sum-number[idx]); // 뺀 경우
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    n = numbers.size();
    tar = target;
    number = numbers;
    re(0,0); // 완탐 재귀
    
    return answer=cnt;
}
