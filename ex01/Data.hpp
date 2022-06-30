#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>
#include <ostream>
#include <string>

class Data
{
public:

	Data(void);
	Data(const Data& other);
	Data(size_t id, std::string name);
	~Data(void);

	Data & operator=(const Data& other);

	size_t		getId(void) const;
	std::string	getName(void) const;

private:

	size_t		m_id;
	std::string	m_name;

};

std::ostream & operator<<(std::ostream& os, const Data& data);

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
