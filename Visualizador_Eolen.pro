QT += qml quick quickcontrols2 network websockets

# Add these lines to ensure QML modules are bundled
QML_IMPORT_PATH = $$[QT_INSTALL_QML]
QML_DESIGNER_IMPORT_PATH = $$QML_IMPORT_PATH

# Explicitly import QML modules
QML_IMPORT_SCAN = $$QML_IMPORT_PATH

# For Windows deployment
win32 {
    QML_MODULES = \
        QtQuick \
        QtQuick/Controls \
        QtQuick/Controls/impl \
        QtQuick/Templates \
        QtQuick/Window \
        QtQml \
        QtQml/WorkerScript
}


CONFIG += console

DEFINES += REMOTE_MODE

SOURCES += \
        impactVisualizer.cpp \
        main.cpp

RESOURCES += qml.qrc

# # Additional import path used to resolve QML modules in Qt Creator's code model
# QML_IMPORT_PATH =

# # Additional import path used to resolve QML modules just for Qt Quick Designer
# QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# DISTFILES +=

HEADERS += \
    ImpactVisualizer.h

CONFIG(release){ DESTDIR = $$OUT_PWD/release}
# QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt.exe $$shell_quote($$DESTDIR/$$shell_quote($$TARGET).exe) #--no-compiler-runtime
QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt.exe $$shell_quote($$DESTDIR/$$shell_quote($$TARGET).exe) --qmldir $$PWD --no-translations
