CXX = g++
CFLAGS = -Wall -Werror -std=c++11 -c -ggdb3


INCLUDE = -I/usr/local/include
LDFLAGS = -L/usr/local/lib
LDLIBS = -lxerces-c -lxalan-c -lcurl -ltidy


XML_SOURCES = ../src/xml-helper/xml_document.cpp ../src/xml-helper/xml_nodelist.cpp ../src/xml-helper/xml_node.cpp ../src/xml-helper/xml_attributes.cpp
CURL_SOURCES = ../src/curl-helper/curl_helper.cpp ../src/curl-helper/curl_session.cpp ../src/curl-helper/init_curl.cpp
LOG_SOURCES = ../src/log/log.cpp
SHARED_SOURCES = ../src/shared/vars.cpp
MODEL_SOURCES = ../src/model/form_data.cpp
TIDY_SOURCES = ../src/tidy-helper/tidy_converter.cpp
XSL_SOURCES = ../src/xml-helper/xsl_transformer.cpp
TEST_SOURCES = main.cpp xml_test.cpp curl_test.cpp tidy_test.cpp log_test.cpp xsl_test.cpp test_util.cpp
SOURCES = $(TEST_SOURCES) $(XML_SOURCES) $(LOG_SOURCES) $(SHARED_SOURCES) $(CURL_SOURCES) $(MODEL_SOURCES) $(TIDY_SOURCES) $(XSL_SOURCES)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/run_tests

# XML TEST



# $(removeobj)
define removeobj
	@ find -name '*.o' |					\
	awk 'BEGIN { print "Moving objs"; }		\
				{ 							\
 				print "Moving " $$1 "...";		\
				system("mv " $$1 " obj/");	\
				} '							
endef



all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@ if ! test -d obj; then echo "obj directory not found creating..."; mkdir obj; fi
	@ if ! test -d bin; then echo "bin directory not found creating..."; mkdir bin; fi
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@  $(LDLIBS)
	$(call removeobj)
	@ echo Compiling finished......OOO.....

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf bin
	rm -rf obj
