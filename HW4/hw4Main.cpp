

#include "hw4Lib.h" 


using namespace hw4;

int main()
{
 

    cout << "please press enter until the program is finished." << endl ;
     getchar();
    
    DayofYearSet set1;
    cout << endl << "Default constructor created  an empty set. named set 1" << endl ;
    cout << set1;
       getchar();
    
    set1.add(25, 8);
    set1.add(14, 12);
    set1.add(12, 7);
    set1.add(1, 9);
    
    cout << "4 element added to the set. Now the set is:" << endl ;
    cout << set1;
       getchar();
    
    
    DayofYearSet set2(1, 1);
    cout << endl << "İnteger parameter constructor created a new set named set 2 ." << endl << endl;
    cout << set2; 
    getchar();

 
    
    set2.add(12, 7);
    set2.add(14, 12);
    cout << " 2 element added to the set. Now the set is:" << endl << endl;
    cout << set2;
    getchar();

    DayofYearSet set5(set2);
    cout << endl << "set paramater constructor created a new set same with set 2   ." << endl << endl;
    cout << set5; 
    getchar();


    list <DayofYearSet::DayofYear> datelist;
    int arr[8][8] = {{8,1}, {10,11}, {6, 5}, {14, 12}, {30, 3}, {22, 11}, {19, 10}, {12, 7}};
    for(int i=0;i<8;i++){
     DayofYearSet::DayofYear  a;
     a.setDay(arr[i][0]);
     a.setMonth(arr[i][1]);
    datelist.push_back(a);
    }
    
    DayofYearSet set3(datelist);
    cout << endl << "List parameter constructor created a set named set 3" << endl << endl;
    cout << set3;
    getchar();

    set3.remove(8, 1);
    set3.add(3, 1);
    cout << " January 8 removed from the set." << endl;
    cout << " January 3 added to the set." << endl << endl;
    cout << set3;
    getchar();

    DayofYearSet set4 = set1 + set2 + set3;
    cout << "Set created with + overloading operator (set1 + set2 + set3)." <<endl <<"(Same elements did not duplicated.)" << endl << endl;
    cout << set4;
    getchar();
    
    set4.remove(14, 12);
    set4.remove(6, 5);
    set4.add(16, 12);
    cout << " Elements December 14  and May 6 removed then December 16 added to the union set A." << endl << endl;
    cout << set4;
    getchar();

    cout << "Testin operator overloads" << endl;
   
    getchar();

    cout << "set1 : " << endl << set1 << "union set A: " << endl << set4 << endl;

    cout << "Enter to see set 1 + union set A" << endl;
    getchar();
    cout << set1 + set4;

    cout << "Enter to see set 1 - union set A" << endl;
    getchar();
    cout << set1 - set4;

    cout << "Enter to see union set A  - set 1" << endl;
    getchar();
    cout << set4 - set1;
    
    cout << "Enter to see union set A ^ set 1" << endl;
    getchar();
    cout << (set4^set1);
  
   

    cout << "Enter to see !union set A." << endl;
    getchar();
    cout << !set4;
    
    cout << "Enter to see implementaion of [] function." << endl;
    getchar();
    
    cout << "union set before:" << endl << set4;
    cout << "first element is going to change and be setted to my birthday" << endl; 
    set4[0].setMonth(11);
    set4[0].setDay(19);
    cout << endl << "union set A after:" << endl << set4;
    getchar();

 
    
    
    return 0;
}

