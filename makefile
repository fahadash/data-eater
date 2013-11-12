
CXX = g++
CFLAGS = -Wall -Werror


INCLUDE = -I/usr/local/include
LDFLAGS = -l/usr/local/lib
LDLIBS = -lcurl

SOURCES_SIMPLETEST = src/shared/vars.cpp src/shared/args.cpp src/model/form_data.cpp src/curl-helper/curl_helper.cpp src/curl-helper/curl_session.cpp src/curl-helper/init_curl.cpp src/log/log.cpp src/test/simpletest.cpp

SIMPLE_OUT = simpletest.out

simpletest: simpletest_build

simpletest_build: $(SOURCES_SIMPLETEST)
	$(CXX) -o $(SIMPLE_OUT) $(INCLUDE) $(LDLIBS) $(CFLAGS) $(SOURCES_SIMPLETEST) 

SOURCES_POSTTEST = src/shared/vars.cpp src/shared/args.cpp src/model/form_data.cpp src/curl-helper/curl_helper.cpp src/curl-helper/curl_session.cpp src/curl-helper/init_curl.cpp src/log/log.cpp src/test/posttest.cpp

POST_OUT = posttest.out

posttest: posttest_build

posttest_build: $(SOURCES_POSTTEST)
	$(CXX) -o $(POST_OUT) $(INCLUDE) $(LDLIBS) $(CFLAGS) $(SOURCES_POSTTEST)

