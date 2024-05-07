#include <iostream>

template <typename T>
class CircularLinkedList
{
private:
	struct Element
	{
		T data;
		Element* next;
	};

	Element* head;
	int size;

public:
	CircularLinkedList() : head(nullptr), size(0) {}

	~CircularLinkedList()
	{
		while (size > 0)
		{
			remove(0);
		}
	}

	void push(const T& d)
	{
		Element* newElement = new Element{ d, nullptr };
		if (head == nullptr)
		{
			head = newElement;
			head->next = newElement;
		}
		else
		{
			Element* tmp = head;
			for (int i = 1; i < size; ++i)
			{
				tmp = tmp->next;
			}
			tmp->next = newElement;
			newElement->next = head;
			head = newElement;

		}
		size++;
	}

	void remove(int index)
	{
		if (index < 0 || index >= size) 
		{
			std::cout << "Index out of bounds\n";
			return;
		}

		if (size == 1) //добавить size = 0
		{
			delete head;
			head = nullptr;
		}
		else {
			Element* current = head;
			for (int i = 1; i < size - index; i++)
			{
				current = current->next;
			}

			Element* tmp = current->next;

			if (tmp == head)
			{
				head = tmp->next;
			}
			
			current->next = tmp->next;

			delete tmp;
		}

		size--;
	}

	void print(const CircularLinkedList& c)
	{
		std::cout << "The list is " << c.head->data << "  ";
		for (Element* cur = c.head->next; cur != c.head; cur = cur->next)
		{
			std::cout << cur->data << "  ";
		}
		std::cout << std::endl;
	}

	T reverseAt(int index)
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Index out of bounds\n";
			return T();
		}

		Element* current = head;
		for (int i = 0; i < size - index; i++)
		{
			current = current->next;
		}

		return current->data;
	}
};

int main(int argc, char* argv[])
{
	CircularLinkedList<int> list;

	list.push(11);
	list.push(22);
	list.push(33);
	list.push(44);
	list.push(55);
	list.print(list);

	std::cout << "Element at index 1: " << list.reverseAt(1) << std::endl;
	list.remove(1);

	std::cout << "List after removal 1st element: ";
	list.print(list);

	std::cout << "List after removal 3d element: ";
	list.remove(3);
	list.print(list);

	std::cout << "List after removal 2nd element: ";
	list.remove(2);
	list.print(list);

	std::cout << "Try to remove 5th element: ";
	list.remove(5);
	list.print(list); //расширить тесты 1,0 на размерах

	return 0;
}
