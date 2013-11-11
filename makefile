
CXX = g++
CFLAGS = -Wall -Werror


INCLUDE = -I/usr/local/include
LDFLAGS = -l/usr/local/lib
LDLIBS = -lcurl

SOURCES = src/curl-helper/curl_helper.cpp src/test/test.cpp

OUT = test.out

test: build

build: $(SOURCES)
	$(CXX) -o $(OUT) $(INCLUDE) $(CFLAGS) $(SOURCES) 
