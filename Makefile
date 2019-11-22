LIKWID = /home/soft/likwid
LIKWID_FLAGS = -I$(LIKWID)/include
LIKWID_LIBS = -L$(LIKWID)/lib

CFLAGS = -Wall -g -march=native $(LIKWID_FLAGS) -DLIKWID_PERFMON
LDLIBS = $(LIKWID_LIBS) -llikwid
CC=gcc
busca = busca.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

bus: $(busca)
	$(CC) -o $@ $< $(CFLAGS) $(LDLIBS)

purge:
	rm bus