CXX=g++
CXX_FLAGS=-std=c++2a

parser: lexer.o main.o token.o util.o
	$(CXX) $(CXX_FLAGS) lexer.o main.o token.o util.o -o parser

lexer.o:
	$(CXX) $(CXX_FLAGS) -c lexer.cpp

main.o:
	$(CXX) $(CXX_FLAGS) -c main.cpp

token.o:
	$(CXX) $(CXX_FLAGS) -c token.cpp

util.o:
	$(CXX) $(CXX_FLAGS) -c util.cpp

clean:
	rm -rf *.o parser