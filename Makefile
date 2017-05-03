objects = main.o prime_gen.o relation_collect.o
cxx = g++

tryqs : $(objects)
	$(cxx) -o tryqs $(objects)

main.o : main.cpp env.h prime_gen.h relation_collect.h
	$(cxx) -c main.cpp
prime_gen.o : prime_gen.cpp env.h prime_gen.h
	$(cxx) -c prime_gen.cpp -lm
relation_collect.o : relation_collect.cpp env.h relation_collect.h
	$(cxx) -c relation_collect.cpp -lm

clean :
	rm -f tryps $(objects)
