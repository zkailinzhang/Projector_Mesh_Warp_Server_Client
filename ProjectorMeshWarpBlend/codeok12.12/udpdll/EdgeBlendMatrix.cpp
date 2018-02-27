#include "EdgeBlendMatrix.h"

// Static variables
float EdgeBlendMatrix::m_sfMaxColorValue = 0x4000;

EdgeBlendMatrix::EdgeBlendMatrix(	const unsigned int iColumns, const unsigned int iRows,
									const unsigned int iColumnIterpolations, const unsigned int iRowIterpolations,
									const unsigned long ulHandle, int channel)
: RenderMatrix( iColumns, iRows, iColumnIterpolations, iRowIterpolations, ulHandle, channel)
//, m_pEdgeBlendTexture( NULL )
{
	m_pLogger->Write( Logger::LOG_INFO, "EdgeBlendMatrix created with handle: ", static_cast<int>( ulHandle ) );
	UseAsymmetricTextureCoordinates();


	SetupCenteredMatrix( 1.0f, 1.0f );//与控制点句柄不同，1.0 1.0, this 0.2  1.0
}

EdgeBlendMatrix::~EdgeBlendMatrix( void )
{
}
/*
void EdgeBlendMatrix::OnLostDevice( void )
{
	m_pLogger->Write( Logger::LOG_DEBUG, "EdgeBlendMatrix::OnLostDevice" );

	// Release texture from the graphic card to free memory.
	//if ( m_pEdgeBlendTexture != NULL )
	//	m_pEdgeBlendTexture->Release();

	RenderMatrix::OnLostDevice();
}

void EdgeBlendMatrix::OnResetDevice( IDirect3DDevice9* pD3DDevice )
{
	m_pLogger->Write( Logger::LOG_DEBUG, "EdgeBlendMatrix::OnResetDevice" );

	//m_pD3DDevice = pD3DDevice;
	//RenderMatrix::OnResetDevice( pD3DDevice );

	//if ( FAILED( D3DXCreateTexture( m_pD3DDevice,
// 									256,
// 									1,
// 									1,
// 									D3DUSAGE_DYNAMIC,
// 									D3DFMT_A8R8G8B8,
// 									D3DPOOL_DEFAULT,
// 									&m_pEdgeBlendTexture ) ) )
// 	{
// 		m_pLogger->Write( Logger::LOG_ERROR, "EdgeBlendMatrix::CreateEdgeBlendTexture, failed to create edge blend texture." );
// 	}
}
*/
void EdgeBlendMatrix::Draw( void )
{
	m_pLogger->Write( Logger::LOG_DEBUG, "EdgeBlendMatrix::Draw" );

	//if ( m_pEdgeBlendTexture != NULL)
	//	m_pD3DDevice->SetTexture( 0, m_pEdgeBlendTexture );
	RenderMatrix::Draw();
}

bool EdgeBlendMatrix::SetCellValue(const unsigned int uiCellIndex, const Cell& cell, const float fLevel)
{
	unsigned int uiColumn;
	unsigned int uiRow;
	Matrix::Cell firstCell;
	Matrix::Cell thirdCell;

	uiColumn = uiCellIndex % 2; 
	uiRow = uiCellIndex / 2;

//	if (uiColumn)
//	{
//		RenderMatrix::GetCellValue(uiColumn - 1, uiRow, firstCell);
//		thirdCell.fXPos = fabs(firstCell.fXPos - cell.fXPos) * 100.0f;
//		thirdCell.fYPos = fabs(firstCell.fYPos - cell.fYPos) * 100.0f;
//		RenderMatrix::SetCellValue(2, uiRow, thirdCell);
//	}
//
//
//	return RenderMatrix::SetCellValue(uiColumn, uiRow, cell);
//}
	//第三列；第一列减去第二列 或者 第二列减去第一列
	//为了能插值，自生成第三列
	// Is the dark part of the edge blend matrix in the first or the last column?
	if ( fLevel == 1.0 && uiColumn == 0 || fLevel == 0.0 && uiColumn == 1 )
	{
		// Is this the second column in a row in the edge blend matrix?
		if ( uiColumn == 1 )
		{
			// Calculate the third cell in this matrix row in a line from
			// the two first points to position the third point outside of
			// the view.
			RenderMatrix::GetCellValue( uiColumn - 1, uiRow, firstCell );
			thirdCell.fXPos = ( cell.fXPos - firstCell.fXPos ) * 100.0f;//100
			thirdCell.fYPos = ( cell.fYPos - firstCell.fYPos ) * 100.0f;
			RenderMatrix::SetCellValue( 2, uiRow, thirdCell );	
		}
		return RenderMatrix::SetCellValue( uiColumn, uiRow, cell );
	
	}
	else
	{
		uiColumn = ( 1 - uiColumn );
		// Is this the second column in a row in the edge blend matrix?
		if ( uiColumn == 0 )
		{
			// Calculate the third cell in this matrix row in a line from
			// the two first points to position the third point outside of
			// the view.
			RenderMatrix::GetCellValue( uiColumn + 1, uiRow, firstCell );    
			thirdCell.fXPos = ( firstCell.fXPos - cell.fXPos ) * 100.0f;
			thirdCell.fYPos = ( firstCell.fYPos - cell.fYPos ) * 100.0f;
			RenderMatrix::SetCellValue( 2, uiRow, thirdCell );
		}
		return RenderMatrix::SetCellValue( uiColumn, uiRow, cell );
	}
}

void EdgeBlendMatrix::SetEdgeBlendAlpha( const unsigned short* usaAplha, const unsigned short usNumOfValues,
	const unsigned short usFirstIndex, const unsigned short usIndexStepSize ,vector<float> &vec_alpha )
{
	//D3DLOCKED_RECT	lockedRect;
	//D3DCOLOR*		pPixelArray;
	//int tmp = usIndexStepSize*(usNumOfValues);
	float			pPixelArray[256];
	float			fAlpha;
	float			fAlphaStep;
	float			fPrevAlpha;

// 	if ( D3D_OK == m_pEdgeBlendTexture->LockRect( 0, &lockedRect, NULL, NULL ) )
// 	{
		//pPixelArray = (D3DCOLOR*)lockedRect.pBits;
		fPrevAlpha = static_cast<float>( usaAplha[ 0 ] ) / m_sfMaxColorValue;
		for ( int iIndex = 0; iIndex < usNumOfValues - 1; ++iIndex )
		{
			fAlpha = static_cast<float>( usaAplha[ iIndex ] ) / m_sfMaxColorValue;
			fAlphaStep = ( fAlpha - fPrevAlpha ) / usIndexStepSize;
			fPrevAlpha = fAlpha;
			for ( int iStep = 0; iStep < usIndexStepSize; ++iStep )
			{
				pPixelArray[(iIndex * usIndexStepSize) + iStep] = fAlpha;// D3DXCOLOR(0.0f, 0.0f, 0.0f, fAlpha);
				fAlpha += fAlphaStep;
			}
		}
// 		m_pEdgeBlendTexture->UnlockRect( 0 );
// 	}
// 	else
		m_pLogger->Write( Logger::LOG_ERROR, "EdgeBlendMatrix::SetEdgeBlendAlpha, failed to lock edge blend alpha texture." );


		//用 assign来代替 =等于号 ，相当于若vec_alpha有值，直接覆盖，巧妙避开size初始化为0，后面循环中，，，但为啥会闪烁呢
		vec_alpha.assign (pPixelArray, pPixelArray + sizeof(pPixelArray) / sizeof(float));

}