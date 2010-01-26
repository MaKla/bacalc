
UNAME := $(shell uname)

all: bin_folder tui gui server

bin_folder:
	mkdir -p bin

tui:
	cd src/tui; \
	make
	mv src/tui/tui bin/tui
    
gui:
	cd src/gui; \
	qmake -makefile; \
	make
ifeq ($(UNAME),Darwin)
	mv src/gui/QTCalc.app/Contents/MacOS/QTCalc bin/gui
endif
ifeq ($(UNAME),Linux)
	mv src/gui/QTCalc bin/gui
endif

server:
	cd src/server; \
	make
	mv src/server/server bin/server

clean:
	rm bin/*
	rm src/*/*.o

