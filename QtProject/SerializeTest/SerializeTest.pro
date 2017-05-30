QT += core
QT -= gui

CONFIG += c++11

TARGET = SerializeTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../sourceCode/gtest/googletest/include \
               ../../sourceCode/gtest/googlemock/include \
               ../../sourceCode/gtest/googletest/ \
               ../../sourceCode/gtest/googlemock/ \
               ../../sourceCode/Serialize \
               ../../sourceCode/Common


SOURCES += \
    ../../sourceCode/Serialize/ReadBuffer.cpp \
    ../../sourceCode/Serialize/WriteBuffer.cpp \
    ../../sourceCode/gtest/googlemock/src/gmock-all.cc \
    ../../sourceCode/gtest/googlemock/src/gmock-cardinalities.cc \
    ../../sourceCode/gtest/googlemock/src/gmock-internal-utils.cc \
    ../../sourceCode/gtest/googlemock/src/gmock-matchers.cc \
    ../../sourceCode/gtest/googlemock/src/gmock-spec-builders.cc \
    ../../sourceCode/gtest/googlemock/src/gmock.cc \
    ../../sourceCode/gtest/googletest/src/gtest-all.cc \
    ../../sourceCode/gtest/googletest/src/gtest-death-test.cc \
    ../../sourceCode/gtest/googletest/src/gtest-filepath.cc \
    ../../sourceCode/gtest/googletest/src/gtest-port.cc \
    ../../sourceCode/gtest/googletest/src/gtest-printers.cc \
    ../../sourceCode/gtest/googletest/src/gtest-test-part.cc \
    ../../sourceCode/gtest/googletest/src/gtest-typed-test.cc \
    ../../sourceCode/gtest/googletest/src/gtest.cc \
    ../../sourceCode/gtest/googlemock/src/gmock_main.cc \
    ../../sourceCode/Common/Random.cpp \
    ../../sourceCode/SerializeTest/BufferAndDataTest.cpp \
    ../../sourceCode/SerializeTest/ReadWriteBufferTest.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    ../../sourceCode/gtest/googletest/include/gtest/internal/custom/gtest-port.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/custom/gtest-printers.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/custom/gtest.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-death-test-internal.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-filepath.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-internal.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-linked_ptr.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-param-util-generated.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-param-util.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-port-arch.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-port.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-string.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-tuple.h \
    ../../sourceCode/gtest/googletest/include/gtest/internal/gtest-type-util.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-death-test.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-message.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-param-test.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-printers.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-spi.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-test-part.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest-typed-test.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest_pred_impl.h \
    ../../sourceCode/gtest/googletest/include/gtest/gtest_prod.h \
    ../../sourceCode/gtest/googletest/src/gtest-internal-inl.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/custom/gmock-generated-actions.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/custom/gmock-matchers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/custom/gmock-port.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/gmock-generated-internal-utils.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/gmock-internal-utils.h \
    ../../sourceCode/gtest/googlemock/include/gmock/internal/gmock-port.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-actions.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-cardinalities.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-generated-actions.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-generated-function-mockers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-generated-matchers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-generated-nice-strict.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-matchers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-more-actions.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-more-matchers.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock-spec-builders.h \
    ../../sourceCode/gtest/googlemock/include/gmock/gmock.h \
    ../../sourceCode/Serialize/BufferToData.h \
    ../../sourceCode/Serialize/DataToBuffer.h \
    ../../sourceCode/Serialize/ReadBuffer.h \
    ../../sourceCode/Serialize/WriteBuffer.h \
    ../../sourceCode/Common/Random.h