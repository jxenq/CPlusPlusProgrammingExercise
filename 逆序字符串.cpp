#include <iostream>
#include <string>
using namespace std;

/* 你的代码将嵌在这里 */
void reverse_string(string &s)   // 形参s是是实参str的别名 
{
    int N = s.size();            // 或 N = s.length(); 
    for (int i = 0; i < N / 2; i++)
    {
        char temp;
        temp = s[i];
        s[i] = s[N - i - 1]; 
        s[N - i - 1] = temp;
    }
} 

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);		//输入字符串
    reverse_string(str); 	//逆序字符串str
    cout << str << endl;	//输出逆序后的字符串
    return 0;
}
