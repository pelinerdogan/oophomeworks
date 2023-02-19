
#include <iostream>
#include <cstdlib>
#include <list>
#include <string>

using namespace std;


namespace hw4
{
    class DayofYearSet
    {
        public:
            class DayofYear//inner class
            {
                public:
                //constructors
                    DayofYear(){  };  //default
                    DayofYear(int nDay, int nMonth); 
                    //getters
                    int getDay() const {return day; }; 
                    int getMonth() const {return month; }; 

                    //setters
                    void setDay(int nDay); //check
                    void setMonth(int nMonth); //check

                private:
                    int day;
                    int month;
                    int arrdaynum[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };

            };

            DayofYearSet(){  };
           ~DayofYearSet(); 
            DayofYearSet( list<DayofYear> &nSet);
            DayofYearSet(int nDay, int nMonth);
           DayofYearSet(const DayofYearSet& otherset);

            int  size() const{   return sizeofdates;} ;
            void remove(int rmDay, int rmMonth);
            void add(int newDay, int newMonth);
            bool operator==(const DayofYearSet &other) const;
            DayofYear& operator[](int index) const; 
            bool operator!=(const DayofYearSet &other) const;
            const DayofYearSet operator^(const DayofYearSet &other) const; 
            DayofYearSet& operator=(const DayofYearSet &rightSet);
            const DayofYearSet operator+(const DayofYearSet &other) const;
            const DayofYearSet operator-(const DayofYearSet &other) const;
            const DayofYearSet operator!(void) const;
            friend ostream& operator<<(ostream &outputStream, const DayofYearSet &mySet);
           
           
    

        
           

        private:
            DayofYear *dates = nullptr;
            int sizeofdates = 0;
            int arrdaynumm[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };
           
    };
}

