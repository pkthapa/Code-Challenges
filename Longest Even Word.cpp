#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'longestEvenWord' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING sentence as parameter.
 */
string longestEvenWord(string sentence)
{
	string longestString;
    int len = sentence.length(), offset = 0, tempStrLen = 0, longestStringLen = 0;
    char char_sentence[len + 1], tempStr[len + 1];
    memset(char_sentence, 0, len + 1);
    memset(tempStr, 0, len + 1);
    strcpy(char_sentence, sentence.c_str());

    while(offset < len){
        tempStrLen = 0, longestStringLen = 0;
        int i = 0;
        while((char_sentence[offset] != ' ') && (offset < len)){//!! Separate words.
            tempStr[i++] = char_sentence[offset++];
            tempStrLen++;
        }
        tempStr[i++] = '\0';
        offset++;

        if((0 == tempStrLen%2) && (tempStrLen > (longestStringLen = longestString.length()))){
            longestString = tempStr;
        }
    }
    if(longestString.length())
        sentence = longestString;
    else
        sentence = "00";
    return sentence;
}

int main()
{
    cout<<longestEvenWord("This is a testing string");
    return 0;
}