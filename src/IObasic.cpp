#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <ctime>
#include "IObasic.h"
using namespace std;


IObasic::IObasic(string entrada,string saida){
	is.open(entrada,fstream::in); 
	final.open(saida,fstream::out);
}

bool IObasic::is_empted(){
	return is.peek() == ifstream::traits_type::eof();
}

bool IObasic::is_empted(fstream& pFile){
	return pFile.peek() == ifstream::traits_type::eof();
}
void IObasic::lerEntrada(){
	is.read(buf, sz);
	sort(buf, buf + sz);
	string ind = to_string(cont);
	chunk[cont].open("chunk"+ind,fstream::out);
	chunk[cont].write(buf, sz);
	cont++;
}

void IObasic::closeChunks(){
	for(int i = 0;i < cont; i++){ 
		chunk[i].close();
	}
}

void IObasic::openChunksAndFillHeads(char heads[][1000000]){
	for(int i = 0;i < cont; i++){
		string ind = to_string(i);
		chunk[i].open("chunk" + ind,fstream::in);
		chunk[i].read(heads[i], sz2);
	}
}

void IObasic::finalClose(){
	closeChunks();
	is.close();
	final.close();
}

void IObasic::initializingPQ(priority_queue<pair<char,int>,vector<pair<char,int> >, greater<pair<char,int> > > &pq, char heads[][1000000]){
	memset(pos, 0 ,sizeof pos);
	for(int i = 0; i < cont; i++){
		pq.push({heads[i][pos[i]++],i});
	}
}

void IObasic::Writing(){
	if(posbfsaidad == 0) return;
	final.write(bfsaida,sz2); 
	posbfsaidad = 0;
}

void IObasic::pushToExitBuffer(char c){
	bfsaida[posbfsaidad++] = c;
}

void IObasic::verHead_Ind(char heads[][1000000], int ind){
	if(!is_empted(chunk[ind]) && pos[ind] == sz2){ // is_empted nao tem parametro :o
		chunk[ind].read(heads[ind], sz2);
		pos[ind] = 0;
	}
}

void IObasic::putElementPQ(priority_queue<pair<char,int>,vector<pair<char,int> >, greater<pair<char,int> > > &pq, char heads[][1000000],int ind){
	if(pos[ind] < sz2) pq.push({heads[ind][pos[ind]++], ind});
}

int IObasic::getposbf(){
	return posbfsaidad;
}