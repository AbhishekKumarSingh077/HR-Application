// Name: ABHISHEK KUMAR SINGH
// Seneca Student ID: 133410209
// Seneca email: aksingh25@myseneca.ca
// Date of completion: 03-12-2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iostream>
#include "Workstation.h"
#include "LineManager.h"
#include "Utilities.h"

namespace sdds {
	LineManager::LineManager()
	{
		m_cntCustomerOrder = 0;
		m_firstStation = nullptr;
	}
	LineManager::LineManager(const std::string & file, const std::vector<Workstation*> & stations)
	{
		try {
			m_cntCustomerOrder = pending.size();
			m_firstStation = nullptr;

			std::fstream readFile(file);
			if (!readFile) throw("");

			std::string sterm;
			Utilities val;
			while (std::getline(readFile, sterm)) {
				size_t succeed = 0;
				bool xtra;
				std::string initial, upcoming;

				initial = val.extractToken(sterm, succeed, xtra);
				if (xtra) upcoming = val.extractToken(sterm, succeed, xtra);

				std::for_each(stations.begin(), stations.end(), [&](Workstation* station) {
					if (station->getItemName() == initial) {

						std::for_each(stations.begin(), stations.end(), [&](Workstation* upcomStat) {
							if (upcomStat->getItemName() == upcoming) {
								station->setNextStation(upcomStat);
							}
							});
						activeLine.push_back(station);
					}
					});

				m_firstStation = activeLine.front();
			}
		}
		catch (...) {
			throw std::string("There an error occured during the loading of Line Manager.");
		}
	}
	void LineManager::linkStations()
	{
		std::vector<Workstation*> arranged{ m_firstStation };
		size_t k = 0;

		std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* prevalent) {
			std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* upcoming) {
				if (arranged[k]->getNextStation()) 
					if (arranged[k]->getNextStation()->getItemName() == upcoming->getItemName()) {
						arranged.push_back(upcoming);
						k++;
					}
			});
		});

		activeLine = arranged;
	}
	bool LineManager::run(std::ostream& os)
	{
		static size_t n_Repeat = 0;
		size_t totalCompleted_ord = completed.size() + incomplete.size();

		os << "Line Manager Iteration: " << ++n_Repeat << std::endl;
		if (!pending.empty()) {
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}

		std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* ws) {
			ws->fill(os);
		});

		std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* ws) {
			ws->attemptToMoveOrder();
		});

		m_cntCustomerOrder -= ((completed.size() + incomplete.size()) - totalCompleted_ord);
		return m_cntCustomerOrder <= 0;
	}
	void LineManager::display(std::ostream& os) const
	{
		std::for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* ws) { ws->display(os); });
	}
}
