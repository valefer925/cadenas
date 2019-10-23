#include <iostream>

using namespace std;

int tam(char* cad)
{
	int tam = 0;
	while (*cad++ != '\0')
		tam++;
	return tam;
}
void invertirIte(char* cad)
{
	char* t = cad + tam(cad) - 1;
	while (cad < t)
	{
		char aux = *cad;
		*cad++ = *t;
		*t-- = aux;
	}
}

void invertirRec(char* cad, char* t)
{
	if (cad < t)
	{
		char aux = *cad;
		*cad = *t;
		*t = aux;
		return invertirRec(++cad, --t);
	}
}

bool palindromeIte(char* cad, char* t)
{
	while (cad < t)
	{
		if (*cad++ != *t--)
			return false;
	}
	return true;
}

bool palindromeRec(char* cad, char* t)
{
	if (*cad != *t)
		return false;
	if (cad == t)
		return true;
	return palindromeRec(++cad, --t);

}

int main()
{
	char cad[] = "asdsa";
	char* t = cad + tam(cad) - 1;
	/*cout << cad << endl;
	invertirIte(cad);
	cout << cad << endl;
	invertirRec(cad,t);
	cout << cad << endl;*/
	cout << palindromeRec(cad, t);

	return 0;
}

