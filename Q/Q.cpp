#include <iostream>

using namespace std;

struct Spis2
{
	int info;
	Spis2* next, * prev;
} *beginB, * endB, * t;

void Create_Spis2(Spis2** b, Spis2** e, int in);
void Add_Spis2(int kod, Spis2** b, Spis2** e, int in);
void View_Spis2(int kod, Spis2* t);

int main()
{
	int i, in;
	int answer = -1; 
	int answer2 = -1;
	char Str[2][10] = { "Begin", "End" };

	while (true)
	{
		cout << "\n\tCreate - 1" <<
			"\n\tAdd Stack - 2" <<
			"\n\tView - 3" <<
			"\n\tDelete - 4" <<
			"\n\tEXIT - 0" << endl;

		cin >> answer;

		switch (answer)
		{		
		default:
			cout << "error" << endl;
			break;
		case 1: 
			if (beginB != NULL)
				cout << "Memory has cleared" << endl;

			cout << "Begin Info = ";
			cin >> in;
			Create_Spis2(&beginB, &endB, in);

			cout << "Create Begin = " << beginB->info << endl;
			break;

		case 2:
			cout << "Info = "; 
			cin >> in;
			Add_Spis2(answer2, &beginB, &endB, in);

			if (answer2 == 0)
				t = beginB;
			else
				t = endB;

			cout << "Add to " << Str[answer2] << "  " << t->info << endl;
			break;

		case 3:
			if (!beginB)
			{
				cout << "Stack Pyst!" << endl;
				break;
			}

			cout << "View Begin-0,View End-1:";
			cin >> answer2;

			if (answer2 == 0)
			{
				t = beginB;
				cout << "--Begin --" << endl;
			}
			else
			{
				t = endB;
				cout << "---End --" << endl;
			}

			View_Spis2(answer2, t);
			break;		

		case 0:
			return 0;
			break;
		}
	}
}

void Create_Spis2(Spis2** b, Spis2** e, int in)
{
	t = new Spis2;
	t->info = in;
	t->next = t->prev = NULL; 
	*b = *e = t;
}

void Add_Spis2(int kod, Spis2** b, Spis2** e, int in) 
{
	t = new Spis2; 
	t->info = in; 
	if (kod == 0) 
	{ 
		t->prev = NULL; t->next = *b;
		(*b)->prev = t; 
		*b = t; 
	} 
	else 
	{
		t->next = NULL;
		t->prev = *e;
		(*e)->next = t; 
		*e = t; 
	} 
}

void View_Spis2(int kod, Spis2* t) 
{
	while (t != NULL) 
	{
		cout<< t->info<< endl;

		if(kod== 0) 
			t = t->next;
		else
			t= t->prev;
	}
}