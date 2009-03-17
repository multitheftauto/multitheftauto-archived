INCLUDES += -I$(srcdir)/../sdk/
INCLUDES += -I$(srcdir)/../../vendor/tinyxml/

lib_LTLIBRARIES = \
	libxml.la

libxml_la_SOURCES = \
	CXMLArray.cpp \
	CXMLArray.h \
	CXMLAttributeImpl.cpp \
	CXMLAttributeImpl.h \
	CXMLAttributesImpl.cpp \
	CXMLAttributesImpl.h \
	CXMLFileImpl.cpp \
	CXMLFileImpl.h \
	CXMLImpl.cpp \
	CXMLImpl.h \
	CXMLNodeImpl.cpp \
	CXMLNodeImpl.h \
	StdInc.cpp \
	StdInc.h \
	XML.cpp

libxml_la_LDFLAGS = -L../../vendor/tinyxml -ltinyxml
