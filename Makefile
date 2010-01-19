
all: tui gui server


tui:
	g++ src/tui/Calculator.cpp -o bin/tui
    
gui:
	cd src/gui; \
	qmake -makefile; \
	make
	mv src/gui/QTCalc bin/gui

server:
	cd src/server; \
	qmake -makefile; \
	make
	mv src/server/network2 bin/server

clean:
	rm bin/*

