#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// [프로그래머스 c++ V] 단체사진 찍기
// 문제: 8명의 멤버가 있을 때 문자열로 주어지는 조건에 맞는 순열의 수 구하기
// 접근: 완전탐색: 8명이 줄스는 경우의 수 -> next_permutation() 이용 모든 순열 탐색
// 멤버 사이 거리는 string.find() 함수 이용
// 시간복잡도: O(n*순열의 수) = 100*8! = 약 400만 -> 완전탐색 가능
// 풀이: 
// 8명의 멤버 문자열로 저장
// next_permutation() 으로 모든 순열 탐색 -> 각 순열마다 n개의 data규칙 성립되는지 검사 -> 맞으면 개수증가
//개념:
//: next_permutation(str.begin(),str.end()) : 모든 순열 조합 , 더이상 조합 없으면 npos반환
//: str.find(찾는문자) : 찾는 문자의 위치 반환 != find(v.begin(),v.end(),찾는값)

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string str = "ACFJMNRT";
   
    do{
         int c=0;
        for(int i=0;i<data.size();i++){
            char f1 = data[i][0];
            char f2 = data[i][2];
            char comp = data[i][3];
            int num = data[i][4] - '0';
            
            int dist = str.find(f1) - str.find(f2); // 멤버 사이 거리
            dist = abs(dist)-1;
            // 각 조건에 맞는지 검사
            if(comp == '=' && num == dist){
                c++;
            }
            if(comp == '>' && dist > num){
                c++;
            }
            if(comp == '<' && dist < num){
                c++;
            }
        }
        
        if(c == n){answer++;}
    }while(next_permutation(str.begin(),str.end()));

    return answer;
}
