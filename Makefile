CPPFLAGS  = -Wall -Wextra -Werror -g -I /usr/local/boost_1_63_0/ -Wno-error=unused-parameter
OBJECTS = question1_1 question1_4 question1_5 question1_6 question1_7 question1_8 \
          question1_9 range_test linked_list

all : $(OBJECTS)


question1_1 : question1_1.cc Makefile
	g++ $(CPPFLAGS) -o question1_1 question1_1.cc


question1_4 : question1_4.cc Makefile
	g++ $(CPPFLAGS) -o question1_4 question1_4.cc

question1_7 : question1_7.cc Makefile
	g++ $(CPPFLAGS) -o question1_7 question1_7.cc

question1_8 : question1_8.cc Makefile
	g++ $(CPPFLAGS) -o question1_8 question1_8.cc

question1_9 : question1_9.cc Makefile
	g++ $(CPPFLAGS) -o question1_9 question1_9.cc

range_test : range_test.cc Makefile
	g++ $(CPPFLAGS) -o range_test range_test.cc

linked_list : linked_list.cc Makefile
	g++ $(CPPFLAGS) -o linked_list linked_list.cc

.PHONY: clean

clean :
	rm $(OBJECTS)

check-syntax:
	g++ -o /dev/null -S ${CHK_SOURCES}
