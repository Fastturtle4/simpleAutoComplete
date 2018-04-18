OBJECTS = autocomplete.o term.o main.o SortingList.o 
HEADERS = autocomplete.h term.h SortingList.h
CS216PA3: $(OBJECTS)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o CS216PA3

