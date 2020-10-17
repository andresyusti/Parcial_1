#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    float xo, xd, ho, hd, ao, ad, t, vix, viy, vx, vy, copiax, copiay;

    cout << "ingresar La hubicacion en x de o y d, la altura de o y d, el angulo en el que esta o y d (En ese orden): " << endl;
    cin >> xo;
    cin >> xd;
    cin >> ho;
    cin >> hd;
    cin >> ao;
    cin >> ad;

    //Saber si O golpea D
    cout << "Ingresar la velocidad inicial en x: ";
    cin >> vix;
    for(t=0;copiax<=xd;t++){
        vx=vix+cos(ao);
        copiax=xo+vx*t;
    }

    for(t=0;copiay<=hd;t++){
        vy=(viy*sin(ao))-(9.81*t);
        copiay=ho+(vy*t)-(0.5*9.81*t*t);
    }

    if (xd-copiax<=0.05){
        if(hd-copiay<=0.05){
            cout << "El cañon O golpea al D: ";
        }
        else cout << "El cañon O no golpea al D: ";
    }
    else cout << "El cañon O no golpea al D: ";


    //Saber si D golpea O
    cout << "ingresar la velocidad inicial en x: ";
    cin >> vix;
    for(t=0;copiax<=xo;t++){
        vx=vix+cos(ad);
        copiax=xd+vx*t;
    }

    for(t=0;copiay<=ho;t++){
        vy=(viy*sin(ad))-(9.81*t);
        copiay=hd+(vy*t)-(0.5*9.81*t*t);
    }

    if (xo-copiax<=0.05){
        if(ho-copiay<=0.05){
            cout << "El cañon D golpea al O: ";
        }
        else cout << "El cañon D no golpea al O: ";
    }
    else cout << "El cañon D no golpea al O: ";


    //Saber si el cañon D Se defiende sin importa el cañon O
    vx=vix+cos(ad);
    for(t=2;copiax<=xo;t++){
        copiax=xo+vx*t;
        copiay=ho+(vy*t)-(0.5*9.81*t*t);
        if (copiax-(xd+(vix+cos(ad))*(t-2)<=0.05)){
            if (copiay-hd+(((viy*sin(ad))-(9.81*(t-2)))*(t-2))-(0.5*9.81*(t-2)*(t-2))<=0.05){
                cout << "El cañon D se defiende satisfactoriamente";
            }
            else if (copiay-hd<=0.025){
                cout << "El cañon D no se denfendio satisfactoriamente";
            }
        }
        else if(copiax-xd<=0.025){
            cout << "El cañon D no se denfendio satisfactoriamente";
        }
    }




    return 0;
}
