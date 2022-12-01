// Name: ABHISHEK KUMAR SINGH
// Seneca Student ID: 133410209
// Seneca email: aksingh25@myseneca.ca
// Date of completion: 03-12-2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {

	size_t CustomerOrder::m_widthField;

	CustomerOrder::CustomerOrder()
	{
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
	CustomerOrder::CustomerOrder(const std::string zstr)
	{
		Utilities val;
		size_t orig_item, succeed = 0;
		bool supple = true;
		std::string n_perma;

		m_name = val.extractToken(zstr, succeed, supple);
		m_product = val.extractToken(zstr, succeed, supple);
		
	
		orig_item = succeed;
		m_cntItem = 0;
		while (supple) {
			val.extractToken(zstr, succeed, supple);
			m_cntItem++;
		}

		m_lstItem = new Item * [m_cntItem];
		supple = true;
		for (size_t z = 0; z < m_cntItem; z++) {
			m_lstItem[z] = new Item(val.extractToken(zstr, orig_item, supple));
		}

		if (m_widthField < val.getFieldWidth()) m_widthField = val.getFieldWidth();
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& cuo) noexcept
	{
		if (this != &cuo) {
	
			m_name = std::move(cuo.m_name);
			m_product = std::move(cuo.m_product);
			m_cntItem = std::move(cuo.m_cntItem);
			m_lstItem = std::move(cuo.m_lstItem);

			cuo.m_name = "";
			cuo.m_product = "";
			cuo.m_cntItem = 0;
			cuo.m_lstItem = nullptr;
		}
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& cuo) noexcept
	{
		if (this != &cuo) {
			if (m_lstItem) {
				for (size_t k = 0; k < m_cntItem; k++) {
					delete m_lstItem[k];
				}
				delete[] m_lstItem;
			}

			m_name = std::move(cuo.m_name);
			m_product = std::move(cuo.m_product);
			m_cntItem = std::move(cuo.m_cntItem);
			m_lstItem = std::move(cuo.m_lstItem);

			cuo.m_name = "";
			cuo.m_product = "";
			cuo.m_cntItem = 0;
			cuo.m_lstItem = nullptr;
		}

		return *this;
	}
	CustomerOrder::~CustomerOrder()
	{
		for (size_t z = 0; z < m_cntItem; z++) {
			delete m_lstItem[z];
		}
		delete[] m_lstItem;
	}
	bool CustomerOrder::isFilled() const
	{
		bool infuse = true;
		std::for_each(m_lstItem, (m_lstItem + m_cntItem), [&infuse](const Item* item) {
			if (!item->m_isFilled) infuse =  false;
		});
		return infuse;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool infuse = true;
		std::for_each(m_lstItem, (m_lstItem + m_cntItem), [itemName, &infuse](const Item* item) {
			if (item->m_itemName == itemName && !item->m_isFilled) infuse = false;
		});
		return infuse;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		std::for_each(m_lstItem, (m_lstItem + m_cntItem), [&](Item* &item) {
			if (item->m_itemName == station.getItemName()) {
				if (station.getQuantity() >= 1) {
					station.updateQuantity();
					item->m_serialNumber = station.getNextSerialNumber();
					item->m_isFilled = true;

					os << "    Filled " << m_name << ", " << m_product << " [" << item->m_itemName << "]" << std::endl;
				}
				else os << "    Unable to fill " << m_name << ", " << m_product << " [" << item->m_itemName << "]" << std::endl;
			}
		});
	}
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;

		std::for_each(m_lstItem, (m_lstItem + m_cntItem), [&os](const Item* item) {
			os << "[" << std::setw(6) << std::right << std::setfill('0') << item->m_serialNumber << "] "
				<< std::setw(m_widthField) << std::left << std::setfill(' ') << item->m_itemName << " - "
				<< (item->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		});
	}
}
