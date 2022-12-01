// Name: ABHISHEK KUMAR SINGH
// Seneca Student ID: 133410209
// Seneca email: aksingh25@myseneca.ca
// Date of completion: 03-12-2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>
namespace sdds {
	class Utilities {
		size_t m_widthField;
		static char m_delimiter;
	public:
		Utilities();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif // !UTILITIES_H
