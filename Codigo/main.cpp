#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>

using namespace std;

void o_golpea_d(float xo, float ho,float hd, float ao, float d);

void d_golpea_o(float xo, float ho,float hd, float ad, float d);

void d_defiende_o(float xo, float ho,float hd, float ao, float d);

int main()
{
    float xo, d, ho, hd, ao, ad;
    int ejercicio;

    xo=0;
    d=600;
    ho=100;
    hd=100;
    ao=50*3.14/180;
    ad=50*3.14/180;

    cout << "ingresar el ejercicio: ";
    cin >> ejercicio;

    if (ejercicio==1) o_golpea_d(xo, ho, hd, ao, d);

    else if (ejercicio==2) d_golpea_o(xo, ho, hd, ad, d);

    else if (ejercicio==3) d_defiende_o(xo, ho, hd, ao, d);


    //Saber si O golpea D
//    cout << "Ingresar la velocidad inicial en x: ";
//    cin >> vix;
//    for(t=0;copiax<=xd;t++){
//        vx=vix+cos(ao);
//        copiax=xo+vx*t;
//    }

//    for(t=0;copiay<=hd;t++){
//        vy=(viy*sin(ao))-(9.81*t);
//        copiay=ho+(vy*t)-(0.5*9.81*t*t);
//    }

//    if (xd-copiax<=0.05){
//        if(hd-copiay<=0.05){
//            cout << "El cañon O golpea al D: ";
//        }
//        else cout << "El cañon O no golpea al D: ";
//    }
//    else cout << "El cañon O no golpea al D: ";

/*
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


*/


    return 0;
}

void o_golpea_d(float xo, float ho,float hd, float ao, float d){

    float copiax, copiay, vx, vy, vio, raiz;
    int t, cond;
    cond=0;

    for (vio=0;vio<=100;vio+=5){
        vx=vio*cos(ao);
        vy=vio*sin(ao);
        cout << vio << endl;
        cout << vx << endl;
        cout << vy << endl;
        cout << endl;
        for(t=0;t<=12;t+=1){
            copiax=xo+vx*t;
            copiay=ho+vy*t-(0.5*9.81*t*t);
            cout << " x= " << copiax << " y= " << copiay;
            raiz=pow((d-copiax),2)+pow((hd-copiay),2);
            if (sqrt(raiz)<=(0.05*d)){
                cond=1;
                break;
            }

        }
        if (cond==1) break;
    }
    cout << "Para que el canon O golpee el D necesita una velocidad de:" << vio << " en un tiempo: " << t << endl;
}

void d_golpea_o(float xo, float ho,float hd, float ad, float d){

    float copiax, copiay, vx, vy, vio, raiz;
    int t, cond;
    cond=0;

    for (vio=0;vio<=100;vio+=1){
        vx=(vio*cos(ad));
        vy=vio*sin(ad);
        cout << vio << endl;
        cout << vx << endl;
        cout << vy << endl;
        cout << endl;
        for(t=0;t<=1000;t+=1){
            copiax=-d+vx*t;
            copiay=hd+vy*t-(0.5*9.81*t*t);
            raiz=pow((-xo-copiax),2)+pow((ho-copiay),2);
            if (sqrt(raiz)<=(0.025*d)){
                cond=1;
                break;
            }

        }
        if (cond==1) break;
    }
    cout << "Para que el canon O golpee el D necesita una velocidad de:" << vio << " en un tiempo: " << t << endl;
}


void d_defiende_o(float xo, float ho,float hd, float ao, float d){
    float copiax, copiay, copiax2, copiay2, vx, vy, vx2, vy2, vio, raiz;
    int t, cond, angulo;

    for (vio=0;vio<=100;vio+=5){
        vx=45*cos(ao);
        vy=45*sin(ao);
        for(t=0;t<=100;t+=1){
            copiax=xo+vx*(t+2);
            copiay=ho+vy*(t+2)-(0.5*9.81*(t+2)*(t+2));
            for(angulo=90;angulo<180;angulo+=1){
                vx2=vio*cos(angulo*3.14/180)*(-1);
                vy2=vio*sin(angulo*3.14/180);
                copiax2=d+vx2*(t);
                copiay2=hd+vy2*t-(0.5*9.81*(t)*(t));
                raiz=pow((copiax2-copiax),2)+pow((copiay2-copiay),2);
                if (sqrt(raiz)<=(0.025*d)){
                    cond=1;
                    break;
                }
            }
        if (cond==1) break;
        }
        if (cond==1) break;
    }
    cout << "Para que el canon O golpee el D necesita una velocidad de:" << vio << " en un tiempo: " << t << " con un angulo de: " << angulo << endl;
}
