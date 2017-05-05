objects = main.o prime_gen.o relation_collect.o large_integer.o \
	linear_combiner.o
cxx = g++
g = -g -Og

tryqs : $(objects)
	$(cxx) -o tryqs $(objects)

main.o : main.cpp env.h prime_gen.h relation_collect.h large_integer.h linear_combiner.h
	$(cxx) -c $(g) main.cpp
prime_gen.o : prime_gen.cpp env.h prime_gen.h
	$(cxx) -c $(g) prime_gen.cpp -lm
relation_collect.o : relation_collect.cpp env.h relation_collect.h
	$(cxx) -c $(g) relation_collect.cpp -lm
large_integer.o : large_integer.cpp large_integer.h
	$(cxx) -c $(g) large_integer.cpp
linear_combiner.o : linear_combiner.cpp linear_combiner.h env.h
	$(cxx) -c $(g) linear_combiner.cpp

clean :
	rm -f tryps $(objects)
