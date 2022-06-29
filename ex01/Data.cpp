#include "Data.hpp"

Data::Data(void): m_id(0) {}

Data::Data(const Data& other): m_id(other.m_id), m_name(other.m_name) {}

Data::Data(size_t id, std::string name): m_id(id), m_name(name) {}

Data::~Data(void) {}

Data & Data::operator=(const Data& other)
{
	this->m_id = other.m_id;
	this->m_name = other.m_name;
	return *this;
}

size_t Data::getId(void) const { return m_id; }

std::string Data::getName(void) const { return m_name; }

std::ostream & operator<<(std::ostream& os, const Data& data)
{
	os << "Data("
	<< "id=" << data.getId() << ", "
	<< "name=" << data.getName() << ")"
	<< std::endl;
	return os;
}

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
