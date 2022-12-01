// Name: ABHISHEK KUMAR SINGH
// Seneca Student ID: 133410209
// Seneca email: aksingh25@myseneca.ca
// Date of completion: 03-12-2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H
#include <string>
namespace sdds {
	class Station {
		int stat_id;
		std::string stat_itemName;
		std::string stat_description;
		size_t nxtItem_sNumber;
		size_t nItems_stock;
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station();
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !STATION_H
