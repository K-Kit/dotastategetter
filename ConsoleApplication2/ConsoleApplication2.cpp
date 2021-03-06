// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//#include <obs.h>
//#include <obs-module.h>
//#include <obs-frontend-api.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
std::string path = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\dota 2 beta\\game\\dota\\console.log";
std::vector<std::string> lines_in_order;
size_t vsize;
size_t start;
string getlateststate(std::vector<std::string> logfile);
int getstate();
int main()
{
	while (1 > 0) {
		cout << getstate();
	}
}
//TODO add check for changegamestateui dashboard from vsize-x to max
string getlateststate(std::vector<std::string> logfile) {
	vsize = logfile.size();
	while (vsize > 0) {
	std:string cur = lines_in_order[vsize];
		std::string key("Gamerules");
		std::size_t found = cur.rfind(key);
		std::size_t founds = cur.rfind(" ");
		if (found != std::string::npos)
			return cur.substr(founds);
		vsize = vsize - 1;
		
	}
	return "nofind";
}

int getstate() {
	std::ifstream input(path);

	std::string line;
	while (std::getline(input, line))
	{
		lines_in_order.push_back(line);
	}

	std::string latest = getlateststate(lines_in_order);
	// space plus single tic quote around state for now because lazy switch to substr(2, max-1) later
	if (latest == " 'DOTA_GAMERULES_STATE_INIT'")
		return 0;
	if (latest == " 'DOTA_GAMERULES_STATE_WAIT_FOR_PLAYERS_TO_LOAD'")
		return 1;
	if (latest == " 'DOTA_GAMERULES_STATE_CUSTOM_GAME_SETUP'")
		return 2;
	if (latest == " 'DOTA_GAMERULES_STATE_HERO_SELECTION'")
		return 1;
	if (latest == " 'DOTA_GAMERULES_STATE_STRATEGY_TIME'")
		return 3;
	if (latest == " 'DOTA_GAMERULES_STATE_TEAM_SHOWCASE'")
		return 4;
	if (latest == " 'DOTA_GAMERULES_STATE_PRE_GAME'")
		return 5;
	if (latest == " 'DOTA_GAMERULES_STATE_GAME_IN_PROGRESS'")
		return 6;
	if (latest == " 'DOTA_GAMERULES_STATE_POST_GAME'")
		return 7;
	if (latest == " 'DOTA_GAMERULES_STATE_DISCONNECT'")
		return 8;
	return 9;
}