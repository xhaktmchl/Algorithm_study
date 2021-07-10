#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// [프로그래머스 c++ V] 최댓값과 최솟값
// 문제: 
// 접근: 문자열 숫자 정수로 변환 -> 배열 정렬 해서 최대 최소 찾음 -> 문자열에 추가
// 풀이: 

string solution(string s) {
    string answer = "";
    vector<int> ar;
    string tp="";
    for(int i=0;i<s.size();i++){
        if(s[i] != ' '){
             tp+= s[i];
        }
        if(s[i] == ' ' || i == (s.size()-1)){
           ar.push_back(stoi(tp));
            //cout<<tp<<'\n';
            tp = "";
        }
       
    }
    // 최대최소값 문자열에 추가
    sort(ar.begin(),ar.end());
    answer += to_string(ar[0]);
    answer += " ";
    answer += to_string(ar[ar.size()-1]);
    return answer;
}
