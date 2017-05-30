#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "myresolve.h"
using namespace std;
bool myresolve(BigInt f, long DR, long DP, long trynum){
    srand((unsigned)time(NULL));
    while(trynum--){
        bool* t=linear_combiner(DR, DP);
        if(t==NULL){
            printf("failure: t= NULL \n");
            free(t);
            continue;
        }
        print_combiniation(t, DP);
        BigInt A=1,B=1;
        for(int i=0;i<DR;++i){
            if(t[i]){
                A=A*y[i];
                B=B*q[i];
            }
        }
        B=B.bigsqrt();
        cout<<"A="<<A<<",B="<<B<<endl;

        BigInt gcd=biggcd(A-B,f);
        if(gcd==1||gcd==f){
            printf("failure: ordinary prime fector \n");
            free(t);
            continue;
        }
        cout<<"success!"<<f<<'='<<gcd<<'*'<<f/gcd<<endl;
        free(t);
        return 1;
    }
    return 0;
}
