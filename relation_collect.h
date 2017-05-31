#ifndef RELATION_COLLECT_H
#define RELATION_COLLECT_H

#include "env.h"
using namespace std;

void init();
void gen(BigInt A, int &ccnt, int num_prime, int &pcnt);
void collect(BigInt f, int num_relation, int num_prime);
void print_relation(int num_relation, int num_prime, int num_partial);

#endif
