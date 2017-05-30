#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "myresolve.h"
using namespace std;
bool myresolve(long f, long DR, long DP, long trynum){
    srand((unsigned)time(NULL));
    while(trynum--){
        bool* t=linear_combiner(DR, DP);
        if(t==NULL){
            printf("failure: t= NULL \n");
            free(t);
            continue;
        }
        print_combiniation(t, DP);
        long A=1,B=1;
        for(int i=0;i<DR;++i){
            if(t[i]){
                A*=y[i];
                B*=q[i];
            }
        }
        B=(long)sqrt(double(B));
        printf("A=%ld,B=%ld\n",A,B);
        long gcd=mygcd(A-B,f);
        if(gcd==1||gcd==f){
            printf("failure: ordinary prime fector \n");
            free(t);
            continue;
        }
        printf("success!%ld=%ld*%ld\n",f,gcd,f/gcd);
        free(t);
        return 1;
    }
    return 0;
}
