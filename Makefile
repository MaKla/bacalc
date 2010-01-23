
all: tui gui server


tui:
	cd src/tui; \
	make; \
	mv tui ../bin
    
gui:
	cd src/gui; \
	qmake -makefile; \
	make
	mv src/gui/QTCalc bin/gui

server:
	cd src/server; \
	make; \
	mv server ../bin

clean:
	rm bin/*
	rm src/*/*.o

