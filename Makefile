main: lab_07_anthony_tran.cpp
	g++ -std=c++11 lab_07_anthony_tran.cpp -o main
run:
	./main < matrix-data.txt
clean:
	rm -f *.o main