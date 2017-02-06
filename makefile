CC = g++
CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

tester: main.o CppPrimerExsFunc.o CppPrimerTestFunc.o OpenCVTestFunc.o
	$(CC) -o tester main.o CppPrimerExsFunc.o CppPrimerTestFunc.o OpenCVTestFunc.o $(LIBS)

OpenCVTestFunc.o: OpenCVTestFunc.cpp OpenCVHeader.h
	$(CC) -c $(CFLAGS) OpenCVTestFunc.cpp -std=c++11
CppPrimerTestFunc.o: CppPrimerTestFunc.cpp CppPrimerHeader.h
	$(CC) -c CppPrimerTestFunc.cpp -std=c++11
CppPrimerExsFunc.o: CppPrimerExsFunc.cpp CppPrimerHeader.h Sales_item.h
	$(CC) -c CppPrimerExsFunc.cpp -std=c++11
main.o: main.cpp CppPrimerHeader.h OpenCVHeader.h
	$(CC) -c main.cpp -std=c++11

clean:
	rm -f main.o CppPrimerExsFunc.o CppPrimerTestFunc.o OpenCVTestFunc.o tester
