#include "env.h"
#include "prime_gen.h"
#include "relation_collect.h"
#include "large_integer.h"
#include "linear_combiner.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


long f;	

int main(int argc, char const *argv[])
{
	//scanf("%ld", f);
	//f = 4033;
	f = 991241;
	prime_gen();
	//prime_print();

	collect(f, 50, 30);
	//void collect(long f, int num_relation, int num_prime);
	print_relation(50, 30, 100);
	//void print_relation(int num_relation, int num_prime, int num_partial);

    /*bool* t=linear_combiner(9, 8);
    if(t==NULL){
        printf("failure\n");
        return 0;
    }
    print_combiniation(t, 9);
    long A=1,B=1;
    for(int i=0;i<D_R;++i){
        if(t[i]){
            A*=y[i];
            B*=y[i]*y[i]-f;
        }
    }
    B=(long)sqrt(double(B));
    printf("A=%ld,B=%ld\n",A,B);
    long gcd=mygcd(A-B,f);
    if(gcd==1){
        printf("failure\n");
        return 0;
    }
    printf("success!%ld=%ld*%ld\n",f,gcd,f/gcd);
    
    free(t);*/
	return 0;
}
