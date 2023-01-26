#include <iostream>
#include <fstream>
#include <string.h>

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

void modificaNoleggio(int numero[7],int c){
    ifstream fin("autoappoge.txt", ios::app);
    bool controllo;

    while(!fin.eof()){
        controllo = true;
        fin>>caratteristicheMacchina.Categoria;
        fin>>caratteristicheMacchina.Marca;
        fin>>caratteristicheMacchina.Modello;
        fin>>caratteristicheMacchina.Colore;
        for(int j = 0; j < 7; j++)
            fin>>caratteristicheMacchina.Settimana[j];

        for(int i = 0; i < c ; i++){
            if(caratteristicheMacchina.Settimana[numero[i]] == "A")
                controllo = false;
        }
        if(controllo)
            cout<<caratteristicheMacchina.Categoria<<" ";
            cout<<caratteristicheMacchina.Marca<<" ";
            cout<<caratteristicheMacchina.Modello<<" ";
            cout<<caratteristicheMacchina.Colore<<" ";
            for(int i = 0;i <7;i++)
                cout<<caratteristicheMacchina.Settimana[i]<<" ";
    }
}

void ricercaCampo(string categ,string giorni){
    ifstream fin("auto.txt", ios::in);
    ofstream fout("autoappoge.txt", ios::out);
    int i=0,c=0,numero[7];
    char app;


    while(giorni[i] != '\0'){
        if(giorni[i] != ','){
            numero[c] = (int)giorni[i] - 48;
            c++;
        }
        i++;
    }
    modificaNoleggio(numero,c);

    while(!fin.eof()){
        fin>>caratteristicheMacchina.Categoria;
        fin>>caratteristicheMacchina.Marca;
        fin>>caratteristicheMacchina.Modello;
        fin>>caratteristicheMacchina.Colore;
        for(int i = 0;i <7;i++)
            fin>>caratteristicheMacchina.Settimana[i];

        if(caratteristicheMacchina.Categoria == categ ){
            cout<<caratteristicheMacchina.Categoria<<" ";
            cout<<caratteristicheMacchina.Marca<<" ";
            cout<<caratteristicheMacchina.Modello<<" ";
            cout<<caratteristicheMacchina.Colore<<" ";
            for(int i = 0;i <7;i++)
                cout<<caratteristicheMacchina.Settimana[i]<<" ";

            fout<<caratteristicheMacchina.Categoria<<" ";
            fout<<caratteristicheMacchina.Marca<<" ";
            fout<<caratteristicheMacchina.Modello<<" ";
            fout<<caratteristicheMacchina.Colore<<" ";
            for(int i = 0;i <7;i++)
                fout<<caratteristicheMacchina.Settimana[i]<<" ";
            fout<<"\n";
        }

    cout<<endl;
    }


    fin.close();
    fout.close();
}

int main()
{
    int scelta;
    string categ,giorni;

    while(true){
        cout<<"     Menu       "<<endl;
        cout<<"1- Prenotazione di una macchina"<<endl;
        cout<<"2- Stampa del catalogo"<<endl;
        cout<<"3- Uscita"<<endl;
        cin>>scelta;
        switch(scelta){
            case 1:
                cout<<"Quale categoria di macchina si vuole prenotare ?"<<endl;
                cin>>categ;
                cout<<"In quali giorni?(es: 3,4)"<<endl;
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
