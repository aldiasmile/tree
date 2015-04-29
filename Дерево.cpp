/*! \file main.cpp
Главный файл проекта
*/
#include "conio.h"
#include <iostream>
using namespace std;

/** 
Структура дерева
*/
struct TREE {
int info;
 TREE *right,*left;
 };
 
TREE *root=NULL;
int count=0; 
 
 /** \fn void Create(TREE **current, int n)
Функция создания дерева
*/
void Create(TREE **current, int n)
 {
if(n==0)
 *current=NULL;
else
 {
int nl = n/2;
int nr = n-nl-1;
 TREE *tmp=new TREE;
 ::count++;
 cin >> tmp->info;
 Create(&tmp->left,nl);
 Create(&tmp->right,nr);
 *current=tmp;
 }
}
/** \fn void obr(TREE *current)
Обратный обход
*/
void obr(TREE *current)
 {
if(current!=NULL)
 {
 obr(current->left);
 cout << " ";
 obr(current->right);
  cout << current->info ;
  cout <<" ";
 }

}
/** \fn void ShowSymmetric(TREE *current,int l)
Симметрический обход
*/
void ShowSymmetric(TREE *current,int l)
 {
	 
if(current!=NULL)
 {
 ShowSymmetric(current->left, l+1);
 cout << "->";
 cout << current->info;
 ShowSymmetric(current->right, l+1);
 }
 }

/** \fn void ShowOnward(TREE *current)
Прямой обход
*/
void ShowOnward(TREE *current)
 {
if(current!=NULL)
 {
 cout << "->";
 cout << current->info ;
 ShowOnward(current->left);
 ShowOnward(current->right);
 }
}
 
/** \fn int main()
Главная функция проекта
*/

int main()
 {
 setlocale(LC_ALL,"Russian");
char otv;
int n;
do
 {
 cout << endl << "1. Создать дерево"              << endl
              << "2. Обход в прямом направлении"  << endl
              << "3. Симметричный обход"          << endl
              << "4. Обход в обратном направлении"<< endl
              << "0. Выход"						  << endl;
 cin >> otv;
switch(otv)
 {
case '1':
 cout << endl << "Введите число вершин = ";
 cin >> n;
 Create(&root, n);
break;
case '2':
if(::count==0)
 cout << endl << "Дерево пустое" << endl;
else
 ShowOnward(root);
break;
 
case '4':
if(::count==0)
 cout << endl << "Дерево пустое" << endl;
else
obr(root);
break;
 
case '3':
if(::count==0)
 cout << endl << "Дерево пустое" << endl;
else
 ShowSymmetric(root, 0);
break;
case '0':
break;
default:
 cout << endl << "Ошибка" << endl;
break;
}
}while(otv!='0');
 cin.get();
}

