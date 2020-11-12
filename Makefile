.PHONY: clean Clean

PROGNAME = AutoRestart

$(PROGNAME): main.o
	$(CC) main.o -o $(PROGNAME)

clean:
	rm -f *.o

Clean: clean
	rm -f $(PROGNAME)
