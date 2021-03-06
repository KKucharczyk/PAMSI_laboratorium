#ifndef SORT_H
#define SORT_H

/*!
 * \file sort.h
 * \brief Definicja klasy Sort
 * 
 * Plik zawiera definicję klasy Sort.
 */

#include <iostream>
#include "obiekt.h"

using namespace std;

/*!
 * \class Sort
 * \brief Umożliwia sortowanie tablic
 * 
 * Klasa służy do sortowania tablic zawartych w obiektach klasy Obiekt. Posiada metody umozliwiające
 * zarówno sortowanie elementów tablic różnymi algorytmami o różnej wydajności, jak i zapisać aktualne
 * dane z obiektu i przedstawić zestawienie danych (przed sortowanie, po sortowaniu).
 */

class Sort{
public:
   /*! 
    * \brief Zapisuje dane z obiektu Obiekt
    * 
    * Pole służy przy wizualizacji zmian zachodzących w tablicach obiektów. Nie ma żadnego praktycznego
    * znaczenia w ujęciu sortowania elementów.
    */
   int *Zapisane_dane;
   
   /*!
    * \brief Przepisuje dane z obiektu Obiekt
    * 
    * Zadanie metody jest przepisanie elementów z obiektu Obiekt do wewnŧrznej tablicy, aby później
    * możliwe było przystępne przedstawienie owych danych i łatwiejsza lokalizacja błędów. Tablica
    * z której pobierane są dane pozostaje nie naruszona dzięki modyfikatorowi const.
    * 
    * \param Obiekt Obiekt z którego mają zostać przepisane dane
    */
   void Zapisz_dane(const Obiekt Obiekt);
   /*!
    * \brief Pokazuje zmiany w przystępnej formie
    * 
    * Metoda wyświetla dane w postaci dwóch kolumn: lewa odpowiada za dane nie posortowane, prawa
    * za posortowane. Wszystkie elementy są indeksowane. Służy tylko i wyłącznie w celu wizualizacji
    * i nie ma żadnego praktycznego znaczenia w ujęciu algorytmów sortowania. Tablica z której 
    * pobierane są dane pozostaje nie naruszona dzięki modyfikatorowi const.
    * 
    * \param Obiekt Obiekt z którego mają zostać przepisane dane
    */
   void Wizualizuj_zmiany(const Obiekt Obiekt);
   
   // Quicksort
   /*!
    * \brief Sortowanie elementów metodą Quicksort
    * 
    * Metoda służy do sortowanie elementów tablicy obiektu przesyłanej jako argument metody.
    * Algorytm sortowania szybkiego (ang. quicksort) polega na dzieleniu tablicy na podtablice zgodnie
    * z określonym kryterium (tzw. punkt osiowy), jedna tablica tworzona jest z mniejszych od elementu
    * osiowego elementu, druga z większych od elementu osiowego elemntów. Następnie rekurencyjnie 
    * powtarzane jest dzielenie tablic na podtablice aż do tablic jednoelemntowych.
    * 
    * \param Obiekt Obiekt, którego tablica ma zostać posortowana
    * \param pierwszy Indeks pierwszego elementu, od którego ma się rozpocząć sortowanie
    * \param ostatni Indeks ostatniego elementu, który ogranicza sortowanie
    */ 
   void QuickSort(Obiekt& Obiekt, int pierwszy, int ostatni);
   
   // Sortowanie Kopcowe
   /*!
    * \brief Tworzy strukturę kopca
    * 
    * Metoda tworzy strukturę kopca binarnego z przesyłanej jako argument tablicy obiektu Obiekt. Dzięki
    * rozdzielaniu części określonej jako id na korzeń i dwójkę potomstwa, możliwe jest szybkie rejestrowanie,
    * czy struktura kopca jest w pełni zachowana. W przypadku dowolnych niezgodności, kopiec zostaje 
    * szybko naprawiony.
    * 
    * \param[in] Obiekt Obiekt, którego tablica ma zostać posortowana
    * \param[in] id Numer elementu, który wraz z potomstwem ma być badany
    * \param[in] hs Licznik określający ilość przebiegów sortowania, pochodzi z metody HeapSort
    */
   void StrukturaKopca(Obiekt &Obiekt, int id, int hs);
   
   /*!
    * \brief Tworzy kopiec binarny z tablicy danych
    * 
    * Metoda pozwala stworzyć kopiec z określonego elementu Obiekt. Inicjuje metodę StrukturaKopca i za jej 
    * pomocą, dla określonych elementów, zmienia tablicę w pre-posortowany kopiec, którego struktura
    * umożliwia działanie algorytmowi sortowania kopcowego, w wypadku tego programu jest to HeapSort.
    * 
    * \param[in] Obiekt Obiekt, którego tablica ma zostać posortowana
    * \param[in] hs Licznik określający ilość przebiegów sortowania, pochodzi z metody HeapSort
    */
   void BudujKopiec(Obiekt &Obiekt, int hs);
   
   /*!
    * \brief Sortowanie tablicy metodą kopcową
    * 
    * Metoda umożliwia posortowanie tablicy Obiektu za pomocą algorytmu sortowania kopcowego (ang. HeapSort).
    * Algorytm działa na zasadzie ustawiania największego elementu sortowanej tablicy (korzenia) na pierwszym
    * miejscu posortowanych elementów, następnie jego stare miejsce zostaje zastąpione elementem z najniższej
    * gałęzi. Dzięki metodzie naprawiania, struktura kopca zostaje naprawiona i na szczycie ponownie zostaje
    * umieszczony największy element, który z korzenia wędruje na drugie miejsce posortowanej tablicy, etc.
    * Dzięki temu tablica wypełnia się posortowanymi liczbami w kolejności malejącej (najpierw liczby największe)
    * potem mniejsze.
    *
    * \param[in] Obiekt Obiekt, którego tablica ma zostać posortowana */
   void HeapSort(Obiekt &Obiekt);
   
   // Sortowanie przez podział
   /*!
    * \brief Dzieli tablicę Obiektu na dwie części
    * 
    * Metoda jest pomocniczą metodą algorytmu sortowania przez scalanie. Jej rolą jest podział tablicy Obiektu
    * na dwie równe części.
    * 
    * \param[in] Obiekt Obiekt, którego tablica ma zostać posortowana
    * \param[in] low Określa początek tablicy
    * \param[in] high Określa koniec tablicy 
    * \param[in] mid Określa środek tablicy
    */
   void Merge(Obiekt &Obiekt, int poczatek, int koniec, int srodek);

   /*!
    * \brief Sortuje tablicę obiektu za pomocą algorytmu sortowania przez scalanie
    * 
    * Metoda umożliwia posortowanie tablicy obiektu Obiekt poprzez zastosowanie rekurencyjnego algorytmu 
    * sortowania przez scalanie (ang. Merge sort). Metoda ta ogranicza się do rekurencyjnego wywoływania
    * siebie i metody Merge. Tablica przeznaczona do sortowania jest dzielona aż do oporu lub jednego pozostałego
    * elementu, a następnie, mając posortowane kawałki, łączy części w jedną, posortowaną, wynikową tablicę.
    * 
    * \param[in] Obiekt Obiekt, którego tablica ma zostać posortowana
    * \param[in] low Określa początek stosowania algorytmu (tablicy)
    * \param[in] high Określa konec stosowania algorytmu (tablicy)
    */
   void MergeSort(Obiekt& Obiekt, int poczatek, int koniec);
};

#endif