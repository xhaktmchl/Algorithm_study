#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// [프로그래머스 c++ O] 예산
// 문제: 한정된 예산 안에서 최대 몇개 부서의 예산을 감당할 수 있는가
// 접근: 그리디: 정렬시킨다음 최솟값 부터 예산을 더해가는것이 최대 갯수라고 생각
// 풀이: 
// 예산 배열정렬
// 최솟값부터 더하면서 예산 초과하는지 검사
// 최대갯수 반환
int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum=0;
    sort(d.begin(),d.end());
    for(int i=0;i<d.size();i++){
        if(sum+d[i] > budget){break;}
        sum+=d[i];
        answer=i+1; // 0개 있는 경우 주의
    }
    return answer;
}
