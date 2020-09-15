tokenizer: main.o tokenizer.o history.o
	cc main.o tokenizer.o history.o

clean:
	rm -f *.o tokenizer history.o

tokenizer.o: tokenizer.h tokenizer.c

main: main.c tokenizer.h history.h

history.o: history.h history.c
