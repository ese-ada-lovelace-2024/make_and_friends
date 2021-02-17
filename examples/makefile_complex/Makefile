all: bug my_beetle

HEADERS = $(wildcard include/*.h)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

bug: src/animal.o src/bug.o $(HEADERS)
	$(CXX) $(CXXFLAGS) -Iinclude src/animal.o src/bug.o -o bug

my_beetle: src/animal.o src/beetle.o $(HEADERS)
	$(CXX) $(CXXFLAGS) -Iinclude src/animal.o src/beetle.o -o my_beetle