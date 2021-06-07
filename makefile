
CC= gcc
GCCFLAGS= -std=gnu99  -Wall -pedantic 
GCCLIBS= -lm

SOURCES_SERVER= customServer.c
SOURCES_CLIENT= user.c
SOURCES_LEVELS= levels.c

OBJECTS_LEVELS=$(SOURCES_LEVELS:.c=.o)

EXECUTABLE_SERVER= customServer
EXECUTABLE_CLIENT= user

all: $(OBJECTS_LEVELS) client
	$(CC) $(GCCFLAGS) $(SOURCES_SERVER) $(OBJECTS_LEVELS) -I./include -o $(EXECUTABLE_SERVER) $(GCCLIBS)
	touch .RUN_ME
	objcopy --add-section .RUN_ME=.RUN_ME  customServer
	rm .RUN_ME

%.o: %.c
	$(CC) $(GCCFLAGS) -I./include -c $^ $(GCCLIBS)

client:
	$(CC) $(GCCFLAGS) $(SOURCES_CLIENT) -o $(EXECUTABLE_CLIENT)

clean:
	rm -rf *.o customServer user

cleanTest:
	rm -rf output.cppOut report.tasks results.valgrind

test: cleanTest
	./pvs.sh; valgrind --leak-check=full -v ./customServer 2>> results.valgrind; valgrind --leak-check=full -v ./user 2>> results.valgrind; cppcheck --quiet --enable=all --force --inconclusive customServer.c levels.c user.c 2>> output.cppOut

.PHONY: all clean cleanTest test