#include "WarpMatrix.h"

#define SAFE_DELETE(pointer) if( pointer != NULL ) { delete pointer; pointer = NULL; }

WarpMatrix::WarpMatrix(	const unsigned int uiColumns, const unsigned int uiRows,
						const unsigned int uiColumnIterpolations, const unsigned int uiRowIterpolations,
						const unsigned long ulHandle, const unsigned int uiWindowXWidth,
						const unsigned int uiWindowYHeight ,int num)
: RenderMatrix( uiColumns, uiRows, uiColumnIterpolations, uiRowIterpolations, ulHandle,num )
, m_uiWindowXWidth( uiWindowXWidth ) , m_uiWindowYHeight( uiWindowYHeight )
{
	m_pLogger->Write( Logger::LOG_INFO, "WarpMatrix created with handle: ", static_cast<int>( ulHandle ) );
	SetupCenteredMatrix( 1.0f, 1.0f );


}

WarpMatrix::~WarpMatrix( void )
{
	LostDevice();
}
void WarpMatrix::LostDevice(void)
{
	// Release texture from the graphic card to free memory.
// 	if (m_pWarpTexture != NULL)
// 		m_pWarpTexture->Release();
// 	if (m_pBackBufferSurface != NULL)
// 		m_pBackBufferSurface->Release();
}
void WarpMatrix::OnLostDevice( void )
{
	m_pLogger->Write( Logger::LOG_INFO, "WarpMatrix::OnLostDevice" );

	LostDevice();
	//RenderMatrix::OnLostDevice( );
}


void WarpMatrix::Draw( void )
{
	m_pLogger->Write( Logger::LOG_DEBUG, "WarpMatrix::Draw" );
	RenderMatrix::Draw();
}

bool WarpMatrix::SetCellValue( const unsigned int uiColumn, const unsigned int uiRow, const Cell& cell )
{
	unsigned int	uiSwitchedRow;
	Cell			SwitchedCell;

	// Switch the row order and the fYPos for the cells in the
	// warp matrix to make it the same as the CompactControl server.
	int x = Matrix::GetNumOfRows();
	uiSwitchedRow = ( Matrix::GetNumOfRows() - 1 ) - uiRow;
	SwitchedCell.fXPos = cell.fXPos;
	SwitchedCell.fYPos = cell.fYPos * -1.0f;   

	return RenderMatrix::SetCellValue( uiColumn, uiSwitchedRow, SwitchedCell );
}

bool WarpMatrix::GetCellValue( const unsigned int uiColumn, const unsigned int uiRow, Cell& cell ) const
{
	unsigned int	uiSwitchedRow;
	Cell			SwitchedCell;
	bool			bGotCell;

	// Switch the row order and the fYPos for the cells in the
	// warp matrix to make it the same as the CompactControl server.
	int x = Matrix::GetNumOfRows();
	uiSwitchedRow = ( Matrix::GetNumOfRows() - 1 ) - uiRow;
	bGotCell = RenderMatrix::GetCellValue( uiColumn, uiSwitchedRow, cell );
	SwitchedCell.fXPos = cell.fXPos;
	SwitchedCell.fYPos = cell.fYPos * -1.0f;

	return bGotCell;
}