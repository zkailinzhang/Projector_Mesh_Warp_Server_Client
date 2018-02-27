#include "Spline.h"






Spline::Spline( void )
: m_bMinMaxValue( true ), m_fTension( 0.0f )
{
}

Spline::~Spline( void )
{
}

void Spline::CreateHermiteSpline(	const vector< SplinePoint >& pointVector,  vector< SplinePoint >& returnVector,
									const unsigned int uiNumOfInterpolations)
{
	m_bMinMaxValue = false;
	CreateHermiteSpline( pointVector, returnVector, uiNumOfInterpolations, 0.0f, 0.0f );
	m_bMinMaxValue = true;
}

void Spline::CreateHermiteSpline(	const vector< SplinePoint >& pointVector, vector< SplinePoint >& returnVector,
									const unsigned int uiNumOfInterpolations, const float fMaxYValue, const float fMinYValue )
{
	SplinePoint*	pointTangentArray;	// The points tangent.
	SplinePoint		startPoint;			// The start point to calculate the tangent.
	SplinePoint		endPoint;			// The end point to calculate the tangent.
	unsigned int	uiPointVectorSize;
	float			fT;
	float			fXValue;
	float			fYValue;
	SplinePoint		thePoint;
	bool			bFirstRow = true;

	pointTangentArray = new SplinePoint[ pointVector.size() * uiNumOfInterpolations ]; //插值前控制点数目每行的，*每行两点之间要插个数
	uiPointVectorSize = static_cast< int >( pointVector.size() );
	// Create the splines in the y-direction.
	for ( unsigned int uiPointIndex = 0; uiPointIndex < uiPointVectorSize; ++uiPointIndex )
	{
		// Create the points tangent to make the spline segments continuous.
		if ( uiPointIndex == 0 ) //建立索引-1的点坐标  差分， 起始点为当前点的左边，
		{
			// This is an start point so calculate a temporary point
			// in a line from the two last points to make the
			// end spline curvature correct.
			startPoint.fX = pointVector[ uiPointIndex ].fX - ( pointVector[ uiPointIndex + 1].fX - pointVector[ uiPointIndex ].fX );
			startPoint.fY = pointVector[ uiPointIndex ].fY - ( pointVector[ uiPointIndex + 1].fY - pointVector[ uiPointIndex ].fY );
		}
		else
		{
			startPoint.fX = pointVector[ uiPointIndex - 1 ].fX;
			startPoint.fY = pointVector[ uiPointIndex - 1 ].fY;
		}

		if ( uiPointIndex + 1 == uiPointVectorSize )
		{
			// This is an right end point so calculate a temporary point
			// in a line from the two last points to make the end spline
			// curvature correct.
			endPoint.fX = pointVector[ uiPointIndex ].fX - (pointVector[ uiPointIndex - 1].fX - pointVector[ uiPointIndex ].fX);
			endPoint.fY = pointVector[ uiPointIndex ].fY - (pointVector[ uiPointIndex - 1].fY - pointVector[ uiPointIndex ].fY);
		}
		else
		{
			endPoint.fX = pointVector[ uiPointIndex + 1].fX;
			endPoint.fY = pointVector[ uiPointIndex + 1].fY;
		}


		pointTangentArray[ uiPointIndex ].fX = ( ( 1.0f - m_fTension ) / 2.0f ) 
			* ( ( pointVector[ uiPointIndex ].fX - startPoint.fX )+ endPoint.fX - pointVector[ uiPointIndex ].fX);

		pointTangentArray[ uiPointIndex ].fY = ( ( 1.0f - m_fTension ) / 2.0f ) * ( ( pointVector[ uiPointIndex ].fY - startPoint.fY )
			+ endPoint.fY - pointVector[ uiPointIndex ].fY);
	}

	// Create the interpolated points of the spline.
	for ( unsigned int uiPointIndex = 0; uiPointIndex < uiPointVectorSize - 1; ++uiPointIndex )
	{
		fT = 0.0f;
		for ( unsigned int uiInterpolationIndex = 0; uiInterpolationIndex < uiNumOfInterpolations; ++uiInterpolationIndex)
		{
			fXValue = ( 2*fT*fT*fT - 3*fT*fT ) * pointVector[ uiPointIndex ].fX
				+ ( fT*fT*fT - 2*fT*fT + fT ) * pointTangentArray[ uiPointIndex ].fX
				+ ( fT*fT*fT - fT*fT ) * pointTangentArray[ uiPointIndex + 1 ].fX
				+ ( -2*fT*fT*fT + 3*fT*fT ) * pointVector[ uiPointIndex + 1 ].fX
				+ pointVector[ uiPointIndex ].fX;

			fYValue = ( 2*fT*fT*fT - 3*fT*fT ) * pointVector[ uiPointIndex ].fY
				+ ( fT*fT*fT - 2*fT*fT + fT ) * pointTangentArray[ uiPointIndex ].fY
				+ ( fT*fT*fT - fT*fT ) * pointTangentArray[ uiPointIndex + 1].fY
				+ ( -2*fT*fT*fT + 3*fT*fT ) * pointVector[ uiPointIndex + 1].fY
				+ pointVector[ uiPointIndex ].fY;

			fT += 1.0f / static_cast<float>( uiNumOfInterpolations );

			thePoint.fX = fXValue;
			thePoint.fY = fYValue;
			if ( m_bMinMaxValue )
			{
				if ( thePoint.fY > fMaxYValue )
					thePoint.fY = fMaxYValue;
				if ( thePoint.fY < fMinYValue )
					thePoint.fY = fMinYValue;
			}
			returnVector.push_back( thePoint );
		}
		bFirstRow = false;
	}
	returnVector.push_back( pointVector[ pointVector.size() - 1 ] ); //每一行的最后一个控制点

	delete[] pointTangentArray;
}

void Spline::SetSplineTension( float fTension )
{
	m_fTension = fTension;
}



//NURBS basis function 递归 
double Spline::N_Base_New(int i, int k, int t, double u, std::vector<float> U)
{
	double N[20];//保存基函数的中间变量
	double saved, temp;
	N[0] = 1.0;
	for (int j = 1; j <= t; j++)  //阶数  每一阶都需要低阶参与
	{
		saved = 0.0;
		for (int r = 0; r < j; r++) // 
		{
			if (N[r] == 0 && (U[i + r + 1] - U[i + 1 - j + r]) == 0)
			{
				temp = 0;
			}
			else
			{
				temp = N[r] / (U[i + r + 1] - U[i + 1 - j + r]);
			}
			N[r] = saved + (U[i + r + 1] - u)*temp;
			saved = (u - U[i + 1 - j + r])*temp;

		}
		N[j] = saved;
	}
	return N[k];
}

//<生成nurbs线点坐标>//参数：度数，控制点，节点向量
void  Spline::NB_Spline_New(int t, std::vector<SplinePoint>  CP, std::vector<float> U, std::vector<Spline::SplinePoint>& nurbcurve)
{

	int Num = (CP.size() - 1) * 16 + 1;  //插值出Num个点 16*3+1  0-48

	std::vector<SplinePoint>  curvePs;//保存生成的顶点	
	auto Unumm = U.size();
	std::vector<float> NewU;//[0,1]之间的节点向量U
	std::vector<int> CPIndexs;
	for (int i = 0; i < Unumm; i++)
	{
		float tempu = U[i] / U[Unumm - 1];
		NewU.push_back(tempu);
	}
	for (double u = 0; u < Num; u++)
	{
		float deltau = float(1.0) / Num*u;
		SplinePoint tempP(0.0, 0.0);
		int i, j;

		if (u == Num - 1)
		{
			auto Uvecnum = NewU.size();
			for (j = 0; j < Uvecnum - 1; j++)
			{
				if (NewU[j] <= deltau && deltau <= (NewU[j + 1]))
				{
					i = j;
					break;
				}
			}
		}
		else
		{
			auto Uvecnum = NewU.size();
			for (j = 0; j < Uvecnum - 1; j++)
			{
				if (NewU[j] <= deltau && deltau < NewU[j + 1])
				{
					i = j;
					break;
				}
			}
		}
		std::vector<SplinePoint> tempPs;
		for (int k = 0; k <= t; k++)
		{
			SplinePoint tempPP = SplinePoint(
				CP[i + k - t].fX*N_Base_New(i, k, t, deltau, NewU),
				CP[i + k - t].fY*N_Base_New(i, k, t, deltau, NewU));
			//CP[i + k - t].z*N_Base_New(i, k, t, deltau, NewU));//i:节点向量的下标索引
			tempPs.push_back(tempPP);
			CPIndexs.push_back(i + k - t);
		}
		auto Numm = tempPs.size();
		for (int k = 0; k < Numm; k++)
		{
			tempP.fX += tempPs[k].fX; tempP.fY += tempPs[k].fY; //tempP.z += tempPs[k].z;
		}
		// 		curvePs.push_back(tempP);
		// 	}
		// 	nurbcurve = curvePs;
		nurbcurve.push_back(tempP);
	}
}

//生成节点向量//cp+t+1 =U     cp<t
std::vector<float> Spline::nodevec(int cp_num, int order) {

	std::vector<float> node;
	for (int i = 0; i < cp_num + order + 1; i++)
	{
		if (i < order + 1)
			node.push_back(0);
		else if (i > cp_num)
			node.push_back(cp_num - order);
		else
			node.push_back(i - order);
	}
	return node;
}

//
void Spline::CreatenurbSpine(const vector< SplinePoint >& pointVector, vector< SplinePoint >& returnVector,
	const unsigned int uiNumOfInterpolations,int &degree) {

	int t = degree;
	std::vector<float> U = nodevec(pointVector.size(), degree);
	
	std::vector<SplinePoint>  CP = pointVector;
	std::vector<SplinePoint> spline;

	NB_Spline_New(t, CP, U, spline);


	returnVector = spline;
// 	if (returnVector.size() ==0)
// 	{
// 		int a =0;
// 	}
// 	cout << "*********** " << returnVector.size() << endl;
}