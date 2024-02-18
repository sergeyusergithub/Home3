#include "all_classes.hpp"
#include <iostream>


int main() {

	const int h_size = 10;
	Human hm[h_size]{};
	hm[0] = {"Bob","Tompson","Male","Father",35};
	hm[1] = { "Mark","Twen","Male","Son",61 };
	hm[2] = { "Klear","Pops","Female","Mother",40 };
	hm[3] = { "Emely","Casper","Female","Dougther",15 };
	hm[4] = { "Peter","Volos","Male","Son",5 };
	hm[5] = { "Mary","Volos","Female","Mother",24 };
	hm[6] = { "Sofy","Global","Female","Dougther",31 };
	hm[7] = { "Pipe","Global","Male","Father",65 };
	hm[8] = { "Cate","Global","Female","Mother",62 };
	hm[9] = { "Stive","Truth","Male","Son",22 };

	const int fl_size = 10;

	Flat fl[fl_size];

	fl[0].addFlat(& hm[0], 1, 44.5, 2, 1, 1 );
	fl[1].addFlat(& hm[1], 1, 33.5, 1, 2, 1 );
	fl[2].addFlat(& hm[2], 1, 75.5, 3, 3, 1 );
	fl[3].addFlat(& hm[3], 1, 47.5, 2, 4, 2 );
	fl[4].addFlat(& hm[4], 2, 66.5, 2, 5, 2 );
	fl[5].addFlat(& hm[6], 3, 99.5, 4, 6, 2 );
	fl[6].addFlat(& hm[9], 1, 22.5, 1, 7, 3 );
	



	House ho(10,1);

	// заполняем квартиры в доме
	for (int i = 0; i < 7; ++i) {
		ho.add_flat(fl[i]);
	}



	std::cout << "The house has numbers of free flats: " << ho.Free_flat() << std::endl;

	// определим количество жильцов в доме
	int sum{};

	for (int i = 1; i <= ho.size(); ++i) {
		if (ho.get_Flat(i).getSize()) {
			sum += ho.get_Flat(i).getSize();
		}
	}

	std::cout << "All nubmers of human in house number " << ho.House_numb() << " : " << sum << "\n\n";

	// заполнение пустой квартиры, пока без жильцов
	fl[7].addFlat(nullptr, 0, 43.2, 3, 8, 3);

	// создание жильцов
	const int new_hm = 3;
	Human hm1[new_hm];
	hm1[0] = { "Margaret","Pitcher","Female","Mother",23 };
	hm1[1] = { "Djon","Pitcher","Male","Father",29 };
	hm1[2] = { "Stive","Pitcher","Male","Son",2 };

	// Заполнение квартиры жильцами
	for (int i = 0; i < new_hm; ++i) {
		fl[7].addHuman(hm1[i]);

	}
	
	
	std::cout << "Flat number " << fl[7].getFlatN() << " has human: " << std::endl;
	std::cout << "Name is : " << fl[7].getHuman(1).getName() << "and age is: " << fl[7].getHuman(1).getAge() << std::endl;

	// добавление информации о жильцах в дом
	ho.add_flat(fl[7]);

	std::cout << "The house has numbers of free flats: " << ho.Free_flat() << std::endl;

	// имя человека номер 2 в доме в квартире 8 
	std::cout << "The name of human in new house is: " << ho.get_Flat(8).getHuman(2).getName() << "\n\n";

	
	std::cout << "Number of human in " << ho.get_Flat(8).getFlatN() << " flat is : " << ho.get_Flat(8).getSize() << "\n";


	// список жильцов квартиры 8
	for (int i = 1; i <= ho.get_Flat(8).getSize(); ++i) {
		std::cout << ho.get_Flat(8).getHuman(i).getName() <<
			" " << 
			ho.get_Flat(8).getHuman(i).getSurName() <<
			" " <<
			ho.get_Flat(8).getHuman(i).getAge() <<
			"\n";
	}
	std::cout << std::endl;
	// удалим человека из дома и квартиры
	ho.delete_human(ho.get_Flat(8).getFlatN(), 2);

	std::cout << "Number of human in " << ho.get_Flat(8).getFlatN() << " flat is : " << ho.get_Flat(8).getSize() << "\n";


	// список жильцов квартиры 8
	for (int i = 1; i <= ho.get_Flat(8).getSize(); ++i) {
		std::cout << ho.get_Flat(8).getHuman(i).getName() <<
			" " <<
			ho.get_Flat(8).getHuman(i).getSurName() <<
			" " <<
			ho.get_Flat(8).getHuman(i).getAge() <<
			"\n";
	}
	std::cout << std::endl;
	// определим количество жильцов в доме
	sum = {};

	for (int i = 1; i <= ho.size(); ++i) {
		if (ho.get_Flat(i).getSize()) {
			sum += ho.get_Flat(i).getSize();
		}
	}

	std::cout << "All nubmers of human in house number " << ho.House_numb() << " : " << sum << "\n\n";


	// поиск человека в доме по имени
	for (int i = 1; i <= ho.size(); ++i) {
		for (int j = 1; j <= ho.get_Flat(i).getSize(); ++j) {
			if (ho.get_Flat(i).getHuman(j).getName() == "Bob") {
				std::cout << ho.get_Flat(i).getHuman(j).getName() << " live in flat number " << ho.get_Flat(i).getFlatN() << " at floor " << ho.get_Flat(i).getFloor() << "\n\n";
			}
		}
	}


	// поиск человека в доме по имени
	for (int i = 1; i <= ho.size(); ++i) {
		for (int j = 1; j <= ho.get_Flat(i).getSize(); ++j) {
			if (ho.get_Flat(i).getHuman(j).getName() == "Sofy") {
				std::cout << ho.get_Flat(i).getHuman(j).getName() << " live in flat number " << ho.get_Flat(i).getFlatN() << " at floor " << ho.get_Flat(i).getFloor() << "\n\n";
			}
		}
	}





	return 0;
}