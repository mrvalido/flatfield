#ifndef FLATFIELD_HPP
#define FLATFIELD_HPP

#include <opencv2/highgui/highgui.hpp>


#include <math.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>   // for srand and rand
#include <ctime>     // for time
#include <CCfits/CCfits>
#include <fitsio.h>
#include <string>
#include <algorithm>
#include <cmath>

#include <fstream>

#include <vector>
#include <array>


#include<dirent.h>
#include <sys/types.h>
#include "utility.hpp"


#define no_of_image 9
//#define no_of_image 16
//#define dimX					2048
//#define dimY					2048
//
//#define dimX					1080 //Test SolarC
//#define dimY					1080
//int dimX;					//1024 //dimension imagenes HRT de prueba
//int dimY;				//1024
#define ind( y, x ) ( y*dimX+x )

using namespace cv;
using namespace std;
using namespace CCfits;

vector<vector<int>> read_disp(string namefile);
vector<string> read_directory(  string path, int &num_imag);
ImageValINT readImageFit2(string nombreImagen);
ImageValInt readImageFit(string nombreImagen,int &dimX,int &dimY);
//template <typename T>
int writeImage(ImageValDouble val,string fileName,long bitPix,int dimX,int dimY);
void Mask(ImageValInt& data, ImageValShort& tmp,  const int iMin, const int iMax, int index);

template <typename TT>
void pinta(valarray<TT>& val,int Dy,int Dx, int indice);

ImageValChar escalado8(const ImageValDouble& val);
ImageValChar escalado8(const ImageValShort& val);
ImageValChar escalado8(const ImageValInt& val);
ImageValInt shift_to(const ImageValINT& val,int min);
int* desplazamientos(const int centros[9][2], int imagenQ, int imagenR);

template <typename T>
ImageValDouble ROI(const valarray<T>& val, int dx, int dy,int dimX,int dimY);

template <typename T>
void sumROI(valarray<T>& val, const valarray<T>& ROI, int dx, int dy,int dimX,int dimY);


void normalicer(ImageValDouble&, ImageValDouble&,int dimX,int dimY);
void criba_zero(ImageValDouble& GTmp,ImageValDouble& pixCnt2,int dimX,int dimY);
ImageValDouble media(ImageValDouble& GTmp,ImageValDouble& pixCnt2,int dimX,int dimY);
ImageValDouble criba_fivesigma(ImageValDouble& val, double aver2, double fiveSigma,int dimX,int dimY);
ImageValDouble flatfield(ImageValDouble& val,const ImageValShort& tmp,int dimX,int dimY );
//ImageValDouble getConst(vector<ImageValInt>& data,
//		const ImageValShort& tmp,\
//		ImageValDouble& pixCnt,\
//		const int disp[9][2],int dimX,int dimY);
//
//void doIteration(const ImageValDouble& con,\
//		ImageValDouble& gain,\
//		const ImageValShort& tmp,\
//		const ImageValDouble& pixCnt,\
//		const int disp[9][2],int dimX,int dimY);
//
//ImageValDouble iterate(const ImageValDouble& con, \
//		ImageValDouble& gain, \
//            const ImageValShort& tmp, \
//            const ImageValDouble& pixCnt, \
//            const int disp[9][2], \
//			const unsigned int loops,int dimX,int dimY);

ImageValDouble getConst(vector<ImageValInt>& data,
		const ImageValShort& tmp,\
		ImageValDouble& pixCnt,\
		vector<vector<int>> disp,int dimX,int dimY);

void doIteration(const ImageValDouble& con,\
		ImageValDouble& gain,\
		const ImageValShort& tmp,\
		const ImageValDouble& pixCnt,\
		vector<vector<int>> disp,int dimX,int dimY);

ImageValDouble iterate(const ImageValDouble& con, \
		ImageValDouble& gain, \
            const ImageValShort& tmp, \
            const ImageValDouble& pixCnt, \
			vector<vector<int>> disp, \
			const unsigned int loops,int dimX,int dimY);


#endif

