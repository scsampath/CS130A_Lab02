.PHONY:main
all:main

main:
	g++ -std=c++11 -g *.cpp -o main
	./main

clean:
	/bin/rm -rf *.o main
