/** @class WarpLogic
	@version 1.0 
	@date 2008-11-24
	@author Robert Malmstrom
*/

#ifndef WARP_LOGIC_H
#define WARP_LOGIC_H

#include "StdAfx.h"
#include "WarpMatrix.h"
#include "EdgeBlendMatrix.h"
#include "Logger.h"
#include "CompactCommunication.h"

#include "Mesh.h"


class Point2font;
class Point2f;
class Mesh;
template<class T> class point2;
/// This class handles all the actions sent from the CompactControl server.
/** This is the main class in the soft warp dll and it is a singleton class
	where you call the function GetInstance to get the single instance.
	The class handles the communication with the CompactControl server with
	the function NetworkProcess and performes the actions that the server sends.
	For example this function creates and removes warp- and edge blend
	matrices by calling the function CreateAndRemoveObjects, moves points
	in the matrices by calling the function SetCellValue in the matrices. This
	class also creates and sets the view projection for the soft warping and
	draws all the warp- and edge blend matrices with the function Draw. After
	drawing the matrices it resets all the render states that has been changed
	so that the application that uses this dll don't have to reset the states
	after calling the function Draw.
*/

using namespace std;

class WarpLogic
{
private:
// 	typedef struct _RenderState
// 	{
// 		_RenderState( D3DRENDERSTATETYPE stateType, DWORD dState )
// 		{
// 			_RenderState::stateType = stateType;
// 			_RenderState::dWarpState = dState;
// 		};
// 		D3DRENDERSTATETYPE	stateType;
// 		DWORD				dWarpState;
// 		DWORD				dSavedState;
// 	} RenderState;

public:
	~WarpLogic( void );
	/** This function is called to get the single instance of this singleton
		class.
	*/
	static WarpLogic* GetInstance( void );
	/** This function is called when the DirectX render device loses the device.
		This can happen when, for example, you press Ctrl-Alt-Delete or
		when the screen saver is activated.
	*/
	void OnLostDevice( void );
	/** This function is called when the DirectX render device is created or
		after a lost DirectX render device.
	*/
	//void OnResetDevice( IDirect3DDevice9* pD3DDevice );
	/** This function do all the rendering of the warp- and edge blend
		matrices.
	*/
	void Draw(int& num);
	/** This function is used to turn on or off if the Soft warp edge blend
		should be drawn as seperate edge blend matrices or if all edge blend
		matrices should be drawn to a single texture to reduce the number
		of vertices to a minimum. If pixel filling rate is the performance
		bottle neck for the graphics card then you don't have to call this
		function since the one texture strategi is default turn off.
		If the vertex pipe line is the bottle neck then call this function
		with the inparameter bState set to true to activate the one texture
		strategi that minimizes the number of vertices.
	*/
	void SetEdgeBlendMinimizeVertices( bool bState );
	/** This function is called to start communicating with the CompactControl
		server. The inparameter strProjectorAddress is this clients unique id
		so that the server know who you are.
	*/
	void StartCommunication( );
	
public:
	WarpLogic( void );
	/** This function creates the view projection for the soft warp
		rendering.
	*/
	void CreateViewProjection( void );
	/** Searches in the m_warpMatrixList for a warp matrix, added with
		the function AddWarpMatrix, with the same handle as the inparameter
		ulHandle. It returns true if the matrix is found.
	*/
	bool FindWarpMatrix( const unsigned long ulHandle );
	/** Searches in the m_edgeBlendMatrixList for a warp matrix, added with
		the function AddWarpMatrix, with the same handle as the inparameter
		ulHandle. It returns true if the matrix is found.
	*/
	bool FindEdgeBlendMatrix( const unsigned long ulHandle, int &num);
	/** Searches in the m_warpMatrixList for a warp matrix, added with
		the function AddWarpMatrix, with the same handle as the in parameter
		ulHandle. It returns true if the matrix is found and sets the iterator
		to the found matrix.
	*/
	bool GetWarpMatrix( const unsigned long ulHandle, list<WarpMatrix*>::iterator& warpMatrixIterator, int &num);
	/** Searches in the m_edgeBlendMatrixList for a warp matrix, added with
		the function AddWarpMatrix, with the same handle as the inparameter
		ulHandle. It returns true if the matrix is found and sets the iterator
		to the found matrix.
	*/
	bool GetEdgeBlendMatrix( const unsigned long ulHandle, list<EdgeBlendMatrix*>::iterator& edgeBlendMatrixIterator, int &num);
	/** Adds a new warp matrix to the m_warpMatrixList. The new warp matrix
		is then rendered by the function Draw. The inparameter uiColumns and
		uiRows sets the size of the matrix. The inparameter ulHandle should be
		unique because it is used to search for the matrix.
	*/
	void AddWarpMatrix( const unsigned long ulHandle, const unsigned int uiColumns, const unsigned int uiRows, list<WarpMatrix*>::iterator& warpMatrixIterator, bool &replace, int &num);
	/** This function removes the WarpMatrix pointed out by the in parameter
		warpMatrixIterator from the m_warpMatrixList.
	*/
	void RemoveWarpMatrix( list<WarpMatrix*>::iterator& warpMatrixIterator );
	/** Adds a new edge blend matrix to the m_edgeBlendMatrixList. The new 
		edge blend matrix is then rendered by the function Draw. The inparameter
		uiColumns and uiRows sets the size of the matrix. The inparameter ulHandle
		should be unique because it is used to search for the matrix.
	*/
	void AddEdgeBlendMatrix( const unsigned long ulHandle, const unsigned int uiColumns, const unsigned int uiRows, int &num);
	/** This function communicates with the CompactControl server by receiving
		CUDPWrapper. The CUDPWrappers are then decoded and executed in the
		function DecodeUDPWrapper.
	*/	
	void NetworkProcess(int& num);
	/** This function execute a command received from the CompactControl
		server. For example this function creates and removes warp- and
		edge blend matrices by calling the function CreateAndRemoveObjects,
		moves points in the matrices by calling the function SetCellValue
		in the matrices.
	*/	
	void DecodeUDPWrapper( CUDPWrapper* pCUDPWrapper,int& num, int &receive_seriel_obj);
	/** This function searches the m_warpMatrixList for a created warp matrix
		with the same handle as the inparameter ulHandle. If the matrix
		doesn't excist then a new warp matrix is created.
	*/
	void CreateWarpMatrix( const unsigned long ulHandle, const unsigned int uiColumns, const unsigned int uiRows ,int& num);
	/** This function searches the m_edgeBlendMatrixList for a created edge
		blend matrix with the same handle as the inparameter ulHandle. If the
		matrix doesn't excist then a new warp matrix is created.
	*/
	void CreateEdgeBlendMatrix(const unsigned long ulHandle, int &num);
	/** This function is used to remove WarpMatrix- or EdgeBlendMatrix objects
		that has the same handle as the in parameter ulHandle.
	*/
	void RemoveObjects( const unsigned long ulHandle );
	/** This function is used to add render states that should be set before
		the rendering of the soft warp. The inparameters stateType and dState
		are added to the m_renderStateList. All the added render states are
		then set with the function SetWarpRenderStates. The states are reset
		to the old render states with the function ResetRenderStates.
	*/
	void AddWarpRenderState( D3DRENDERSTATETYPE stateType, DWORD dState );
	/** This function sets all the render states that are added with the
		function AddWarpRenderState. This function is called before the 
		rendering of the soft warp. This function also saves the old render
		states so that they can be reset after the rendering of the soft
		warp with the function ResetRenderStates.
	*/
	void SetWarpRenderStates( void );
	/** This function resets all the render states that are changed with the
		function SetWarpRenderStates after the rendering of the soft warp.
	*/
	void ResetRenderStates( void );
	/** This function creates one edge blend texture by rendering all edge
		blend matrices to that texture. This is only done if any edge blend
		matrix has changed some cell value.
	*/
	void CreateEdgeBlendTexture( void );
	/** This function draws the edge blend texture that covers the hole
		scene.
	*/
	void DrawEdgeBlendTexture( void );

private:
	Logger*					m_pLogger;
	static WarpLogic*		m_pInstance;
public:
	list<WarpMatrix*>		m_warpMatrixList;
	list<EdgeBlendMatrix*>	m_edgeBlendMatrixList;
private:
	
	bool					m_bViewProjectionCreated;

	//list<RenderState>		m_renderStateList;
	CompactCommunication	m_compactCommunication;
	bool					m_bDrawEdgeBlendMatricesAsOneTexture;

public:
	Mesh*                   m_pMesh;
	bool                    m_end;
	bool                    m_start;
	bool                    m_state;

	bool                    m_edge_alpha;


	std::mutex mu_receive;
	//cv::Mat m_img;
	void  getAllID(std::string &filename, int &num);
	std::vector<std::string> sqe_vec;
	int numProj;
	int		m_uiWindowXWidth;
	int		m_uiWindowYHeight;
	std::mutex testmutex2;
	std::mutex testmutex3;
	//std::list<Point2f > list_vertex_cur;
	std::vector < bool>  save_vec;


	//WarpMatrix::RenderMatrix::nurb_x_order
	//WarpMatrix  warpmatrix;
	std::vector <std::vector < float>>  Alpha_vec_;
	std::vector < float>  Alpha_vec;
	//std::vector < point2<float> >  line_vec2;
	//std::vector < std::vector < point2<float> > >  drawline_vec2;

	//一次line
	std::vector < Point2f >  line_vec;
	//所有的line
	std::vector < std::vector < Point2f > >  drawline_vec;
	//ctrl记号
	std::vector <int>  drawline_ctrl; 
	//坐标标记
	std::vector < Point2font >  mark_vec; 

	int mark_clip;  std::vector<int > mark_clip_vec;
	int line_clip; std::vector<int > line_clip_vec;
	bool breceivewhite;
	std::map<std::string, bool> Whitelevel;

	int num_edge;

	std::vector < point2<float> >  line_vec_edge;
	std::vector < std::vector < point2<float> > >  line_vec_edge_two;


	
	std::vector<std::pair<int, int >> alpha_reverse_vec;
	//std::vector< int > alpha_reverse_vec;
};

#endif