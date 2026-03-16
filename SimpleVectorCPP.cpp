// Основни операции
//  push_back() – добавя елемент в края
//  pop_back() – премахва последния елемент
//  insert() – вмъква елемент на дадена позиция
//  erase() – изтрива елемент

// Достъп до елементи
//  operator[] – достъп без проверка
//  at() – достъп с проверка
//  front() – първи елемент
//  back() – последен елемент
//  data() – pointer към първия елемент

// Размер и капацитет
//  size() – брой елементи
//  capacity() – заделена памет
//  resize() – променя броя елементи
//  reserve() – заделя памет предварително
//  empty() – дали е празен

// Модификация
//  clear() – изтрива всички елементи
//  assign() – заменя съдържанието
//  swap() – разменя съдържание с друг vector

// Итерация
//  begin(), end()
//  rbegin(), rend()

#include <iostream>
#include <algorithm>

/*
class SimpleVector{
    int* s_vector;
    int iSize = 5;
    int lastElement = 0;

public:
    SimpleVector(std::initializer_list<int>& elements)
    {
        for(int element : elements){
            this->push_back(element);
            lastElement++;
        }
    }

    void push_back(int newElement){
    int* newArr = NULL;
    //int newSize = 0;
    if(lastElement == iSize){
        iSize *= 2;
    }
    newArr = new int[iSize]();

    if(iSize > 0 && iSize == lastElement){
        for(int i = 0; i < lastElement; i++)
        {
            std::cout << "push_back - copy arr\n";
            newArr[i] = s_vector[i];
        }
        newArr[lastElement] = newElement;
    } else {
        s_vector[lastElement] = newElement;
    }

    lastElement++;
}

    //void PrintVector(int* s_vector){
    //    for(int i = 0; i < size(s_vector); ++i){
    //        std::cout << "";
    //    }
    //}
};*/


int* pArr = NULL;
int iSize = 5;
int lastElement = 0;


// push back to an array as last position
void push_back(int newElement){
    int* newArr = NULL;
    //int newSize = 0;
    if(lastElement == iSize){
        iSize *= 2;
    }
    newArr = new int[iSize]();

    if(iSize > 0 && iSize == lastElement){
        for(int i = 0; i < lastElement; i++)
        {
            std::cout << "push_back - copy arr\n";
            newArr[i] = pArr[i];
        }
        newArr[lastElement] = newElement;
    } else {
        pArr[lastElement] = newElement;
    }

    lastElement++;
    //delete pArr;
    //pArr = newArr;
}


// Insert only one element
// accept negative position - add element on position from end to beginning
int insert(int position, int newElement){

    if(position >= 0 && lastElement - position >= 0){
        // do nothing
    } else if(position < 0 && lastElement + position >= 0) {
        position = lastElement + position;
    } else {
        std::cout << "Cannot insert item on that position.\n";
        return -1;
    }

    if(position == lastElement){
        push_back(newElement);
        return 0;
    }

    int* newArr = NULL;
    if(lastElement + 1 == iSize){
        iSize *= 2;
    }
    newArr = new int[iSize]();

    for(int i = 0; i < position; i++)
    {
        std::cout << "insert - copy element - (" << pArr[i] << ")\n";
        newArr[i] = pArr[i];
    }

    std::cout << "insert " << newElement << " as new element\n";
    newArr[position] = newElement;

    for(int i = position; i < lastElement; i++)
    {
        std::cout << "insert - copy element - (" << pArr[i] << ")\n";
        newArr[i + 1] = pArr[i];
    }

    delete[] pArr;
    pArr = newArr;

    lastElement++;

    return 0;
}

// remove last element
void pop_back(){
    if(lastElement > 0){
        pArr[lastElement] = 0;
        lastElement--;
    } else {
        std::cout << "There are no elements to be removed\n";
    }

}

int* at(int position){
    if(position < 0 || position >= lastElement){
        std::cout << "No element on this position.\n";
        return NULL;
    }

    return &pArr[position];
}


// Removes element at position
int erase(int position){

    //if(position >= 0 && lastElement - position >= 0){
        // do nothing
    //} else
    if(position < 0 && lastElement >= 0) {
        std::cout << "Cannot insert item on that position.\n";
        return -1;
    }

    if(position == lastElement - 1){
        pop_back();
        return 0;
    }

    lastElement--;

    // reduce the size if the lastElement  position * 2 is less or equal to size
    if(iSize > lastElement * 2) iSize /= 2;

    int* newArr = NULL;

    newArr = new int[iSize]();

    for(int i = 0; i < position; i++)
    {
        std::cout << "erase - copy element - (" << pArr[i] << ")\n";
        newArr[i] = pArr[i];
    }

    for(int i = position+1; i <= lastElement; i++)
    {
        std::cout << "erase - copy element - (" << pArr[i] << ")\n";
        newArr[i - 1] = pArr[i];
    }

    delete[] pArr;
    pArr = newArr;

    return 0;
}

void print(std::string delimiter){
    for(int i = 0; i < lastElement; i++)
    {
        std::cout << pArr[i];
        if(i < lastElement - 1)
            std::cout << delimiter;
    }
    std::cout << std::endl;
}

int main()
{
    pArr = new int[iSize]{};

    push_back(5);
    push_back(4);
    insert(1, 6);
    //insert(-1, 3);
    *at(1) = -1;

    print(" ");
    erase(1);
    print(" ");
}

