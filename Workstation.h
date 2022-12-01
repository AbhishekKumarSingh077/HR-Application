// Name: ABHISHEK KUMAR SINGH
// Seneca Student ID: 133410209
// Seneca email: aksingh25@myseneca.ca
// Date of completion: 03-12-2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

extern std::deque<sdds::CustomerOrder> pending;
extern std::deque<sdds::CustomerOrder> completed;
extern std::deque<sdds::CustomerOrder> incomplete;

namespace sdds {
	class Workstation : public Station {
		std::deque<CustomerOrder> m_orders{};
		Workstation *m_pNextStation;
	public:
		Workstation();
		Workstation(const std::string zxtr);
		Workstation(const Workstation& co) = delete;
		Workstation& operator=(const Workstation& co) = delete;
		Workstation(Workstation&& co) noexcept = delete;
		Workstation& operator=(Workstation&& co) noexcept = delete;
		~Workstation() {} 
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif //! WORKSTATION_H