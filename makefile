
CXX = g++
CFLAGS = -Wall -Werror


INCLUDE = -I/usr/local/include
LDFLAGS = -l/usr/local/lib
LDLIBS = -lcurl

SOURCES = src/shared/vars.cpp src/shared/args.cpp src/curl-helper/curl_helper.cpp src/curl-helper/curl_session.cpp src/curl-helper/init_curl.cpp src/log/log.cpp src/test/test.cpp

OUT = test.out

test: build

build: $(SOURCES)
	$(CXX) -o $(OUT) $(INCLUDE) $(LDLIBS) $(CFLAGS) $(SOURCES) 
