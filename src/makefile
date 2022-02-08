
# lines beginning with '#' are comment lines ignored by make

# the line below (CC=gcc) is an example of a variable in a makefile.
# In this particular case, we create a variable CC which expands
#    to gcc (see usage in targets of $(CC)
# Why might we do this instead of just using 'gcc' itself?
#    The idea is the same as defining constants in a regular program
#    so your code doesn't have the same magic number all over the place
#    and in the event you want to change that constant, you just have
#    to change the one line that defines the constant.
#
# Here, imagine that you want to try a different compiler (like clang or cc).
#    You can just change the one line.
#    Similarly, if you wanted gcc to be invoked with a certain flag or
#    flags, you can also just change the line (for example the flag that
#    enables debugging with gdb).
#
CC=gcc -g

all: bsearch demo

bsearch: bsearch.c
	$(CC) bsearch.c -o bsearch

demo:  demo.c pdigits.o
	$(CC) -o demo demo.c pdigits.o

pdigits.o:  pdigits.h pdigits.c
	$(CC) -c pdigits.c

clean:
	rm -f *.o demo bsearch
