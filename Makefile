
all: tui gui server


tui:
	cd src/tui; \
	make
	mv src/tui/tui bin/tui
    
gui:
	cd src/gui; \
	qmake -makefile; \
	make
	mv src/gui/QTCalc bin/gui

server:
	cd src/server; \
	make
	mv src/server/server bin/server

clean:
	rm bin/*
	rm src/*/*.o

