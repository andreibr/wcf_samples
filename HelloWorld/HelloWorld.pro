QT -= gui
QT += network xml sql

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp

LIBS += -ljemalloc

INCLUDEPATH += /usr/lib
debug {
    LIBS += -L/usr/lib -lCPPWebFrameworkd
}
release {
    LIBS += -L/usr/lib -lCPPWebFramework
}

DISTFILES += \
    server/config/CPPWeb.ini \
    server/config/cppwebserverpages/403.view \
    server/config/cppwebserverpages/404.view \
    server/config/cppwebserverpages/index.view \
    server/config/cppwebserverpages/resources/css/cppweb.css \
    server/config/cppwebserverpages/resources/images/favicon.ico \
    server/config/cppwebserverpages/resources/images/logo.png \
    server/config/log/CPPWebServer.log \
    server/config/ssl/cert.pem \
    server/config/ssl/key.pem \
    server/pages/hello.html \
    server/pages/helloresults.view

