/** @class Matrix
	@version 1.0 
	@date 2008-10-24
	@author Robert Malmstrom
*/

#ifndef MATRIX_H
#define MATRIX_H

#include "stdafx.h"

#include "Logger.h"

/// This class is used to store position data in a Matrix.
/** This class is used to store position data in the form
	of a struct called Cell. The Cell struct constists of
	a x position (fXPos) and a y position (fYPos). The
	constructor takes two parameters (iColumns and iRows)
	that sets the number of columns and rows in the matrix.
	It then allocates memory for the matrix and sets all the
	cells to (0.0f, 0.0f).
	Use the function SetCellValue and GetCellValue to 
	set/get the value of a single cell.
*/

class Matrix 
{
public:
	typedef struct _Cell
	{
		float fXPos;
		float fYPos;
		_Cell& operator=( const _Cell& cell )
		{
			_Cell::fXPos = cell.fXPos;
			_Cell::fYPos = cell.fYPos;
			return *this;
		};
		bool operator!=( const _Cell& cell )
		{
			if ( _Cell::fXPos != cell.fXPos || _Cell::fYPos != cell.fYPos )
				return true;
			else
				return false;
		};
	} Cell;

	Matrix( const unsigned int uiColumns, const unsigned int uiRows );
	~Matrix( void );


	Matrix& operator=(const Matrix& mat)
	{
		int iColumnInterp = mat.GetNumOfColumns();
		int iRowInterp = mat.GetNumOfRows();
		for (int uiColumnIndex = 0; uiColumnIndex < iColumnInterp; ++uiColumnIndex)
		{
			for (int uiRowIndex = 0; uiRowIndex < iRowInterp; ++uiRowIndex)  //行列插值点
			{
				Matrix::Cell cell;
				mat.GetCellValue(uiColumnIndex, uiRowIndex, cell);
				Matrix::SetCellValue(uiColumnIndex, uiRowIndex, cell);
			}
		}
		return *this;
	};




	/** This function sets the cell value in the matrix if the inparameters
		iColumn and iRow is inside the matrix. If the cell value is set
		this function returns true.
	*/
	virtual bool SetCellValue( const unsigned int uiColumn, const unsigned int uiRow, const Cell& cell );
	/** This function returns the cell value in the matrix if the inparameters
		iColumn and iRow is inside the matrix. If the cell value is returned
		this function returns true.
	*/
	virtual bool GetCellValue( const unsigned int uiColumn, const unsigned int uiRow, Cell& cell ) const;
	/** This function returns the number of columns in the matrix.
	*/
	const unsigned int GetNumOfColumns() const;
	/** This function returns the number of rows in the matrix.
	*/
	const unsigned int GetNumOfRows() const;
	/** This function fills the matrix cells with values so that it is 
		centered around (0.0f, 0.0f) and has a size according to the
		parameters fXSize and fYSize.
	*/
	void SetupCenteredMatrix( const float fXSize, const float fYSize );
	/** This function returns true if some cell value in the matrix has
		been changed since last call to this function. The function
		resets the m_bMatrixChanged variable to false.
	*/
	bool HasMatrixChanged( void );
	/** This function returns a char array with the Cell data for this
		matrix and. The function returns the number of bytes in the
		char array in the reference parameter iNumOfBytes. This function
		is used by the class Filehandler to save the matrix on disk.
	*/
	virtual bool Serialize( const char* cpData, unsigned int& iNumOfBytes );
	/** This function takes a char array and the number of bytes in this
		array and fills the matrix with the data. This function
		is used by the class Filehandler to load the matrix from disk.
	*/
	virtual bool Unserialize( const char* cpData, const unsigned int iNumOfBytes );
	/** This function returns the number of bytes that is needed to
		store the matrix Cell data in a char array.
	*/
	virtual unsigned int GetSerializeNumOfBytes( void );

protected:
	Logger*				m_pLogger;

private:
	/** This function returns true if the inparameters uiColumn and uiRow
		is smaller than the column and row size of the matrix.
	*/
	bool			InsideMatrix( unsigned int uiColumn, unsigned int uiRow ) const;
	/** This function calculates the index in the m_cellMatrix to get
		the Cell for the inparameter uiColumn and uiRow.
	*/
	unsigned int	CalculateMatrixIndex( unsigned int uiColumn, unsigned int uiRow ) const;

	const unsigned int	m_uiColumns;
	const unsigned int	m_uiRows;
	Cell*				m_cellMatrix;
	bool				m_bMatrixChanged;	// Sets to true if some cell value in the matrix has been changed.
};

#endif