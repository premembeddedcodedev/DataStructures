CC = gcc
#CFLAGS  = -g -Wall
CFLAGS  = 

default: count count-1 count-2 count-3 count-4

count:  example-1.o algo.o
	$(CC) $(CFLAGS) -o check Algo.o 268_Missing.o
count-1:  example-2.o algo.o
	$(CC) $(CFLAGS) -o check_1 Algo.o 287.FindtheDuplicateNumber.o
count-2:  example-3.o algo.o
	$(CC) $(CFLAGS) -o check_2 Algo.o 41.FirstMissingPositive.o
count-3:  example-4.o algo.o
	$(CC) $(CFLAGS) -o check_3 Algo.o 448.all_disappeared_num.o
count-4:  example-5.o algo.o
	$(CC) $(CFLAGS) -o check_4 Algo.o 645.SetMismatch.o

example-1.o:  268_Missing.c Algo.h 
	$(CC) $(CFLAGS) -c 268_Missing.c

example-2.o: 287.FindtheDuplicateNumber.c  Algo.h
	$(CC) $(CFLAGS) -c 287.FindtheDuplicateNumber.c
example-3.o: 41.FirstMissingPositive.c Algo.h 
	$(CC) $(CFLAGS) -c 41.FirstMissingPositive.c
example-4.o: 448.all_disappeared_num.c Algo.h
	$(CC) $(CFLAGS) -c 448.all_disappeared_num.c
example-5.o: 645.SetMismatch.c Algo.h
	$(CC) $(CFLAGS) -c 645.SetMismatch.c

algo.o:  Algo.c Algo.h 
	$(CC) $(CFLAGS) -c Algo.c

clean: 
	$(RM) count *.o *~
