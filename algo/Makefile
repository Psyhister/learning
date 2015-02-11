CXXFLAGS = -std=c++11
KARATSUBADIR=karatsuba_mul
MERGEDIR=merge_sort

all: karatsuba mergesort

karatsuba: $(KARATSUBADIR)/karatsuba_mul.cpp
	$(CXX) $(CXXFLAGS) $(KARATSUBADIR)/karatsuba_mul.cpp -o bin/mul
mergesort: $(MERGEDIR)/merge_sort.cpp
	$(CXX) $(CXXFLAGS) $(MERGEDIR)/merge_sort.cpp -o bin/merge
