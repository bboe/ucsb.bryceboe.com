# We're not taking advantage of any separate compilation here as it's too much
# of a mess with the templates :-/. The alternative would be to put the complete
# BST implementation in BST.h which still means there is no separate compilation
# advantage and that just makes more work for the student.

all: virtual_directory.cpp
	clang++ -g virtual_directory.cpp -o virtual_directory

clean:
	rm -f virtual_directory
