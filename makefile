CXX = g++
CPPFLAGS = -std=c++11 -Wall -g

SRCS_CPP = \
	./lib/Process.cpp \
	./lib/Algorithm.cpp \
	./lib/RoundRobin.cpp \
	./lib/SJF.cpp \
	./lib/MeanPriorityQueue.cpp \
	./lib/DRRHA.cpp \
	./lib/mDRRHA.cpp \
	./lib/nDRRHA.cpp \
	./lib/HRRNHA.cpp \
	./src/main.cpp \

run:
	$(CXX) $(SRCS_CPP) -o application $(CPPFLAGS)