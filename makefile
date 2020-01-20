.PHONY: info all target_1 target_2 target_3 target_4 target_5 target_6 

info:
	@echo "===================Data Structure======================" 
	@echo "For testing the single_list please enter: make single"
	@echo "For testing the double_list please enter: make double"
	@echo "For testing the set         please enter: make set"
	@echo "For testing the map         please enter: make map"
	@echo "For testing the vector      please enter: make vector"
	@echo "For testing the hash map    please enter: make hashmap"


all: targte_1 target_2 target_3 target_4 target_5 target_6

target_1: single

target_2: double

target_3: set

target_4: vector

target_5: map

target_6: hashmap

set   : bfs.cpp
	@g++ -g --coverage bfs.cpp -o $@
	@./set
	@gcov bfs.cpp -m

vector: vector.cpp
	@g++ -g --coverage vector.cpp -o $@
	@./vector
	@gcov vector.cpp -m

map   : map.cpp
	@g++ -g --coverage map.cpp -o $@
	@./map
	@gcov map.cpp -m

hashmap: hash_map.cpp
	@g++ -g --coverage hash_map.cpp -o $@
	@./hashmap
	@gcov hash_map.cpp -m
			
single: single_list.cpp
	@g++ -g --coverage single_list.cpp -o $@
	@./single
	@gcov single_list.cpp -m

double: double_list.cpp
	@g++ -g --coverage double_list.cpp -o $@
	@./double
	@gcov double_list.cpp -m
	
clean:
	rm -rf  *.o single double set map vector hashmap
