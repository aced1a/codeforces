//https://codeforces.com/problemset/problem/1217/F
//????
#include <iostream>
#include <string>
using namespace std;

bool** pathwayMatrix = nullptr;
bool** searchPatchwayMatrix = nullptr;

bool** createMatrix(unsigned short n)
{
    bool** pMatrix = new bool*[n];
    for(unsigned short i=0;i<n;i++)
    {
        pMatrix[i] = new bool[n];
        for(unsigned short j=0;j<n;j++)
        {
            pMatrix[i][j] = 0;
        }
    }
    return pMatrix;
}

void delelteMatrix(bool** pMatrix,unsigned short n)
{
    for(unsigned short i=0;i<n;i++)
    {
        delete[] pMatrix[i];
    }
    delete[] pMatrix;
}

bool searchPathway(unsigned short x,unsigned short y,unsigned short n)
{
    if(pathwayMatrix[x][y])
        return true;

    for(unsigned short i=0;i<n;i++)
    {
        if(pathwayMatrix[x][i] && !(searchPatchwayMatrix[x][i]))
        {
            searchPatchwayMatrix[x][i] = true;
            searchPatchwayMatrix[i][x] = true;

            if(searchPathway(i,y,n))
                return true;
        }
    }
    return false;
}

void chgEdge(unsigned short x,unsigned short y)
{
    pathwayMatrix[x][y] = !(pathwayMatrix[x][y]);
    pathwayMatrix[y][x] = pathwayMatrix[x][y];
}

int main()
{
    unsigned short n=0,m=0,x=0,y=0;
    bool last = 0;
    char result[2] = {'0','1'}, command = ' ';
    string resultString = "";

    cin>>n>>m;
    pathwayMatrix = createMatrix(n);

    for(unsigned short i=0;i<m;i++)
    {
        cin>>command>>x>>y;
        if(command == '1')
        {  
            chgEdge((x+last-1)%n,(y+last-1)%n);                     // (x+last-1)%n+1  (y+last-1)%n+1 | +1 убрано для сответствия индексам массива
        }
        else
        {
            searchPatchwayMatrix = createMatrix(n);

            last = searchPathway((x+last-1)%n,(y+last-1)%n,n);      // (x+last-1)%n+1  (y+last-1)%n+1 | +1 убрано для сответствия индексам массива
            resultString += result[last];

            delelteMatrix(searchPatchwayMatrix,n);
        }
    }
    delelteMatrix(pathwayMatrix,n);
    cout<<resultString<<endl;
    return 0;
}










