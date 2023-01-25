#include <iostream>
#include <fstream>

using namespace std;

struct autoNoleggio{
    string Categoria;
    string Marca;
    string Modello;
    string Colore;
    string Settimana[7];
}caratteristicheMacchina;

void visualizzazioneCatalogo(){
    ifstream fin("auto.txt", ios::in);
    if(!fin)
        cout<<"Errore di apertura file!";
    string temp;
    cout<<endl;
    while(!fin.eof()){
        getline(fin,temp);
        cout<<temp<<endl;
    }
    fin.close();
}

void ricercaCampo(string cat,string giorni){
    ifstream fin("auto.txt", ios::in);
    int i=0;

    while(!fin.eof()){
        fin>>caratteristicheMacchina.Categoria;
        fin>>caratteristicheMacchina.Marca;
        fin>>caratteristicheMacchina.Modello;
        fin>>caratteristicheMacchina.Colore;
        fin>>caratteristicheMacchina.Settimana[i];
        i++;
    }
}

int main()
{
    int scelta;
    string categ,giorni;

    while(true){
        cout<<"     Menu       ";
        cout<<"1- Prenotazione di una macchina";
        cout<<"2- Stampa del catalogo";
        cout<<"3- Uscita";
        cin>>scelta;
        switch(scelta){
            case 1:
                cout<<"Quale categoria di macchina si vuole prenotare ?";
                cin>>categ;
                cout<<"In quali giorni?";
                cin>>giorni;
                ricercaCampo(categ,giorni);
                break;
            case 2:
                visualizzazioneCatalogo();
                break;
            case 3:
                return 0;
                break;
        }
    }

    return 0;
}
