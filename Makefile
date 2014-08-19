###########################################################  Makefile
# CS570, Summer 2014, a2
# Jason Ronquillo, masc1425
###########################################################
EXEC = a2
CC = gcc 
FILES = main.c functions.c functions.h
OBJECTS = $(FILES:.c=.o)

$(EXEC):$(OBJECTS) 
	$(CC) -o $(EXEC) $(OBJECTS) 
	rm -f *.o

clean:
	rm -f *.o core $(EXEC)

#######################[ EOF: Makefile ]###################
