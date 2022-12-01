// Name: ABHISHEK KUMAR SINGH
// Seneca Student ID: 133410209
// Seneca email: aksingh25@myseneca.ca
// Date of completion: 03-12-2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
namespace sdds {
	class LineManager {
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;
	public:
		LineManager();
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		LineManager(const LineManager& co) = delete;
		LineManager& operator=(const LineManager& co) = delete;
		LineManager(LineManager&& co) noexcept = delete;
		LineManager& operator=(LineManager&& co) noexcept = delete;
		~LineManager() {}
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif //! LINEMANAGER_H