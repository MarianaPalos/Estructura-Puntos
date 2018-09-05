#include <iostream>
#include <cmath>
using namespace std;

struct Punto
{
float x, y;

Punto operator+ (Punto aux){ //Componenente de la derecha de la suma o el operador a usar
  Punto temp;
  temp.x = x + aux.x;
  temp.y = y + aux.y;
  return temp;
}

Punto operator- (Punto aux){
  Punto temp;
  temp.x = x - aux.x;
  temp.y = y - aux.y;
  return temp;
}

Punto operator+= (Punto aux){ // a la misma variable x, x= x+y
  x = x + aux.y;
  y = y + aux.x;
  return *this;

}


void Muestra () {
cout << "(" << x << "," << y << ")" << endl;
}

float dist() {
  return sqrt(pow(x,2)+ pow(y,2));
}  //Distancia al Origen

};

void Distancia (Punto p1, Punto p2){
  float dist;
  dist= sqrt( (pow((p2.x - p1.x),2)) + (pow((p2.y - p1.y),2)) );
    cout << "La distancia entre puntos es: " << dist << endl;
}

void Manhattan (Punto p1, Punto p2){
  float compx, compy, dist;
  compx= abs(p1.x - p2.x);
  compy= abs(p1.y - p2.y);
  dist= compx + compy;
  cout << "La distancia Manhattan entre los puntos a y b puntos es: " << dist << endl;
}

void Arreglo (Punto Puntos[10], float Distancias[10])
{
  int i, j;
  float a,b,c;

  cout << "\nLa lista de Puntos: " << endl; //Imprime el arreglo de puntos
  for (i=0; i < 10; ++i){
  cout << i+1 << ". " << "(" << Puntos[i].x << "," << Puntos[i].y << ")" << endl;
}

cout << "\nLa lista de distancias: " << endl;
for (i=0; i < 10; ++i){
       Distancias[i]=Puntos[i].dist(); //Esta calculando las distancias de cada punto en el arreglo Puntos, y las esta guardando en el arreglo Distancias
        cout << i+1 << ". "<< Distancias[i] << endl;
   }


   for (i=0; i<10; ++i){
        for (j=0; j<10; ++j){
            if(Distancias[i]<Distancias[j]){
                a=0, b=0, c=0;
                a=Puntos[i].x;
                b=Puntos[i].y;
                Puntos[i].x=Puntos[j].x;
                Puntos[i].y=Puntos[j].y;
                Puntos[j].x=a;
                Puntos[j].y=b;
                c=Distancias[i];
                Distancias[i]=Distancias[j];
                Distancias[j]=c;
            }
        }
    }

 cout << "\nLa lista de distancias ordenadas: " << endl;
 for(i=0;i<10;i++) {
 cout << i+1 << ". "<< Distancias[i] << endl;
 //cout << i+1 << ". " << "(" << Puntos[i].x << "," << Puntos[i].y << ")" << endl;
 }

 cout << "\nLa lista de Puntos ordenadas: " << endl;
 for(i=0;i<10;i++) {
 cout << i+1 << ". " << "(" << Puntos[i].x << "," << Puntos[i].y << ")" << endl;
 }

}


int main (void)
{
Punto pa, pb, pc;
pa.x = 3.0;
pa.y = -5.4;
pb.x = 7.28;
pb.y = 6.45;
pa.Muestra();
pb.Muestra();

pc= pa + pb;
pc.Muestra();
pc= pa - pb;
pc.Muestra();

pc= pa+=pb;
pc.Muestra();

Distancia (pa,pb);
Manhattan (pa,pb);

Punto Puntos[10];

Puntos[0].x=1.2;
Puntos[0].y=1.3;
Puntos[1].x=2;
Puntos[1].y=8;
Puntos[2].x=6;
Puntos[2].y=7.8;
Puntos[3].x=6;
Puntos[3].y=9;
Puntos[4].x=7;
Puntos[4].y=-5.2;
Puntos[5].x=2;
Puntos[5].y=15;
Puntos[6].x=0.5;
Puntos[6].y=-6;
Puntos[7].x=-6;
Puntos[7].y=11.7;
Puntos[8].x=3;
Puntos[8].y=3.3;
Puntos[9].x=5.9;
Puntos[9].y=1;

float Distancias [10];

Arreglo (Puntos, Distancias);

  return 0;
}
