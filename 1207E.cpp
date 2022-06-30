//http://codeforces.com/problemset/problem/1207/E
// solved
#include <iostream>
using namespace std;


#define FIRSTMASK 127
#define SECONDMASK 16256
unsigned short finalAnswer=0;

void createRequire(unsigned short mask,short offset)
{
    cout<<"? ";
    for(short i=0;i<100;i++)
    {
        cout<<(mask | (i<<offset))<<' ';
    }
    cout<<'\n';
    fflush(stdout);   
}

void answerAnalisys(unsigned short answer,unsigned short mask)
{
    finalAnswer = (finalAnswer | ((answer xor mask) & mask));
}

int main()
{
    unsigned short answer=0;

    createRequire(FIRSTMASK,7);
    cin>>answer;
    answerAnalisys(answer,FIRSTMASK);


    createRequire(SECONDMASK,0);
    cin>>answer;
    answerAnalisys(answer,SECONDMASK);


    cout<<"! "<<finalAnswer<<'\n';
    fflush(stdout);
    return 0;
}

