#include <bits/stdc++.h>               //Space complexity is -> O(n^2) , Time complexity is -> O(n^2) ,n=numOfWords

using namespace std;
const int N = 1e3+5, M = 1e4, OO = 0x3f3f3f3f;
vector<string>vs;
int numOfWords,len,cost[N][N],minCost[N],result[N];
string str;

void TextJustification()
{

    for(int i=0; i<numOfWords; ++i)
    {
        cost[i][i]=len-vs[i].size();
        for(int j=i+1; j<numOfWords; ++j)
            cost[i][j]=cost[i][j-1]-vs[j].size()-1;      //add more than one word in the same line
    }

    for(int i=0; i<numOfWords; ++i)
        for(int j=i; j<numOfWords; ++j)
        {
            if(cost[i][j]<0)cost[i][j]=OO;
            else cost[i][j]*=cost[i][j];
        }

    for(int i=numOfWords-1; ~i; --i)
    {
        minCost[i]=cost[i][numOfWords-1];
        result[i]=numOfWords;
        for(int j=numOfWords-1; j>i; --j)
        {
            if(cost[i][j-1]==OO)continue;
            if(minCost[i]>minCost[j]+cost[i][j-1])minCost[i]=minCost[j]+cost[i][j-1],result[i]=j;
        }
    }
    printf("%d\n",minCost[0]);
}

void printSolution()
{
    int i,j;
    for(i=0; i<numOfWords; i=j)
    {
        for(j=i; j<result[i]; ++j)cout<<vs[j]<<" ";
        puts("");
    }
}

int main()
{
    scanf("%d%d",&numOfWords,&len);

    for(int i=0; i<numOfWords; ++i)
    {
        cin>>str;
        vs.push_back(str);
    }

    TextJustification();
    printSolution();

    return 0;
}
