#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 다음 큰 숫자
// 문제: 자연수 n이 주어졌을 때 이진수의 1의 갯수가 같은 n보다 큰 수 구하기
// 접근: 완전탐색: n+1 부터 이진수 구하면서 증가
// 풀이: 
// 반복문으로 n의 이진수 구학고
// 반복문으로 n+1 부터 이진수 구하고
// 이진수의 1의 갯수 비교 => 같으면 정답

int solution(int n) {
    int answer = 0;
    // n의 이진수 구하기
    int tp=n;
    vector<int> binaryN; // n의 이진수 벡터
    while(tp>0){
        binaryN.push_back(tp%2);
        tp/=2;
    }
    // n의 다음 큰 숫자 구하기
    for(int i=n+1;;i++){
        vector<int> binary;
        // 이진수 구하기
        tp = i;
        while(tp>0){
        binary.push_back(tp%2);
        tp/=2;
        }
        // 두 이진수의 1의 갯수 구하기
            int c1=0,c2=0;
            for(int j=0;j<binary.size();j++){ // n보다 큰 이진수 1갯수
                if(binary[j] == 1){ c1++;}
            }
         for(int j=0;j<binaryN.size();j++){ // n 이진수 1갯수
                if(binaryN[j] == 1){ c2++;} 
            }
            if(c1 == c2){answer = i; break; } // 1갯수 같으면 정답 반환
    }
    return answer;
}
