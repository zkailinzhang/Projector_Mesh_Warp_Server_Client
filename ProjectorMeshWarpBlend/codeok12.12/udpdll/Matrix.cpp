#include "Matrix.h"

Matrix::Matrix( const unsigned int uiColumns, const unsigned int uiRows )
: m_cellMatrix( 0 ), m_uiColumns( uiColumns ), m_uiRows( uiRows )
, m_bMatrixChanged( false )
{
	unsigned int uiMatrixIndex;

	m_pLogger = Logger::GetInstance();

	// Allocate the cell matrix.
	m_cellMatrix = new Cell[ m_uiColumns * m_uiRows ];

	// Reset the cell values in the matrix to (0.0f, 0.0f)
	if ( m_cellMatrix != 0 )
	{
		for ( unsigned int uiRowIndex = 0 ; uiRowIndex < m_uiRows; ++uiRowIndex )
		{
			for ( unsigned int uiColumnIndex = 0 ; uiColumnIndex < m_uiColumns; ++uiColumnIndex )
			{
				uiMatrixIndex = uiColumnIndex + ( uiRowIndex * m_uiColumns );
				m_cellMatrix[ uiMatrixIndex ].fXPos = 0.0f;
				m_cellMatrix[ uiMatrixIndex ].fYPos = 0.0f;
			}
		}
	}
	else
		m_pLogger->Write( Logger::LOG_ERROR, "Matrix::Matrix, failed allocating memory" );
}

Matrix::~Matrix( void )
{
	// Deallocate the float matrix.
	if ( m_cellMatrix != 0 )
	{
		delete[] m_cellMatrix;
	}
}

bool Matrix::SetCellValue( const unsigned int uiColumn, const unsigned int uiRow, const Cell& cell )
{
	bool bValueSet = false;

	if ( m_cellMatrix != 0 )
	{
		if ( InsideMatrix( uiColumn, uiRow ) )
		{
			m_cellMatrix[ CalculateMatrixIndex( uiColumn, uiRow ) ] = cell;
			bValueSet = true;
			m_bMatrixChanged = true;
		}
		else
			m_pLogger->Write( Logger::LOG_ERROR, "Matrix::SetCellValue, tried to set a value outside of the matrix" );
	}

	return bValueSet;
}

bool Matrix::GetCellValue( const unsigned int uiColumn, const unsigned int uiRow, Cell& cell ) const
{
	bool bGotValue = false;

	if ( m_cellMatrix != 0 )
	{
		if ( InsideMatrix( uiColumn, uiRow ) )
		{
			cell = m_cellMatrix[ CalculateMatrixIndex( uiColumn, uiRow ) ];
			bGotValue = true;
		}
	}

	return bGotValue;
}

const unsigned int Matrix::GetNumOfColumns() const
{
	return m_uiColumns;
}

const unsigned int Matrix::GetNumOfRows() const
{
	return m_uiRows;
}

bool Matrix::Serialize( const char* cpData, unsigned int& uiNumOfBytes )
{
	bool bMatrixAllocated = false;

	if ( m_cellMatrix != 0 )
	{
		bMatrixAllocated = true;
		cpData = ( char* )&m_cellMatrix;
		uiNumOfBytes = m_uiColumns * m_uiRows * sizeof( Cell );
		m_bMatrixChanged = true;
	}

	return bMatrixAllocated;
}

bool Matrix::Unserialize( const char* cpData, const unsigned int uiNumOfBytes )
{
	bool bUnserialized = false;

	if ( m_cellMatrix != 0 )
	{
		m_cellMatrix = ( Cell* )cpData;
		bUnserialized = true;
	}

	return bUnserialized;
}

unsigned int Matrix::GetSerializeNumOfBytes( void )
{
	return m_uiColumns * m_uiRows * sizeof( Cell );
}

void Matrix::SetupCenteredMatrix( const float fXSize, const float fYSize )
{
	float			fXPos;
	float			fYPos;
	float			fXStartPos;
	float			fYStartPos;
	float			fXStepSize;
	float			fYStepSize;
	unsigned int	uiMatrixIndex;

	// Calculate start column and start row cell position.
	fXStartPos = -( fXSize / 2.0f );
	fYStartPos = -( fYSize / 2.0f );

	// Calculate the step size between each cell position.
	fXStepSize = fXSize / static_cast<float>( m_uiColumns - 1 );
	fYStepSize = fYSize / static_cast<float>( m_uiRows - 1 );

	if ( m_cellMatrix != 0 )
	{
		fYPos = fYStartPos;
		for ( unsigned int uiRowIndex = 0 ; uiRowIndex < m_uiRows; ++uiRowIndex )
		{
			fXPos = fXStartPos;
			for ( unsigned int uiColumnIndex = 0 ; uiColumnIndex < m_uiColumns; ++uiColumnIndex )
			{
				uiMatrixIndex = CalculateMatrixIndex( uiColumnIndex, uiRowIndex );
				m_cellMatrix[ uiMatrixIndex ].fXPos = fXPos;
				m_cellMatrix[ uiMatrixIndex ].fYPos = fYPos;
				fXPos += fXStepSize;
			}
			fYPos += fYStepSize;
		}
		m_bMatrixChanged = true;
	}
}

bool Matrix::InsideMatrix( unsigned int uiColumn, unsigned int uiRow ) const
{
	if ( uiColumn < m_uiColumns && uiRow < m_uiRows )
		return true;
	else
		return false;
}

unsigned int Matrix::CalculateMatrixIndex( unsigned int uiColumn, unsigned int uiRow ) const
{
	return uiColumn + ( uiRow * m_uiColumns );
}

bool Matrix::HasMatrixChanged( void )
{
	bool bMatrixChanged = m_bMatrixChanged;

	m_bMatrixChanged = false;

	return bMatrixChanged;
}