#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <set>
#include <string.h>
#include "linear_combiner.h"
using namespace std;
/*just tool func*/
void boolxor(bool* t,bool* s, long size){
    for(long i=0;i<size;++i)
        t[i]=(t[i]!=s[i]);
}
/*
 randomly choose D_P+1 vectors and use some of them to get a linear combiniation
 the func will return an address of a bool-type array
 for we will use the function calloc, don't foget to free the array then
 */
bool* linear_combiner(long DR, long DP)
{
    bool *t=(bool *)calloc(D_R, sizeof(bool));
    bool a[D_P+1][D_P]={0};
    bool b[D_P+1][D_P+1]={0};
    long setsize=1;
    for(int i=0;i<DP;++i){
        for(int j=0;j<DR;++j){
            if(m[j][i]==1){
                setsize++;
                break;
            }
        }
    }
    set <int> s;
    srand((unsigned)time(NULL));
    set<int>::iterator it;
    int c=0;
    while(s.size()<setsize){
        int randnum=rand()%DR;
        if(r[randnum]==1)
            s.insert(randnum);
    }
    for(it=s.begin();it!=s.end();++it,++c){
        b[c][c]=1;
        memcpy(a[c], m[*it], DP*sizeof(bool));
    }
    set <int> ss;
    for(int i=0;i<DP;++i){
        bool flag=0;
        int bn=0;
        for(int j=0;j<setsize;++j){
            if(a[j][i]==0||ss.find(j)!= ss.end())
                continue;
            if(a[j][i]==1){
                if(flag){
                    boolxor(a[j], a[bn], DP);
                    boolxor(b[j], b[bn], setsize);
                }
                else{
                    flag=1;
                    bn=j;
                    ss.insert(j);
                }
            }
        }
    }
    for(int i=0;i<DP+1;++i){
        for(int j=0;j<DP;++j){
            if(a[i][j]==1) break;
            if(j==DP-1){
                for(it=s.begin(),c=0;it!=s.end();++it,++c){
                    if(b[i][c]){
                        t[*it]=1;
                    }
                }
                return t;
            }
                
        }
    }
    return NULL;
}
void print_combiniation(bool *t, long DR)
{
    for(int i=0; i<DR; ++i){
        if(t[i]){
            printf("1 ");
        }
        else printf("0 ");
    }
    printf("\n");
    return;
}
