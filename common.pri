PREFIX = $$PREFIX
isEmpty(PREFIX):PREFIX = /usr/local

macx {
    # Do a universal build when possible
    contains(QT_CONFIG, ppc):CONFIG += x86 ppc
    QMAKE_MAC_SDK = /Developer/SDKs/MacOSX10.5.sdk
}

