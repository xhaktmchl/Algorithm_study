#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 평균 구하기
// 문제: 배열 원소의 평균 구하기
// 접근: 
// 풀이: 

double solution(vector<int> arr) {
    double answer = 0;
    double sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    answer = sum/arr.size();
    return answer;
}
