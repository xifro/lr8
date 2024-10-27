#include <iostream>
#include <iomanip>
#include <string>
#include <array>

struct Monastery
{
	std::string name;
	char school;
	unsigned short monkCount;
	float landArea;
};

void printRow(const Monastery &monastery)
{
	std::cout << "| " << std::setw(10) << std::left << monastery.name
						<< " |   " << monastery.school << "   |   " << std::setw(7) << monastery.monkCount
						<< "    | " << std::setw(5) << std::fixed << std::setprecision(1) << monastery.landArea << "       |\n";
}

int main()
{
	std::array<Monastery, 3> monasteries;

	for (int i = 0; i < monasteries.size(); ++i)
	{
		std::cout << i + 1 << ". Введіть назву монастиря: ";
		std::cin >> monasteries[i].name;
		std::cout << "   Введіть школу (T, C, D): ";
		std::cin >> monasteries[i].school;
		std::cout << "   Введіть кількість монахів: ";
		std::cin >> monasteries[i].monkCount;
		std::cout << "   Введіть площу землі (га): ";
		std::cin >> monasteries[i].landArea;
		std::cout << "\n";
	}

	std::cout << "-----------------------------------------------\n";
	std::cout << "| Буддійські монастирі Японії періоду Нара      |\n";
	std::cout << "|---------------------------------------------|\n";
	std::cout << "| Назва      | Школа | Кількість | Площа землі |\n";
	std::cout << "|            |       | монахів   | (га)        |\n";
	std::cout << "|------------|-------|-----------|-------------|\n";

	for (const auto &monastery : monasteries)
	{
		printRow(monastery);
	}

	std::cout << "|---------------------------------------------|\n";
	std::cout << "| Примітка: T - Тэндай; C - Сингон;            |\n";
	std::cout << "|           D - Дзедзицу                      |\n";
	std::cout << "-----------------------------------------------\n";

	return 0;
}
