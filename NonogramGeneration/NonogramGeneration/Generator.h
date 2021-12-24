#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Generator
{
private:
	int width; 
	int height;
	int pole[10][10];
public:
	Generator(int width, int height)
	{
		this->width = width;
		this->height = height;
	}
	int getWidth()
	{
		return this->width;
	}
	void setWidth(int width)
	{
		this->width = width;
	}
	int getHeight()
	{
		return this->height;
	}
	void setHeight(int height)
	{
		this->height = height;
	}
	void generate()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				pole[i][j] = rand() % 2;
				std::cout << pole[i][j] << " ";
			}
			std::cout << endl;
		}
	}
	void writeHor()
	{
		cout <<"--------------------------hor-----------------------------"<<endl;
		std::ofstream out;
		out.open("nonogram.txt");
		cout << "1"<<endl;
		out << "1" << endl;
		cout << width << " " << height << endl;
		out << width << " " << height << endl;
		int sum = 0;
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++) {
				if (j == height - 1)
				{
					if (pole[i][j] > 0) 
					{ 
						sum++;
					}
					if (sum > 0) {
						cout << sum << " ";
						if (out.is_open())
						{
							out << sum << " ";
						}
					}
					sum = 0;
					continue;
				}

				if (pole[i][j] != 0) 
				{
					sum++;
					continue;
				}
				
				if (sum > 0)
				{
					cout << sum << " ";
					out << sum << " ";
				}
				sum = 0;
			}
			cout << "0" << endl;
			out << "0" << endl;
			sum = 0;
		}
		out.close();
	}
	void writeVer()
	{
		std::ofstream out;
		out.open("nonogram.txt", std::ios::app);
		cout << "--------------------------vert-----------------------------" << endl;
		cout << "1" << endl;
		cout << width << " " << height << endl;
		int sum = 0;
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++) {
				if (j == height - 1)
				{
					if (pole[j][i] > 0)
					{
						sum++;
					}
					if (sum > 0) {
						cout << sum << " ";
						out << sum << " ";
					}
					sum = 0;
					continue;
				}

				if (pole[j][i] != 0)
				{
					sum++;
					continue;
				}

				if (sum > 0)
				{
					cout << sum << " ";
					out << sum << " ";
				}
				sum = 0;
			}
			cout << "0" << endl;
			out << "0" << endl;
			sum = 0;
		}
		out.close();
	}
};