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



Flat::Flat(Flat& flt):Flat(flt.phum_,flt.size_,flt.area_,flt.numb_rooms_,flt.flat_numb_,flt.floor_){ }

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

Flat& Flat::operator=(const Flat& other)
{
	
	numb_rooms_ = other.numb_rooms_;
	area_ = other.area_;
	flat_numb_ = other.flat_numb_;
	floor_ = other.floor_;
	size_ = other.size_;
	phum_ = new Human[size_];
	for (int i = 0; i < size_; i++) {
		phum_[i].setName(other.phum_[i].getName());
		phum_[i].setSurName(other.phum_[i].getSurName());
		phum_[i].setGender(other.phum_[i].getGender());
		phum_[i].setFam_Status(other.phum_[i].getFam_Status());
		phum_[i].setAge(other.phum_[i].getAge());
	}

	return *this;
	// TODO: insert return statement here
}

//================================================================
// сеттеры
void Flat::setHuman(Human* phm, int size) {
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
Human Flat::getHuman(int index) {
	if (index - 1 > size_) {
		throw std::exception("Error: The flat is consist of fewer numbers of human");
	}
	if (!size_) {
		throw std::exception("Error: The flat is empty.\n");
	}

	return phum_[index - 1];
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

void Flat::addHuman(const Human& hm) {
	if (numb_rooms_ != 0 && flat_numb_ != 0 && flat_numb_ != 0 && floor_ != 0) {
		size_ += 1;
		Human* tmp = new Human[size_];
		for (int i = 0; i < size_ - 1; i++) {
			tmp[i] = phum_[i];
		}
		tmp[size_ - 1] = hm;
		delete[] phum_;
		phum_ = tmp;
		return;
	}
	throw - 1;
	
}

//=================================================================

void Flat::deleteHuman(int index) {
	if (index - 1 > size_) {
		throw std::exception("Error: The flat is consist of fewer numbers of human");
	}
	 
	int indx = 0;
	size_ -= 1;
	Human*  tmp = new Human[size_];
	for (int i = 0; i < size_ + 1; i++) {
		if (i != index - 1) {
			tmp[indx] = phum_[i];
			indx += 1;
		}
	}
	delete[] phum_;
	phum_ = tmp;
}



//===========================================================================
void Flat::addFlat(Human* phm, int size, float area, int n_rooms, int flat, int floor)
{
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

//=================================================================

Flat::~Flat() {
	delete[] phum_;
	size_ = 0;
	phum_ = nullptr;
}

//=============================================================================
//=================================  House  ===================================
//=============================================================================

House::House(int flat_numbers, int num) :fl_{}, house_numb_{ num }, full_flat_{ 0 }, size_{ flat_numbers } {
	fl_ = new Flat[size_]{};
}

// деструктор
House::~House() {
	delete[] fl_;
	size_ = 0;
	full_flat_ = 0;
	house_numb_ = 0;
}



House::House(const House& other) :fl_{}, house_numb_{}, full_flat_{}, size_{}
{
	fl_ = new Flat[other.size_]{};
	size_ = other.size_;
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
	if (size_ == 0) {
		fl_ = new Flat[size]{};
		size_ = size;
	}
	else {
		throw std::exception("Error: House has a flat alrady.\n");
	}
	
}

Flat House::get_Flat(int index)
{
	return fl_[index - 1];
}


int House::Free_flat()const {
	return size_ - full_flat_;
}

// добавление заполненой квартиры в дом
void House::add_flat(const Flat& flt) {
	fl_[full_flat_] = flt;
	full_flat_ += 1;
}


//====================================================================

void House::add_human(const Human& hmn, int index)
{
	if (0 <= index && index < size_) {
		fl_[index].addHuman(hmn);
		return;
	}
	throw - 1;
}

//=====================================================================
void House::delete_human(int flat_number, int index)
{
	for (int i = 0; i < size_; ++i) {
		if (fl_[i].getFlatN() == flat_number) {
			fl_[i].deleteHuman(index);
		}
	}
}




