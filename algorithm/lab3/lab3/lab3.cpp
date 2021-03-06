// lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "BinaryTree.h"

int main()
{
	abonent abn1("Sergey Bayramov", "89313112511");
	abonent abn2("Sergey Evdokimov", "89221578977");
	abonent abn3("Sasha Vatrakshina", "87997417777");
	abonent abn4("Natalya Bayramova", "89631410171");

	BinaryTree *tree = new BinaryTree(abn3);
	tree->insert(abn1);
	tree->insert(abn2);
	tree->insert(abn4);

	bool stop = false;
	string in;
	int price = 0;
	int time = 0;

	while (!stop)
	{
		cout << "---------------------------\nMenu:\n1.Show all abonents\n2.Find abonent\n3.Input number and dialog time(seconds)\n4.Exit" << "\n";
		std::getline(std::cin, in);
		if (in.compare("1") == 0) {
			tree->walk();
		}
		else if (in.compare("2") == 0) {
			cout << "Input number or name:\n";
			std::getline(std::cin, in);
			node *n = tree->search(in);
			if (n == nullptr) {
				cout << "Nothing found!\n";
			}
			else {
				cout << n->data.name << " | " << n->data.number << "\n";
			}
		}
		else if (in.compare("3") == 0) {
			cout << "Input number:\n";
			std::getline(std::cin, in);
			node *n = tree->search(in);

			if (n == nullptr) {
				cout << "Abonent number not found!\n";
				continue;
			}
			cout << "Input dialog time in seconds:\n";
			std::getline(std::cin, in);

			try
			{
				time = std::stoi(in);
			}
			catch (const std::exception&)
			{
				cout << "Wrong number!\n";
				continue;
			}
			if (time <= 0) {
				cout << "Wrong number!\n";
				continue;
			}
			cout << "Input price per minute:\n";
			std::getline(std::cin, in);
			try
			{
				price = std::stoi(in);
			}
			catch (const std::exception&)
			{
				cout << "Wrong number!\n";
				continue;
			}
			if (price <= 0) {
				cout << "Wrong number!\n";
				continue;
			}
			int add = 0;
			if (time % 60 > 0)
				++add;
			cout << "--------------------\n"
				<< "Name: " << n->data.name << "\n"
				<< "Number: " << n->data.number << "\n"
				<< "Dialog time: " << time / 60 << "m " << time % 60 << "s\n"
				<< "Price: " << time / 60 * price + add * price << " rubles\n"; 
		}
		else if (in.compare("4") == 0) {
			break;
		}
	}

	return 0;
}

