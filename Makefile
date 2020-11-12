.PHONY: clean Clean

PROGNAME = AutoRestart

$(PROGNAME): main.o
	$(CC) main.o -o $(PROGNAME)

main.o:

clean:
	rm *.o

Clean: clean
	rm $(PROGNAME)
