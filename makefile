CXX = g++
CPPFLAGS = -std=c++11 -Wall -g

SRCS_CPP = \
	./lib/Process.cpp \
	./lib/Algorithm.cpp \
	./lib/RoundRobin.cpp \
	./lib/SJF.cpp \
	./lib/DRRHA.cpp \
	./lib/MeanPriorityQueue.cpp \
	./src/main.cpp \

run:
	$(CXX) $(SRCS_CPP) -o application $(CPPFLAGS)