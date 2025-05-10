#include<iostream>
using namespace std;
#define INF 99999;

int coinchange(int coins[], int total, int n)
{
    if(total ==0)
        return 0;
    int memo=INF;
    for(int i=1;i<=n;i++){
        if(total>=coins[i]){
            int numcoins = coinchange(coins,total-coins[i],n);//some issue here!
            if(numcoins+1 <memo){
                memo=numcoins+1;
            }
        }    
    }
    return memo;

}


int main()
{
    int coins[3] = {1,4,6};
    int total = 11;
    int n = sizeof(coins)/sizeof(coins[0]);
    int result = coinchange(coins, total, n);
    cout << "Minimum Coin(s) Needed: " << result << "\n";
    return 0;
}

