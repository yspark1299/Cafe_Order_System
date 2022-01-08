//
//  main.cpp
//  assign_main
//
//  Created by Yeseo Park on 2020/05/21.
//  Copyright © 2020 Yeseo Park. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;
double cost =0;
string Icode;
double price = 0;
double sumprice =0;
string name;
string MenuIchoose[20]={};
int eachprice[20]={};//make a array and asssume that menu is less than 20 for each order

int s=0;
int oprice=0;

//to count each menu, initalize first
int counta1=0; int counta2=0; int counta3=0; int countb1=0; int countb2=0; int countb3=0; int countc1=0; int countc2=0; int countc3=0; int countc4=0; int countc5=0;
void order(){
    cout<<"Enter the Item code:";
    cin >> Icode;
    if (Icode == "A1"){ // if input items is A1, price is $30, and increase couunta1 by 1
        price = 30;
        counta1++;}
    else if (Icode == "A2"){
        price = 34;
        counta2++;}
    else if (Icode == "A3"){
        price = 32;
        counta3++;}
    else if (Icode == "B1"){
        price = 28;
        countb1++;}
    else if (Icode == "B2"){
        price = 20;
        countb2++;}
    else if (Icode == "B3"){
        price = 28;
        countb3++;}
    else if (Icode == "C1"){
        price = 36;
        countc1++;}
    else if (Icode == "C2"){
        price = 28;
        countc2++;}
    else if (Icode == "C3"){
        price = 28;
        countc3++;}
    else if (Icode == "C4"){
        price = 26;
        countc4++;}
    else if (Icode == "C5"){
        price = 26;
        countc5++;}
    else if (Icode == "S1"){
        price = 48;}
    else if (Icode == "S2"){
        price = 60;}
    else if (Icode == "S3"){
        price = 50;}
    else if (Icode == "S4"){
        price = 90;}
    else if (Icode == "S5"){
        price = 50;}
    else if (Icode == "B2"&& Icode == "C1"){
        price = 48;
    }
    MenuIchoose[s]=Icode;//put input in each array elements
    eachprice[s]=price;

    sumprice = sumprice + price;
    s++;
    
    
}

void sysc(){//When typing a first system command
    int sysc; //system command
    cout <<"1:Press 0 to exit the system or 1 to start ordering:";
    cin>>sysc;
    while (!(sysc == 0 || sysc == 1 )){//if input is not 0 or 1, rewrite the input
        cout<<"Error: Rewrite the system code again";
        cin >> sysc;
    }
   cout<<"Enter your name:";
    cin>> name;
    if (sysc ==0){
        cout<<"Exit programme. Thank You.\n";
    }
    else {
        order ();
    }
}

void sysc1(){//When typing a first system command
    int sysc1; //system command
    cout <<"Press 0 to checkout, 1 to continue this order:\n";
    cin>>sysc1;
    while (!(sysc1 == 0|| sysc1 == 1 )){
        cout<<"Error: Rewrite the system code again\n";
        cin >> sysc1;
    }
    if (sysc1 ==0){
        cout<<"Order completed. Process to checkout\n";
    }
    else {
        order ();
        cout <<"Press 0 to checkout, 1 to continue this order:\n";
        int sysc2;
        cin >> sysc2;
        while (sysc2== 1){
            order();
            cout <<"Press 0 to checkout, 1 to continue this order:\n";
            cin >> sysc2;
        }
        if (sysc2 == 0){
            cout << "Order completed. Process to checkout\n";}
    }
}

void operation(){
    cout<<"Welcome To Cafe 7-23\n";
    sysc();
    sysc1();
    double discountprice=0;
    //Process to find set menu
    if ((countb2 != 0)&&(countc1 != 0)){//
        while ((countb2 != 0) && (countc1 != 0)){
            sumprice = sumprice -8;//Subtract the price different with two single menus and set menu
            countb2= countb2-1; countc1 = countc1-1;//to find how many set menu, need to subtract by 1
        }
    }
    else if ((counta3 != 0)&&(countb2 != 0)&&(countc4 != 0)){
        while ((counta3 != 0)&&(countb2 != 0)&&(countc4 != 0)){
            sumprice = sumprice -18;
            counta3--; countb2--; countc4--;
        }
    }
    else if ((countc5 != 0)&&(counta1 != 0)){
        while ((countc5 != 0)&&(counta1 != 0)){
            sumprice = sumprice -6;
            counta1--; countc5--;
        }
    }
    else if ((countc5 != 0)&&(countc1 != 0)&&(counta2 != 0)&&(countb3 != 0)){
        while ((countc5 != 0)&&(counta1 != 0)&&(counta2 != 0)&&(countb3 != 0)){
            sumprice = sumprice -34;
            countc5--; countc1--;counta2--; countb3--;
        }
    }
    else if ((countc1 != 0)&&(countb1 != 0)){
        while ((countc1 != 0)&&(countb1 != 0)){
            sumprice = sumprice -14;
            countc1--; countb1--;
        }
    }
    else if ((countc1 != 0)&&(countb3 != 0)){
        while ((countc1 != 0)&&(countb3 != 0)){
            sumprice = sumprice -14;
            countc1--; countb3--;
        }
    }
    else if ((countc2 != 0)&&(countb1 != 0)){
        while ((countc2 != 0)&&(countb1 != 0)){
            sumprice = sumprice -6;
            countc2--; countb1--;
        }
    }
    else if ((countc2 != 0)&&(countb3 != 0)){
        while ((countc2 != 0)&&(countb3 != 0)){
            sumprice = sumprice -6;
            countc2--; countb3--;
        }
    }
    
    if (sumprice>100){//When total price is over 100, discount 5 percent.
        discountprice = 0.95*sumprice;
    }
    else{
        discountprice = sumprice;
    }
    cout << "Total items you ordered are\n";
    for (int j=0;j<s;j++){
        cout<< MenuIchoose[j]<<setw(13)<<"$"<<eachprice[j]<<endl;
    }
    cout<<fixed<<setprecision(2);//set the output in two decimal points
    cout << "The final price is $"<<(discountprice)<<"\n"<<endl;
    s=0; //initalization
}

int main(){
    for (int a=0;a>=0;a++){//infinite loop
        operation();
        sumprice =0;
    }
}
