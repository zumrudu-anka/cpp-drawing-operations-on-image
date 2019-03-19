// Image_Process1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <math.h>

//User defined includes
#include "imge_bmp.h"
#include "Cizimler.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	LPCTSTR input, output;
	int Width, Height;
	long Size, new_size;

	cout << "Haydi Bismillah" << endl;
	input = L"..//Pictures//tiger.bmp";
	
	BYTE* buffer = LoadBMP(&Width, &Height, &Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
	char ch;
	cout << "Sonucu diske kaydetsin mi? E/H:"; cin >> ch;
	if ((ch == 'E') || (ch == 'e')) {

		BYTE* display_imge = ConvertIntensityToBMP(raw_intensity, Width, Height, &new_size);
		output = L"..//Pictures//intensity.bmp";
		if (SaveBMP(display_imge, Width, Height, new_size, output))
			cout << " Output Image was successfully saved" << endl;
		else cout << "Error on saving image" << endl;
		delete[] display_imge;
	}//
	cout << "Cizgi Cizilsin mi? E/H:"; cin >> ch;
	if (ch == 'E' || ch == 'e') {
		int xx1, xx2, yy1, yy2;
		cout << "Cizgi cizilmesini istediginiz baslangic noktasi icin x1 giriniz:"; cin >> xx1;
		cout << "y1 giriniz:"; cin >> yy1;
		cout << "Bitis noktasi icin x2: giriniz:"; cin >> xx2;
		cout << "y2 giriniz:"; cin >> yy2;

		BYTE* new_raw_intensity = DrawLine(buffer, Width, Height, xx1, yy1, xx2, yy2);

		BYTE* display_imge2 = ConvertIntensityToBMP(new_raw_intensity, Width, Height, &new_size);
		output = L"..//Pictures//Line.bmp";
		if (SaveBMP(display_imge2, Width, Height, new_size, output))
			cout << " Output Image was successfully saved" << endl;
		else cout << "Error on saving image" << endl;
		delete[] display_imge2;
		delete[] new_raw_intensity;
	}

	cout << "Cember Cizilsin mi? E/H:"; cin >> ch;
	if (ch == 'E' || ch == 'e') {
		int centerx, centery, radius;
		cout << "Cemberin merkez noktasi icin x1 giriniz:"; cin >> centerx;
		cout << "y1 giriniz:"; cin >> centery;
		cout << "cemberin yaricapini giriniz:"; cin >> radius;

		BYTE* new_raw_intensity2 = DrawCircle(buffer, Width, Height, centerx, centery, radius);

		BYTE* display_imge3 = ConvertIntensityToBMP(new_raw_intensity2, Width, Height, &new_size);
		output = L"..//Pictures//Circle.bmp";
		if (SaveBMP(display_imge3, Width, Height, new_size, output))
			cout << " Output Image was successfully saved" << endl;
		else cout << "Error on saving image" << endl;
		delete[] display_imge3;
		delete[] new_raw_intensity2;
	}

	cout << "Elips Cizilsin mi? E/H:"; cin >> ch;
	if (ch == 'E' || ch == 'e') {
		int centerx, centery, xrad, yrad ;
		cout << "Elipsin merkez noktasi icin x1 giriniz:"; cin >> centerx;
		cout << "y1 giriniz:"; cin >> centery;
		cout << "elipsin x eksen yaricapini giriniz:"; cin >> xrad;
		cout << "elipsin y eksen yaricapini giriniz:"; cin >> yrad;


		BYTE* new_raw_intensity3 = DrawEllipse(buffer, Width, Height, centerx, centery, xrad, yrad);

		BYTE* display_imge4 = ConvertIntensityToBMP(new_raw_intensity3, Width, Height, &new_size);
		output = L"..//Pictures//Ellipse.bmp";
		if (SaveBMP(display_imge4, Width, Height, new_size, output))
			cout << " Output Image was successfully saved" << endl;
		else cout << "Error on saving image" << endl;
		delete[] display_imge4;
		delete[] new_raw_intensity3;
	}


	delete[] buffer;
	delete[] raw_intensity;
	
	return 0;
}







