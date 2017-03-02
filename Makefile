CPPFLAGS  = -Wall -Wextra -Werror
OBJECTS = question1_1 question1_4 question1_5 question1_6 question1_7

all : $(OBJECTS)


question1_1 : question1_1.cpp Makefile
	g++ $(CPPFLAGS) -o question1_1 question1_1.cpp


question1_4 : question1_4.cpp Makefile
	g++ $(CPPFLAGS) -o question1_4 question1_4.cpp

question1_7 : question1_7.cpp Makefile
	g++ $(CPPFLAGS) -o question1_7 question1_7.cpp

.PHONY: clean

clean :
	rm $(OBJECTS)

check-syntax:
	g++ -o /dev/null -S ${CHK_SOURCES}
