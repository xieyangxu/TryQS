#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <set>
#include <string.h>
#include "linear_combiner.h"
using namespace std;
/*just tool func*/
void boolxor(bool* t,bool* s, int size){
    for(int i=0;i<size;++i)
        t[i]=(t[i]!=s[i]);
}
/*
 randomly choose D_P+1 vectors and use some of them to get a linear combiniation
 the func will return an address of a bool-type array
 for we will use the function calloc, don't foget to delete the array then
 */
bool* linear_combiner()
{
    bool *t=(bool *)calloc(D_R, sizeof(bool));
    bool a[D_P+1][D_P]={0};
    bool b[D_P+1][D_P+1]={0};
    set <int> s;
    srand((unsigned)time(NULL));
    set<int>::iterator it;
    int c=0;
    while(s.size()<D_P+1)
        s.insert(rand()%D_R);
    for(it=s.begin();it!=s.end();++it,++c){
        b[c][c]=1;
        memcpy(a[c], m[*it], D_P*sizeof(bool));
    }
    set <int> ss;
    for(int i=0;i<D_P;++i){
        bool flag=0;
        int bn=0;
        for(int j=0;j<D_P+1;++j){
            if(a[j][i]==0||ss.find(j)!= ss.end())
                continue;
            if(a[j][i]==1){
                if(flag){
                    boolxor(a[j], a[bn], D_P);
                    boolxor(b[j], b[bn], D_P+1);
                }
                else{
                    flag=1;
                    bn=j;
                    ss.insert(j);
                }
            }
        }
    }
    for(int i=0;i<D_P+1;++i){
        for(int j=0;j<D_P;++j){
            if(a[i][j]==1) break;
            if(j==D_P-1){
                for(it=s.begin(),c=0;it!=s.end();++it,++c){
                    if(b[i][c]){
                        t[*it]=1;
                    }
                }
                return t;
            }
                
        }
    }
    return t;
}
