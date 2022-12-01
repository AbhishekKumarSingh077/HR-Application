// Name: ABHISHEK KUMAR SINGH
// Seneca Student ID: 133410209
// Seneca email: aksingh25@myseneca.ca
// Date of completion: 03-12-2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Utilities.h"

namespace sdds {

	char Utilities::m_delimiter;

	Utilities::Utilities()
	{
		m_widthField = 1;
	}
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string sterm;

		if (str[next_pos] == m_delimiter) {
			more = false;
			throw("The Delimiter was not here, it was discovered at some new location");
		}
		else if (str.find(m_delimiter, next_pos) == std::string::npos) {
			sterm = str.substr(next_pos);
			more = false;
			next_pos = 0;
		}
		else {
			sterm = str.substr(next_pos, str.find_first_of(m_delimiter, next_pos) - next_pos);
			more = true;
			next_pos = str.find(m_delimiter, next_pos) + 1; 
		}

		if (m_widthField < sterm.length()) m_widthField = sterm.length();

		return sterm;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}