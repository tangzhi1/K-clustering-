big_k_clustering : big_k_clustering.o union_find.o 
			g++ -Wall -g -o big_k_clustering big_k_clustering.o union_find.o

big_k_clustering.o : big_k_clustering.cpp union_find.h 
			g++ -Wall -g -c big_k_clustering.cpp

union_find.o : union_find.cpp union_find.h
			g++ -Wall -g -c union_find.cpp

