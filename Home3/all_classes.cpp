//all_classes.hpp

#include "all_classes.hpp"

//==================================================

Human::Human(Human& h_obj) {
	name_ = h_obj.name_;
	surname_ = h_obj.surname_;
	gender_ = h_obj.gender_;
	family_status_ = h_obj.family_status_;
	age_ = h_obj.age_;
}


//===================================================

void Human::setName(std::string name)
{
	name_ = name;
}

//===================================================

void Human::setSurName(std::string surname)
{
	surname_ = surname;
}


//===================================================

void Human::setFam_Status(std::string f_status)
{
	family_status_ = f_status;
}

//===================================================

void Human::setGender(std::string gender)
{
	gender_ = gender;
}


//===================================================

void Human::setAge(int age)
{
	age_ = age;
}


//===================================================

std::string Human::getName()
{
	return name_;
}

//===================================================

std::string Human::getSurName()
{
	return surname_;
}

//===================================================

std::string Human::getFam_Status() {
	return family_status_;
}

//===================================================

std::string Human::getGender()
{
	
	return gender_;
}


//===================================================

int Human::getAge() {
	return age_;
}

//=====================================================================
//======================        Flat      =============================
//=====================================================================



Flat::Flat(Human* phm, int size, float area, int n_rooms, int flat, int floor) {
	if (phm == nullptr && size > 0) {
		throw (std::exception("Error: pointer is NULL"));
	}

	numb_rooms_ = n_rooms;
	area_ = area;
	flat_numb_ = flat;
	floor_ = floor;
	size_ = size;
	phum_ = new Human[size_];
	for (int i = 0; i < size_; i++) {
		phum_[i].setName(phm[i].getName());
		phum_[i].setSurName(phm[i].getSurName());
		phum_[i].setGender(phm[i].getGender());
		phum_[i].setFam_Status(phm[i].getFam_Status());
		phum_[i].setAge(phm[i].getAge());

	}

}

//================================================================
// сеттеры
void Flat::setHum(Human* phm, int size) {
	if (phm == nullptr || size > 0) {
		throw (std::exception("Error: Pointer is NULL"));
	}

	size_ = size;
	phum_ = new Human[size_];
	for (int i = 0; i < size_; i++) {
		phum_[i] = phm[i];
	}
}

//=================================================================

void Flat::setArea(float area) {
	area_ = area;
}

//=================================================================


void Flat::setRooms(int n_rooms) {
	numb_rooms_ = n_rooms;
}

//=================================================================

void Flat::setFlatN(int flat) {
	flat_numb_ = flat;
}

//=================================================================

void Flat::setFloor(int floor) {
	floor_ = floor;
}

//=================================================================

// геттеры
// получить конкретного человека в квартире
Human* Flat::getHum(int index) {
	if (index - 1 > size_) {
		throw std::exception("Error: The flat is consist of fewer numbers of human");
	}
	if (!size_) {
		throw std::exception("Error: The flat is empty.\n");
	}
	Human tmp;
	tmp = phum_[index - 1];
	return &tmp;
}

//=================================================================

int Flat::getSize() {
	return size_;
}

//=================================================================

float Flat::getArea() {
	return area_;
}

//=================================================================

int Flat::getRooms() {
	return numb_rooms_;
}

//=================================================================

int Flat::getFlatN() {
	return flat_numb_;
}

//=================================================================

int Flat::getFloor() {
	return floor_;
}

//=================================================================

void Flat::AddHuman(Human& hm) {
	size_ += 1;
	Human* tmp = new Human[size_];
	for (int i = 0; i < size_ - 1; i++) {
		tmp[i] = phum_[i];
	}
	tmp[size_ - 1] = hm;
	phum_ = tmp;
	tmp = nullptr;
}

//=================================================================

void Flat::DeleteHuman(int index) {
	if (index - 1 > size_) {
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

//=================================================================

Flat::~Flat() {
	delete[] phum_;
	size_ = 0;
	phum_ = nullptr;
}

//=============================================================================
//=================================  House  ===================================
//=============================================================================

House::House(int flat_numbers, int num = 1) :fl_{}, house_numb_{ num }, free_flat_{}, size_{ flat_numbers } {
	free_flat_ = size_;
	fl_ = new Flat[size_]{};
}

// деструктор
House::~House() {
	delete[] fl_;
	size_ = 0;
	free_flat_ = 0;
	house_numb_ = 0;
}



// геттеры и сеттеры полей класса
int House::House_numb()const {
	return house_numb_;
}

void House::House_numb(int number) {
	house_numb_ = number;
}

int House::size() const {
	return size_;
}

void House::size(int size) {
	size_ = size;
}


int House::Free_flat()const {
	return free_flat_;
}

// добавление заполненой квартиры в дом
void House::add_flat(const Flat& flt) {

}




