.PHONY: directories clean stat

all: directories bin/ut_all bin/ut_second_largest_num

bin/ut_all: test/ut_main.cpp test/ut_second_largest_num.h src/second_largest_num.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

bin/ut_second_largest_num: test/ut_main.cpp test/ut_second_largest_num.h src/second_largest_num.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_second_largest_num -lgtest -lpthread
directories:
	mkdir -p bin

clean:
	rm -f bin/*

stat:
	wc src/* test/*

# .PHONY:clean stat

# ut_main: 
# 	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread
# clean: 
# 	rm -f bin/*

# stat:
# 	wc src/*
