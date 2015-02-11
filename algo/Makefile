CXXFLAGS = -std=c++11
KARATSUBADIR=karatsuba_mul/
MERGEDIR=merge_sort/
BINDIR=bin/

.PHONY: directories

all: directories karatsuba mergesort

karatsuba: directories $(KARATSUBADIR)/karatsuba_mul.cpp
	$(CXX) $(CXXFLAGS) $(KARATSUBADIR)/karatsuba_mul.cpp -o bin/mul
mergesort: directories $(MERGEDIR)/merge_sort.cpp
	$(CXX) $(CXXFLAGS) $(MERGEDIR)/merge_sort.cpp -o bin/merge
mergesort_test: directories $(MERGEDIR)/merge_sort_test.cpp
	$(CXX) $(CXXFLAGS) $(MERGEDIR)/merge_sort_test.cpp -o bin/test/merge -lgtest -lpthread

directories:
	mkdir -p bin
	mkdir -p bin/test
