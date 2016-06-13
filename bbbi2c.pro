TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CPBBoneBlackI2C.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    CPBBoneBlackI2C.hpp

CONFIG   += c++11
