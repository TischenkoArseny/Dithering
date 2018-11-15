#include <iostream>
#include <QImage>
#include <QFile>
#include <QDataStream>
#include "rgb_color.h"
using namespace std;

int main()
{
    QImage *img = new QImage("1.png", nullptr);
    if(img->isNull())
    cout << "NULL" << endl;
    else
    {
        cout << "Not Null" << endl;
        QVector <RGB_Color> *pallet;
        pallet =new QVector<RGB_Color>();
        unsigned int tmp;
        for(int i=0; i<img->width(); i++)
            for(int j=0; j<img->height(); j++)
            {
                tmp=img->pixel(i,j);
                pallet->append(RGB_Color(tmp));
            }
        QFile file("pallet.txt");
        file.open(QIODevice::ReadWrite);
        QDataStream out(&file);
        RGB_Color temp;
        for(int i=0; i<pallet->size(); i++)
        {
            temp = (*pallet)[i];
            out << (unsigned char)i;
        }

        file.close();
        file.open(QIODevice::ReadWrite);
        QDataStream in(&file);
        pallet->clear();
        while(!in.atEnd())
        {
            in >> tmp;
            pallet->append(RGB_Color(tmp));
        }
        for(int i=0; i<pallet->size(); i++)
        {
            cout << "Red=" << (int)(*pallet)[i].getRed() << " ";
            cout << "Red=" << (int)(*pallet)[i].getGreen() << " ";
            cout << "Red=" << (int)(*pallet)[i].getBlue() << endl;
        }
    }

    system("pause");
    return 1;
}
