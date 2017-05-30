#ifndef ENV_H
#define ENV_H

#include "large_integer.h"

#define D_P 1000  // Dimension of primes
#define D_R 1000	// Dimension of relations
#define D_PR 1000 // Dimension of partial relations
using namespace std;

extern long p[D_P+10]; 			// Prime table
extern bool m[D_R+10][D_P+10]; 	// Relation table
extern BigInt y[D_R+10];			// Y table for each relation (y[i]^2 is factored in m[i])
extern BigInt r[D_R+10];          // Remain number table of factor
extern BigInt q[D_R+10];
extern BigInt f;					// Number to factor

#endif
