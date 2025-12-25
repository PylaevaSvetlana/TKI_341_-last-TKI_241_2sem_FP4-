#include <iostream>
#include <cstdlib>
using namespace std;

bool Ferma(size_t n, size_t t);
bool Solovei_Shtrassen(size_t n, size_t t);
bool Miller_Rabin(size_t n, size_t t);
size_t Powmod(size_t a, size_t x, size_t n);
void get_number(size_t& number);
void get_metod(size_t& metod);

int main()
{
	cout << "Enter n: " << endl;
	size_t n=0;
	get_number(n);
	size_t t = 100;
	cout << "Enter metod (1 - Ferma; 2 -  Solovei_Shtrassen; 3 - Miller_Rabin): " << endl;
	size_t metod = 0;
	get_metod(metod);

	if (metod == 1)
	{
		cout << "Algoritm Ferma: " << Ferma(n, t) << endl;
	}
	if (metod == 2)
	{
		cout << "Algoritm Solovei_Shtrassen: " << Solovei_Shtrassen(n, t) << endl;
	}
	if (metod == 3)
	{
		cout << "Algoritm Miller_Rabin: " << Miller_Rabin(n, t) << endl;
	}
	return 0;
}

void get_number(size_t& number)
{
	cin >> number;
	if (number % 2 == 0 || number <= 3)
	{
		throw invalid_argument("");
	}
}

void get_metod(size_t& metod)
{
	cin >> metod;
	if (metod < 1 || metod > 3)
	{
		throw invalid_argument("");
	}
}

bool Ferma(size_t n, size_t t)
{
	for (size_t i = 0; i < t; i++)
	{
		size_t a = rand() % (n - 3) + 1;
		size_t r = Powmod(a, (n - 1), n);
		if (r != 1)
		{
			return false;
		}
	}
	return true;
}

bool Solovei_Shtrassen(size_t n, size_t t)
{
	for (size_t i = 0; i < t; i++)
	{
		size_t a = rand() % (n - 4) + 2;
		size_t r = Powmod(a, (n - 1) / 2, n);
		if (r != 1 && r != n-1)
		{
			return false;
		}
	}
	return true;
}

bool Miller_Rabin(size_t n, size_t t)
{
	size_t r = n - 1;
	size_t s = 0;
	while (r % 2 == 0)
	{
		s++;
		r /= 2;
	}
	for (size_t i = 0; i < t; i++)
	{
		size_t b = rand() % (n - 3) + 1;
		size_t y = Powmod(b, r, n);
		if (y != 1 && y != n-1)
		{
			size_t j = 1;
			while (j < s && y != n-1)
			{
				y = Powmod(y, 2, n);
				if (y == 1)
				{
					return false;
				}
				j++;
			}
			if (y != n - 1)
			{
				return false;
			}
		}
	}
	return true;
}

size_t Powmod(size_t a, size_t x, size_t n)
{
	size_t result = 1;

	while (x>0)
	{
		if (x % 2 == 0)
		{
			x /= 2;
			a = (a * a) % n;
		}
		else
		{
			x--;
			result = (result * a) % n;
		}
	}

	return result % n;
}

