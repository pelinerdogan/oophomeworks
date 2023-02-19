#include "hw4Lib.h"


namespace hw4{


DayofYearSet::DayofYear::DayofYear(int nDay, int nMonth){ //day number parameter constructor


        if (month < 1 || month > 12 || day < 1 || day > arrdaynum[month - 1])
        {
            cout << "not a valid date " << endl;
        
        }
        else{

             day=nDay;
             month=nMonth;
        }

}


void DayofYearSet::DayofYear::setDay(int nDay){ //setter for day

day= nDay;

}


void DayofYearSet::DayofYear::setMonth(int nMonth){ //setter month


month = nMonth;

}

  DayofYearSet::~DayofYearSet(void){ //destructor (BIG 3!!)
        if (dates != nullptr) 
        delete [] dates;
    }

   DayofYearSet::DayofYearSet(int newDay, int newMonth){  //day number parameter constructor
        add(newDay, newMonth);
    }
   
    DayofYearSet ::DayofYearSet( list<DayofYear> &nSet){  //list parameter constructor

    list<DayofYear>::iterator p;

    for(p = nSet.begin(); p != nSet.end();p++)
         
       add((*p).getDay(),(*p).getMonth());

    }
  
    DayofYearSet::DayofYearSet(const DayofYearSet &otherset)  //add another set constructor
    {
        
        dates = new DayofYear[ otherset.size()];
        sizeofdates = otherset.size();        
        DayofYear nd;

        
        for (int i = 0; i < sizeofdates; i++) //copying other sets elements
        {
           nd.setDay(otherset.dates[i].getDay()); 
           nd.setMonth(otherset.dates[i].getMonth());
           dates[i] = nd;
            
            
        }
    }

    void DayofYearSet::add(int newDay, int newMonth) //add function
    {
          
       for (int i = 0; i < sizeofdates; i++)
        {
            if(dates[i].getDay() == newDay && dates[i].getMonth() == newMonth)
            {
                cout << "A set can't have the same element again. Element nod added " << endl;
                
            }
        }

         
           decltype (this->dates)  tempdate = new DayofYear[sizeofdates+1];
       
       
        for (int i = 0; i < sizeofdates; i++)
        {   
            tempdate[i].setMonth(dates[i].getMonth());
            tempdate[i].setDay(dates[i].getDay());
        }
       

        if (dates != nullptr) //if its not null it cleans the array and makes sure we dont have memory leak
         delete [] dates;

        //realloc
       
        dates = tempdate;

        sizeofdates++;
        DayofYear ndate;
        ndate.setMonth(newMonth);
        ndate.setDay(newDay);
        dates[sizeofdates - 1] = ndate;
        
      
       
    }
    

   void DayofYearSet::remove(int rmDay, int rmMonth)
    {
         decltype (this->dates)  temp = nullptr;
        int index;

        bool thereis = false;

        for (int i = 0; i < sizeofdates; i++)
        {
            if ((dates[i].getDay() == rmDay && dates[i].getMonth() == rmMonth))
            {
              
                thereis = true;  
                index = i;         //keeps the index of the element we want to remove
            }
            
                
        }



        if (thereis == true)
        {
            sizeofdates--;

            temp = new DayofYear[sizeofdates];
            auto exceptindex = 0;
            for (int i = 0; i < sizeofdates; i++)
            {
                if(i == index || exceptindex == 1){ // copies every element except the one we want to remove
                 
                 temp[i] = dates[i+1];
            
                 exceptindex = 1;

                }
                else{

                 temp[i] = dates[i];
        

                }

            }
             
                        
                if(dates!=nullptr)
                delete[] dates;
                
                dates = temp;
        
        }
        else
        {
            cout << "There is no element matching with the parameters" << endl << endl;
        }
    

      
    }


      bool DayofYearSet::operator==(const DayofYearSet &other) const
    {
        if (sizeofdates == 0 && other.size() == 0)
         return true;
        if (sizeofdates != other.size()) 
        return false;
        
        bool control;
        for (int i = 0; i < sizeofdates; i++)
        {
            for (int j = 0; j <sizeofdates; j++)
            {
                if (dates[i].getDay() == other.dates[j].getDay() && 
                    dates[i].getMonth() == other.dates[j].getMonth())
                {
                    control = true;
                    break;
                }
                else
                    control = false;
            }
            if (control == false) 
            return false;

        }
        return true;
    }




     DayofYearSet::DayofYear& DayofYearSet::operator[](int index) const
    {
        if (index >= sizeofdates || index < 0)
        {
            cout << "Invalid index (or segmentation fault but this one is prettier)" << endl << endl;
            exit(1);
        }
        return dates[index];
    }

        bool DayofYearSet::operator!=(const DayofYearSet &other) const
    {
        if (sizeofdates != other.size())
        {
            return true;
        }

        int control = 0;
        for (int i = 0; i < sizeofdates; i++)
        {
            for (int j = 0; j < sizeofdates; j++)
            {
                if (dates[i].getDay() == other.dates[j].getDay() && 
                    dates[i].getMonth() == other.dates[j].getMonth())
                {
                    control++;
                }
            }
        }

        if (control == sizeofdates) 
        return false;

        return true;
    }

    const DayofYearSet DayofYearSet::operator^(const DayofYearSet &other) const 
    {
     
        DayofYearSet tempset; 
       

        bool thereis;

        for (int i = 0; i < sizeofdates; i++)
        {
            for (int j = 0; j < other.size(); j++)
            {
                if (dates[i].getDay() == other.dates[j].getDay() &&     //if both set has it copy to temp set
                    dates[i].getMonth() == other.dates[j].getMonth())
                {
                    thereis = true;
                    break;
                }
                else
                    thereis = false;
            }
            if (thereis == true)
            {
                tempset.add(dates[i].getDay(), dates[i].getMonth());
            }
        }
        
        
        return tempset;
    }

   DayofYearSet& DayofYearSet::operator=(const DayofYearSet &other) //copies other to this object with coping dates array
    {
        if (sizeofdates != other.size())
        {
            if (dates != nullptr) 
            delete [] dates;
        
            sizeofdates = other.size();
            dates = new DayofYear[size()];
            
        }
        for(int i = 0; i < sizeofdates; i++)
        {
            dates[i].setMonth(other[i].getMonth());
            dates[i].setDay(other[i].getDay());
        }
        return *this;
    }



 const DayofYearSet DayofYearSet::operator+(const DayofYearSet &other) const
    {
      

        DayofYearSet temp;
        for (int i = 0; i < sizeofdates; i++)
        {
            temp.add(dates[i].getDay(),dates[i].getMonth());  //putting this sets elements
        }
        
       

        bool thereis;
        for (int i = 0; i < other.size(); i++)
        {
            for (int j = 0; j < temp.size(); j++)
            {
                if (other.dates[i].getDay() == temp[j].getDay() && //check if other sets elements are same with this set if not put it in this set
                    other.dates[i].getMonth() == temp[j].getMonth())
                {
                    thereis = true;
                    break;
                }
                else
                    thereis = false;
            }
            if (thereis == false)
            {
                temp.add(other.dates[i].getDay(), other.dates[i].getMonth());
            }
        }

        return temp;
    }


 const DayofYearSet DayofYearSet::operator-(const DayofYearSet &other) const
    {
       DayofYearSet temp;

           decltype (true)  thereis;

        for (int i = 0; i < sizeofdates; i++)
        {
            for (int j = 0; j < other.size(); j++)
            {
                if (dates[i].getDay() == other.dates[j].getDay() &&   //checks if other set has the same element on this set
                    dates[i].getMonth() == other.dates[j].getMonth())
                {
                    thereis = true;
                    break;
                }
                else
                    thereis = false;
            }
            if (thereis == false)
            {
                temp.add(dates[i].getDay(), dates[i].getMonth()); //adding the elements only this set has 
            }
        }

        return temp;
    }

    const DayofYearSet DayofYearSet::operator!(void) const
    {
        DayofYearSet temp;
        decltype (true) thereis;

        for(int i = 0; i < 12; i++)
        {
            for(decltype(i) j = 1; j <= arrdaynumm[i]; j++)
            {
                for(auto k = 0; k < sizeofdates; k++)
                {
                    if(dates[k].getDay() == j && dates[k].getMonth() == i + 1)
                    {
                        thereis = true;
                        break;
                    }
                    else
                    {
                        thereis = false;
                    }
                }
                if (thereis == false)
                {
                    temp.add(j, i + 1);//adding every day that exists except the ones we have
                }
            }
        }
        return temp;
    }


    ostream& operator<<(ostream &outputStream, const DayofYearSet &mySet)
    {
        cout << "Elements in the set are: " << endl;
     
        for (int i = 0; i < mySet.size(); i++)
        { outputStream <<i+1<< ")  ";
            switch (mySet.dates[i].getMonth())
            {
            case 1:
                outputStream << "January    ";
                break;
            case 2:
                outputStream << "February   ";
                break;
            case 3:
                outputStream << "March      ";
                break;
            case 4:
                outputStream << "April      ";
                break;
            case 5:
                outputStream << "May        ";
                break;
            case 6:
                outputStream << "Jun        ";
                break;
            case 7:
                outputStream << "July       ";
                break;
            case 8:
                outputStream << "August     ";
                break;
            case 9:
                outputStream << "Semptember ";
                break;
            case 10:
                outputStream << "October    ";
                break;
            case 11:
                outputStream << "November   ";
                break;
            case 12:
                outputStream << "December   ";
                break;
            }
            outputStream << mySet.dates[i].getDay() << endl;
        }
        outputStream <<endl << "Number of days: " << mySet.size() << endl <<endl;

        return outputStream;
    }
}