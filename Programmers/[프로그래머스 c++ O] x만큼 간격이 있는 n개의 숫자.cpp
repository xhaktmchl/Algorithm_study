#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] x만큼 간격이 있는 n개의 숫자
// 문제: 
// 접근: 
// 풀이: 

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long curNum = x;
    for(int i=0;i<n;i++){
        answer.push_back(curNum);
        curNum += x;
    }
    return answer;
}
