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
mergesort_test: directories $(MERGEDIR)/merge_sort_test.cpp $(MERGEDIR)/array_downloader.cpp
	$(CXX) $(CXXFLAGS) $(MERGEDIR)/merge_sort_test.cpp $(MERGEDIR)/array_downloader.cpp -o bin/test/merge -lgtest -lpthread -lcurl
mergesort_big: directories $(MERGEDIR)/array_downloader.cpp $(MERGEDIR)/merge_sort_big.cpp
	$(CXX) $(CXXFLAGS) $(MERGEDIR)/array_downloader.cpp $(MERGEDIR)/merge_sort_big.cpp -o bin/merge_big -lcurl
inversions: directories $(MERGEDIR)/inversions.cpp
	$(CXX) $(CXXFLAGS) $(MERGEDIR)/inversions.cpp -o bin/inversions
inversions_big: directories $(MERGEDIR)/array_downloader.cpp $(MERGEDIR)/inversions_big.cpp
	$(CXX) $(CXXFLAGS) $(MERGEDIR)/array_downloader.cpp $(MERGEDIR)/inversions_big.cpp -o bin/inversions_big -lcurl

directories:
	mkdir -p bin
	mkdir -p bin/test
