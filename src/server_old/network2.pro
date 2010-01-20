SOURCES += bacalc_server.cpp \
    bacalc_server_main.cpp \
    bacalc_processor.cpp \
    tools.cpp

# install
sources.files = $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    $$FORMS \
    network2.pro
INSTALLS += target \
    sources
QT += network
HEADERS += bacalc_server.h \
    bacalc_processor.h
