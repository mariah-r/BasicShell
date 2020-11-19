###########################################################
#
# Simple Makefile for Operating Systems Project 1
# guish
#
###########################################################
.SUFFIXES: .h .c .cpp .l .o

guish2: guish.yy.o guish2.o
	g++ guish.yy.o guish2.o -o mroberts4_proj1
	

guish2.o: guish2.cpp
	g++ -c guish2.cpp historyFile.cpp

guish.yy.o: guish.yy.c
	gcc -c guish.yy.c

guish.yy.c: guish.l
	flex -oguish.yy.c guish.l

clean:
	/bin/rm -f *.o *~ core guish guish.yy.c


