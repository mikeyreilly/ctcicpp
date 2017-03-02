CFLAGS  = -Wall -Wextra -Werror

all : question1_1 question1_4


question1_1 : question1_1.cpp Makefile
	g++ $(CFLAGS) -o question1_1 question1_1.cpp


question1_4 : question1_4.cpp Makefile
	g++ $(CFLAGS) -o question1_4 question1_4.cpp

clean :
	rm question1_4 question1_1

