#include<vector>
#include<iostream>
using namespace std;
string encodearr(vector<string>& str)
{
    string word="";
    for(string s:str)
    {
        int _len=s.length();
        word=word+to_string(_len)+"#"+s;
    }
    return word;
}
vector<string> decode(string s)
{
    vector<string> res;
    int right=0;
    int len=s.length();

    while(right<len)
    {
        int j=right;
        while(j<len && s[j]!='#')
        {
            j++;
        }
        int len=stoi(s.substr(right,j-right));
        string word=s.substr(j+1,len);
        res.push_back(word);
        right=j+1+len;
    }
    return res;
}
int main()
{
    vector<string> str={"leet","code","dummy","word"};
    string en_res=encodearr(str);
    cout<<en_res;
    vector<string> res=decode(en_res);
    cout<<",";
    for(string s:res)
    {
        cout<<s<<",";
    }
    return 0;
}