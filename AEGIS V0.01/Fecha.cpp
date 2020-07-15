using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposClases.h"
#include "PrototiposGlobales.h"
#include "Fecha.h"

Fecha::Fecha()
{
    //ctor
}

int Fecha::CargarFecha()
{
    int error=0,i=0,aux;
    while (error!=0||error!=1)
    {
        cout<<"Ingrese Fecha "<<endl;
        cout<<"Fecha a Buscar (d/m/a):"<<endl;
        cin>>aux;
        setDia(aux);
        cout<<"/";
        cin>>aux;
        setMes(aux);
        cout<<"/";
        cin>>aux;
        setAnio(aux);
        error=ValidarFecha();
        if (error==-1)
        {
            i++;
            error_msj(-2,i);
            anykey();
            cls();
        }
        else
            break;
    }
    return error;

};
int Fecha :: ValidarFecha()
{
    if(mes==0&&dia==0&&anio==0)
        return 1;
    if((mes>0&&mes<13)&&(anio>1910&&anio<=2020))
    {
        switch(mes)
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( dia >= 1 && dia <= 31 )
            {
                return 0;
            }
            else
            {
                return -1;
            }
        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( (dia >= 1) && (dia <= 30) )
            {

                return 0;
            }
            else
                return -1;
        case  2 :
            if( (anio % 4 == 0 && anio % 100 != 0 )|| (anio % 400 == 0 ))
                if ( dia >= 1 && dia <= 29 )
                {

                    return 0 ;
                }
                else
                {
                    return -1;
                }
            else if ( dia >= 1 && dia <= 28 )
            {
                return 0;
            }
            else
            {
                return -1;
            }

        }
    }
    else
    {

        return -1;
    }
    return-1;
};
void AsignarOrdenaFechas(Fecha *reg1,Fecha *reg2)
{
    Fecha Aux;
    if(reg1->getDia()<=reg2->getDia()&&reg1->getMes()<=reg2->getMes()&&reg1->getAnio()<=reg2->getAnio())
        return;
    if(reg1->getAnio()>reg2->getAnio()||reg1->getMes()>reg2->getMes()||(reg1->getMes()==reg2->getMes()&&reg1->getDia()>reg2->getDia()))
    {
///     Aux.setFecha(*reg1);
///     reg1->setFecha(*reg2);
///     reg2->setFecha(Aux);
        return;
    }
};


