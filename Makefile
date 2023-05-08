OBJECTS=./build/compiler.o ./build/cprocess.o ./build/buffer.o ./build/vector.o ./build/main.o

INCLUDES= -I./ -I./helpers/

all: ${OBJECTS}
	gcc ${OBJECTS} ${INCLUDES} -g -o ./build/peach

./build/compiler.o: ./src/compiler.c
	gcc ./src/compiler.c ${INCLUDES} -o ./build/compiler.o -g -c

./build/cprocess.o: ./src/cprocess.c
	gcc ./src/cprocess.c ${INCLUDES} -o ./build/cprocess.o -g -c

./build/buffer.o: ./helpers/buffer.c
	gcc ./helpers/buffer.c ${INCLUDES} -o ./build/buffer.o -g -c

./build/vector.o: ./helpers/vector.c
	gcc ./helpers/vector.c ${INCLUDES} -o ./build/vector.o -g -c

./build/main.o: ./src/main.c
	gcc ./src/main.c ${INCLUDES} -o ./build/main.o -g -c

clean:
	rm -rf ${OBJECTS}
