CC=g++
INCLUDE_DIR=include
SOURCES_DIR=sources
LIB_STATIC_DIR=lib_static
LIB_SHARED_DIR=lib_shared
STATIC_FLAGS=-static
SHARED_FLAGS=-fpic -shared

# Build target with static library
mainStatic: libll.a main.cpp
	$(CC) main.cpp -o main -lll -I $(INCLUDE_DIR) -L $(LIB_STATIC_DIR) $(STATIC_FLAGS)

libll.a:  $(SOURCES_DIR)/node.o $(SOURCES_DIR)/ll.o
	ar cr $(LIB_STATIC_DIR)/libll.a $^


# Build target with shared library
mainShared: libll.so main.cpp
	$(CC) main.cpp -o main -lll -I $(INCLUDE_DIR) -L $(LIB_SHARED_DIR) $(SHARED_FLAGS)

libll.so: $(SOURCES_DIR)/ll.o $(SOURCES_DIR)/node.o
	$(CC)  $^ -Wl,-soname,libll.so -o $(LIB_SHARED_DIR)/libll.so $(SHARED_FLAGS)


# Compile library object files
node.o: $(SOURCES_DIR)/node.cpp $(SOURCES_DIR)/node.h
	$(CC) -c $^ -o $(SOURCES_DIR)/node.o

ll.o: $(SOURCES_DIR)/ll.cpp $(SOURCES_DIR)/ll.h
	$(CC) -c $^ -o $(SOURCES_DIR)/ll.o


# Clean all
clean:
	rm $(SOURCES_DIR)/*.o main

