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
}

int main()
{
    int scelta;

    while(true){
        cout<<"     Menu       ";
        cout<<"1- Inserire la macchina desiderata";
        cout<<"2- Stampa del catalogo";
        cout<<"3- Uscita";
        cin>>scelta;
        switch(scelta){
            case 1:

                break;
            case 2:

                break;
            case 3:
                return 0;
                break;
        }
    }

    return 0;
}
