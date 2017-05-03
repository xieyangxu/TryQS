#ifndef ENV_H
#define ENV_H

#define D_P 100000  // Dimension of primes
#define D_R 1		// Dimension of relations
using namespace std;

extern long p[D_P+10]; 		// Prime table
extern bool m[D_R][D_P+10]; // Relation table
extern long f;				// Number to factor

#endif