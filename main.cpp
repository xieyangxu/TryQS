#include "env.h"
#include "prime_gen.h"
#include "relation_collect.h"
#include "large_integer.h"
#include "linear_combiner.h"
#include "myresolve.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
time_t start_time;
time_t cur_time;
clock_t start_time_ms;
clock_t cur_time_ms;
float Alpha=1.2;
BigInt f("0");
int main(int argc, char const *argv[])
{
    int DR,DP;
    string s;
    s.resize(100);
    prime_gen();
    freopen("case.txt","r",stdin);
    freopen("result.txt","w",stdout);
    for(int i=0;i<24;++i){
        cin>>s>>DR>>DP>>Alpha;
        cout<<"case "<<i<<":"<<endl<<"f = "<<s<<" DR = "<<DR<<" DP = "<<DP<<" Alpha = "<<Alpha<<endl;
        f = BigInt(s.c_str());
        start_time_ms=clock();
        //prime_print();
        collect(f, DR, DP, Alpha);
        cur_time_ms=clock();
        printf("collect time = %ld ms\n",(cur_time_ms-start_time_ms)/1000);
        start_time_ms=cur_time_ms;
        //void collect(long f, int num_relation, int num_prime);
        //print_relation(D_R, D_P, 0);
        //void print_relation(int num_relation, int num_prime, int num_partial);

        myresolve(f,DR,DP,1000);
        cur_time_ms=clock();
        printf("combine time = %ld ms\n\n",(cur_time_ms-start_time_ms)/1000);
        
    }
	return 0;
}
