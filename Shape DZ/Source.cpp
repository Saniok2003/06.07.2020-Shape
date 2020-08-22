#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Shape
{
private:
	int cor_x;
	int cor_y;
	int a;
	int b;
	float r;
public:
	Shape() : cor_x(0), cor_y(0), a(0), b(0), r(0)	
	{	}
	virtual void Show() = 0;
	virtual void Save() const	{	}
	virtual void Load()	{	}
};

class Circle : public Shape
{
private:
	int cor_x;
	int cor_y;
	float r;
public:
	Circle(int cor_x, int cor_y, float r) : cor_x(cor_x), cor_y(cor_y), r(r)
	{	}
	virtual void Save() const override
	{
		ofstream fout;
		fout.open("Saves.txt", ios_base::app);
		bool isOpen = fout.is_open();
		if (isOpen == true)
		{
			ofstream rewrite("Saves.txt");
			rewrite.write("", 0);
			rewrite.close();
			fout << cor_x << endl;
			fout << cor_y << endl;
			fout << r << endl;
		}
		else
		{
			cout << "File not find" << endl;
		}
		fout.close();
	}

	virtual void Load() override
	{
		ifstream fin;
		fin.open("Saves.txt");
		bool isOpen = fin.is_open();
		if (isOpen == true)
		{
			fin >> cor_x;
			fin >> cor_y;
			fin >> r;
		}
		else
		{
			cout << "File not find" << endl;
		}
		fin.close();
	}
	virtual void Show()
	{
		cout << "X: " << cor_x << endl << "Y: " << cor_y << endl;
		cout << "Radius: " << r << endl << endl;
	}
};

class Square : public Shape
{
private:
	int cor_x;
	int cor_y;
	int a;
public:
	Square(int cor_x, int cor_y, int a) : a(a), cor_x(cor_x), cor_y(cor_y)
	{	}
	virtual void Save() const override
	{
		ofstream fout;
		fout.open("Saves.txt", ios_base::app);
		bool isOpen = fout.is_open();
		if (isOpen == true)
		{
			ofstream rewrite("Saves.txt");
			rewrite.write("", 0);
			rewrite.close();
			fout << cor_x << endl;
			fout << cor_y << endl;
			fout << a << endl;
		}
		fout.close();
	}
	virtual void Load() override
	{
		ifstream fin;
		fin.open("Saves.txt");
		bool isOpen = fin.is_open();
		if (isOpen == true)
		{
			fin >> cor_x;
			fin >> cor_y;
			fin >> a;
		}
		fin.close();
	}
	virtual void Show()
	{
		cout << "X: " << cor_x << endl << "Y: " << cor_y << endl;
		cout << "Side: " << a << endl << endl;;
	}
};

class Rectangle : public Shape
{
private:
	int cor_x;
	int cor_y;
	int a;
	int b;
public:
	Rectangle(int x, int y, int a, int b) : cor_x(x), cor_y(y), a(a),b(b)
	{	}
	virtual void Save() const override
	{
		ofstream fout;
		fout.open("Saves.txt", ios_base::app);
		bool isOpen = fout.is_open();
		if (isOpen == true)
		{
			ofstream rewrite("Saves.txt");
			rewrite.write("", 0);
			rewrite.close();
			fout << cor_x << endl;
			fout << cor_y << endl;
			fout << a << endl;
			fout << b << endl;
		}
		fout.close();
	}
	virtual void Load() override
	{
		ifstream fin;
		fin.open("Saves.txt");
		bool isOpen = fin.is_open();
		if (isOpen == true)
		{
			fin >> cor_x;
			fin >> cor_y;
			fin >> a;
			fin >> b;
		}
		fin.close();
	}
	virtual void Show()
	{
		cout << "X: " << cor_x << endl << "Y: " << cor_y << endl;
		cout << "Side A: " << a << endl;
		cout << "Side B: " << a << endl<<endl;
	}
};

class Ellipse : public Shape
{
private:
	int cor_x;
	int cor_y;
	int a;
	int b;
public:
	Ellipse(int cor_x, int cor_y, int a, int b) : cor_x(cor_x), cor_y(cor_y), a(a), b(b)
	{	}
	virtual void Save() const override
	{
		ofstream fout;
		fout.open("Saves.txt", ios_base::app);
		bool isOpen = fout.is_open();
		if (isOpen == true)
		{
			ofstream rewrite("Saves.txt");
			rewrite.write("", 0);
			rewrite.close();
			fout << cor_x << endl;
			fout << cor_y << endl;
			fout << a << endl;
			fout << b << endl;
		}
		fout.close();
	}
	virtual void Load() override
	{
		ifstream fin;
		fin.open("Saves.txt");
		bool isOpen = fin.is_open();
		if (isOpen == true)
		{
			fin >> cor_x;
			fin >> cor_y;
			fin >> a;
			fin >> b;
		}
		fin.close();
	}
	virtual void Show()
	{
		cout << "X: " << cor_x << endl << "Y: " << cor_y << endl;
		cout << "Side A: " << a << endl;
		cout << "Side B: " << a << endl << endl;
	}
};

int main()
{
	Circle sss(4, 4, 4);
	sss.Save();
	Shape* s[4]
	{
		new Square(3,3,3),
		new Rectangle(4,4,4,4),
		new Circle(3,3,3),
		new Ellipse(7,7,7,7)
	};
	
	for (int i = 0; i < 4; i++)
	{
		s[i]->Show();
	}
	
	Shape* ss[4];
	for (int i = 0; i < 4; i++)
	{
		ss[i] = s[i];
	}
	for (int i = 0; i < 4; i++)
	{
		ss[i]->Show();
	}
	return 0;
}
