#include "RenderMatrix.h"

#define SAFE_DELETE(pointer) if( pointer != NULL ) { delete pointer; pointer = NULL; }
int RenderMatrix::nurb_x_order = (0);
int  RenderMatrix::nurb_y_order = (0);
bool RenderMatrix::interpolation_nurbs = (0);
bool RenderMatrix::interpolation_poly = (0);

RenderMatrix::RenderMatrix(	const unsigned int uiColumns, const unsigned int uiRows,
						const unsigned int uiColumnIterpolations, const unsigned int uiRowIterpolations,
						const unsigned long ulHandle ,int channel )
: Matrix( uiColumns, uiRows )
, m_splinedMatrix( ( ( uiColumns - 1 ) * uiColumnIterpolations ) + 1, ( ( uiRows - 1 ) * uiRowIterpolations ) + 1 )
, m_ulHandle( ulHandle ), m_ulHandlechannel(channel),
 m_bAsymmetricTextureCoordinates( false )
{
	//if ( uiColumns < 3 || uiRows < 3 )
	//	m_pLogger->Write( Logger::LOG_ERROR, "RenderMatrix::RenderMatrix a splined matrix must NOT have less than 3 columns or 3 rows" );
	//m_pMesh = Mesh::GetInstance();

	//m_pMesh->splinedlist_vec.resize(m_pMesh->numchannels);
	//m_pMesh->splinedMatrix_vec.resize(m_pMesh->numchannels);
	//Matrix *Mat = new Matrix(m_splinedMatrix.GetNumOfColumns(), m_splinedMatrix.GetNumOfRows()); //初始化为行列插值后的总的点数
	//m_pMesh->splinedMatrix_vec[m_pMesh->cur_cur] = Mat;

}

RenderMatrix::~RenderMatrix( void )
{
	//OnLostDevice();
}





void RenderMatrix::Draw( void )
{
	m_pLogger->Write( Logger::LOG_DEBUG, "RenderMatrix::Draw" );

}

const unsigned long RenderMatrix::GetHandle() const
{
	return m_ulHandle;
}

int RenderMatrix::GetHandlechannel() 
{
	return m_ulHandlechannel;
}

bool RenderMatrix::SetCellValue( const unsigned int uiColumn, const unsigned int uiRow, const Cell& cell )
{
	bool bValueSet = true;
	Cell currentCell;

	// Find out if the new cell position is the same that already is set. If
	// that is the case then return true.
	if ( Matrix::GetCellValue( uiColumn, uiRow, currentCell ) )
	{
		if ( currentCell != cell ) //如果相同位置的某个cell不等于之前位置对应的cell，则应该是拉动点，更新该控制点的坐标，再进行插值再次
		{
			bValueSet = Matrix::SetCellValue( uiColumn, uiRow, cell );
			FillSplinedMatrix();  //行列插值完毕，每次拉动，还扔会保留所有点吗
			
		}
	}
	else
	{
		// The iColumn and/or iRow was outside of the matrix.
		bValueSet = false;
	}

	return bValueSet;
}

//1.直接将Matrix std::vector<Matrix>,,和之前一样，push_back到第几个通道，显示直接读Matrix，要把第几个通道传过来
//2.将splinedMatrix存储方式转为list，传给opengl，便于显示
/*void RenderMatrix::ChangeTolist(void) {
	//m_splinedMatrix
	int iColumnInterp =m_splinedMatrix.GetNumOfColumns();
	int iRowInterp = m_splinedMatrix.GetNumOfRows();

	std::list<Point2f> listp2;
	for (int uiColumnIndex = 0; uiColumnIndex < iColumnInterp; ++uiColumnIndex)
	{
		for (int uiRowIndex = 0; uiRowIndex < iRowInterp; ++uiRowIndex)  //行列插值点
		{
			Matrix::Cell cell;
			m_splinedMatrix.GetCellValue(uiColumnIndex, uiRowIndex, cell);

			//glVertex2f(cell.fXPos, cell.fYPos);
			Point2f tmp;
			tmp.ID.x = uiColumnIndex; tmp.ID.y = uiRowIndex;
			//std::cout << "插点： " << cell.fXPos << "  " << cell.fYPos << std::endl;
			tmp.coordination.x = cell.fXPos; tmp.coordination.y = cell.fYPos;
			listp2.push_back(tmp);
		}
	}

	m_pMesh->splinedlist_vec[m_pMesh->cur_cur] = listp2;

}
*/




void RenderMatrix::FillSplinedMatrix()
{
	vector< Spline::SplinePoint > unsplinedPointVector;
	vector< Spline::SplinePoint > splinedPointVector;
	Spline::SplinePoint splinePoint;
	Cell cell;
	int iColumnInterpolations;
	int iRowInterpolations;

	//每个控制点两两之间插值个数
	// Calculate the number of interpolations from the original matrix to the splined matrix.
	iColumnInterpolations = m_splinedMatrix.GetNumOfColumns() / ( GetNumOfColumns() - 1 ) ;
	iRowInterpolations = m_splinedMatrix.GetNumOfRows() / ( GetNumOfRows() - 1 );

	// Create a SplinePoint vector from the original matrix column cells for
	// the CreateHermiteSpline function and fill the m_splinedMatrix with the
	// horizontal column splines.
	for( unsigned int uiRowIndex = 0; uiRowIndex < GetNumOfRows(); ++uiRowIndex )  //行列控制点
	{
		for( unsigned int uiColumnIndex = 0; uiColumnIndex < GetNumOfColumns(); ++uiColumnIndex )
		{
			if ( Matrix::GetCellValue( uiColumnIndex, uiRowIndex, cell ) )
			{
				splinePoint.fX = cell.fXPos;
				splinePoint.fY = cell.fYPos;
				unsplinedPointVector.push_back( splinePoint );
			}
		}
		
		//每一行控制点拿到，然后每行插值
	//	try		{
				if (interpolation_poly)
					m_spline.CreateHermiteSpline(unsplinedPointVector, splinedPointVector, iColumnInterpolations);
				else if (interpolation_nurbs)
					m_spline.CreatenurbSpine(unsplinedPointVector, splinedPointVector, iColumnInterpolations, nurb_x_order);
				int size2 = splinedPointVector.size();
				if (size2 == 0)
				{
					m_spline.CreatenurbSpine(unsplinedPointVector, splinedPointVector, iColumnInterpolations, nurb_x_order);
					//throw size;
					//cout << "9999" << "/n";
				}
// 		}
// 		catch (const std::exception&)	{
// 			//cout << "8888 " << splinedPointVector.size() << endl;	}
// 		catch (int)	{
// 			//cout << "8888 " << splinedPointVector.size() << endl;	}
		

		int size = m_splinedMatrix.GetNumOfColumns();

		for( unsigned int uiColumnIndex = 0; uiColumnIndex < splinedPointVector.size(); ++uiColumnIndex )
		{
			cell.fXPos = splinedPointVector[ uiColumnIndex ].fX;
			cell.fYPos = splinedPointVector[ uiColumnIndex ].fY;
			m_splinedMatrix.SetCellValue( uiColumnIndex, uiRowIndex * iRowInterpolations, cell );	//控制点 每行相邻点插值，	
		}
		unsplinedPointVector.clear();
		splinedPointVector.clear();
	}

	// Create a SplinePoint vector from the original m_splinedMatrix row cells for
	// the CreateHermiteSpline function and fill the m_splinedMatrix with the
	// vertical column splines.
	for( unsigned int uiColumnIndex = 0; uiColumnIndex < m_splinedMatrix.GetNumOfColumns(); ++uiColumnIndex ) //插值后的列数 空点*插值数
	{
		for( unsigned int uiRowIndex = 0; uiRowIndex < GetNumOfRows(); ++uiRowIndex ) //空点行
		{
			if ( m_splinedMatrix.GetCellValue( uiColumnIndex, uiRowIndex * iRowInterpolations, cell ) )
			{
				splinePoint.fX = cell.fXPos;
				splinePoint.fY = cell.fYPos;
				unsplinedPointVector.push_back( splinePoint );
			}
		}
		//当前列的 刚刚插值的列，拿到，插值行
		if (interpolation_poly)
			m_spline.CreateHermiteSpline(unsplinedPointVector, splinedPointVector, iRowInterpolations);
		else if (interpolation_nurbs)
			m_spline.CreatenurbSpine(unsplinedPointVector, splinedPointVector, iRowInterpolations, nurb_y_order);
		int size = splinedPointVector.size();
		if (size == 0)
		{
			m_spline.CreatenurbSpine(unsplinedPointVector, splinedPointVector, iColumnInterpolations, nurb_y_order);
			
		}


		for( unsigned int uiRowIndex = 0; uiRowIndex < m_splinedMatrix.GetNumOfRows(); ++uiRowIndex )
		{
			cell.fXPos = splinedPointVector[ uiRowIndex ].fX;
			cell.fYPos = splinedPointVector[ uiRowIndex ].fY;
			//cout << "x " << cell.fXPos << "y  " << cell.fYPos << endl;
			m_splinedMatrix.SetCellValue( uiColumnIndex, uiRowIndex, cell );		
		}
		unsplinedPointVector.clear();
		splinedPointVector.clear();
	}
}



void RenderMatrix::SetupCenteredMatrix( const float fXSize, const float fYSize )
{
	Matrix::SetupCenteredMatrix( fXSize, fYSize ); //已知服务器上的控制点坐标范围是-1，1，（-0.5，-0.5）固知道控制点个数就可以自己生成控制点原始坐标
	FillSplinedMatrix();
	//CreateVerticesAndIndices();
}

void RenderMatrix::UseAsymmetricTextureCoordinates( void )
{
	m_bAsymmetricTextureCoordinates = true;
}