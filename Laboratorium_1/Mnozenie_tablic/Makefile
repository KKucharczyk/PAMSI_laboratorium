#__start__: obj program
#	./program

PROG=program1

OBJ=obj/main.o obj/obiekt.o

CPPFLAGS=-Wall -pedantic -Iinc -I/home/krzysztof/Desktop/PAMSI/Laboratorium_2/Mnozenie_tablic/inc -c
LDFLAGS= -Wall -L/home/krzysztof/Desktop/PAMSI/Laboratorium_2/Mnozenie_tablic/obj

#obj:
#	mkdir obj

$(PROG):$(OBJ)
	g++ ${LDFLAGS} -std=c++0x -o $(PROG) $(OBJ)  -lrt


obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o $@ $^ -lrt -std=c++0x
	
obj/obiekt.o: src/obiekt.cpp
	g++ ${CPPFLAGS} -o $@ $^ -lrt -std=c++0x

clean:
	rm -f program obj/*