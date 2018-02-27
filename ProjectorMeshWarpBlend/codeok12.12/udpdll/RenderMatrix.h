/** @class RenderMatrix
	@version 1.0 
	@date 2008-11-24
	@author Robert Malmstrom
*/

#ifndef RENDER_MATRIX_H
#define RENDER_MATRIX_H

#include "stdafx.h"
//#include "RenderDX.h"
#include "matrix.h"
#include "Spline.h"


/// This class is used to render a matrix as textured triangles.
/** This class is used to create a high cell matrix from
	a matrix with a lower number of cells with the help of spline
	curves. This matrix can then be rendered with DirectX to
	visualize the matrix as textured triangles. You create an
	instance of this class by calling the constructor with the
	number of columns and rows in the low cell matrix with the
	in parameter iColumns and iRows. The in parameters
	iColumnIterpolations and iRowIterpolations sets the number
	of cells that shall be created, with a spline function,
	between the low cells. Each time you call the
	function SetCellValue to change a cell value in the low cell
	matrix it calculates the splined high cell matrix. The in
	parameter ulHandle should be a unique handle for this matrix.
*/



class RenderMatrix : public Matrix
{
public:
	RenderMatrix() ;
public:
	RenderMatrix(	const unsigned int uiColumns, const unsigned int uiRows,
					const unsigned long ulHandle  );
	RenderMatrix(	const unsigned int uiColumns, const unsigned int uiRows,
					const unsigned int uiColumnIterpolations, const unsigned int uiRowIterpolations,
					const unsigned long ulHandle, int channel);
	~RenderMatrix( void );

	/** This function is called when the DirectX Device is lost. This can happen when
		the screen saver is started or when you press Ctrl-Alt-Del. It then release
		all the resources on the graphics card that this class has created such
		as verteices, index list and texture.
	*/
//	virtual void OnLostDevice( void );
	/** This function is called when this class is instanciated or when the
		DirectX Device is reset from a lost device. It then creates 
		all the resources on the graphics card that this class uses such
		as verteices, index list and texture.
	*/
	//virtual void OnResetDevice( IDirect3DDevice9* pD3DDevice );
	/** This function is called by the WarpLogic class when the matrix shall
		be rendered to the back buffer on the graphics card.
	*/
	virtual void Draw( void );
	/** This function returns the handle that identifies this matrix
	*/
	const unsigned long	GetHandle() const;
	int GetHandlechannel() ;
	/** This function sets the cell value at the position specified
		by the in parameters iColumn and iRow. If the cell is out
		side of the matrix this function returns false.
	*/
	virtual bool		SetCellValue( const unsigned int iColumn, const unsigned int iRow, const Cell& cell );
	void ChangeTolist(void);
	/** This function resets the cell values in the matrix to a uniform
		rectangle of the size set by the in parameters fXSize and fYSize.
	*/
	void				SetupCenteredMatrix( const float fXSize, const float fYSize );

protected:
	/** This function loads the texture that is rendered with the matrix
	*/
	//IDirect3DTexture9*	LoadTexture( const std::string fileNameString );
	/** This function is called when the matrix shall have texture coordinates
		for the last two columns that are both set to 1.0f. This is used by the
		EdgeBlendMatrix class to make the matrix black from the middle cell
		column to the outer column.
	*/
	void UseAsymmetricTextureCoordinates( void );

private:
	/** This function is called each time some cell value in the matrix is
		changed. It creates the vertices and index list in RAM so that they
		can be copied to the graphics card to render the matrix.
	*/
	void				CreateVerticesAndIndices( void );
	/** This function generates the vertices in RAM from the values in the matrix
		cells so that it can be copied to the graphics card to render the matrix.
	*/
	//TexturedVertex*		GenerateVertices( Matrix& refMatrix );
	/** This function generates the index list in RAM for the vertices created with the
		function CreateVerticesAndIndices so that it can be copied to the graphics
		card to render the matrix.
	*/
	//IndexPrimitive*		GenerateIndices( const unsigned int uiColumns, const unsigned int uiRows );
	/** This function copies the vertex and index data created with the
		functions CreateVerticesAndIndices and GenerateVertices to the
		graphics card.
	*/
	void				CopyVerticesFromRAMToGraphicsCard( void );
	/** This function calls the function GenerateVertices, GenerateIndices and
		CopyVerticesFromRAMToGraphicsCard to create and copy the matrix to
		the graphics card for rendering.
	*/
	void				CreateMatrixOnGraphicsCard();
	/** This function is used to create a high cell matrix from a matrix with
		a lower number of cells with the help of spline curves.
	*/
	void				FillSplinedMatrix();

	//IDirect3DDevice9*		m_pD3DDevice;
	//IDirect3DVertexBuffer9*	m_pMatrixVertexBuffer;
	//IDirect3DIndexBuffer9*	m_pMatrixIndexBuffer;
	unsigned int			m_uiNumOfMatrixVertices;
	unsigned int			m_uiNumOfMatrixIndices;
	unsigned int			m_uiNumOfMatrixTriangles;
	//TexturedVertex*			m_pRAMMemoryTexturedVertices;
	//IndexPrimitive*			m_pRAMMemoryIndices;
	unsigned long			m_ulHandle;
	int                     m_ulHandlechannel;
	Spline					m_spline;
public:
	Matrix					m_splinedMatrix;
	std::vector < float>     alpha_vec;
private:
	bool					m_bAsymmetricTextureCoordinates;

public:
	//Mesh*                   m_pMesh;

	static int nurb_x_order;
	static int nurb_y_order;
	static bool interpolation_nurbs;
	static bool interpolation_poly;

};

#endif
