#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Monastery
{
private:
	std::string name;
	char school;
	unsigned int monkCount;
	float landArea;

public:
	void set(const std::string &name, char school, unsigned int monkCount, float landArea)
	{
		this->name = name;
		this->school = school;
		this->monkCount = monkCount;
		this->landArea = landArea;
	}

	void show() const
	{
		std::cout << std::setw(20) << std::left << name
							<< " | " << school
							<< " | " << monkCount
							<< " | " << std::fixed << std::setprecision(1) << landArea << " |\n";
	}
};

void inputMonastery(Monastery &monastery)
{
	std::string name;
	char school;
	unsigned int monkCount;
	float landArea;

	std::cout << "Введіть назву монастиря: ";
	std::getline(std::cin >> std::ws, name);
	std::cout << "Введіть школу (T, C, D): ";
	std::cin >> school;

	while (school != 'T' && school != 'C' && school != 'D')
	{
		std::cout << "Неправильний ввід! Спробуйте ще раз (T, C, D): ";
		std::cin >> school;
	}

	std::cout << "Введіть кількість монахів: ";
	std::cin >> monkCount;
	std::cout << "Введіть площу землі (га): ";
	std::cin >> landArea;

	monastery.set(name, school, monkCount, landArea);
}

int main()
{
	std::vector<Monastery> monasteries;
	const int N = 3;

	for (int i = 0; i < N; ++i)
	{
		Monastery monastery;
		inputMonastery(monastery);
		std::cout << "\n";
		monasteries.push_back(monastery);
	}

	std::cout << "---------------------------------------------------------\n";
	std::cout << "| Буддійські монастирі Японії періоду Нара               |\n";
	std::cout << "|-------------------------------------------------------|\n";
	std::cout << "| Назва               | Школа | Кількість | Площа землі |\n";
	std::cout << "|---------------------|-------|-----------|-------------|\n";

	for (const auto &monastery : monasteries)
	{
		monastery.show();
	}

	std::cout << "|-------------------------------------------------------|\n";
	std::cout << "| Примітка: T - Тэндай; C - Сингон; D - Дзедзицу       |\n";
	std::cout << "---------------------------------------------------------\n";

	return 0;
}
