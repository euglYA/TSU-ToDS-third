QT = core \
    widgets

CONFIG += c++17 cmdline


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        app.cpp \
        charts.cpp \
        chartscomponent.cpp \
        filereader.cpp \
        filescomponent.cpp \
        ioc.cpp \
        ioctool.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    app.h \
    charts.h \
    chartscomponent.h \
    filereader.h \
    filescomponent.h \
    ioc.h \
    ioctool.h

QT += charts

