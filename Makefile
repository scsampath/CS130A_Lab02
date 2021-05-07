.PHONY:main
all:main

main:
	g++ -std=c++11 -g *.cpp -o main
#	./main input_files/test.in 0 3
	./main input_files/test_zipf0.in OUTPUT_FILE 1023

clean:
	/bin/rm -rf *.o main
