#include "stdafx.h"
#include "metod.h"

void metod::setparams(int sn,int sk)
{
	n=sn;
	k=sk;
	isnot_lriv=n*k;
//	p=new int[(k+1)*(n+2)];
	int i,j;
	for(i=0;i<k+1;i++)
		for(j=0;j<n+2;j++)
			mat[i][j]=0/*p[i*(n+2)+j]=0*/;
}

metod::metod():n(0),k(0)
{}

metod::~metod()
{}

void metod::run()
{
	int i,j,min,l;
	for(i=0;i<k;i++)
		mat[i][n]/*p[(i+1)*(n+2)-2]*/=0;
	for(i=0;i<k;i++)
		mat[i][n+1]/*p[(i+1)*(n+2)-1]*/=0;
	for(i=0;i<n;i++)
		mat[k][i]/*p[k*(n+2)+i]*/=0;
	for(i=0;i<k;i++)
		for(j=0;j<n;j++)
			mat[i][n]/*p[(i+1)*(n+2)-2]*/+=mat[i][j]/*p[i*(n+2)+j]*/;
//Nor dasi oroshum<--------------
	for(i=0;i<k;i++)
	{
		j=0;
		while(mat[j][n+1]/*p[(j+1)*(n+1)]*/!=0)
			j++;
		min=j;
		for(l=min+1;l<k;l++)
			if(mat[l][n+1]==0 && mat[l][n]/*p[(l+1)*(n+2)]*/<mat[min][n]/*p[(min+1)*(n+2)]*/)
				min=l;
		mat[min][n+1]/*p[(min+1)*(n+2)]*/=i+1;
	}
//Tij-i oroshum<----------------
	for(j=0;j<n;j++)
		for(i=0;i<k;i++)
			if(mat[i][j]/*p[i*(n+2)+j]*/==mat[i][n+1]/*p[(i+1)*(n+2)]*/)
				mat[k][j]/*p[k*(n+2)+j]*/++;
	double Gumar_T=0;
	for(j=0;j<n;j++)
		Gumar_T+=mat[k][j]*(mat[k][j]*mat[k][j]-mat[k][j]);
	S=0;
	double mig=n*(k+1)/2.0;
	for(i=0;i<k;i++)
		S+=(mat[i][n]-mig)*(mat[i][n]-mig);
	W=12*S/(n*n*(k*k*k-k)-n*Gumar_T);
}

void metod::Serialize(CArchive& archive)
{
	int i,j;
	if(archive.IsStoring())
	{
		archive<<isnot_lriv;
		archive<<k;
		archive<<n;
		for(i=0;i<k+1;i++)
			for(j=0;j<n+2;j++)
				archive<<mat[i][j]/*p[i*(n+2)+j]*/;

	}
	else
	{
		archive>>isnot_lriv;
		archive>>k;
		archive>>n;
		for(i=0;i<k+1;i++)
			for(j=0;j<n+2;j++)
				archive>>mat[i][j]/*p[i*(n+2)+j]*/;
	}
}

IMPLEMENT_SERIAL(metod, CObject, 0)