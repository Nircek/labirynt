#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "getch.h"
#include "labirynt.h"
#define DEBUG false

int main() {
    char wybor=0;
    try {
        if(DEBUG) {
            cout << "type \'c\' to break\n";
            char ch;
            while(1) {
              ch=getch();
              if(ch=='c')break;
              cout<<(unsigned int)ch<<' ';
            }
        }
        if(DEBUG) {
            cout<<"Naciskaj kolejne klawisze strzalek, zeby przetestowac kalibracje.\n";
            while(1) {
                cout<<getEvent()<<' ';
            }
        }
    winutf8();
    if(isModeAvailable(WIN))g_color_mode=WIN;
    else if(isModeAvailable(ANSI))g_color_mode=ANSI;
    else g_color_mode=NO;
    srand (time(NULL));
    for(;;){
    clear_screen();
    cout<<"         Witaj w naszej amatorskiej grze \"Labirynt\"."    <<endl<<endl<<endl;
    cout<<"   ################################################"       <<endl;
    cout<<"   #                                              #"       <<endl;
    cout<<"    #       |------------MENU------------|       # "       <<endl;
    cout<<"     #      | Wybierz:                   |      #  "       <<endl;
    cout<<"      #     | 1. - Kampania              |     #   "       <<endl;
    cout<<"       #####| 2. - Losowa mapa           |#####    "       <<endl;
    cout<<"      #     | 3. - Wyswietl tworcow      |     #   "       <<endl;
    cout<<"     #      | 4. - Kalibracja klawiszy   |      #  "       <<endl;
    cout<<"    #       | 5. - Wyjdz                 |       # "       <<endl;
    cout<<"   #        |------------MENU------------|        #"       <<endl;
    cout<<"   ################################################"       <<endl<<endl<<endl;
    cout<<"         Wybieram: ";
    wybor = getch();
    bool won=false;
    size_t i = (size_t)-1;
switch(wybor)
{
    case '1':
            while(doEnd(++i)) {
                getMap();
                loop();
            }
            won=true;
    break;


    case '2':
            clear_screen();
            size_t cordy1, cordy2;
            cout<<"Wybierz rozmiar mapy: "<<endl;
            cout<<"Podaj szerokosc: ";cin>>cordy1;
            cout<<"Podaj wysokosc: ";cin>>cordy2;
            generateMap(cordy1,cordy2);
            loop();
            won=true;
    break;

    case '3':
        clear_screen();
        cout << "---------TWORCY---------" <<endl;
        cout << "Nircek aka Mrcc Znepva" << endl;
        cout << "MrDarkness19"           << endl;
        cout << "Crackenhoff"            << endl;
        cout << "GummyBear"              << endl;
        cout << "Bialas"                 << endl;
        getch();

    break;

    case '4':
        clear_screen();
        calibrate();
    break;

    case '5':
        clear_screen();
        cout<<"Nastapi wyjscie z programu"<<endl;
        getch();
        return 0;
    break;

    default:
        cout<<"Nie znaleziono takiej opcji..."<<endl;
        getch();
    break;
}
    if(won){clear_screen(); cout<<"Gratulacje wygrales !!!"; getch();}
    }
    return 0;
        }catch(const char * c) {
        cout << "error: " << c;
        cin.get();
        return 033653340336; // 0xDEADC0DE
    }catch(...) {
        cout << "UNEXCEPTED ERROR\n";
        cin.get();
        return 033653340336; // 0xDEADC0DE
    }

}
