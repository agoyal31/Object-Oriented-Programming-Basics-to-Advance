/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/05/28
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"TennisLog.h"
#include<fstream>
using namespace std;
namespace sdds {
	ostream& operator<<(ostream& os, const TennisMatch& match)
	{
		if (match.m_matchID == 0) {
			os << "Empty Match";
		}
		else {
			//tournamentID
			os.width(20);
			os.setf(ios::right);
			os.fill('.');
			os << "Tourney ID" << " : ";
			os.unsetf(ios::right);
			os.width(30);
			os.setf(ios::left);
			os.fill('.');
			os << match.m_tournamentID <<endl;
			os.unsetf(ios::left);
			//matchID
			os.width(20);
			os.setf(ios::right);
			os.fill('.');
			os << "Match ID" << " : ";
			os.unsetf(ios::right);
			os.width(30);
			os.setf(ios::left);
			os.fill('.');
			os << match.m_matchID << endl;
			os.unsetf(ios::left);
			//tournamentName
			os.width(20);
			os.setf(ios::right);
			os.fill('.');
			os << "Tourney" << " : ";
			os.unsetf(ios::right);
			os.width(30);
			os.setf(ios::left);
			os.fill('.');
			os << match.m_tournamentName << endl;
			os.unsetf(ios::left);
			//winner
			os.width(20);
			os.setf(ios::right);
			os.fill('.');
			os << "Winner" << " : ";
			os.unsetf(ios::right);
			os.width(30);
			os.setf(ios::left);
			os.fill('.');
			os << match.m_matchWinner << endl;
			os.unsetf(ios::left);
			//loser
			os.width(20);
			os.setf(ios::right);
			os.fill('.');
			os << "Loser" << " : ";
			os.unsetf(ios::right);
			os.width(30);
			os.setf(ios::left);
			os.fill('.');
			os << match.m_matchLoser << endl;
			os.unsetf(ios::left);
		}

		return os;
	}
	TennisLog::TennisLog(const char* f) {
		ifstream fptr(f); //opens file
		if (fptr.is_open()) {
			fptr.ignore(10000, '\n');
			while (!fptr.eof()) {
				fptr.ignore(10000, '\n');
				m_numberOfMatches += 1;
			}
			m_numberOfMatches = m_numberOfMatches - 1;
			match = new TennisMatch[m_numberOfMatches];//delete all the TennisMatch objects created dynamically
			int matchNum = 0; //type of count to count number of matches(counter)//basically to assign every object with the parameters
			fptr.seekg(0, ios::beg);
			fptr.ignore(10000, '\n');

			for (int i = 0; i < m_numberOfMatches;++i) {
				getline(fptr, match[matchNum].m_tournamentID, ',');
				getline(fptr, match[matchNum].m_tournamentName, ',');
				fptr >> match[matchNum].m_matchID;
				fptr.ignore(1);
				getline(fptr, match[matchNum].m_matchWinner, ',');
				getline(fptr, match[matchNum].m_matchLoser, '\n');
				matchNum++;
			}
		}
	}
	void TennisLog::addMatch(const TennisMatch& tm)
	{
		//dynamically resizing an array
		TennisMatch* tempTennisMatch;
		tempTennisMatch = new TennisMatch[m_numberOfMatches];
		for (int i = 0; i < m_numberOfMatches; ++i) { 
			tempTennisMatch[i] = match[i];
		}
		delete[] match;
		m_numberOfMatches++;
		
		match = new TennisMatch[m_numberOfMatches];

		for (int i = 0; i < m_numberOfMatches - 1; ++i) {
			match[i] = tempTennisMatch[i];
		}
		delete[] tempTennisMatch;
		
		match[m_numberOfMatches-1] = tm;
		
		
	}
	TennisLog TennisLog::findMatches(const char* playerName)const
	{
		TennisLog tempObj;
		tempObj.match = new TennisMatch[m_numberOfMatches];//m_numberOfMatches=25001//first line ignored
		for (int i = 0; i < m_numberOfMatches; i++) {
			if (match[i].m_matchWinner == playerName || match[i].m_matchLoser == playerName) {
				tempObj.match[tempObj.m_numberOfMatches] = match[i];
				tempObj.m_numberOfMatches++;
			}
		}
		return tempObj; 
		//passing everything inside tempObj by copy to (suppose 'x' object of TennisLog)
		//TennisLog x = tempObj;
	}
	TennisLog::TennisLog(const TennisLog& tennis)
	{
		*this = tennis;
	}
	TennisLog& TennisLog::operator=(const TennisLog& tennis)
	{
		if (this != &tennis) {
			//shallow copy
			if (tennis.m_numberOfMatches != 0) {
				m_numberOfMatches = tennis.m_numberOfMatches;
				//deep copy
				if (match != nullptr) {
					delete[] match;
					match = nullptr;
				}
				match = new TennisMatch[m_numberOfMatches];
				for (int i = 0; i < m_numberOfMatches; ++i) {
					match[i] = tennis.match[i];
				}
			}

		}
		return *this;
	}
	TennisLog::TennisLog(TennisLog&& tennis)
	{
		operator=(move(tennis));
	}

	TennisLog& TennisLog::operator=(TennisLog&& tennis)
	{
		if (this != &tennis) {
			if (tennis.m_numberOfMatches) {
				//shallow copy
				m_numberOfMatches = tennis.m_numberOfMatches;
				//deep copy
				delete[] this->match;
				match = nullptr;
				match = tennis.match;
				tennis.match = nullptr;
				tennis.m_numberOfMatches = 0;
			}
		}
		return *this;
	}

	TennisLog::~TennisLog()
	{
		if (match != nullptr) {
			delete[] match;
			match = nullptr;
		}
	}
	TennisMatch TennisLog::operator[](const size_t &matchOfTennis)
	{
		if (m_numberOfMatches) {
			return match[matchOfTennis];
		}
		TennisMatch emptyMatch;
		return emptyMatch;
	}
	TennisLog::operator size_t()
	{
		return m_numberOfMatches;
	}
	//ostream& right(ostream& os)
	//{
	//	os.width(20);
	//	os.setf(ios::right);
	//	os.fill('.');
	//	return os;
	//}
	//ostream& left(ostream& os)
	//{
	//	os.width(20);
	//	os.setf(ios::right);
	//	os.fill('.');
	//	return os;
	//}
}


