/*
 * HDT.h
 *
 *  Created on: Jul 17, 2024
 *      Author: kusha
 */

#ifndef HDT_H_
#define HDT_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
using namespace std;

#include <sstream>
#include <vector>

class HDT : public NMEASentence {
private:
    string sentenceID;
    double heading;
    char indicator;
    string checksum;

public:
    void parse(const string& HDT) override{
    	vector<string> parsedValues ;
    	parsedValues =  subparser (HDT);


    	size_t asteriskPos = parsedValues.back().find('*');
    	checksum = parsedValues.back().substr(asteriskPos + 1);

    	sentenceID = parsedValues[0];
    	heading = stod(parsedValues[1]);
    	indicator = parsedValues[2][0];
    }


    string getSentenceID() const { return sentenceID.substr(3,3); }
    string getChecksum() const override { return (checksum); }
    double getHeading() const {return heading;}
    char getIndicator() const { return indicator;}



public:
    virtual ~HDT() {}
};




#endif /* HDT_H_ */
