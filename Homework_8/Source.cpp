#include <iostream>

template <typename T>
struct Element
{
	T data;
	Element<T>* next;
};

template <typename T>
struct Queue
{
	Element<T>* head = nullptr, * tail = nullptr;
};

template <typename T>
void push(Queue<T>& q, T d)
{
	Element<T>* e = (Element<T>*)malloc(sizeof(Element<T>));
	e->data = d;
	e->next = nullptr;
	if (q.head == nullptr)
	{
		q.tail = e;
		q.head = e;
	}
	else
	{
		q.tail->next = e;
		q.tail = e;
	}
}

template <typename T>
T pull(Queue<T>& q)
{
	if (q.head == nullptr)
	{
		return 0;
	}
	T d = q.head->data;
	if (q.head == q.tail)
	{
		q.tail = nullptr;
	}
	Element<T>* e = q.head;
	q.head = q.head->next;
	free(e);
	return d;
}

template<typename T>
void print(const Queue<T>& q)
{
	for (Element<T>* cur = q.head; cur != nullptr; cur = cur->next)
	{
		printf("%i - ", cur->data);
	}
	printf("\b\b \n");
}

template <typename T>
void loop()
{
	Queue<T> myq;
	int choice;
	while (true)
	{
		printf("Choose: 1 - add element, 2 - remove element, 3 - exit \n");
		do
		{
			scanf_s("%i", &choice);
		} while (choice < 1 || choice > 3);

		int tmp;
		switch (choice)
		{
		case 1:
			scanf_s("%i", &tmp);
			push(myq, tmp);
			break;
		case 2:
			tmp = pull(myq);
			printf("Removed element with data %i\n", tmp);
			break;
		case 3:
			return;
		}
		print(myq);
	}
}

int main()
{
	loop<int>(); //тесты для других типов 

	system("pause");
	return 0;
}
