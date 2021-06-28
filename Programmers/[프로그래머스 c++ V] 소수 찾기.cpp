#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
// [프로그래머스 c++ V] 소수 찾기
// 문제: 숫자가 나열된 문자열 입력 받으면 문자열 속 숫자로 만들 수 있는 수 중 소수의 갯수 구하기
// 접근: 소수찾기->에라토스테네스의 체 / 1,2,3,..자릿수의 수 어쩧게 탐색? => next_permutation() 와 substr으로 각 수열의 모든 자릿수 탐색
// 풀이: 
// next_permutation() 으로 모든 수열 탐색하기 위해 문자열 정렬
// 반복문에서 substr으로 각 수열일 경우 1,2,3,... 자리의 수 추출 후 정수로 변환
// 추출된 수 소수판별후 소수이면 해쉬배열에 1대입
// 배열탐색으로 소수의 갯수 구하기
// 개념: 
// next_permutation(numbers.begin(),numbers.end()) : 작은 수부터 다음 수열로 증가하다 끝나면 false반환
// stoi(문자열) : 문자열을 정수로 반환
// 문자열.substr(부분문자열 시작 인덱스,부분문자열 길이) : [pos, pos + count) 범위의 문자열 추출
// 주의:
// 에라토스테네스의 체 에서 0,1 예외조건 

// 소수판별 에라토스테네스의 체
int checkPrime(int checkNum){
    // 0과 1 인 경우 제외
    if(checkNum == 0 || checkNum == 1){ return 0;} // 주의: 처음에 조건 빼먹어서 틀림
    //에라토스테네스의 체
    for(int i=2;i<=sqrt(checkNum);i++){
        if(checkNum%i == 0){ return 0;} // 소수가 아닌 경우 0 반환
    }
    return 1;
}

int ar[9999999]; // 소수 정답 목록 확인용 해쉬배열

int solution(string numbers) {
    int answer = 0;
    
    // 주어진 문자열에서 가능한 순열 조함 순서대로 탐색
    sort(numbers.begin(),numbers.end());
    do{
        //각 순열에서 1,2,3,4... 자릿수 추출해서 소수판별
        for(int i=0;i<numbers.size();i++){
            int checkNum = stoi(numbers.substr(0,i+1)); // 1,2,3,... 자리수 문자열 추출 후 정수로 변환
            if(checkPrime(checkNum)){ar[checkNum]=1; } // 소수이면 배열 소수 인덱스에 1 대입
        }
    }while(next_permutation(numbers.begin(),numbers.end())); // 순열 차례로 증가
    
    // 소수의 개수 확인
    for(int i=0;i<=9999999;i++){
        if(ar[i] == 1){answer++;}
    }
    return answer;
}
