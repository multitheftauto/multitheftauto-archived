INCLUDES += -I$(srcdir)/../sdk/
INCLUDES += -I$(srcdir)/tinyxml/

noinst_LIBRARIES = \
  libtinyxml.a \
	libxml.a

libtinyxml_a_SOURCES = \
  tinyxml/tinystr.cpp \
  tinyxml/tinystr.h \
  tinyxml/tinyxml.cpp \
  tinyxml/tinyxmlerror.cpp \
  tinyxml/tinyxml.h \
  tinyxml/tinyxmlparser.cpp

libtinyxml_a_CXXFLAGS = \
  -DTIXML_USE_STL

libxml_a_SOURCES = \
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

