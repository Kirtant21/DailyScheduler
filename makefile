CXX = g++
CXXFLAGS = -Wall

proj3: Item.o Schedule.o Manager.o proj3.cpp
	$(CXX) $(CXXFLAGS) Item.o Schedule.o Manager.o proj3.cpp -o proj3

Manager.o: Item.o Schedule.o Manager.cpp Manager.h
	$(CXX) $(CXXFLAGS) -c Manager.cpp

Schedule.o: Item.o Schedule.cpp Schedule.h
	$(CXX) $(CXXFLAGS) -c Schedule.cpp

Item.o: Item.cpp Item.h
	$(CXX) $(CXXFLAGS) -c Item.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj3

run1:
	./proj3 proj3_schedule1.txt

run2:
	./proj3 proj3_schedule2.txt

run3:
	./proj3 proj3_schedule3.txt

val1:
	valgrind ./proj3 proj3_schedule1.txt

val2:
	valgrind ./proj3 proj3_schedule2.txt

val3:
	valgrind ./proj3 proj3_schedule3.txt

submit:
	cp Item.h Item.cpp Schedule.h Schedule.cpp Manager.h Manager.cpp proj3.cpp ~/cs202proj/proj3

ta1:
	valgrind ./proj3 proj3_ta1.txt

ta2:
	valgrind ./proj3 proj3_ta2.txt

ta3:
	valgrind ./proj3 proj3_ta3.txt

S:
	emacs Schedule.cpp
I:
	emacs Item.cpp
M:
	emacs Manager.cpp
sch:
	emacs Schedule.h
item:
	emacs Item.h
man:
	emacs Manager.h
proj:
	emacs proj3.cpp
file1:
	emacs proj3_schedule1.txt
file2:
	emacs proj3_schedule2.txt
file3:
	emacs proj3_schedule3.txt
samp1:
	emacs proj3_sample1.txt
samp2:
	emacs proj3_sample2.txt
mk:
	emacs makefile
