#include <iostream>
#include <string>
#include "../api/ImageComputation.hpp"

/*
 * IC Refers to Image Computation
 */

static int MedianVal(unsigned char* Dat, uint8_t Size)
{
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = i + 1; j < Size; j++)
		{
			if (Dat[i] > Dat[j])
			{
				Dat[i] = Dat[i] ^ Dat[j];
				Dat[j] = Dat[i] ^ Dat[j];
				Dat[i] = Dat[i] ^ Dat[j];
			}
		}
	}

	return Dat[Size / 2];
}

static void IC_Average_Median(unsigned char* Dat, unsigned char* ResData, int Row, int Col)
{
	int8_t Index = 0, Seq[3] = { -1,0,1 };

	unsigned char PixelVal[9];

	int R, C, Sum = 0;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			for (int8_t k = 0; k < 3; k++)
			{
				for (int8_t l = 0; l < 3; l++)
				{
					R = i + (Seq[k]);
					C = j + (Seq[l]);

					if (R >= Row)
					{
						R--;
					}

					if (C >= Col)
					{
						C--;
					}

					if (0 > R)
					{
						R = i;
					}

					if (0 > C)
					{
						C = j;
					}

					PixelVal[Index] = (*(Dat + C + R * Col));
					Index++;
				}
			}

			Index = 0;

			(*(ResData + (i * Col) + j)) = MedianVal(PixelVal, 9);
			Sum = 0;
		}
	}
}

static void IC_Average_Smooth(unsigned char* Dat, unsigned char* ResData, int Row, int Col)
{
	int8_t Seq[3] = { -1,0,1 };

	int R, C, Sum = 0;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			for (int8_t k = 0; k < 3; k++)
			{
				for (int8_t l = 0; l < 3; l++)
				{
					R = i + (Seq[k]);
					C = j + (Seq[l]);

					if (R >= Row)
					{
						R--;
					}

					if (C >= Col)
					{
						C--;
					}

					if (0 > R)
					{
						R = i;
					}

					if (0 > C)
					{
						C = j;
					}

					Sum += (*(Dat + C + R * Col));
				}
			}

			(*(ResData + (i * Col) + j)) = (Sum / 9);
			Sum = 0;
		}
	}
}

static bool IC_MakeCopy(std::string ImgName, const char* Header, const char* ColorTable, const char *ImgData, const int size)
{
	std::ofstream ImageOut(ImgName, std::ios::binary);

	ImageOut.write(Header, 54);

	if (ColorTable != NULL)
	{
		ImageOut.write(ColorTable, 1024);
	}

	ImageOut.write(ImgData, size);

	ImageOut.close();

	// TO DO : Implement appropriate logic to return the status of the cloning
	return 1;
}


bool ImageProcess::ImageComputation::MakeClone(ImageProcess::Image& Img)
{
	return IC_MakeCopy(("clone_" + Img.Image_Name), Img.Image_Header, Img.Image_ColorTable, Img.Image_Data, (Img.Image_Width * Img.Image_Height * (Img.Image_ColorDepth / 8)));
}

bool ImageProcess::ImageComputation::SmoothAvg(ImageProcess::Image& Img)
{
	bool RetVal = false;

	char* ProcessedImg = new char[Img.Image_Width * Img.Image_Height * (Img.Image_ColorDepth / 8)];

	IC_Average_Smooth((unsigned char*)Img.Image_Data, (unsigned char*)ProcessedImg, Img.Image_Width, Img.Image_Height);

	RetVal = IC_MakeCopy(("as_" + Img.Image_Name), Img.Image_Header, Img.Image_ColorTable, ProcessedImg, (Img.Image_Width * Img.Image_Height * (Img.Image_ColorDepth / 8)));

	delete ProcessedImg;

	return RetVal;
}

bool ImageProcess::ImageComputation::MedianAvg(ImageProcess::Image& Img)
{
	bool RetVal = false;

	char* ProcessedImg = new char[Img.Image_Width * Img.Image_Height * (Img.Image_ColorDepth / 8)];

	IC_Average_Median((unsigned char*)Img.Image_Data, (unsigned char*)ProcessedImg, Img.Image_Width, Img.Image_Height);

	RetVal = IC_MakeCopy(("ms_" + Img.Image_Name), Img.Image_Header, Img.Image_ColorTable, ProcessedImg, (Img.Image_Width * Img.Image_Height * (Img.Image_ColorDepth / 8)));

	delete ProcessedImg;

	return RetVal;
}