#include "env.h"
#include "prime_gen.h"
#include "relation_collect.h"
#include "large_integer.h"


long f;	

int main(int argc, char const *argv[])
{
	//scanf("%ld", f);
	prime_gen();
	prime_print();

	//collect(f);
	
	return 0;
}
