#__start__: obj program
#	./program

PROG=gen

OBJ=obj/main.o obj/generator.o

CPPFLAGS=-Wall -pedantic -Iinc -I/home/krzysztof/Desktop/PAMSI/Laboratorium_1/Generator_liczb/inc -c
LDFLAGS= -Wall -L/home/krzysztof/Desktop/PAMSI/Laboratorium_1/Generator_liczb/obj

#obj:
#	mkdir obj

$(PROG):$(OBJ)
	g++ ${LDFLAGS} -o $(PROG) $(OBJ)  -lrt


obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o $@ $^ -lrt
	
obj/generator.o: src/generator.cpp
	g++ ${CPPFLAGS} -o $@ $^ -lrt

clean:
	rm -f program obj/*