/** @class RenderDX
	@version 1.0 
	@date 2008-11-24
	@author Robert Malmstrom
*/

#ifndef WARP_MATRIX_H
#define WARP_MATRIX_H

#include "stdafx.h"
//#include "RenderDX.h"
#include "RenderMatrix.h"

//using namespace RenderDX;

/// This class is used to create a warp matrix
/** This class creates a matrix for warping the back buffer. The first five in
	parameters in the constructor is explained in the header file RenderMatrix.h.
	The in parameter uiWindowXWidth and uiWindowYHeight should be set to the size of the
	application window size that uses this SoftWarp dll. The window size information
	is used to set the size of the warp texture that is created by the ResetDevice function.
	The Draw function is called each frame and it copys the back buffer to the warp
	texture so that it can be warped on to the matrix.
*/

class WarpMatrix : public RenderMatrix
{
public:
	static const unsigned int	m_suiMaxNumOfColumnInterpolations	= 50;
	static const unsigned int	m_suiMaxNumORowInterpolations		= 50;

	WarpMatrix(	const unsigned int uiColumns, const unsigned int uiRows,
				const unsigned int uiColumnIterpolations, const unsigned int uiRowIterpolations,
				const unsigned long ulHandle, const unsigned int uiWindowXWidth,
				const unsigned int uiWindowYHeight ,int num);
	~WarpMatrix( void );

	/** This function is called when the DirectX Device is lost. This can happen when
		the screen saver is started or when you press Ctrl-Alt-Del. It then release
		all the resources on the graphics card that this class has created such
		as verteices, index list and texture.
	*/
	void OnLostDevice( void );
	/** This function is called when this class is instanciated or when the
		DirectX Device is reset from a lost device. It then creates 
		all the resources on the graphics card that this class uses such
		as verteices, index list and texture.
	*/
	//void OnResetDevice( IDirect3DDevice9* pD3DDevice );
	/** This function is called by the WarpLogic class when the warp matrix shall
		be rendered to the back buffer on the graphics card.
	*/
	void Draw( void );

	/** This function sets the cell value at the position specified by the in
		parameters iColumn and iRow. If the cell is out side of the matrix this
		function returns false.
	*/
	bool SetCellValue( const unsigned int uiColumn, const unsigned int uiRow, const Cell& cell );
	/** This function returns the cell value in the matrix if the inparameters
		iColumn and iRow is inside the matrix. If the cell value is returned
		this function returns true.
	*/
	bool GetCellValue( const unsigned int uiColumn, const unsigned int uiRow, Cell& cell ) const;

private:
	void LostDevice( void );
	void ResetDevice( void );

	//IDirect3DDevice9*	m_pD3DDevice;
	//IDirect3DSurface9*	m_pBackBufferSurface;
	//IDirect3DSurface9*	m_pWarpTextureSurface;
	//IDirect3DTexture9*	m_pWarpTexture;
	const unsigned int	m_uiWindowXWidth;
	const unsigned int	m_uiWindowYHeight;
};

#endif