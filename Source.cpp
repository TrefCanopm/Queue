#include <iostream>
#include <string>

using namespace std;

struct Node
{
	Node* next = nullptr;
	string a;;
};
struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
	size_t size = 0;
};

void push(List* list);
void DelK(List* list);
void PushK(List* list);
bool Chek(List* list);
void CoutList(List* list);
void Del(List* list);
void Menu();

int main()
{
	setlocale(0, "RUS");
	List* list = new List;
	bool F = 1;
	int i;
	while (F)
	{
		Menu();
		cout << "Enter the action number" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			system("cls");
			push(list);
			break;
		}
		case 2:
		{
			system("cls");
			DelK(list);
			break;
		}
		case 3:
		{
			system("cls");
			PushK(list);
			break;
		}
		case 4:
		{
			system("cls");
			CoutList(list);
			break;
		}
		case 5:
		{
			system("cls");
			Del(list);
			cout << "The list has been deleted" << endl;
			break;
		}
		case 6:
		{
			F = 0;
			delete list;
		}
		default:
		{
			cout << "Enter the action number from the menu" << endl;
		}
		}
	}
}

void Menu()
{
	cout << "\t Menu" << endl;
	cout << "1) Add an element" << endl;
	cout << "2) Remove the required number of elements from the specified number" << endl;
	cout << "3) Add the required number of elements" << endl;
	cout << "4) Display the list items on the screen " << endl;
	cout << "5) Remove all items from the list" << endl;
}

void push(List* list)
{
	list->size++;
	Node* node = new Node;
	getline(cin >> ws, node->a);
	if (Chek(list))
	{
		list->tail->next = node;
		list->tail = node;
	}
	else
	{
		list->head = node;
		list->tail = node;
	}
}

void PushK(List* list)
{
	int i;
	cout << "Enter the number of items to be entered" << endl;
	cin >> i;
	list->size += i;
	while (i > 0)
	{
		Node* node = new Node;
		getline(cin >> ws, node->a);
		if (Chek(list))
		{
			list->tail->next = node;
			list->tail = node;
		}
		else
		{
			list->head = node;
			list->tail = node;
		}
		i--;
	}
}

void DelK(List* list)
{
	int n, i;
	cout << "Enter which element will be deleted from" << endl;
	cin >> n;
	cout << "Enter the number of items to delete" << endl;
	cin >> i;
	list->size = list->size - i;
	if (Chek(list))
	{
		Node* temp = list->head;
		while (n - 1 > 0)
		{
			list->head = list->head->next;
			temp->next = nullptr;
			list->tail->next = temp;
			list->tail = list->tail->next;
			temp = list->head;
			n--;
			CoutList(list);
		}
		/*while (i > 0)
		{*/
			Node* temp1 = list->head;
			list->head = list->head->next;
			delete temp1;
			/*i--;
		}*/
		cout << "Elements removed" << endl;
	}
	else
	{
		cout << "The list is empty" << endl;
	}
}

void Del(List* list)
{
	Node* temp = list->head;
	while (temp != nullptr)
	{
		Node* temp1 = temp;
		temp = temp->next;
		delete temp1;
	}
}

bool Chek(List* list)
{
	if (list->head == nullptr)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void CoutList(List* list)
{
	int i = 1;
	Node* temp = list->head;
	while (temp != nullptr)
	{
		cout << i << ") " << temp->a << endl;
		i++;
		temp = temp->next;
	}
	cout << "The elements are output" << endl;
}