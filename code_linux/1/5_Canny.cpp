//--------------------------------------【程序说明】-------------------------------------------
//		程序说明：《OpenCV3编程入门》OpenCV3版书本配套示例程序05
//		程序描述：使用canny函数进行灰度边缘检测
//		开发测试所用操作系统： Windows 7 64bit
//		开发测试所用IDE版本：Visual Studio 2010
//		开发测试所用OpenCV版本：	3.0 beta
//		2014年11月 Created by @浅墨_毛星云
//		2014年11月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------

//---------------------------------【头文件、命名空间包含部分】----------------------------
//		描述：包含程序所使用的头文件和命名空间
//-------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

//-----------------------------------【main( )函数】--------------------------------------------
//		描述：控制台应用程序的入口函数，我们的程序从这里开始
//-------------------------------------------------------------------------------------------------
int main( )
{
	//【0】载入原始图  
	Mat srcImage = imread("../1/5.jpg");  //工程目录下应该有一张名为1.jpg的素材图
	imshow("【原始图】Canny边缘检测", srcImage); 	//显示原始图 
	Mat dstImage,edge,grayImage;	//参数定义

	//【1】创建与src同类型和大小的矩阵(dst)
	dstImage.create( srcImage.size(), srcImage.type() );

	//【2】将原图像转换为灰度图像
	//此句代码的OpenCV2版为：
	//cvtColor( srcImage, grayImage, CV_BGR2GRAY );
	//此句代码的OpenCV3版为：
	cvtColor( srcImage, grayImage, COLOR_BGR2GRAY );

	//【3】先用使用 3x3内核来降噪
	blur( grayImage, edge, Size(3,3) );

	//【4】运行Canny算子
	Canny( edge, dstImage, 3, 9,3 );

	//【5】显示效果图 
	imshow("【效果图】Canny边缘检测", srcImage);
	waitKey(0);
	if (!grayImage.empty())
	{
		imshow("【效果图】Canny边缘检测", grayImage);
		waitKey(0);
	}
	if (!edge.empty())
	{
		imshow("【效果图】Canny边缘检测", edge);
		waitKey(0);
	}
	imshow("【效果图】Canny边缘检测", dstImage);

	waitKey(0);

	return 0; 
}