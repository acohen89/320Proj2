cache-sim: main.o DMC.o cacheBlock.o SAC.o cacheBlockCollection.o FAC.o
	g++ -g -O0 -o cache-sim main.o DMC.o cacheBlock.o SAC.o cacheBlockCollection.o FAC.o

main.o: main.cpp
	g++ -g -O0 -c main.cpp

DMC.o: DMC.cpp
	g++ -g -O0 -c DMC.cpp

cacheBlock.o: cacheBlock.cpp
	g++ -g -O0 -c cacheBlock.cpp

SAC.o: SAC.cpp
	g++ -g -O0 -c SAC.cpp

cacheBlockCollection.o: cacheBlockCollection.cpp
	g++ -g -O0 -c cacheBlockCollection.cpp

FAC.o: FAC.cpp
	g++ -g -O0 -c FAC.cpp

clean: 
	rm -f core *.o 
	rm cache-sim.exe

