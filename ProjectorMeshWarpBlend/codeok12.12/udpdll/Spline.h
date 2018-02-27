/** @class Spline
	@version 1.0 
	@date 2008-11-24
	@author Robert Malmstrom
*/

#ifndef SPLINE_H
#define SPLINE_H

#include "StdAfx.h"
#include <vector>

/// This class creates a spline curve from a point vector.
/** This class is used to create a hermite spline curve
	from a vector of points. The Hermite spline curve passes
	through all the points in the point vector but can have
	different tension. The tension controls how "hard", the
	splined points between the points in the point vector,
	can turn from one vector point to the next.
	You call the function SetSplineTension to set the tension
	and the default value of the tension is 1.0f.
*/

using namespace std;

class Spline
{
public:
	struct SplinePoint
	{
		float fX;
		float fY;
		SplinePoint(float x, float y/*, float z*/) : fX(x), fY(y) {};
		SplinePoint() {};
		~SplinePoint() {};
	};

public:
	Spline( void );
	virtual ~Spline( void );

	/** This function creates a hermite spline curve vector (returnVector)
		from a vector of points (pointVector). The in parameter iNumOfInterpolations
		sets the number of splined points that are created in the returnVector from
		one point to the next in the pointVector.
	*/
	void CreateHermiteSpline(	const vector< SplinePoint >& pointVector, vector< SplinePoint >& returnVector,
								const unsigned int iNumOfInterpolations );
	/** This function creates a hermite spline curve vector (returnVector)
		from a vector of points (pointVector). The in parameter iNumOfInterpolations
		sets the number of splined points that are created in the returnVector from
		one point to the next in the pointVector. The in parameters fMaxYValue and
		fMinYValue sets the y max and min value of all the points in the splined
		returnVector.
	*/
	void CreateHermiteSpline(	const vector< SplinePoint >& pointVector, vector< SplinePoint >& returnVector,
								const unsigned int uiNumOfInterpolations, const float fMaxYValue, const float fMinYValue );
	/** This function is used to set the so called tension on the spline curves
		created with the CreateHermiteSpline function. The tension controls how
		"hard" the splined curves can turn from one control point to the next.
		The default value of the tension is 1.0f.
	*/
	void SetSplineTension( float fTension );

	double N_Base_New(int i, int k, int t, double u, std::vector<float> U);
	void NB_Spline_New(int t, std::vector<SplinePoint> CP, std::vector<float> U, std::vector<Spline::SplinePoint> &nurbcurve);
	std::vector<float> nodevec(int cp_num, int order);
	void CreatenurbSpine(const vector<SplinePoint>& pointVector, vector<SplinePoint>& returnVector, const unsigned int uiNumOfInterpolations
		, int &degree);

	

private:
	float	m_fTension;			// How hard are the curves of the splines.
	bool	m_bMinMaxValue;




};

#endif
