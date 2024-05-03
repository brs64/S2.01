TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        diaporama.cpp \
        image.cpp \
        imageDansDiaporama.cpp \
        lecteur.cpp \
        main.cpp \
        sousProgrammes.cpp

HEADERS += \
    ImageDansDiaporama.h \
    image.h \
    lecteur.h \
    diaporama.h \
    sousProgrammes.h
