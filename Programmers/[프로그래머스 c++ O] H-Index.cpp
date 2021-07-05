#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// [프로그래머스 c++ O] H-Index
// 문제: H-index의 수 구하기
// 접근: h의 최댓값은 최대 논문 인용횟수보다 이하이므로 정렬을 통해 최댓값부터 탐색 ->완전탐색
// 풀이: 
// 최대인용횟수 구하기 위한 정렬
// 최대논문 인용횟수부터 작아지면서
// h이상 인용된 논문의 갯수 구하기
 // h이상 인용된 논문이 h편 이상인 경우 정답 반환
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end()); // 최대인용횟수 구하기 위한 정렬
    // 최대 hindex 탐색
    for(int i=citations[citations.size()-1];i>=0;i--){ // 최대논문 인용횟수부터 작아지면서
        int c1=0;
        for(int j=citations.size()-1;j>=0;j--){ // h이상 인용된 논문의 갯수 구하기
            if(citations[j] >= i){c1++;}
        }
        if(c1 >= i){answer = i; break;} // h이상 인용된 논문이 h편 이상인 경우 정답 반환
    }
    return answer;
}
