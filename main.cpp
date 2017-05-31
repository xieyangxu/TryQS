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
        cin>>s>>DR>>DP;
        cout<<"case "<<i<<":"<<endl<<"f = "<<s<<" DR = "<<DR<<" DP = "<<DP<<endl;
        f = BigInt(s.c_str());
        //prime_print();
        collect(f, DR, DP);
        //void collect(long f, int num_relation, int num_prime);
        //print_relation(D_R, D_P, 0);
        //void print_relation(int num_relation, int num_prime, int num_partial);

        myresolve(f,DR,DP,100);
    }
	return 0;
}
