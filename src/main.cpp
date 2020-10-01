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
const int sz = 1e8;
const int sz2 = 1e6;

char heads[11][sz2];/// initalizing heads;
int total = 0;
int total2 = 0;

int main(){
  clock_t totaltime = clock();
  clock_t totalread,totalwrite;
  IObasic IObasic("entradagigante","saida"); /////////construtor
  
  IObasic.cont = 0;
  
  while(!IObasic.is_empted()){ ////// método lerEntrada() e abrindo os chunks em modo OUT
      IObasic.lerEntrada();
  }


  IObasic.closeChunks(); //// fechando os chunks

  IObasic.openChunksAndFillHeads(heads);  ///// abrindo os chunks em modo IN preenchendo as heads

  priority_queue<pair<char,int>,vector<pair<char,int> >, greater<pair<char,int> > > pq;//// priority_queue

  IObasic.initializingPQ(pq,heads); //// putting elements in pq

  clock_t timealg = clock();

  while(!pq.empty()){
    if(IObasic.getposbf()==sz2){
      IObasic.Writing();        
    }

    pair<char,int> top = pq.top();
    pq.pop();

    char c = top.first;
    int ind = top.second;

    IObasic.pushToExitBuffer(c);
    
    IObasic.verHead_Ind(heads,ind);

    IObasic.putElementPQ(pq, heads, ind);
  
  }

  timealg = clock() - timealg;
  cout<<"Tempo no k-way...: "<<(float)timealg/CLOCKS_PER_SEC <<" seconds\n";
  
  IObasic.Writing();

  IObasic.finalClose();

  totaltime = clock() - totaltime;
  clock_t totaltimewithoutIO = totaltime - totalwrite - totalread;
  cout<<"Tempo total...: "<<(float)totaltime/CLOCKS_PER_SEC <<" seconds\n";
  cout<<"Tempo lendo...: "<<(float)totalread/CLOCKS_PER_SEC <<" seconds\n";
  cout<<"Tempo escrevendo...: "<<(float)totalwrite/CLOCKS_PER_SEC <<" seconds\n";
  cout<<"Tempo sem IO....: "<<(float)totaltimewithoutIO/CLOCKS_PER_SEC <<" seconds\n";
  return 0;
}