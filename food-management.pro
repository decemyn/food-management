QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    source/statisticsmenu.cpp \
    source/productdetails.cpp \
    source/productadder.cpp \
    source/sellregister.cpp \
    source/basewindow.cpp \
    source/dialoglogin.cpp \
    source/dialogregister.cpp \
    source/fileio.cpp \
    source/loginmenu.cpp \
    source/product.cpp \
    source/saleinterface.cpp \
    source/statisticsinterface.cpp \
    source/useraccount.cpp \
    source/userdomain.cpp \


HEADERS += \
    headers/basewindow.h \
    headers/dialoglogin.h \
    headers/dialogregister.h \
    headers/fileio.h \
    headers/loginmenu.h \
    headers/product.h \
    headers/saleinterface.h \
    headers/statisticsinterface.h \
    headers/useraccount.h \
    headers/userdomain.h \
    headers/sellregister.h \
    headers/productadder.h \
    headers/productdetails.h \
    headers/statisticsmenu.h \
    include/rapidjson/allocators.h \
    include/rapidjson/document.h \
    include/rapidjson/encodedstream.h \
    include/rapidjson/encodings.h \
    include/rapidjson/error/en.h \
    include/rapidjson/error/error.h \
    include/rapidjson/filereadstream.h \
    include/rapidjson/filewritestream.h \
    include/rapidjson/fwd.h \
    include/rapidjson/internal/biginteger.h \
    include/rapidjson/internal/diyfp.h \
    include/rapidjson/internal/dtoa.h \
    include/rapidjson/internal/ieee754.h \
    include/rapidjson/internal/itoa.h \
    include/rapidjson/internal/meta.h \
    include/rapidjson/internal/pow10.h \
    include/rapidjson/internal/regex.h \
    include/rapidjson/internal/stack.h \
    include/rapidjson/internal/strfunc.h \
    include/rapidjson/internal/strtod.h \
    include/rapidjson/internal/swap.h \
    include/rapidjson/istreamwrapper.h \
    include/rapidjson/memorybuffer.h \
    include/rapidjson/memorystream.h \
    include/rapidjson/msinttypes/inttypes.h \
    include/rapidjson/msinttypes/stdint.h \
    include/rapidjson/ostreamwrapper.h \
    include/rapidjson/pointer.h \
    include/rapidjson/prettywriter.h \
    include/rapidjson/rapidjson.h \
    include/rapidjson/reader.h \
    include/rapidjson/schema.h \
    include/rapidjson/stream.h \
    include/rapidjson/stringbuffer.h \
    include/rapidjson/writer.h \





FORMS += \
    ui/statisticsmenu.ui \
    ui/productdetails.ui \
    ui/productadder.ui \
    ui/sellregister.ui \
    ui/basewindow.ui \
    ui/dialoglogin.ui \
    ui/dialogregister.ui \
    ui/loginmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES += \
    assets/hamburger_logo.png

RESOURCES += \
    resouces.qrc

#DECEBAL LIBSODIUM CONF

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/ -lsodium
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/ -lsodium
#else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lsodium

#INCLUDEPATH += $$PWD/../../../../../usr/local/include
#DEPENDPATH += $$PWD/../../../../../usr/local/include

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/release/libsodium.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/debug/libsodium.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/release/sodium.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/debug/sodium.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libsodium.a


#LIVIU LIBSODIUM CONF

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/release/ -lsodium
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/debug/ -lsodium
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/ -lsodium

INCLUDEPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/x86_64-linux-gnu/release/libsodium.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/x86_64-linux-gnu/debug/libsodium.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/x86_64-linux-gnu/release/sodium.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/x86_64-linux-gnu/debug/sodium.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/x86_64-linux-gnu/libsodium.a
