CC=gcc
DEBUG_FLAGS=-g
#INCLUDE_FLAGS=-I dm6425/
#LIBRARY_FLAGS=dm6425/librtd-dm6425.a
#OPTIMIZE_FLAGS=-O2
WARNING_FLAGS=-Wall

#CFLAGS:=$(DEBUG_FLAGS) $(INCLUDE_FLAGS) $(OPTIMIZE_FLAGS) $(WARNING_FLAGS)
CFLAGS:=$(DEBUG_FLAGS) $(WARNING_FLAGS)

PROGRAMS= \
	getaddrinfo \
	showip \
	bind \
	connect

all: $(PROGRAMS)

gethostent: getaddrinfo.c
	$(CC) $(CFLAGS) -o getaddrinfo getaddrinfo.c

showip: showip.c
	$(CC) $(CFLAGS) -o showip showip.c

bind: bind.c
	$(CC) $(CFLAGS) -o bind bind.c

connect: connect.c
	$(CC) $(CFLAGS) -o connect connect.c

clean:
	rm -f *.o *.dat *~ $(PROGRAMS)