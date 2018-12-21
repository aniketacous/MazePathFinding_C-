#include"Sampler.h"
#include <iostream>
#include <cstdlib>

Sampler::Sampler(int n) {
	arr = new int[n];
	for(int i = 0; i < n; i++) {
  			arr[i] = i;
  	}
  	  this->n = n;
}

Sampler::~Sampler() {
	delete[] arr;
}

int Sampler::getSample() {
	int i = rand() % n;
  	int sample;
  	sample = arr[i];
  	n--;
  	arr[i] = arr[n];

  return sample;
}