#include<iostream>
#include<map>
#include<list>
#include<vector>
using namespace std;


class Penalty {
	size_t id;
	string text;
	size_t penalty_point;
	size_t amount_of_penalty;
	string date_of_penalty;
	string police_name;
	string police_surname;
public:
	static size_t ID;
	Penalty() :id(), penalty_point(), date_of_penalty(), amount_of_penalty(), text(), police_name(), police_surname() {}

	Penalty(const string& text, const size_t& penalty_point, const size_t& amount_of_penalty, const string& date_of_penalty, const string& police_name, const string& police_surname)
	{
		this->id = ++ID;
		this->penalty_point = penalty_point;
		this->date_of_penalty = date_of_penalty;
		this->amount_of_penalty = amount_of_penalty;
		this->text = text;
		this->police_name = police_name;
		this->police_surname = police_surname;
	}

	void showPenalty() {
		cout << ">>>>> Penalty " << this->id << " info <<<<<" << endl;
		cout << "Penalty text: " << this->text << endl;
		cout << "Penalty point: " << this->penalty_point << endl;
		cout << "Penalty amount: " << this->amount_of_penalty<<" manat" << endl;
		cout << "Penalty date: " << this->date_of_penalty << endl;
		cout << "Police name,surname: " << this->police_name << " " << police_surname << endl << endl;
	}
};

size_t Penalty::ID = 0;

class Car {
	map<string, list<Penalty>> carPenalties;
public:
	void printPenaltyList() {
		for (auto& carPenalty : carPenalties)
		{
			cout << "Car number: " << carPenalty.first << endl;
			cout << "Penalties" << endl;
			for (auto& i : carPenalty.second)
			{
				i.showPenalty();
			}
			cout << endl;
		}
	}

	void addPenalty(string carNo, list<Penalty> penalty) {
		carPenalties.insert({ carNo,penalty });
	}
};

class YPX {
	list<list<Penalty>> allPenalties;
public:
	auto& getAllPenalties() {
		return allPenalties;
	}

	void showAllPenalty() {
		for (auto& penalty : allPenalties)
		{
			for (auto& i : penalty)
			{
				i.showPenalty();
			}
		}
	}
};

void main() {
	YPX ypx;
	Penalty c1p1("Qirmizi isiqda kecme emeliyyati", 3, 60, "25.05.2021", "Imran", "Eliyev");
	Penalty c1p2("Kemerin taxilmamasi", 0, 40, "12.04.2021", "Rasim", "Memmedov");
	list<Penalty> c1p;
	c1p.push_back(c1p1);
	c1p.push_back(c1p2);

	Penalty c2p1("Suret heddi asma 41-60 km/saat", 3, 150, "04.03.2021", "Perviz", "Isayev");
	list<Penalty> c2p;
	c2p.push_back(c2p1);


	Car c1;
	c1.addPenalty("90 ON 805", c1p);
	c1.printPenaltyList();

	Car c2;
	c2.addPenalty("90 ZZ 403", c2p);
	//c2.printPenaltyList();

	ypx.getAllPenalties().push_back(c1p);
	ypx.getAllPenalties().push_back(c2p);
	//ypx.showAllPenalty();

}