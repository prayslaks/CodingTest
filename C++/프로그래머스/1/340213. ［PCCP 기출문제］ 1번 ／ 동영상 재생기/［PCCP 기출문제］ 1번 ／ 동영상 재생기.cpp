#include <string>
#include <vector>
#include <iostream>

using namespace std;

//정수 변환
int toInt(string input)
{
    int result = 0;
    for(int i = 0; i < input.length(); i++)
        result = (result * 10) + (input[i] - '0');
    return result;
}

//문자열 변환
string toStr(int num)
{
    string str = "";
    string rev = "";
    while(num > 0)
    {
        str += num % 10 + '0';
        num /= 10;
    }
    for(int i = str.length() - 1; i >= 0; i--)
        rev += str[i];
    
    if(rev.length() == 0)
        rev = "00";
    else if(rev.length() == 1)
        rev = "0" + rev;
    
    return rev;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    //video_len 동영상 길이
    //pos 기능 수행 직전 위치
    //op_start 오프닝 시작 위치
    //op_end 오프닝 종료 위치
    //command 사용자 입력
    //출력 "mm:ss"
    
    //비디오 길이
    int video_minute = toInt(video_len.substr(0, 2));
    int video_second = toInt(video_len.substr(3, 2));
    int video_time = 60 * video_minute + video_second;
    
    //시작 초
    int op_start_minute = toInt(op_start.substr(0, 2));
    int op_start_second = toInt(op_start.substr(3, 2));
    int op_start_time = 60 * op_start_minute + op_start_second;
    
    //종료 초
    int op_end_minute = toInt(op_end.substr(0, 2));
    int op_end_second = toInt(op_end.substr(3, 2));
    int op_end_time = 60 * op_end_minute + op_end_second;

    //현재 초
    int minute = toInt(pos.substr(0, 2));
    int second = toInt(pos.substr(3, 2));
    int time = 60 * minute + second;
    
    //오프닝 위치 확인
    if(op_start_time <= time && time <= op_end_time)
        time = op_end_time;
    
    for(string command : commands)
    {
        if(command == "prev")
        {
            //10초 전으로
            time -= 10;
            
            //위치가 10초 미만
            if(time < 10)
                time = 0;
        }
        else if(command == "next")
        {
            //10초 후로 이동
            time += 10;
            
            //비디오 10초 미만 남음
            if(video_time - time < 10)
                time = video_time;
        }
        
        //오프닝 위치 확인
        if(op_start_time <= time && time <= op_end_time)
            time = op_end_time;
    }
    
    minute = time / 60;
    second = time % 60;
    return toStr(minute) + ":" + toStr(second);
}