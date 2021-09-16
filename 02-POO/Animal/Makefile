CC=g++
FLAGS=-O2 -Wall

# run:
#	make all
#	./zoo

all: animal.o dog.o cat.o zoo

animal.o: animal.cpp animal.hpp
	${CC} ${FLAGS} -c animal.cpp

dog.o:	dog.cpp dog.hpp animal.o
	${CC} ${FLAGS} -c dog.cpp

cat.o: cat.hpp cat.cpp animal.o 
	${CC} ${FLAGS} -c cat.cpp

zoo: animal.o dog.o cat.o main.cpp
	${CC} ${FLAGS} main.cpp animal.o dog.o cat.o -o zoo
	
clean:
	rm -f *.o zoo
