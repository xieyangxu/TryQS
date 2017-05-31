#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "myresolve.h"
using namespace std;
bool myresolve(BigInt f, long DR, long DP, long trynum){
    srand((unsigned)time(NULL));
    int n=0;
    int success_cnt=0;
    int failure_cnt=0;
    long setsize=1;
    for(int i=0;i<DP;++i){
        for(int j=0;j<DR;++j){
            if(m[j][i]==1){
                setsize++;
                break;
            }
        }
    }
    printf("setsize = %ld\n",setsize);
    while(n<trynum){
        n++;
        //printf("trynum = %d ",n);
        fflush(stdout);
        bool* t=linear_combiner(DR, DP, setsize);
        if(t==NULL){
            //printf("failure: t= NULL \n");
            free(t);
            failure_cnt++;
            continue;
        }
        //print_combiniation(t, DP);
        BigInt A=1,B=1;
        for(int i=0;i<DR;++i){
            if(t[i]){
                A=A*y[i];
                B=B*q[i];
            }
        }
        B=B.bigsqrt();
        //cout<<"A="<<A<<",B="<<B<<endl;

        BigInt gcd=biggcd(A-B,f);
        if(gcd==1||gcd==f){
            //printf("failure: ordinary prime fector \n");
            free(t);
            failure_cnt++;
            continue;
        }
        //cout<<"success!"<<f<<'='<<gcd<<'*'<<f/gcd<<endl;
        success_cnt++;
        free(t);
    }
    printf("success : %d, failure : %d\n",success_cnt,failure_cnt);
    return 0;
}
