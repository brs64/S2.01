#include "ImageDansDiaporama.h"
#include <iostream>
using namespace std;



// constructeurs et destructeur
ImageDansDiaporama::ImageDansDiaporama(const Image& pImage, unsigned int pPos,unsigned int pRang):
    Image(pImage),
    pos(pPos),
    rang(pRang){}

ImageDansDiaporama::ImageDansDiaporama(const ImageDansDiaporama& pImageDansDiaporama):
    Image(pImageDansDiaporama),
    pos(pImageDansDiaporama.getPos()),
    rang(pImageDansDiaporama.getRang()){}


ImageDansDiaporama::~ImageDansDiaporama() {}



// setters et getters
void ImageDansDiaporama::setPos(unsigned int pPos)
{
    (*this).pos = pPos;
}

void ImageDansDiaporama::setRang(unsigned int pRang)
{
    (*this).rang = pRang;
}


unsigned int ImageDansDiaporama::getPos() const
{
    return (*this).pos;
}

unsigned int ImageDansDiaporama::getRang() const
{
    return (*this).rang;
}

