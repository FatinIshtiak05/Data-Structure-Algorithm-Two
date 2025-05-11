#include<iostream>
using namespace std;


int lcs(char x[],char y[],int xl,int yl){
    int tab[xl+1][yl+1];
    string sign[xl+1][yl+1];
    for(int i=0;i<=xl;i++){
        tab[i][0]=0;
    }
    for(int i=0;i<=yl;i++){
        tab[0][i]=0;
    }
    for(int i=1;i<=xl;i++){
        for(int j=1;j<=yl;j++){
            if(x[i-1]==y[j-1]){
                tab[i][j] = tab[i-1][j-1] + 1;
                sign[i][j] = "Diagonal";
            }
            else if(tab[i-1][j] >= tab[i][j-1]){
                tab[i][j]=tab[i-1][j];
                sign[i][j] = "TOP";
            }
            else{
                tab[i][j]=tab[i][j-1];
                sign[i][j] = "LEFT";
            }
        }
    }
    //printing 
    return tab[xl][yl];
    
}


int main()
{
    char x[]="AGGTAB";
    char y[]="GXTXAYB";
    int xl = 6;
    int yl = 7;
    //int xl = sizeof(x)/sizeof(x[0]);
    //int yl = sizeof(y)/sizeof(y[0]);
    cout<<lcs(x,y,xl,yl);
    return 0;
}
