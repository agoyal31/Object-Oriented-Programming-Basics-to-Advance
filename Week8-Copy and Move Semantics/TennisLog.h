/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/05/28
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_TENNISLOG_H
#define _SDDS_TENNISLOG_H
#include <string>
namespace sdds {
	typedef struct A{ //data about single match b/w two players
		std::string m_tournamentID{};
		std::string m_tournamentName{};
		unsigned int m_matchID{};
		std::string m_matchWinner{};
		std::string m_matchLoser{};
	}TennisMatch;
	std::ostream& operator<<(std::ostream& os, const TennisMatch& match);
	//std::ostream& right(std::ostream& os);
	//std::ostream& left(std::ostream& os);


	class TennisLog { //holds the tennis match dynamically
        int m_numberOfMatches{};
		TennisMatch* match{};
	public:
		TennisLog() = default;
		TennisLog(const char* f);
		void addMatch(const TennisMatch& tm);
		TennisLog findMatches(const char* playerName)const;
		TennisLog(const TennisLog& tennis);
		TennisLog& operator =(const TennisLog & tennis);
		TennisLog(TennisLog&& tennis);
		TennisLog& operator =(TennisLog&& tennis);
		virtual ~TennisLog();
		TennisMatch operator[](const size_t &matchOfTennis);
		 operator size_t();
	};
}
#endif
