#ifndef SAMPLER_H
#define SAMPLER_H

class Sampler {
	public:
		Sampler(int n);
		virtual ~Sampler();
		int getSample();
	private:
		int *arr;
		int n;
};


#endif // SAMPLER_H
