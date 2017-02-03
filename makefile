tester: main.o CppPrimerExsFunc.o CppPrimerTestFunc.o
	g++ main.o CppPrimerExsFunc.o CppPrimerTestFunc.o -o tester

CppPrimerTestFunc.o: CppPrimerTestFunc.cpp CppPrimerHeader.h
	g++ -c CppPrimerTestFunc.cpp -std=c++11
CppPrimerExsFunc.o: CppPrimerExsFunc.cpp CppPrimerHeader.h Sales_item.h
	g++ -c CppPrimerExsFunc.cpp -std=c++11
main.o: main.cpp CppPrimerHeader.h
	g++ -c main.cpp -std=c++11

clean:
	rm -f main.o CppPrimerExsFunc.o CppPrimerTestFunc.o tester
