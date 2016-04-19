#ifndef METOD_H
#define METOD_H

class metod:public CObject
{
public:
	void setparams(int,int);
	metod();
	~metod();
	void run();
	void Serialize(CArchive& archive);
	DECLARE_SERIAL(metod);
//	int* p;
	short int mat[400][400];
	short int n,k;
	long int isnot_lriv;
	double S,W;
};

#endif