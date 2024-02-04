#pragma once

#ifndef ALL_CLASSES_HPP
#define ALL_CLASSES_HPP

#include <string>

class Human {
public:
	// конструктор по умолчанию
	Human() :name_{}, surname_{}, gender_{}, family_status_{}, age_{} {};
	
	// конструктор с параметрами
	Human(std::string nam, std::string surn, std::string gender, std::string fam_st, int age) :
			name_(nam),surname_(surn),gender_(gender),family_status_(fam_st),age_(age){};

	// конструктор копирования
	Human(Human& h_obj) {
		name_ = h_obj.name_;
		surname_ = h_obj.surname_;
		gender_ = h_obj.gender_;
		family_status_ = h_obj.family_status_;
		age_ = h_obj.age_;
	}
	// сетеры
	void setName(std::string name) {
		name_ = name;
	}

	void setSurName(std::string surname) {
		surname_ = surname;
	}

	void setFam_Status(std::string f_status) {
		family_status_ = f_status;
	}

	void setGender(std::string gender) {
		gender_ = gender;
	}

	void setAge(int age) {
		age_ = age;
	}

	// геттеры
	std::string getName() {
		return name_;
	}

	std::string getSurName() {
		return surname_;
	}

	std::string getFam_Status() {
		return family_status_;
	}

	std::string getGender(){
		return gender_;
	}

	int getAge() {
		return age_;
	}

private:
	std::string name_;			// имя
	std::string surname_;		// фамилия
	std::string gender_;		// пол
	std::string family_status_;	// семейное положение
	int age_;					// возраст
};

class Flat {
public:
	// конструктор по умолчанию
	Flat() :phum_(nullptr), size_(0), area_{}, numb_rooms_(0),flat_numb_(0) {};

	// конструктор копирования
	Flat(Flat& flt) {
		Flat(flt.phum_, flt.size_, flt.area_, flt.numb_rooms_,flt.flat_numb_);
	}

	// конструктор с параметрами
	Flat(Human* phm, int size, float area, int n_rooms, int flat) {
		if (phm == nullptr || size == 0) {
			throw (std::exception("Error: Human is not exist"));
		}
		numb_rooms_ = n_rooms;
		area_ = area;
		flat_numb_ = flat;
		size_ = size;
		phum_ = new Human[size_];
		for (int i = 0; i < size_; i++)
			phum_[i] = phm[i];
	}

	// сеттеры
	void setHum(Human* phm, int size) {
		if (phm == nullptr || size == 0) {
			throw (std::exception("Error: Human is not exist"));
		}

		size_ = size;
		phum_ = new Human[size_];
		for (int i = 0; i < size_; i++) {
			phum_[i] = phm[i];
		}
	}

	void setArea(float area) {
		area_ = area;
	}

	void setRooms(int n_rooms) {
		numb_rooms_ = n_rooms;
	}

	void setFlatN(int flat) {
		flat_numb_ = flat;
	}

	// геттеры
	// получить конкретного человека в квартире
	Human* getHum(int index) {
		if (index > size_) {
			throw std::exception("Error: The flat is consist of fewer numbers of human");
		}
		Human tmp;
		tmp = phum_[index - 1];
		return &tmp;
	}

	int getSize() {
		return size_;
	}

	float getArea() {
		return area_;
	}

	int getRooms() {
		return numb_rooms_;
	}

	int getFlatN() {
		return flat_numb_;
	}

	// метод добавления человека в квартиру
	void AddHuman(Human& hm) {
		Human* tmp = nullptr;
		size_ += 1;
		tmp = new Human[size_];
		for (int i = 0; i < size_ - 1; i++) {
			tmp[i] = phum_[i];
		}
		tmp[size_ - 1] = hm;
		phum_ = tmp;
		tmp = nullptr;
	}

	// метод удаления человека из квартиры
	void DeleteHuman(int index) {
		if (index > size_) {
			throw std::exception("Error: The flat is consist of fewer numbers of human");
		}
		Human* tmp = nullptr;
		int indx = 0;
		size_ -= 1;
		tmp = new Human[size_];
		for (int i = 0; i < size_ + 1; i++) {
			if (i != index) {
				tmp[indx] = phum_[i];
				indx += 1;
			}
		}

		phum_ = tmp;
		tmp = nullptr;
	}

	// деструктор
	~Flat() {
		delete[] phum_;
		size_ = 0;
		phum_ = nullptr;
	}

private:
	Human* phum_;			// человек
	int size_;				// количество человек
	float area_;			// площадь квартиры
	int numb_rooms_;		// количество комнат
	int flat_numb_;			// номер квартиры
};


class House {
public:
	House() :fl_({}), house_numb_(0) {};


private:
	Flat fl_[10];			// квартиры в доме
	int house_numb_;		// номер дома

};






#endif // ALL_CLASSES_HPP