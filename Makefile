# CSE_1325 Homework 4

output: main.o publication.o library.o
	g++ --std=c++11 -o output main.o publication.o library.o dialogs.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main.o: dialogs.o *.h
	g++ --std=c++11 -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

dialogs.o: dialogs.cpp *.h
	g++ --std=c++11 -c dialogs.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

test_library: test_library.o library.o publication.o
	g++ --std=c++11 -o test_library test_library.o library.o publication.o

test_library.o: test_library.cpp
	g++ --std=c++11 -c test_library.cpp

library.o: library.cpp library.h
	g++ --std=c++11 -c library.cpp

test_publication: test_publication.o publication.o
	g++ --std=c++11 -o test_publication test_publication.o publication.o

test_publication.o: test_publication.cpp
	g++ --std=c++11 -c -w test_publication.cpp

publication.o: publication.cpp publication.h
	g++ --std=c++11 -c publication.cpp

clean:
	-rm -f *.o output test_publication test_library
