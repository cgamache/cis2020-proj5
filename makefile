DIR=/home/faculty/uh/cis4930/proj5
CC=gcc
CFLAGS= -g -c -I$(DIR) -I. -DLEFTTORIGHT -DSPARC

csem: sym.o scan.o sem.o cgram.o semutil.o
	gcc -g -o csem sym.o scan.o sem.o cgram.o semutil.o

sym.o: $(DIR)/sym.c $(DIR)/cc.h y.tab.h
	gcc $(CFLAGS) $(DIR)/sym.c

scan.o:	$(DIR)/scan.c $(DIR)/cc.h y.tab.h
	gcc $(CFLAGS) $(DIR)/scan.c

sem.o: sem.c $(DIR)/cc.h y.tab.h
	gcc $(CFLAGS) sem.c

semutil.o: $(DIR)/semutil.c $(DIR)/cc.h $(DIR)/sem.h $(DIR)/sym.h
	gcc $(CFLAGS) $(DIR)/semutil.c

y.tab.h cgram.c: $(DIR)/cgram.y
	yacc -vd $(DIR)/cgram.y
	mv y.tab.c cgram.c
clean:
	rm -f *.o *~ cgram.c y.tab.h \#*\#

