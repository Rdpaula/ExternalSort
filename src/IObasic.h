#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <ctime>
using namespace std;
#pragma once

struct IObasic{
	int sz = 100000000;
	int sz2 = 10000000;
	char buf[100000000];
	char bfsaida[10000000];
	int posbfsaidad = 0;
	int pos[11];
	int cont = 0;
	fstream is;
  	fstream chunk[10]; 
  	fstream final;
	IObasic(string entrada,string final);

	bool is_empted();

	bool is_empted(fstream& pFile);
	
	void lerEntrada();
	
	void closeChunks();

	void openChunksAndFillHeads(char heads[][1000000]); 

	void finalClose();

	void initializingPQ(priority_queue<pair<char,int>,vector<pair<char,int> >, greater<pair<char,int> > > &pq, char heads[][1000000]);

	void Writing();

	void pushToExitBuffer(char c);

	void verHead_Ind(char heads[][1000000], int ind);

	void putElementPQ(priority_queue<pair<char,int>,vector<pair<char,int> >, greater<pair<char,int> > > &pq, char heads[][1000000],int ind);

	int getposbf();
};