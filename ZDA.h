/*
 * ZDA.h
 *
 *  Created on: Jul 15, 2024
 *      Author: kusha
 */

#ifndef ZDA_H_
#define ZDA_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
using namespace std;

#include <sstream>
#include <vector>

class ZDA : public NMEASentence {
private:
    string sentenceID;
    string time;
    int day;
    int month;
    int year;
    int localZoneHours;
    int localZoneMinutes;
    string checksum;
    int hr;
    int mn;
    int sc;

public:
    void parse(const string& ZDA) override {

    	vector<string> parsedValues ;
  	   	parsedValues =  subparser (ZDA);

        size_t asteriskPos = parsedValues.back().find('*');
        localZoneMinutes = stoi(parsedValues.back().substr(0, asteriskPos));
        checksum = parsedValues.back().substr(asteriskPos + 1);

        sentenceID = parsedValues[0];
        time = (parsedValues[1]);
        day = stoi(parsedValues[2]);
        month = stoi(parsedValues[3]);
        year = stoi(parsedValues[4]);
        localZoneHours = stoi(parsedValues[5]);
        hr = stoi(time.substr(0, 2));
        mn = stoi(time.substr(2, 2));
        sc = stoi(time.substr(4, 2));
    }

    	string getSentenceID() const { return sentenceID; }
        string getTime() const { return time; }
        int getDay() const { return day; }
        int getMonth() const { return month; }
        int getYear() const { return year; }
        int getLocalZoneHours() const { return localZoneHours; }
        int getLocalZoneMinutes() const { return localZoneMinutes; }
        string getChecksum() const { return checksum; }
        int getHr() const { return hr; }
        int getMn() const { return mn; }
        int getSc() const { return sc; }
public:
    virtual ~ZDA() {}
};



#endif /* ZDA_H_ */
