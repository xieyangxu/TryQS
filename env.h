#ifndef ENV_H
#define ENV_H

#define D_P 100  // Dimension of primes
#define D_R 100	// Dimension of relations
using namespace std;

extern long p[D_P+10]; 			// Prime table
extern bool m[D_R+10][D_P+10]; 	// Relation table
extern long y[D_R+10];			// Y table for each relation (y[i]^2 is factored in m[i])
extern long r[D_R+10];          // Remain number table of factor
extern long f;					// Number to factor

#endif
