#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
// [프로그래머스 c++ O] 최솟값 만들기
// 문제: 두 배열에서 1개의 수를 뽑아 더한 총 합의 최속값 구하기
// 접근: 가장 최소가 되는 두 배열 원소 곱 -> 그리디
// 두 수의 곱의 합이 최소가 되기 위해선 -> 최소*최대 를 더해야 한다 -> 배열을 정렬시킴
// 풀이: 
// a배열을 오름차순 정렬,  b배열을 내림차순 정렬
// 완전탐색으로 최소*최대 의 누적 합 구하기

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(),A.end()); // a배열을 오름차순 정렬
    sort(B.begin(),B.end(),greater<int>()); //b배열을 내림차순 정렬
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum += A[i] * B[i]; // 최소*최대 의 누적 합 구하기
    } 
    return answer = sum;
}
