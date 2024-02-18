#pragma once

#ifndef ALL_CLASSES_HPP
#define ALL_CLASSES_HPP

#include <iostream>

////////	Human	////////////////////////////

class Human {
public:
	// конструктор по умолчанию
	Human() :name_{}, surname_{}, gender_{}, family_status_{}, age_{} {};
	
	// конструктор с параметрами
	Human(std::string nam, std::string surn, std::string gender, std::string fam_st, int age) :
			name_(nam),surname_(surn),gender_(gender),family_status_(fam_st),age_(age){};

	// конструктор копирования
	Human(Human& h_obj);

	// сетеры
	void setName(std::string name); 

	void setSurName(std::string surname); 

	void setFam_Status(std::string f_status);

	void setGender(std::string gender); 

	void setAge(int age);

	// геттеры
	std::string getName();

	std::string getSurName();

	std::string getFam_Status();

	std::string getGender();

	int getAge();

private:
	std::string name_;			// имя
	std::string surname_;		// фамилия
	std::string gender_;		// пол
	std::string family_status_;	// семейное положение 
	int age_;					// возраст
};

//////////   Flat   /////////////////////////////////////////

class Flat {
public:
	// конструктор по умолчанию
	Flat() :phum_{}, size_{}, area_{}, numb_rooms_{}, flat_numb_{}, floor_{} {};

	// конструктор копирования
	Flat(Flat& flt); 

	// конструктор с параметрами
	Flat(Human* phm, int size, float area, int n_rooms, int flat, int floor);

	// оператор присваивания копированием
	Flat& operator=(const Flat& other);

	// сеттеры
	void setHuman(Human* phm, int size);

	void setArea(float area);

	void setRooms(int n_rooms);

	void setFlatN(int flat);

	void setFloor(int floor);

	// геттеры
	// получить конкретного человека в квартире
	Human getHuman(int index);

	int getSize();

	float getArea();

	int getRooms();

	int getFlatN();

	int getFloor(); 

	// метод добавления человека в квартиру
	// если квартира существует, т.е. заполнены поля все кроме phum_ и size_
	void addHuman(const Human& hm);

	// метод удаления человека из квартиры
	void deleteHuman(int index);

	// добавление информации о квартире, в том числе и список жильцов квартиры
	void addFlat(Human* hm,int size, float area, int n_rooms, int flat, int floor);

	// деструктор
	~Flat();

private:
	Human* phum_;			// человек
	int size_;				// количество человек в квартире
	float area_;			// площадь квартиры
	int numb_rooms_;		// количество комнат
	int flat_numb_;			// номер квартиры
	int floor_;				// этаж
};


//////////////   House    //////////////////////////////////

class House {
public:
	// конструктор по умолчанию
	House() :fl_{}, house_numb_{}, full_flat_{}, size_{} {}

	// конструктор с параметром задающий количество квартир в доме и номер дома (по умолчанию номер дома 1)
	House(int flat_numbers, int num);

	// конструктор копирования, копирует количество квартир
	House(const House& other);

	// деструктор
	~House();



	// геттеры и сеттеры полей класса
	int House_numb()const;

	void House_numb(int number);

	int size() const;

	void size(int size);

	Flat get_Flat(int index);


	int Free_flat()const;

	// добавление заполненой квартиры в дом
	void add_flat(const Flat& flt);

	// добавление человека в квартиру, по индексу квартиры, расположению в массиве
	void add_human(const Human& hmn, int index);

	// удаление человека из квартиры номер: flat_number 
	void delete_human(int flat_number, int index);


private:
	Flat* fl_;				// квартиры в доме
	int house_numb_;		// номер дома
	int full_flat_;			// количество заполненых квартир
	int size_;				// количество квартир в доме
	
};


#endif // ALL_CLASSES_HPP