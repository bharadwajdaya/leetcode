#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool checkValidString(string s)
{
    // ( minOpen ++ 
    // ( maxOpen ++
    // ) minOpen--
    // ) maxOpen--
    // * minOpen-- if I get * ) or '' 
    // * maxOpen++ if I get * (

    // *** maxOpen=3
    // minopen -3 = 0 
    // *) minOpen=-1 maxOpen=1
    // minOpen=-2
    // maxOpen=0

    // (*()


    int minOpen=0;
    int maxOpen=0;

    for(char c:s)
    {
        if(c=='(')
        {
            minOpen++;maxOpen++;
        }
        else if(c==')')
        {
            minOpen--;maxOpen--;
        }
        else 
        {
            minOpen--;
            maxOpen++;
        }
        if(maxOpen<0)
        {
            return false;
        }
        minOpen=max(0,minOpen);
    }
    return minOpen==0;
}
int main()
{
    string s="(*)";
    cout<<(checkValidString(s)==true ? "Valid":"InValid")<<endl;
    return 0;
}