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
multiset<BigInt> rs;
stack<BigInt> ns;
int dp(BigInt g){
    if(g<BigInt("100000000")) return 150;
    if(g<BigInt("10000000000")) return 200;
    if(g<BigInt("1000000000000")) return 300;
    if(g<BigInt("100000000000000")) return 400;
    if(g<BigInt("10000000000000000")) return 500;
    if(g<BigInt("1000000000000000000")) return 600;
    else return 1000;
}
int main(int argc, char const *argv[])
{
    start_time = time(NULL);
    if(argc==1){
        cout<<"error : please import a positive integer!"<<endl;
        return 0;
    }
    if(argc>2){
        cout<<"error : too many args"<<endl;
        return 0;
    }
    rs.clear();
    while(!ns.empty()) ns.pop();
    int DR,DP;
    prime_gen();
    ns.push(BigInt(argv[1]));
    while(!ns.empty()){
        f=ns.top();
        ns.pop();
        for(int i=1;p[i]<=D_P;++i){
            while(f%p[i]==0){
                rs.insert(p[i]);
                f=f/p[i];
            }
        }
        if(f<p[D_P]*p[D_P]){
            if(f!=1) rs.insert(f);
            continue;
        }
        DR=DP=dp(f);
        cout<<"f = "<<f<<" DR = "<<DR<<" DP = "<<DP<<" Alpha = "<<Alpha<<endl;
        start_time_ms=clock();
        //prime_print();
        collect(f, DR, DP, Alpha);
        cur_time_ms=clock();
        printf("collect time = %ld ms\n",(cur_time_ms-start_time_ms)/1000);
        start_time_ms=cur_time_ms;
        //void collect(long f, int num_relation, int num_prime);
        //print_relation(D_R, D_P, 0);
        //void print_relation(int num_relation, int num_prime, int num_partial);
        myresolve(f,DR,DP,10000);
        cur_time_ms=clock();
        printf("combine time = %ld ms\n\n\n",(cur_time_ms-start_time_ms)/1000);
    }
    multiset<BigInt>::iterator msi;
    cout<<"f = ";
    for(msi=rs.begin();msi!=rs.end();++msi){
        if(msi!=rs.begin()) cout<<"* ";
        cout<<*msi<<" ";
    }
    cout<<endl;
    return 0;
}
