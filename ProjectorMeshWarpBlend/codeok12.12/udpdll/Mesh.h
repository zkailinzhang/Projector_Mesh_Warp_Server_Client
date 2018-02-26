#pragma once
#include "stdafx.h"

#include "freeglut\\include\\GL\\freeglut.h"
#pragma comment(lib,"freeglut.lib")

 #include "WarpLogic.h"
#include "tinyxml2/tinyxml2.h"
 class WarpLogic;


template<class T>
class point2 {
public:
	T x, y;
	point2(T x, T y) : x(x), y(y) {}
	point2() {};
	~point2() {};
};


class Point2f
{
public:
	Point2f(float f1, float f2, int x, int y) : fx(f1), fy(f2), x(x), y(y) {}
	Point2f() {};
	~Point2f() {};
	float fx; float fy; int x; int y;
	point2<int> ID; point2<float> coordination;

};


class Point2font
{
public:
	Point2font(float f1,float f2,string mak):fx(f1),fy(f2),mark(mak){}
	Point2font() {};
	~Point2font() {};
	string mark;
	float fx;
	float fy;
};


//N个通道 发一 eum ，二 vector<list>

//vector< vector<int>> n(3, vector(2)); 3*2 mat

enum Role {
	Channel_1 = 0, Channel_2, Channel_3,
	Channel_4, Channel_5
};

//Role role = Channel_1;
#define checkImageWidth 256
#define checkImageHeight 49

class Mesh
{
protected:
	Mesh();

	~Mesh();


private: 
	static Mesh* m_pMeshInstance;

public:
	static Mesh* GetInstance();
	

public:

	struct point2f {
		int x, y;
		point2f(int x, int y) : x(x), y(y) {}
	};

	std::vector< std::list<Point2f> > list_vec;


	std::list<Point2f > list_vertex_show;
	  //cv::Point2f
// 	std::vector<cv::Point2f> vec_vertex;
// 	 cv::Mat mat_vertex;
	int mode_interpolation;
	
	bool bUpdateID;
	bool bGetControlNum;
	bool bGetAllMesh;
	bool bGetAllEdge;
	bool bGetAllEdgetex ;
	bool bGetDrawline;
	bool bGetDrawline_receiveok;
	bool bGetWhitepattern;

	std::vector<int> num_contol_rows;
	std::vector<int> num_contol_cols;
	int num_contol_x;
	int num_contol_y;
	int id_current;
	int id_update;
	
public:
	static void show(int argc, char** argv);
	static void KeysEvent(unsigned char key, int w, int h);
	//void (*reshape)(int w, int h);
	//void(*display2)(); //point2f void(*display3)(); //point3f
	static void reshape(int w, int h);
	static void display2(); //point2f
	static void display3(); //point3f
	static void displayline(int &cur_num);
	static void displayline2(int &cur_num);
	static void showSplineMatrixcp(int &cur_num);
	void SplineMatrixcolor();
	static void showSplineMatrixEdge(int &cur_num);

	void showSplineMatrixEdgecolor();

	static void ProcessSpecialKeyboead(int key, int x, int y);
	static void   IdleFunction(void);
	static void thread_task();
	static void makeCheckImage(int &n);
	static void inittifusionzone(int &n);
	static void initpatterntest(int &);
	static void grabtf(void);
	static void showDrawlinectrl(void);
	static void showDrawwhitepattern(void);
	static void bitmapString(void * fontId, std::string strText);
	static void displaymark(int &num);
	void showSplineMatrixEdgeold2(int & cur_num);
	void showSplineMatrixEdgeold(int & cur_num);
	std::thread testThread_;
	std::mutex testmutex;

	int cur_cur;
	int		m_uiWindowXWidth;
	int		m_uiWindowYHeight;
	bool lastbool;

	//Matrix		splinedMatrix;
	//std::vector< Matrix* > splinedMatrix_vec;
	std::vector < std::list<Point2f> > splinedlist_vec;

	int numchannels;

	WarpLogic* m_warplogic;
	list<WarpMatrix*>		warpMatrixList;


	list<EdgeBlendMatrix*>	m_edgeBlendMatrixList;
	std::vector < float>  alpha_vec;
	std::vector <std::vector < float>>  alpha_vec_;
	std::vector < Matrix::Cell>  alpha_cor;
	std::vector < std::vector < point2<float> > >  line_vec_edge_two_;

	GLubyte checkImage[checkImageHeight][checkImageWidth][4];
	GLuint texName;

	std::vector < std::vector < Point2f > >  mdrawline_vec;
	std::vector < Point2font >  mmark_vec;
	float colorvalue;
	std::vector<int > mmark_clip_vec;
	std::vector<int > mline_clip_vec;

	std::map<std::string, bool> mWhitelevel;
};

class NVMesh
{
public:
	int index, rowIndex, columnIndex;
	double x, y, z;

	NVMesh(){}
	NVMesh(int index, double x, double y,  int rowIndex, int columnIndex)
	{
		this->index = index;
		this->x = x;
		this->y = y;
		this->z = z;
		this->rowIndex = rowIndex;
		this->columnIndex = columnIndex;
	}
};