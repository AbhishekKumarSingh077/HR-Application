// Name: ABHISHEK KUMAR SINGH
// Seneca Student ID: 133410209
// Seneca email: aksingh25@myseneca.ca
// Date of completion: 03-12-2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds {
	size_t Station::m_widthField;
	size_t Station::id_generator;

	Station::Station()
	{
		stat_id = 0;
		stat_itemName = "";
		stat_description = "";
		nxtItem_sNumber = 0;
		nItems_stock = 0;
	}
	Station::Station(const std::string& str)
	{
		Utilities bnft;
		size_t next_pos = 0;
		bool more = true;

		stat_itemName = bnft.extractToken(str, next_pos, more);
		nxtItem_sNumber = stoi(bnft.extractToken(str, next_pos, more));
		nItems_stock = stoi(bnft.extractToken(str, next_pos, more));

		if (m_widthField < bnft.getFieldWidth()) m_widthField = bnft.getFieldWidth();

		stat_description = bnft.extractToken(str, next_pos, more);

		stat_id = ++id_generator;
	}
	const std::string& Station::getItemName() const
	{
		return stat_itemName;
	}
	size_t Station::getNextSerialNumber()
	{
		nxtItem_sNumber++;
		return nxtItem_sNumber - 1;
	}
	size_t Station::getQuantity() const
	{
		return nItems_stock;
	}
	void Station::updateQuantity()
	{
		if (nItems_stock > 0) nItems_stock--;
	}
	void Station::display(std::ostream& os, bool full) const
	{
		if (!full) {
			os << "[" << std::setw(3) << std::setfill('0') << std::right << stat_id << "] Item: " 
			   << std::setw(m_widthField) << std::setfill(' ') << std::left << stat_itemName 
			   << " [" << std::setw(6) << std::setfill('0') << std::right << nxtItem_sNumber << "]" << std::endl;
		} 
		else {
			os << "[" << std::setw(3) << std::setfill('0') << std::right << stat_id << "] Item: " 
			   << std::setw(m_widthField) << std::setfill(' ') << std::left << stat_itemName 
			   << " [" << std::setw(6) << std::setfill('0') << std::right << nxtItem_sNumber << "] Quantity: " 
			   << std::setw(m_widthField) << std::setfill(' ') << std::left << nItems_stock << " Description: " 
			   << stat_description << std::endl;
		}
	}
}