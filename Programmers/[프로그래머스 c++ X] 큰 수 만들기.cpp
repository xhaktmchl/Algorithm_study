#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// [프로그래머스 c++ X] 큰 수 만들기
// 문제: 주어진 문자열에서 k개의 문자를 뺐을 때 만들 수 있는 가장 큰 수 구하기
// 접근:  정렬시킨다음 최대 숫자 구하기 -> 틀림(문자순서 바꾸면 안됨)
// 접근2: 앞에서부터 부분별로 최대 숫자 구해가며 최대 숫자 구하기 
// 뽑아야  되는 숫자의 갯수: 문자열 길이-k
// k구간안에 있는 숫자중 최댓값 구하며 탐색
// 인덱스 0 부터 이어지는 k개의 숫자들중 최대숫자 추가 -> 마지막 까지 가면 인덱스가 문자열길이-k 에서 이어지는 k개 검사하므로 전체 문자열 탐색
// 풀이: 
// 반복문ㄴ으로 <number.size()-k 까지 탐색
// 각 k개의 구간에서 전의 최대문자다음의 문자중 최대문자 추출
// 추출된 최대문자 문자열에 추가

string solution(string number, int k) {
    string answer = "";
    int maxIdx=-1;
    
    for(int i=0;i<number.size()-k;i++){ // number.size()-k개의 숫자 추출
        char maxNum=0; // 각 k구간에서 최대숫자
        for(int j=maxIdx+1;j<=i+k;j++){ //이미 고른 최대문자 다음의 문자부터 새로 최댓값 구하기 위해 maxIdx+1 부터 시작 // 인덱스부터 뒤k개의 숫자중
            if(maxNum < number[j]){ // 최댓값 갱신 및 저장
                maxNum = number[j];
                maxIdx = j;
            }
        }
        answer+= maxNum; // 해당 k개의 구간중 최댓값 문자열 추가
    }
    return answer;
}
