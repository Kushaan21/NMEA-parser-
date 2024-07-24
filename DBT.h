/*
 * DBT.h
 *
 *  Created on: Jul 15, 2024
 *      Author: kusha
 */

#ifndef DBT_H_
#define DBT_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
using namespace std;

#include <sstream>
#include <vector>

class DBT : public NMEASentence {
private:
    string sentenceID;
    float depthBelowTransducer;
    string depthUnits;
    float depthBelowTransducerM;
    string depthMode;
    float depthBelowTransducerF;
    string depthUnitsF;
    string checksum;

public:
    void parse(const string& sdtdbt) override {
    	vector<string> parsedValues ;
    	parsedValues =  subparser (sdtdbt);

        size_t asteriskPos = parsedValues.back().find('*');
        depthUnitsF = parsedValues.back().substr(0, asteriskPos);
        checksum = parsedValues.back().substr(asteriskPos + 1);

        sentenceID = parsedValues[0];
        depthBelowTransducer = stof(parsedValues[1]);
        depthUnits = parsedValues[2];
        depthBelowTransducerM = stof(parsedValues[3]);
        depthMode = parsedValues[4];
        depthBelowTransducerF = stof(parsedValues[5]);
    }

    string getSentenceID() const {
           return sentenceID;
       }

       float getDepthBelowTransducer() const {
           return depthBelowTransducer;
       }

      string getDepthUnits() const {
           return depthUnits;
       }

       float getDepthBelowTransducerM() const {
           return depthBelowTransducerM;
       }

       string getDepthMode() const {
           return depthMode;
       }

       float getDepthBelowTransducerF() const {
           return depthBelowTransducerF;
       }

       string getDepthUnitsF() const {
           return depthUnitsF;
       }

       string getChecksum() const {
           return checksum;
       }

public:
    virtual ~DBT() {}
};
#endif /* DBT_H_ */
