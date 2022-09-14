OBJS := $(addsuffix .o, bst)

all: $(OBJS) driver.cpp
	clang++ $(OBJS) driver.cpp -o driver

%.o: %.cpp
	clang++ -c $<

clean:
	rm -f *.o driver
