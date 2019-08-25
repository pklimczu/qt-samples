QT += gui widgets

HEADERS = MainWindow.h \
          TableModel.h \
          FilterProxy.h

SOURCES = main.cpp \
          MainWindow.cpp \
          TableModel.cpp \
          FilterProxy.cpp

DISTFILES += \
    test_data.csv
